//
//  Point.cpp
//  Solving Sudoku
//
//  Created by Craig Pullar on 10/03/2015.
//  Copyright (c) 2015 Craig Pullar. All rights reserved.
//

#include "Point.h"
#include <iostream>

using namespace std;

Point::Point (int row, int col, int value, Point *lastPoint) {
    Point::row = row;
    Point::col = col;
    Point::value = value;
    Point::lastPoint = lastPoint;
    //Get segments
    Point::rowSeg = row/3;
    Point::colSeg = col/3;
    
}
Point::Point (int row, int col, int value){
    Point::row = row;
    Point::col = col;
    Point::value = value;
}
Point::Point(int row, int col, vector<int> possibleValues) {
    Point::row = row;
    Point::col = col;
    Point::possibleValues = possibleValues;
}

int Point::getCol(){
    return col;
}
void Point::setCol(int col){
    Point::col = col;
}
int Point::getRow(){
    return row;
}
void Point::setRow(int row){
    Point::row = row;
}
int Point::getValue(){
    return value;
}
void Point::setValue(int value){
    Point::value = value;
}
Point* Point::getLastPoint(){
    return lastPoint;
}
void Point::setLastPoint(Point *lastPoint){
    Point::lastPoint = lastPoint;
}
vector<int> Point::getPossibleValues() {
    return possibleValues;
}
void Point::setPossibleValues(vector<int> possibleValues) {
    Point::possibleValues = possibleValues;
}
int Point::getColSeg(){
    return colSeg;
}
void Point::setColSeg(int colSeg){
    Point::colSeg = colSeg;
}
int Point::getRowSeg(){
    return rowSeg;
}
void Point::setRowSeg(int rowSeg){
    Point::rowSeg = rowSeg;
}
void Point::printPoint(){
    cout << "\n";
    cout << "Point: ";
    cout << "[";
    cout << getRow();
    cout << ",";
    cout << getCol();
    cout << "]\n";
    cout << "Value = ";
    cout << getValue();
    cout << "/n";
    for (int value : getPossibleValues()){
        cout << value;
        cout << ", ";
    }
    cout << "\n";
    
}