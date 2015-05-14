//
//  AStarSearch.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 26/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include "AStarSearch.h"
#include <iostream>
#include "SudokuGameEngine.h"
#include <cstdio>
#include <ctime>

using namespace std;

AStarSearch::AStarSearch() {
    
}
AStarNode AStarSearch::findSolutionForNode(AStarNode node) {
    
    std::clock_t start = clock();
    double duration;

    
    SudokuGameEngine engine = SudokuGameEngine();
    
    frontier.push(node);
    
    while (!frontier.empty()) {

        
        AStarNode node = frontier.top();
        frontier.pop();
        duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
        if (duration > 2) return node;

        
        if(node.getState().isGoalState())
            return node;
        else
            closedList.push_back(node);
        
        //Dead State
        if(engine.isStateDead(node.getState())) {
            closedList.push_back(node);
            continue;
        }
        
        
        // Implement multiple path pruning
        for (AStarNode closedNode : closedList)
            if (node.nodeEqualsNode(closedNode))
                continue;
        
//        cout << frontier.size();
//        cout << "\n";

        vector<AStarNode> children = node.getChildNodesForNode(node);
        
        for (AStarNode node : children) {
            bool inClosedList = false;
            for (AStarNode closedNode : closedList)
                if (node.nodeEqualsNode(closedNode))
                    inClosedList = true;
                if (!inClosedList)
                    frontier.push(node);
            }
        
        
    }
    
    return node;
}