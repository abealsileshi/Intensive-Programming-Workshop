#include <cmath>
#include "Point.h"
#include <iostream>

/*
CSCI 3010, PE 2, Spring 2021
Abeal Sileshi
Multidimensional point with Distance and Translate methods.
*/


/**
  Creates a new Point object with coordinates with n-dimensions, stores the point in a vector
  @param n, for n-dimensions
*/
Point::Point(int n)
{
    for(int i = 0; i <= n; i++){ //create a vector of size n
        dim.push_back(0); //push zeroes because this point is at the origin
    }
}

/**
  Creates a new Point object from a vector that contains cooordinates
  @param input is a vector that already has coordinates
*/
Point::Point(vector <int> input)
{
    for(int i = 0; i < input.size(); i++){ 
        dim.push_back(input[i]);  //copying the input vector to our private dim vector
    }
}

/**
  Returns the dim vector
*/
vector <int> Point:: getCoord()
{
    return dim; 
}

/**
  @param n for nth element in the vector of coordinates
  returns: the nth coordinate of the vector
*/
int Point:: getVal(int n) 
{
    return dim[n];
}

/**
  Prints the vector's coordinates 
*/
void Point:: printDim(){
    for(int i = 0; i < dim.size(); i++){
         cout << dim[i] << ", ";
    }
     cout << endl;
}

/**
  Calculates the number of dimensions from a given coordinate
  @param input vector that contains the coordinates
*/
int Point:: numDim(vector <int> input)
{
    int numDim = input.size();
    return numDim;

}

/**
  Moves this Point's coordinates by the amount given.
  @param num int amount by which to move the coordinates of this Point.
*/
void Point:: Translate(int num)
{
    for(int i = 0; i < dim.size(); i++)
    {
        dim[i] = dim[i] + num;  //adding the given amount to each element in the vector
    }
}

/**
  Calculates the distance between two euclidean points
  @param point is a coordinate object
  Returns: the calculated distance between two n-dimensional points
*/
double Point:: Distance(Point &point)
{
    double distance = 0;
    for(int i = 0; i < point.numDim(point.getCoord()); i++){ //numDim calculates the size of the vector of coordinates, i.e. how far to traverse
        distance = distance + pow((dim[i] - point.getVal(i)), 2.0); //for each element square the difference between the points and then add
    }
    return sqrt(distance); //return the square root
}

//Helpful Resource I used: https://stackoverflow.com/questions/23353977/calculate-euclidean-distance-between-4-dimensional-vectors#:~:text=Or%2C%20more%20specifically%3A%20d(,%2Db4)%5E2%20).&text=The%20function%2Fmethod%2Fcode%20above,size%20or%20simply%20the%20n.