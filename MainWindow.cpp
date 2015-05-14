//
//  MainWindow.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 07/04/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include "MainWindow.h"
#include <QtWidgets/qmainwindow.h>
#include <QScrollArea>
#include <QBoxLayout>
#include <iostream>
#include <Tester.h>
#include <SudokuGenerator.h>
#include <GameState.h>
#include <unistd.h>
#include <QObject>



MainWindow::MainWindow() {
    QMainWindow();
    setupWindow();
}
MainWindow::~MainWindow(){
    
}
void MainWindow::setupWindow(){
    setWindowTitle("SudokuSolver");
    setMinimumSize(700, 600);
    mainFrame = new QFrame();
    gridLayout = new QGridLayout(mainFrame);
    gridLayout->setSpacing(0);
    gridLayout->setMargin(0);
    setCentralWidget(mainFrame);
    
    setupTestFrame();
    setupPuzzleFrame();
    setupResultsFrame();
}
void MainWindow::setupTestFrame(){
    //Setup Test Frame
    testFrame = new QFrame();
    testFrame->setStyleSheet("background-color: #9C9C80;");
    QGridLayout *testLayout = new QGridLayout();
    testFrame->setLayout(testLayout);
    
    //Heading
    testHeadingLabel = new QLabel("Setup Test", testFrame);
    testHeadingLabel->setStyleSheet("color: white; font-size:25pt;");
    testHeadingLabel->setAlignment(Qt::AlignCenter);
    testLayout->addWidget(testHeadingLabel,0,0,1,3);
    
    //Algorithm Selector
    algorithmSelector = new QComboBox(testFrame);
    algorithmSelector->addItem("Brute Force Algorithm");
    algorithmSelector->addItem("Random Search Algorithm");
    algorithmSelector->addItem("AStar Search Algorithm");
    algorithmSelector->setStyleSheet("color: white; box-shadow: white; border-radius:3px; border: 1px solid white;");
    testLayout->addWidget(algorithmSelector,1,0,1,1);
    
    //Constraint Selector
    constraintSelector = new QCheckBox(testFrame);
    constraintSelector->setToolTip("Use Constraint Solver");
    testLayout->addWidget(constraintSelector,1,1,1,1);
    
    //Loop Slider
    loopSlider = new QSlider();
    loopSlider->setOrientation(Qt::Horizontal);
    loopSlider->setRange(1, 100);
    testLayout->addWidget(loopSlider,4,0);
    currentSliderValue = new QLabel();
    currentSliderValue->setNum(1);
    currentSliderValue->setAlignment(Qt::AlignCenter);
    currentSliderValue->setStyleSheet("color:white;");
    testLayout->addWidget(currentSliderValue,3,0);
    connect(getLoopSlider(), SIGNAL(valueChanged(int)),currentSliderValue, SLOT(setNum(int)));

    //Level Selector
    levelSelector = new QComboBox();
    levelSelector->addItem("Easy");
    levelSelector->addItem("Average");
    levelSelector->addItem("Hard");
    levelSelector->addItem("Insane");
    levelSelector->addItem("Impossible");
    levelSelector->setStyleSheet("color: white; box-shadow: white; border-radius:3px; border: 1px solid white;");
    testLayout->addWidget(levelSelector,2,0);
    
    //Run button
    runTestButton = new QPushButton("Run Test");
    runTestButton->setStyleSheet("color: white; box-shadow: white; border-radius:3px; border: 1px solid white;");
    testLayout->addWidget(runTestButton,5,0);
    
    gridLayout->addWidget(testFrame,0,0);
}
void MainWindow::setupPuzzleFrame(){
    //Setup Puzzle Frame
    puzzleFrame = new QFrame(mainFrame);
    puzzleFrame->setStyleSheet("background-color: #BABB9C;");
    puzzleLayout = new QGridLayout();
    puzzleFrame->setLayout(puzzleLayout);
    
    //generated puzzle
    generatedPuzzle = new QFrame(puzzleFrame);
    QGridLayout *generatedBoardLayout = new QGridLayout(generatedPuzzle);
    generatedBoardLayout->setSpacing(0);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            QLabel *number = new QLabel("0");
            generatedBoardLayout->addWidget(number,i,j);
            number->setAlignment(Qt::AlignCenter);
            styleSudokuPuzzleForPoint(i, j, number);
        }
    }
    puzzleLayout->addWidget(generatedPuzzle,0,0,1,1);
    
    //solved puzzle
    solvedPuzzle = new QFrame(puzzleFrame);
    QGridLayout *solvedBoardLayout = new QGridLayout(solvedPuzzle);
    solvedBoardLayout->setSpacing(0);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            QLabel *number = new QLabel("0");
            solvedBoardLayout->addWidget(number,i,j);
            number->setAlignment(Qt::AlignCenter);
            styleSudokuPuzzleForPoint(i, j, number);
        }
    }
    puzzleLayout->addWidget(solvedPuzzle,0,1,1,1);
    
    gridLayout->addWidget(puzzleFrame,1,0,2,1);
}
void MainWindow::setupResultsFrame(){
    
    //Setup results frame
    resultsFrame = new QFrame(mainFrame);
    resultsFrame->setStyleSheet("background-color: #627D74;");
    QGridLayout *resultsLayout = new QGridLayout();
    resultsFrame->setLayout(resultsLayout);
    
    //Set up heading
    //Heading
    resultsHeading = new QLabel("Results");
    resultsHeading->setAlignment(Qt::AlignCenter);
    resultsHeading->setStyleSheet("color: white; font-size:25pt;");
    resultsLayout->addWidget(resultsHeading,0,0,1,2);
    
    //Average Time
    averageTimeLabel = new QLabel("Average Time (s):");
    averageTimeLabel->setAlignment(Qt::AlignCenter);
    averageTimeLabel->setStyleSheet("color:white; font-size:14pt;");
    resultsLayout->addWidget(averageTimeLabel,1,0);
    averageTimeValueLabel = new QLabel("0");
    averageTimeValueLabel->setAlignment(Qt::AlignCenter);
    averageTimeValueLabel->setStyleSheet("color:white; font-size:14pt;");
    resultsLayout->addWidget(averageTimeValueLabel,1,1);
    
    //Success Rate
    successRateLabel = new QLabel("Success Rate (%):");
    successRateLabel->setAlignment(Qt::AlignCenter);
    successRateLabel->setStyleSheet("color:white; font-size:14pt;");
    resultsLayout->addWidget(successRateLabel,2,0);
    successRateValueLabel = new QLabel("0");
    successRateValueLabel->setAlignment(Qt::AlignCenter);
    successRateValueLabel->setStyleSheet("color:white; font-size:14pt;");
    resultsLayout->addWidget(successRateValueLabel,2,1);
    
    //add frame to main frame
    gridLayout->addWidget(resultsFrame,3,0);
}
void MainWindow::styleSudokuPuzzleForPoint(int i, int j, QLabel *number){
    
    QString style = "color: grey;";
    if(!i) style += "border-top: 2px dashed grey;";
    if(!j) style += "border-left: 2px dashed grey;";
    if (j == 8) style+= "border-right: 2px dashed grey;";
    if (i == 8) style += "border-bottom: 2px dashed grey;";
    if(j == 2 || j == 5) style += "border-right: 2px dashed grey;";
    if (i == 2 || i == 5) style += "border-bottom: 2px dashed grey;";
    
    number->setStyleSheet(style);

                                    
}

int** MainWindow::getGeneratedPuzzleData()
{
    return generatedPuzzleData;
}
void MainWindow::setGeneratedPuzzleData(int** data){
    MainWindow::generatedPuzzleData = data;
}
int** MainWindow::getSolvedPuzzleData(){
    return solvedPuzzleData;
}
void MainWindow::setSolvedPuzzleData(int** data){
    MainWindow::solvedPuzzleData = data;
}
void MainWindow::updateGeneratedPuzzleWithData(int** data){
    
    QGridLayout *generatedBoardLayout = new QGridLayout();
    
    QWidget().setLayout(generatedPuzzle->layout());
    generatedPuzzle->setLayout(generatedBoardLayout);
    generatedBoardLayout->setSpacing(0);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            QLabel *number = new QLabel();
            number->setNum(data[i][j]);
            generatedBoardLayout->addWidget(number,i,j);
            number->setAlignment(Qt::AlignCenter);
            styleSudokuPuzzleForPoint(i, j, number);
        }
    }
}
void MainWindow::updateSolvedPuzzleWithData(int** data){
    QGridLayout *solvedBoardLayout = new QGridLayout();
    
    QWidget().setLayout(solvedPuzzle->layout());
    solvedPuzzle->setLayout(solvedBoardLayout);
    solvedBoardLayout->setSpacing(0);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            QLabel *number = new QLabel();
            number->setNum(data[i][j]);
            solvedBoardLayout->addWidget(number,i,j);
            number->setAlignment(Qt::AlignCenter);
            styleSudokuPuzzleForPoint(i, j, number);
        }
    }
}
QPushButton* MainWindow::getRunButton(){
    return runTestButton;
}
QComboBox* MainWindow::getAlgorithmSelector(){
    return algorithmSelector;
}
QCheckBox* MainWindow::getConstraintSelector(){
    return constraintSelector;
}
QSlider* MainWindow::getLoopSlider(){
    return loopSlider;
}
void MainWindow::runTest() {
    
    Tester *tester = new Tester();
    double averageTime = 0;
    int goalCounter = 0;
    int loops = getLoopSlider()->value();
    for (int i = 0; i < loops; i++){
        SudokuGenerator generator = SudokuGenerator();
        GameState state = generator.GenerateState(9);
        updateGeneratedPuzzleWithData(state.getData());
        while (!state.isGoalState()) {
            state = generator.GenerateState(9);
        }
        state = generator.digHoles(state, levelSelector->currentIndex());
        updateGeneratedPuzzleWithData(state.getData());
        clock_t startTime = clock();
        GameState solution = tester->runTestForState(state, algorithmSelector->currentIndex(), constraintSelector->isChecked());
        clock_t endTime = clock();
        clock_t clockTicksTaken = endTime - startTime;
        long double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
        if(solution.isGoalState()) {
            averageTime += timeInSeconds;
            goalCounter++;
        }
        updateSolvedPuzzleWithData(solution.getData());
    }
    averageTime = averageTime/loops;
    double successRate = ((float)goalCounter/(float)loops) * 100;
    averageTimeValueLabel->setNum(averageTime);
    successRateValueLabel->setNum(successRate);

    
}
void MainWindow::updateSlider(){
}