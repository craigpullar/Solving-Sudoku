//
//  BruteForce.h
//  Solving Sudoku
//
//  Created by Craig Pullar on 23/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#ifndef __Solving_Sudoku__BruteForce__
#define __Solving_Sudoku__BruteForce__

#include <stdio.h>
#include "GameState.h"

class BruteForce {
    
private:
    
public:
    BruteForce();
    GameState findSolutionForState(GameState state);
    
};
#endif /* defined(__Solving_Sudoku__BruteForce__) */
