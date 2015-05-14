//
//  RandomSearch.h
//  Solving Sudoku
//
//  Created by Craig Pullar on 20/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#ifndef __Solving_Sudoku__RandomSearch__
#define __Solving_Sudoku__RandomSearch__

#include <stdio.h>
#include "GameState.h"
#include <stdlib.h>

class RandomSearch {
    
private:
    
public:
    
    RandomSearch();
    GameState findSolutionForState(GameState state);
    
};

#endif /* defined(__Solving_Sudoku__RandomSearch__) */
