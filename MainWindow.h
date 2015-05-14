//
//  MainWindow.h
//  Solving Sudoku
//
//  Created by Craig Pullar on 07/04/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#ifndef __Solving_Sudoku__MainWindow__
#define __Solving_Sudoku__MainWindow__

#include <stdio.h>
#include <QtWidgets/qmainwindow.h>
#include <QComboBox>
#include <QLabel>
#include <QScrollArea>
#include <QGridLayout>
#include <QCheckBox>
#include <QSlider>
#include <QPushButton>




class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
    
    int** getGeneratedPuzzleData();
    void setGeneratedPuzzleData(int** data);
    int** getSolvedPuzzleData();
    void setSolvedPuzzleData(int** data);
    void updateGeneratedPuzzleWithData(int** data);
    void updateSolvedPuzzleWithData(int** data);
    QPushButton* getRunButton();
    QComboBox* getAlgorithmSelector();
    QCheckBox* getConstraintSelector();
    QSlider* getLoopSlider();
    
private:
    void setupWindow();
    void setupTestFrame();
    void setupPuzzleFrame();
    void setupResultsFrame();
    void styleSudokuPuzzleForPoint(int i, int j, QLabel *number);
    int **generatedPuzzleData;
    int **solvedPuzzleData;
    
    QComboBox *algorithmSelector;
    QCheckBox *constraintSelector;
    QSlider *loopSlider;
    QLabel *testHeadingLabel;
    QFrame *mainFrame;
    QFrame *testFrame;
    QFrame *puzzleFrame;
    QFrame *resultsFrame;
    QGridLayout *gridLayout;
    QFrame *generatedPuzzle;
    QFrame *solvedPuzzle;
    QLabel *timeResult;
    QLabel *successResult;
    QLabel *resultsHeading;
    QLabel *currentSliderValue;
    QPushButton *runTestButton;
    QGridLayout *puzzleLayout;
    QComboBox *levelSelector;
    QLabel *averageTimeLabel;
    QLabel *averageTimeValueLabel;
    QLabel *successRateLabel;
    QLabel *successRateValueLabel;
    
public slots:
    void runTest();
    void updateSlider();
};

#endif /* defined(__Solving_Sudoku__MainWindow__) */
