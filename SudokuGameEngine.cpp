//
//  SudokuGameEngine.cpp
//  Sudoku Project
//
//  Created by Craig Pullar on 04/02/2015.
//
//

#include "SudokuGameEngine.h"
#include "GameState.h"


void SudokuGameEngine::setCurrentGameState(GameState state) {
    SudokuGameEngine::currentGameState = state;
}

GameState SudokuGameEngine::getCurrentGameState() {
    return currentGameState;
}

SudokuGameEngine::SudokuGameEngine(){
    
}

GameState SudokuGameEngine::takeActionForState(Action action, GameState state) {
    
    int **stateData;
    stateData = new int *[state.getDim()];
    for (int i = 0; i < state.getDim(); i++) {
        stateData[i] = new int[state.getDim()];
        for(int j = 0; j < state.getDim(); j++) {
            stateData[i][j] = state.getData()[i][j];
        }
    }
    
    stateData[action.getRow()][action.getCol()] = action.getValue();
    GameState child = GameState(stateData, state.getDim());
    return child;
}

bool SudokuGameEngine::isValidActionForState(Action action, GameState state){
    //Check col
    for (int r = 0; r < state.getDim(); r++)
        if (action.getValue() == state.getData()[r][action.getCol()])
            return false;
    
    //Check row
    for (int c = 0; c < state.getDim(); c++)
        if (action.getValue() == state.getData()[action.getRow()][c])
            return false;
    
    //Get segments
    int rowSeg = action.getRow()/3;
    int colSeg = action.getCol()/3;
    
    //Check segment
    for (int r = rowSeg * 3; r < rowSeg*3+3; r++)
        for (int c = colSeg*3; c < colSeg*3+3; c++)
            if (action.getValue() == state.getData()[r][c])
                return false;
    
    
    return true;
}

vector<Action> SudokuGameEngine::getPossibleActionsForState(GameState state){
    
    vector<Action> possibleActions;
    
    for (int i = 0; i < state.getDim(); i++) {
        for (int j = 0; j < state.getDim(); j++) {
            if (!state.getData()[i][j]) {
                for (int n = 1; n <= state.getDim(); n++) {
                    Action action = Action(n, i, j);
                    if(isValidActionForState(action, state)) {
                        possibleActions.push_back(action);
                    }
                }
                
            }
            
        }
    }
    
    return possibleActions;
}

bool SudokuGameEngine::isStateDead(GameState state) {
    for (int i = 0; i < state.getDim(); i++) {
        for (int j = 0; j < state.getDim(); j++) {
            if (!state.getData()[i][j]) {
                vector<Action> possibleActions = getPossibleActionsForPointinState(i, j, state);
                if (possibleActions.size() == 0)
                    return true;
            }
        }
    }
    
    return false;
}

vector<Action> SudokuGameEngine::getPossibleActionsForPointinState(int row, int col, GameState state)
{
    vector<Action> possibleActions;
    
    for (int n = 1; n <= state.getDim(); n++) {
        Action action = Action(n, row, col);
        if(isValidActionForState(action, state)) {
            possibleActions.push_back(action);
        }
    }
    
    return possibleActions;
}

