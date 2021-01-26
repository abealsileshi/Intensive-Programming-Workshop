#ifndef _POINT_H_ 
#define _POINT_H_

#include <vector>
using namespace std;

/*
CSCI 3010, PE 2, Spring 2021
Abeal Sileshi
Multidimensional point with Distance and Translate methods.
*/

class Point{
public: 
    Point(int n); //default constructor
    Point(vector<int> input); //constructor accepts a vector as a parameter
    int numDim(vector <int> input); //a method that reports how many dimensions there are
    
    vector <int> getCoord(); //gets and returns the vector dim
    int getVal(int n); //gets element dim[n] of the vector
    void printDim(); //prints out the elements of the vector dim

    double Distance(Point &point); //method to calculate the distance between two points
    void Translate(int num); //method to translate the coordinates

private:
     vector <int> dim; //vector that stores the coordinates
};

#endif