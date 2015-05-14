//
//  Tester.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 06/04/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include "Tester.h"
#include "BruteForce.h"
#include <RandomSearch.h>
#include <AStarSearch.h>
#include <iostream>
#include <SudokuGenerator.h>
#include <ConstraintSolver.h>
#include <AStarNode.h>


Tester::Tester(){
    
}
GameState Tester::runTestForState(GameState state, int algorithm, bool useConstraintAlgorithm){
    
    switch (algorithm) {
        case 0:
            return runBruteForceTestForState(state, useConstraintAlgorithm);

        case 1:
            return runRandomSearchTestForState(state, useConstraintAlgorithm);
            
        case 2:
            return runAStarSearchTestForState(state, useConstraintAlgorithm);
    }
    return NULL;
}
GameState Tester::runBruteForceTestForState(GameState state, bool useConstraintAlgorithm){
    ConstraintSolver constraintSolver = ConstraintSolver();
    BruteForce bruteForce = BruteForce();

        if(useConstraintAlgorithm)
            state = constraintSolver.findSolutionForState(state);
        return bruteForce.findSolutionForState(state);
}
GameState Tester::runRandomSearchTestForState(GameState state, bool useConstraintAlgorithm){
    ConstraintSolver constraintSolver = ConstraintSolver();
    RandomSearch randomSearch = RandomSearch();
    if(useConstraintAlgorithm)
        state = constraintSolver.findSolutionForState(state);
    return randomSearch.findSolutionForState(state);
    
}
GameState Tester::runAStarSearchTestForState(GameState state, bool useConstraintAlgorithm){
    ConstraintSolver constraintSolver = ConstraintSolver();
    AStarSearch aStarSearch = AStarSearch();
    if(useConstraintAlgorithm)
        state = constraintSolver.findSolutionForState(state);
    return aStarSearch.findSolutionForNode(AStarNode(0,state)).getState();
}