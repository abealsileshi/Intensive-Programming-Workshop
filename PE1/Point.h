#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point{
private:
    double xcor_;
    double ycor_;
public:
	Point(); //constructor sets the point at the origin
    Point(double x, double y); //initializes a point
    // It should have getter and setter methods for each coordinate and two methods

    double getX(); //getter for xcoor
    double getY(); //getter for ycoor
    double Distance(Point p1, Point p2); //calculates the distance between two points
    void Translate(double num); //translates all points by given number
    void getCoordinates(); //function to tell what the current coordinates are
    
};

#endif