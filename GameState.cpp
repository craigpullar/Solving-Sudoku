//
//  GameState.cpp
//  Sudoku Project
//
//  Created by Craig Pullar on 03/02/2015.
//
//

#include "GameState.h"
#include <iostream>
#include "SudokuGenerator.h"


GameState::GameState(int dim) {
    GameState::dim = dim;
}
GameState::GameState(int **data, int dim){
    GameState::dataArray = data;
    GameState::dim = dim;
}
void GameState::printState() {
    cout << "\n";
    for(int i = 0; i < dim; i++) {
        if (i % 3 == 0) {
            for(int n = 0; n < 25; n++)
                cout << "-";
            cout << "\n";
        }
        for(int j = 0; j < dim;j++){
            if (j % 3 == 0) {
                cout << "| ";
            }
            cout << dataArray[i][j];
            cout << " ";
        }
        cout << "|";
        cout << "\n";
    }
    for(int n = 0; n < 25; n++)
        cout << "-";
    cout << "\n";
}
int GameState::getNumberOfHoles() {
     int counter = 0;
    for (int i = 0; i < getDim(); i++)
        for (int j = 0; j < getDim(); j++)
            if (!getData()[i][j])
                counter++;
    return counter;
}
GameState::GameState(){
    
}

int GameState::getDim() {
    return GameState::dim;
}

void GameState::setDim(int dim) {
    GameState::dim = dim;
}

int ** GameState::getData() {
    return GameState::dataArray;
}

void GameState::setData(int **data) {
    GameState::dataArray = data;
}

bool GameState::isGoalState() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            
            if (!dataArray[i][j]) return false;
            
            //Check col
            for (int r = 0; r < dim; r++)
                if (dataArray[i][j] == dataArray[r][j] && i != r)
                    return false;
            
            //Check row
            for (int c = 0; c < dim; c++)
                if (dataArray[i][j] == dataArray[i][c] && j != c)
                    return false;
            
            //Get segments
            int rowSeg = i/3;
            int colSeg = j/3;
            
            //Check segment
            for (int r = rowSeg * 3; r < rowSeg*3+3; r++)
                for (int c = colSeg*3; c < colSeg*3+3; c++)
                    if (dataArray[i][j] == dataArray[r][c] && i != r && j != c)
                        return false;
        }
    }
    
    return true;
}
bool GameState::isValidState() {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            
            if (!dataArray[i][j]) continue;
            
            //Check col
            for (int r = 0; r < dim; r++)
                if (dataArray[i][j] == dataArray[r][j] && r != i)
                    return false;
            
            //Check row
            for (int c = 0; c < dim; c++)
                if (dataArray[i][j] == dataArray[i][c] && j != c)
                    return false;
            
            //Get segments
            int rowSeg = i/3;
            int colSeg = j/3;
            
            //Check segment
            for (int r = rowSeg * 3; r < rowSeg*3+3; r++)
                for (int c = colSeg*3; c < colSeg*3+3; c++)
                    if (dataArray[i][j] == dataArray[r][c] && r != i && j != c)
                        return false;
        }
    }
    
    return true;
}
bool GameState::isValidNumber(int number, int row, int col){
    
    if(!number)
        return false;
    
    //Check col
    for (int r = 0; r < getDim(); r++)
        if (number == dataArray[r][col] && r != row)
            return false;
    
    //Check row
    for (int c = 0; c < getDim(); c++)
        if (number == dataArray[row][c] && c != col)
            return false;
    
    //Get segments
    int rowSeg = row/3;
    int colSeg = col/3;
    
    //Check segment
    for (int r = rowSeg * 3; r < rowSeg * 3 + 3; r++)
        for (int c = colSeg*3; c < colSeg*3 + 3; c++)
            if (number == dataArray[r][c] && r != row && c != col)
                return false;
    
    
    return true;
}