//
//  GameState.h
//  Sudoku Project
//
//  Created by Craig Pullar on 03/02/2015.
//
//

#ifndef __Sudoku_Project__GameState__
#define __Sudoku_Project__GameState__

#include <stdio.h>
#include <vector>
#include "Action.h"
using namespace std;
class GameState {
    
private:
    int dim;
    int** dataArray;
    
public:
    // Constructors
    GameState( int dim);
    GameState(int **data, int dim);
    GameState();
    
    // Functions
    void printState();
    bool isValidState();
    bool isGoalState();
    bool isValidNumber(int value, int row, int col);
    int getNumberOfHoles();
    
    // Getters & Setters
    void setDim(int dim);
    int getDim();
    void setData(int** data);
    int** getData();
    
    
};

#endif /* defined(__Sudoku_Project__GameState__) */
