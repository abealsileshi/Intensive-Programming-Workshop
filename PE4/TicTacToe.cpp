//file TicTacToe.cpp
//created by: Sean Fitze and Abeal Sileshi
#include <iostream>
#include <string>

using namespace std;

const int N = 3; //size of array

//1 is O in tic tac toe
//2 is X, and 0 means the board is empty


/***
 * Displays board by outputting to console
 * @param arr double pointer to the 2d array
 */
void DisplayBoard(int** arr){
    for(int i = 0; i <N; ++i){ //n = 3 for 3x3 array
        for(int j= 0; j<N; ++j){ //n = 3 for 3x3 array
            cout << arr[i][j]; //prints out array
        }
        cout << endl;
    }
}

/***
 * Creates a new CreateBoard
 * @return returns new board
 */
int** CreateBoard(){
    int** arr = new int*[N]; //points to an array of 3 new pointers 
    for(int i =0; i < N; ++i){ 
        arr[i] = new int[N]; //points to a new array of integers (size 3)
        for(int j = 0; j<N; ++j){
            arr[i][j] = 0; //initializes the array to 0 
        }
    }
    return arr; //returns the double pointer array
}

/***
 * Gets location to update on board
 * @param arr double pointer to a 2d array
 * @return pointer to location on the board
 */
int* GetPlayerChoice(int **arr){
    //asks user for input
    cout << "Where on the board would you like to go to?" << endl;
    cout << "First choose the row (0,1,2): ";
    string i;
    cin >> i;
    int i1 = stoi(i); //stores row
    cout << "Now choose the colum (0,1,2): ";
    string j;
    cin >> j;
    int j1 = stoi(j); //stores col
    int* location; //pointer to location in array
    location = &(arr[i1][j1]);
    return location; //returns pointer to position in the array
}

/***
 * Updates board with marker
 * @param location pointer to location on board
 * @param marker marker to draw on board
 */
void PlaceMarker(int* location, const int marker) {
    *(location) = marker;
}

int main(){
    int **arr; //create double pointer to point to the board
    arr = CreateBoard(); //creates board and sets double pointer to point to the board
    DisplayBoard(arr); //displays board
    cout << "Let's Play Tic-Tac-Toe!" << endl; 
    int turns = 1; //keeps track of how many turns
    int* loc; //stores address of location user wants to mark

    while(turns < 9){ //no more than 9 turns in a 3x3 board
        //first player 
        loc = GetPlayerChoice(arr); //sets loc to user selected location on board
        PlaceMarker(loc, 1); //marks board on location based off of player's marker
        DisplayBoard(arr); //displays updated board
        turns++; //increment turn (took a turn)
        //second player
        loc = GetPlayerChoice(arr); //same as above but for player 2
        PlaceMarker(loc, 2);
        DisplayBoard(arr);
        turns++;
    }
    return 0;
}

//helpful resources: https://www.youtube.com/watch?v=g1Bu4FiJVyQ
