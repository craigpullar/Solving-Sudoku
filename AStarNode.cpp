//
//  AStarNode.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 26/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include "AStarNode.h"
#include "SudokuGameEngine.h"

AStarNode::AStarNode() {
    
}

AStarNode::AStarNode(int correctness, GameState state) {
    AStarNode::correctness = correctness;
    AStarNode::state = state;
    AStarNode::hueristicValue = evaluateHueristic();
}

AStarNode::AStarNode(int correctness, GameState state, Action *action, AStarNode *previousNode) {
    AStarNode::correctness = correctness;
    AStarNode::state = state;
    AStarNode::hueristicValue = evaluateHueristic();
    AStarNode::action = action;
    AStarNode::previousNode = previousNode;
}

int AStarNode::evaluateHueristic() {
    return getNumberOfHoles();
}

int AStarNode::getCorrectness(){
    
    return correctness;
}
int AStarNode::getNumberOfActions() {
    SudokuGameEngine engine =  SudokuGameEngine();
    
    // count number of possible actions
    vector<Action> possibleActions = engine.getPossibleActionsForState(state);
    int counter = (int)possibleActions.size();
    
    return counter;
}
int AStarNode::getNumberOfHoles() {
    int counter = 0;
    for(int i = 0; i < state.getDim(); i++)
        for (int j = 0;  j < state.getDim(); j++)
            if (!state.getData()[i][j])
                counter++;
    
    return counter;
}



vector<AStarNode> AStarNode::getChildNodesForNode(AStarNode node){
    SudokuGameEngine engine = SudokuGameEngine();
    vector<Action> actions = engine.getPossibleActionsForState(node.getState());
    vector<AStarNode> children;
    
   
    
    for (Action action : actions) {
        children.push_back(AStarNode (node.getCorrectness(),
                                      GameState (engine.takeActionForState(action, node.getState()))
                                                 , &action, &node));
    }
    
    for (AStarNode child : children) {
        int correctness = 0;
        for (Action action : actions)
            if (action.getRow() == child.getAction().getRow() && action.getCol() == child.getAction().getCol())
                correctness++;
        child.setCorrectness(correctness + child.getPreviousNode().getCorrectness());

    }
    
    return children;
}

bool AStarNode::nodeEqualsNode(AStarNode node) {
    for(int i = 0; i < state.getDim(); i++)
        for(int j = 0; j < state.getDim(); j++)
            if(state.getData()[i][j] != node.getState().getData()[i][j])
                return false;
    return true;
}

void AStarNode::setCorrectness(int correctness) {
    AStarNode::correctness = correctness;
}
int AStarNode::getHueristicValue() {
    return hueristicValue;
}
void AStarNode::setHueristicValue(int value) {
    AStarNode::hueristicValue = value;
}
int AStarNode::getScore() {
    return correctness + hueristicValue;
}
GameState AStarNode::getState() {
    return state;
}
void AStarNode::setState(GameState state){
    AStarNode::state = state;
}
Action AStarNode::getAction() {
    return *action;
}
AStarNode AStarNode::getPreviousNode(){
    return *previousNode;
}
