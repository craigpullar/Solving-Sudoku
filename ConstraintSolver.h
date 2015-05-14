//
//  ConstraintSolver.h
//  Solving Sudoku
//
//  Created by Craig Pullar on 16/03/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#ifndef __Solving_Sudoku__ConstraintSolver__
#define __Solving_Sudoku__ConstraintSolver__

#include <stdio.h>
#include <vector>
#include "Point.h"
#include "GameState.h"

using namespace std;

class ConstraintSolver {
    
private:
    vector<Point> points;
    bool rowContainsValueForState(int row, int value, GameState state, bool ignoreSeg);
    bool colContainsValueForState(int col, int value, GameState state, bool ignoreSeg);
    bool segmentContainsValueForState(int row, int col, int value, GameState state);
    bool valueIsDefiniteForPointInState(int value, Point point, GameState state);
    GameState findDefinitesForState(GameState state);
    GameState fillFinalHolesForState(GameState);
    bool isLastHoleInRow(Point point, GameState state);
    bool isLastHoleInCol(Point point, GameState state);
    bool isLastHoleInSegment(Point point, GameState state);
    vector<Point> getBlankPointsForState(GameState state);
    vector<Point> shavePossibilitiesForPointsInState(vector<Point> points, GameState state);
    GameState solveStateWithPoints(GameState state, vector<Point> points);
    
public:
    ConstraintSolver();
    GameState findSolutionForState(GameState state);

    
    vector<Point> getPoints();
    void setPoints(vector<Point> points);
    
};

#endif /* defined(__Solving_Sudoku__ConstraintSolver__) */
