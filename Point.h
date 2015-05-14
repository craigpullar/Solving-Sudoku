//
//  Point.h
//  Solving Sudoku
//
//  Created by Craig Pullar on 10/03/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#ifndef __Solving_Sudoku__Point__
#define __Solving_Sudoku__Point__

#include <stdio.h>
#include <vector>

using namespace std;

class Point {
private:
    int col;
    int row;
    int value;
    Point *lastPoint;
    vector<int> possibleValues;
    int rowSeg;
    int colSeg;
    
public:
    Point (int row, int col, int value, Point *lastPoint);
    Point (int row, int col, int value);
    Point (int row, int col, vector<int> possibleValues);
    
    int getCol();
    void setCol(int col);
    int getRow();
    void setRow(int row);
    int getValue();
    void setValue(int value);
    Point* getLastPoint();
    void setLastPoint(Point *lastPoint);
    vector<int> getPossibleValues();
    void setPossibleValues(vector<int> possibleValues);
    int getRowSeg();
    void setRowSeg(int rowSeg);
    int getColSeg();
    void setColSeg(int colSeg);
    void printPoint();
};

#endif /* defined(__Solving_Sudoku__Point__) */
