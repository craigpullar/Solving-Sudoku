//
//  Action.h
//  Solving Sudoku
//
//  Created by Craig Pullar on 19/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#ifndef __Solving_Sudoku__Action__
#define __Solving_Sudoku__Action__

#include <stdio.h>



class Action {
    
private:
    int cost;
    int value;
    int row;
    int col;
    
public:
    Action();
    Action(int value, int row, int col);
    int getCost();
    void setCost(int cost);
    int getValue();
    void setValue(int value);
    int getRow();
    void setRow(int row);
    int getCol();
    void setCol(int col);
    void printAction();
    
};

#endif /* defined(__Solving_Sudoku__Action__) */