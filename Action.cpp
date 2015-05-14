//
//  Action.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 19/02/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include "Action.h"
#include <iostream>

using namespace std;

Action::Action(int value, int row, int col) {
    Action::value = value;
    Action::cost = 1;
    Action::row = row;
    Action::col = col;
}
Action::Action(){
    Action::value = 0;
    Action::cost = 1;
}
int Action::getCost(){
    return cost;
}
void Action::setCost(int cost){
    Action::cost = cost;
}
int Action::getValue() {
    return value;
}
void Action::setValue(int value){
    Action::value = value;
}
int Action::getRow() {
    return row;
}
void Action::setRow(int row){
    Action::row = row;
}
int Action::getCol(){
    return col;
}
void Action::setCol(int col){
    Action::col = col;
}
void Action::printAction(){
    cout << "\n";
    cout << "Point: (";
    cout << row;
    cout << ",";
    cout << col;
    cout << ")";
    cout << "\n";
    cout << "Value: ";
    cout << value;
    cout << "\n";
}
