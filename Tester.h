//
//  Tester.h
//  Solving Sudoku
//
//  Created by Craig Pullar on 06/04/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#ifndef __Solving_Sudoku__Tester__
#define __Solving_Sudoku__Tester__

#include <stdio.h>
#include <QObject>
#include <GameState.h>
class Tester : public QObject{
    Q_OBJECT
    
private:
    GameState runBruteForceTestForState(GameState state, bool useConstraintAlgorithm);
    GameState runRandomSearchTestForState(GameState state, bool useConstraintAlgorithm);
    GameState runAStarSearchTestForState(GameState state, bool useConstraintAlgorithm);
    
public:
    Tester();
    GameState runTestForState(GameState state, int algorithm, bool useConstraintAlgorithm);

    
    
};

#endif /* defined(__Solving_Sudoku__Tester__) */
