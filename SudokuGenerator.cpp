//
//  SudokuGenerator.cpp
//  Sudoku Project
//
//  Created by Craig Pullar on 04/02/2015.
//
//

#include "SudokuGenerator.h"

using namespace std;

GameState SudokuGenerator::GenerateState(int dim){
    
    //Generate random full board
    SudokuGenerator::dim = dim;
    srand (time(NULL));
    SudokuGenerator::data = new int *[dim];
    for (int i = 0; i < dim; i++) {
        data[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            if(deadRowGeneration(i, j)){
                i--;
                j= 0;
            }
            int randNo = rand() % 9 +1;
            int x = 0;
            while(!isValidNumber(randNo, i, j) && x < 20){
                randNo = rand() % 9 +1;
                x++;
            }
            data[i][j] = randNo;

        }
    }
    
    GameState *generatedState = new GameState(data, dim);
    return *generatedState;
}

GameState SudokuGenerator::digHoles(GameState state, int level) {
    //Dig holes
    for (int i = 0; i < state.getDim(); i++) {
        for (int j = 0; j < state.getDim(); j++){
            int chance = rand() % 9 +1;
            if (chance < level + 3)
                state.getData()[i][j] = 0;
        }
    }
    return state;
}
SudokuGenerator::SudokuGenerator(){
    
}
bool SudokuGenerator::isValidNumber(int number, int row, int col){

    //Check col
    for (int r = 0; r < row; r++)
        if (number == data[r][col])
            return false;
    
    //Check row
    for (int c = 0; c < col; c++)
        if (number == data[row][c])
            return false;
    
    //Get segments
    int rowSeg = row/3;
    int colSeg = col/3;
    
    //Check segment
    for (int r = rowSeg * 3; r < row; r++)
        for (int c = colSeg*3; c < col; c++)
            if (number == data[r][c])
                return false;

    
    return true;
}

bool SudokuGenerator::deadRowGeneration(int row, int col) {
    
    int possibleNumbers[9] = {1,2,3,4,5,6,7,8,9};
    
    for (int n : possibleNumbers)
        if(isValidNumber(n, row, col))
            return false;
    
    return true;
}
int** SudokuGenerator::getData() {
    return data;
}
void SudokuGenerator::setData(int **data){
    SudokuGenerator::data = data;
}
