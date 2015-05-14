//
//  SudokuGameEngine.h
//  Sudoku Project
//
//  Created by Craig Pullar on 04/02/2015.
//
//

#ifndef __Sudoku_Project__SudokuGameEngine__
#define __Sudoku_Project__SudokuGameEngine__

#include <stdio.h>
#include "GameState.h"

class SudokuGameEngine{
    
private:
    GameState currentGameState;
    
public:
    SudokuGameEngine();
    
    void setCurrentGameState(GameState state);
    GameState getCurrentGameState();
    
    vector<Action> getPossibleActionsForState(GameState state);
    GameState takeActionForState(Action action, GameState state);
    bool isValidActionForState(Action action, GameState state);
    bool isStateDead(GameState state);
    vector<Action> getPossibleActionsForPointinState(int row, int col, GameState state);
    
    
};

#endif /* defined(__Sudoku_Project__SudokuGameEngine__) */
