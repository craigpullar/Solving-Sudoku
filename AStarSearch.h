//
//  AStarSearch.h
//  Solving Sudoku
//
//  Created by Craig Pullar on 26/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#ifndef __Solving_Sudoku__AStarSearch__
#define __Solving_Sudoku__AStarSearch__

#include <stdio.h>
#include <queue> 
#include <vector>
#include "AStarNode.h"

using namespace std;

struct Compare
{
    bool operator() (AStarNode a, AStarNode b) { return a.getScore() > b.getScore(); }
};

class AStarSearch {
    
private:
    
    priority_queue<AStarNode, vector<AStarNode>, Compare> frontier;
    vector<AStarNode> closedList;
    
public:
    
    AStarSearch();
    AStarNode findSolutionForNode(AStarNode node);
    
};

#endif /* defined(__Solving_Sudoku__AStarSearch__) */
