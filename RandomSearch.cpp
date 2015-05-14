//
//  RandomSearch.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 20/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include "RandomSearch.h"
#include <iostream>
#include <vector>
#include "Point.h"
#include <cstdio>
#include <ctime>


RandomSearch::RandomSearch(){
    
}
GameState RandomSearch::findSolutionForState(GameState state) {
    srand (time(NULL));
    vector<Point> points;
    std::clock_t start = clock();
    double duration;
    for (int i = 0; i < state.getDim(); i++)
        for(int j = 0; j < state.getDim(); j++)
            if(!state.getData()[i][j])
                points.push_back(Point(i,j,0));
    while(!state.isGoalState()) {
        //Generate a random completed state from the param state
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        if (duration > 2) return state;
        
        for(Point point : points)
                if(!state.isValidNumber(state.getData()[point.getRow()][point.getCol()], point.getRow(), point.getCol())) {
                    int randNo = rand() % 9 +1;
                    
                    state.getData()[point.getRow()][point.getCol()] = randNo;
                }
    }

    
    return state;
}