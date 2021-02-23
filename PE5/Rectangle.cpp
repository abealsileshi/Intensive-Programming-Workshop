/*
CSCI 3010 - Spring 2021
PE5 - Unit Testing
Gabriela Tolosa Ramirez
Abeal Sileshi
*/

#include "Rectangle.h"
#include <iostream>

/*
    parameterized constructor of Rectangle
    @param p1 (Point) - lower left corner
    @param p2 (Point) - upper right corner
*/
Rectangle::Rectangle(Point p1, Point p2){
    //single point - okay
    //line - okay
    //p1 MUST be lower left and p2 MUST be upper right
    if(p1.x > p2.x || p1.y > p2.y){
        std::cout << "Cannot create rectangle" << std::endl;
        return;
    }else{
        p1_ = p1;
        p2_ = p2;
    }
}

/*
    get the width of the rectangle
    return (p2.x - p1.x)
*/
int Rectangle::GetWidth(){
    return (p2_.x - p1_.x);
}

/*
    get the height of the rectangle
    return (p2.y - p1.y)
*/
int Rectangle::GetHeight(){
    return (p2_.y - p1_.y);
}

/*
    check if rectangles overlap -- share any points with other
    @param other (Rectanlge) - rectangle comparing
    return bool
*/
bool Rectangle::Overlaps(Rectangle& other){
    Point p1o = other.get_p1();
    Point p2o = other.get_p2();
    if(p1o.x == p1_.x && p1o.y == p1_.y){ //same p1
        return true;
    }else if(p2o.x == p2_.x && p2o.y == p2_.y){ //same p2
        return true;
    }
    else if(p2)
    else{
        return false;
    }
    //gotta return true too if they are on the same line
}

/*
    calculate the area of the rectangle
    return (GetHeight()*GetWidth())
*/
int Rectangle::CalculateArea(){
    return (GetHeight()*GetWidth());
}

/* 
    moves the bottom left coordinate down one and to the left one
    moves the upper right coordinate up one and to the right one
*/
void Rectangle::Expand(){
    p1_.x -= 1;
    p1_.y -= 1;
    p2_.x += 1;
    p2_.y += 1;
}

/*
    moves the bottom left coordinate up one and to the right one
    moves the upper right coordinate down one and to the left one
*/
void Rectangle::Shrink(){
    if((p1_.x == p2_.x) || (p2_.y == p2_.y)){ //if we have a point we can't shrink
        return;
    }
    //check for vertical lines and horizontal lines
    p1_.x += 1;
    p1_.y += 1;
    p2_.x -= 1;
    p2_.y -= 1;
}
