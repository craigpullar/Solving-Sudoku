//
//  SudokuGenerator.h
//  Sudoku Project
//
//  Created by Craig Pullar on 04/02/2015.
//
//

#ifndef __Sudoku_Project__SudokuGenerator__
#define __Sudoku_Project__SudokuGenerator__

#include <stdio.h>
#include "GameState.h"
#include <stdlib.h>
#include <vector>
#include <iostream>
class SudokuGenerator {
private:
    GameState state;
    bool deadRowGeneration(int row, int col);
    int dim;
    int **data;
    
public:
    GameState GenerateState(int dim);
    bool isValidNumber(int number, int row, int col);
    SudokuGenerator();
    void setData(int **data);
    int** getData();
    GameState digHoles(GameState state, int level);
    
};

#endif /* defined(__Sudoku_Project__SudokuGenerator__) */
