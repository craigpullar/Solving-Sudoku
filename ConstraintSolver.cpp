//
//  ConstraintSolver.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 16/03/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include "ConstraintSolver.h"
#include "SudokuGameEngine.h"
#include <stdlib.h>
#include <iostream>

ConstraintSolver::ConstraintSolver() {
    
}
vector<Point> ConstraintSolver::getBlankPointsForState(GameState state) {
    vector<Point> points;;
    for( int i = 0; i < state.getDim(); i++)
        for (int j = 0; j < state.getDim(); j++)
            if(!state.getData()[i][j]) {
                vector<int> possibleValues;
                for (int n = 1; n <= 9; n++)
                    possibleValues.push_back(n);
                points.push_back(Point(i, j, possibleValues));
                
            }
    return points;
}
vector<Point> ConstraintSolver::shavePossibilitiesForPointsInState(vector<Point> points, GameState state){
    SudokuGameEngine engine = SudokuGameEngine();
    

    //Check for definite values
    for (Point point: points){
 
        for (int value : point.getPossibleValues()){
            Action action = Action(value, point.getRow(), point.getCol());
            if (value == 0) continue;
            else if(!engine.isValidActionForState(action, state))
                continue;
            else if(valueIsDefiniteForPointInState(value, point, state)) {
                point.setValue(value);
                point.getPossibleValues().empty();
                break;
            }
        }

            
        }
    points = getBlankPointsForState(state);
            
    return points;
}
bool ConstraintSolver::rowContainsValueForState(int row, int value, GameState state, bool ignoreSeg){
    if (ignoreSeg) {
        int rowSeg = row/3;
        for (int c = 0; c < state.getDim(); c++){
            if (rowSeg == 0 && c < 3) continue;
            else if(rowSeg == 1 && c > 2 && c < 6) continue;
            else if(rowSeg == 2 && c > 6) continue;
            if(state.getData()[row][c] == value)
                return true;
        }
        
    }
    else {
        for (int c = 0; c < state.getDim(); c++)
            if(state.getData()[row][c] == value)
                return true;
    }

    return false;
}
bool ConstraintSolver::colContainsValueForState(int col, int value, GameState state, bool ignoreSeg){
    if (ignoreSeg) {
        int colSeg = col/3;
        for (int r = 0; r < state.getDim(); r++) {
            if (colSeg == 0 && r < 3) continue;
            else if(colSeg == 1 && r > 2 && r < 6) continue;
            else if(colSeg == 2 && r > 6) continue;
            if(state.getData()[r][col] == value)
                return true;
        }
    }
    else {
        for (int r = 0; r < state.getDim(); r++)
            if(state.getData()[r][col] == value)
                return true;
    }

    return false;
}
bool ConstraintSolver::segmentContainsValueForState(int row, int col, int value, GameState state){
    //Get segments
    int rowSeg = row/3;
    int colSeg = col/3;
    
    //Check segment
    for (int r = rowSeg * 3; r < rowSeg*3+3; r++)
        for (int c = colSeg*3; c < colSeg*3+3; c++)
            if (value == state.getData()[r][c])
                return true;
    
    return false;
}
bool ConstraintSolver::valueIsDefiniteForPointInState(int value, Point point, GameState state){
    SudokuGameEngine engine = SudokuGameEngine();
    Action action = Action(value, point.getRow(), point.getCol());
    if(!engine.isValidActionForState(action, state))
        return false;

    

    
    if (point.getRow() == 0 ||point.getRow() == 3 ||point.getRow() == 6) {
        
        if(!rowContainsValueForState(point.getRow()+1, value, state, true) ||
           !rowContainsValueForState(point.getRow()+2, value, state, true))
            return false;
        else if (!state.getData()[point.getRow()+1][point.getCol()] &&
                 !state.getData()[point.getRow()+2][point.getCol()])
            return true;
        
    }

    else if(point.getRow() == 1 ||point.getRow() == 4 ||point.getRow() == 7 ) {
        if(!rowContainsValueForState(point.getRow()-1, value, state, true) ||
           !rowContainsValueForState(point.getRow()+1, value, state, true))
            return false;
        else if (!state.getData()[point.getRow()+1][point.getCol()] &&
                !state.getData()[point.getRow()-1][point.getCol()])
                return true;
    }
    else {
        if(!rowContainsValueForState(point.getRow()-1, value, state, true) ||
            !rowContainsValueForState(point.getRow()-2, value, state, true))
            return false;
        else if (!state.getData()[point.getRow()-1][point.getCol()] &&
                 !state.getData()[point.getRow()-2][point.getCol()])
                    return true;
    }
    
    if (point.getCol() == 0 ||point.getCol() == 3 ||point.getCol() == 6) {
        if(!colContainsValueForState(point.getCol()+1, value, state, true) ||
           !colContainsValueForState(point.getCol()+2, value, state, true))
            return false;
        else if (!state.getData()[point.getRow()][point.getCol()+1] &&
                 !state.getData()[point.getRow()][point.getCol()+2])
                    return true;
        
    }
    else if(point.getCol() == 1 ||point.getCol() == 4 ||point.getCol() == 7 ) {
        if(!colContainsValueForState(point.getCol()-1, value, state, true) ||
           !colContainsValueForState(point.getCol()+1, value, state, true))
            return false;
        else if (!state.getData()[point.getRow()][point.getCol()-1] &&
                !state.getData()[point.getRow()][point.getCol()+1])
                    return true;
    }
    else {
        if(!colContainsValueForState(point.getCol()-1, value, state, true) ||
           !colContainsValueForState(point.getCol()-2, value, state, true))
            return false;
        else if (!state.getData()[point.getRow()][point.getCol()-1] &&
                !state.getData()[point.getRow()][point.getCol()-2])
                    return true;
    }
    
    return true;
}
vector<Point> ConstraintSolver::getPoints(){
    return points;
}
void ConstraintSolver::setPoints(vector<Point> points){
    ConstraintSolver::points = points;
}

GameState ConstraintSolver::findDefinitesForState(GameState state){
    int counter = 1;
    while(counter){
        counter = 0;
        for( int i = 0; i < state.getDim(); i++)
            for (int j = 0; j < state.getDim(); j++)
                if(!state.getData()[i][j]) {
                    Point point = Point(i,j,0);
                    
                    if(isLastHoleInSegment(point, state))
                        for (int x = 1; x <= state.getDim(); x++)
                            if(!segmentContainsValueForState(i, j, x, state)){
                                state.getData()[i][j] = x;
                                counter++;
                            }
                    
                    if(isLastHoleInRow(point, state))
                        for (int x = 1; x <= state.getDim(); x++)
                            if(!rowContainsValueForState(i, x, state, false)) {
                                state.getData()[i][j] = x;
                                counter++;
                            }
                    
                    if(isLastHoleInCol(point, state))
                        for (int x = 1; x <= state.getDim(); x++)
                            if(!colContainsValueForState(j, x, state, false)){
                                state.getData()[i][j] = x;
                                counter++;
                            }

                    for (int x = 1; x <= 9; x++)
                        if(valueIsDefiniteForPointInState(x, point, state)){
                            state.getData()[i][j] = x;
                            counter++;
                            break;
                        }
                }
    }
    return state;
}
bool ConstraintSolver::isLastHoleInRow(Point point, GameState state){
    for (int c = 0; c < state.getDim(); c++)
        if(!state.getData()[point.getRow()][c] && point.getCol() != c)
            return false;
    return true;
}
bool ConstraintSolver::isLastHoleInCol(Point point, GameState state){
    for (int r = 0; r < state.getDim(); r++)
        if(!state.getData()[r][point.getCol()] && point.getRow() != r)
            return false;
    return true;
}
bool ConstraintSolver::isLastHoleInSegment(Point point, GameState state){
    int rowSeg = point.getRow()/3;
    int colSeg = point.getCol()/3;
    int counter = 0;
    
    //Check segment
    for (int r = rowSeg * 3; r < rowSeg*3+3; r++)
        for (int c = colSeg*3; c < colSeg*3+3; c++)
            if (!state.getData()[r][c])
                counter++;
    
    if (counter > 1) return false;
    
    
    return true;
}
GameState ConstraintSolver::findSolutionForState(GameState state) {
    return findDefinitesForState(state);
}