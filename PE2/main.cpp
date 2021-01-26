#include "Point.h"
#include <iostream>

using namespace std;

/*
CSCI 3010, PE 2, Spring 2021
Abeal Sileshi
Multidimensional point with Distance and Translate methods.
*/

int main(){
    vector <int> ex = {5, 5, 5 ,5}; 
    vector <int> ex2 = {10, 10, 10, 10};

    Point p1(3); //initializing a coordinate at the origin
    Point p2(ex); //initializing a coordinate at {5, 5, 5 ,5}

    cout << "p1's dimensions" << endl;
    p1.printDim(); //prints dimensions

    cout << "p2's dimensions" << endl;
    p2.printDim(); //prints dimensions

    Point p3(ex2);
    cout << "p3's dimensions" << endl;
    p3.printDim(); //prints dimensions 

    //calculating the distance using Distance(Point &point) member function
    cout << "This is the distance between p1 and p2: " << p1.Distance(p2) << endl;
    cout << "This is the distance between p1 and p3: " << p1.Distance(p3) << endl;
    cout << "This is the distance between p2 and p3: " << p3.Distance(p2) << endl;

    p1.Translate(10); //moving all coordinates of p1 by 10
    cout << "These are the coordinates after translating +10 " << endl;
    p1.printDim();
    //calculating the distance using Distance(Point &point) member function
    cout << "This is the distance between p1 and p2 (after +10): " << p1.Distance(p2) << endl;
    cout << "This is the distance between p1 and p3: (after +10): " << p1.Distance(p3) << endl;
    cout << "This is the distance between p2 and p3: (after +10): " << p3.Distance(p2) << endl;
    
    p1.Translate(-50);
    cout << "These are the coordinates after translating -50 " << endl;
    p1.printDim();
    cout << "This is the distance between p1 and p2 (after -50): " << p1.Distance(p2) << endl;
    cout << "This is the distance between p1 and p3: (after -50): " << p1.Distance(p3) << endl;
    cout << "This is the distance between p2 and p3: (after -50): " << p3.Distance(p2) << endl;
    
    return 0;
}