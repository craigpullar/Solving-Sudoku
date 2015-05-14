//
//  BruteForce.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 23/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include "BruteForce.h"
#include <iostream>
#include "Action.h"
#include "Point.h"
#include <stack>
#include "SudokuGameEngine.h"
#include <cstdio>
#include <ctime>

BruteForce::BruteForce() {
    
}
GameState BruteForce::findSolutionForState(GameState state) {
    
    std::clock_t start = clock();
    double duration;

    SudokuGameEngine engine = SudokuGameEngine();
    vector<Point> points;
    for (int i = 0; i < state.getDim(); i++)
        for(int j = 0; j < state.getDim(); j++)
            if(!state.getData()[i][j])
                points.push_back(Point(i,j,1));

    for (int i = 0; i < points.size();i++) {
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        if (duration > 2) return state;
        Point *currentPoint = &points.at(i);
        for(int n = currentPoint->getValue(); n <= 9; n++) {
            
            //Create Action
            Action action = Action(n,currentPoint->getRow(),currentPoint->getCol());
            
            //If valid number edit state accordingly and move on to next point
            if(engine.isValidActionForState(action, state)) {
                state.getData()[currentPoint->getRow()][currentPoint->getCol()] = n;
                currentPoint->setValue(n);
                break;
            }
            //If no valid number move back to the last point
            else if(n == 9) {
                i -= 2;
                currentPoint->setValue(1);
                state.getData()[currentPoint->getRow()][currentPoint->getCol()] = 0;
            }
        }
            
    }
        
    return state;
}
