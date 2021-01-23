#include "Point.h"
#include <cmath>

Point::Point() { //default is to set our point to the origin
  xcor_ = 0; //origin point for x
  ycor_ = 0; //origin point for y
}

Point:: Point(double x, double y) //initializes a point
{
    xcor_ = x;
    ycor_ = y;
}

double Point:: getX() //getter for xcoordinate
{
    return xcor_;
}

double Point:: getY() //getter for ycoordinate
{
    return ycor_;
}

/**
    Returns the distance between two points.

    @param each point.
    @return The distance between points.
*/
double Point:: Distance(Point p1, Point p2) //calculates the distance between two points
{
    //We will use the distance formula here d = sqrt((x2-x1)^2 + (y2-y1)^2)
    double distance = 0;//distance variable
    double xdiff = (p2.getX() - p1.getX()); //difference in x coordinates
    xdiff = pow(xdiff, 2); //square the difference
    double ydiff = (p2.getY() - p1.getY()); //difference in y coordinates
    ydiff = pow(ydiff, 2); //square the difference
    distance = ydiff + xdiff; //adding the difference
    distance = sqrt(distance); // the last step of the formula as seen above is to get the square root
    return distance;
}

void Point:: Translate(double num) //translates all points by given number
{
    xcor_ = xcor_ + num; 
    ycor_ = ycor_ + num;
}

void Point:: getCoordinates() //function to tell what the current coordinates are
{
    cout << "(" << xcor_ << ", " << ycor_ << ") " << endl;
}