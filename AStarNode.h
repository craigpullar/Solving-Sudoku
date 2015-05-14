//
//  AStarNode.h
//  Solving Sudoku
//
//  Created by Craig Pullar on 26/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#ifndef __Solving_Sudoku__AStarNode__
#define __Solving_Sudoku__AStarNode__

#include <stdio.h>
#include "GameState.h"
#include <vector>
#include "Action.h"

using namespace std;

class AStarNode {
    
private:
    int correctness;
    int hueristicValue;
    GameState state;
    int compareValue;
    Action *action;
    AStarNode *previousNode;
    
public:
    AStarNode();
    AStarNode(int correctness, GameState state);
    AStarNode(int correctness, GameState state, Action *action, AStarNode *previousNode);
    
    int evaluateHueristic();
    
    int getCorrectness();
    void setCorrectness(int correctness);
    int getHueristicValue();
    void setHueristicValue( int value);
    int getScore();
    GameState getState();
    void setState(GameState state);
    bool nodeEqualsNode(AStarNode node);
    int getNumberOfActions();
    int getNumberOfHoles();
    Action getAction();
    AStarNode getPreviousNode();
    
    vector<AStarNode> getChildNodesForNode(AStarNode node);
    
};

#endif /* defined(__Solving_Sudoku__AStarNode__) */
