//
//  main.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 04/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include <iostream>
#include "SudokuGameEngine.h"
#include "SudokuGenerator.h"
#include "Action.h"
#include "BruteForce.h"
#include "AStarSearch.h"
#include "ConstraintSolver.h"
#include "Point.h"
#include "RandomSearch.h"
#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <QtCore/qarraydata.h>
#include "Tester.h"


int main(int argc, char *argv[]) {

//
//    //--[[INIT]]--//
    
//    Q_INIT_RESOURCE(application);
    
    QApplication app(argc,argv);
    app.setOrganizationName("QtProject");
    app.setApplicationName("Application Example");
    MainWindow mainWin;
    mainWin.show();
    
    
    QObject::connect(mainWin.getRunButton(), SIGNAL(clicked()),&mainWin, SLOT(runTest()));
    
    
    return app.exec();
    

}
