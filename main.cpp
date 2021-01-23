#include <iostream>
#include "Point.h"

using namespace std;

int main(){

    Point pointA(5, 5);
    pointA.getCoordinates();

    Point pointB;
    pointB.getCoordinates();

    Point pointC(-5, 9);
    pointC.getCoordinates();

    cout << "This is the distance between A and B " << pointA.Distance(pointA, pointB) << endl;
    cout << "This is the distance between B and C " << pointB.Distance(pointB, pointC) << endl;
    cout << "This is the distance between A and C " << pointB.Distance(pointA, pointC) << endl;



    // pointA.getCoordinates();
    // pointB.getCoordinates();
    

    pointA.Translate(10);
    cout << "After translation this is our new coordinate for point A "; 
    pointA.getCoordinates();


    cout << "After translation this is the distance between A and C " << pointB.Distance(pointA, pointC) << endl; 

    pointA.Translate(-5);
    cout << "After second translation this is our new coordinate for point A "; 
    pointA.getCoordinates();

    cout << "This is the distance between A and B (after two translations) " << pointA.Distance(pointA, pointB) << endl;
    cout << "This is the distance between A and C (after two translations) " << pointA.Distance(pointA, pointC) << endl;    

    return 0;
}