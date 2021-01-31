#include <iostream>
#include <string>

using namespace std;
// Name: Abeal Sileshi

// Write any functions you need here!

void ptr_function(int * parameter){
    cout << "ptr_function activated!" << endl;
}
void ref_function(int & parameter){
    cout << "ref_function activated!" << endl;

}
void func3(int const &input, int * pointer){
    *(pointer) = input;
}

class Person{
    public:
    Person(): height_(0), name_("") {}; //default constructor
    Person(string n, double h): height_(h), name_(n) {}; //overloaded constructor with name parameter and height parameter
    bool operator== (const Person &p){ //overloaded equal operator
        return (this->height_ == p.height_ && this->name_ == p.name_);
    }
    string getName(){return name_;}; //getter method for name
    int getHeight(){return height_;}; //getter method for height

    Person operator+ (const Person &obj) {  //overloaded plus operator
         Person res; 
         res.height_ = height_ + obj.height_; 
         res.name_ = name_ + obj.name_; 
         return res; 
    } 
    void print() { cout << name_ << " " << height_ << endl; } //print method
    private:
    double height_;
    string name_;
};



int main() {
    // Add as many prints to cout as you need to answer the questions.
    // Leave them in your code when you turn it in.
    // If you have lines of code that cause errors that test the questions,
    // leave this code in your file but comment it out.
    
    // 1) Declare an int
    int a = 5;

    // 2) Declare a pointer to that int
    int * ptr_a = &a;
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value of ptr_a: " << ptr_a << endl;

    // 3) Increment the int via the pointer
    (*ptr_a)++;
    cout << "New value of a: " << a << endl;
    // 4) Declare a reference to your int
    int & ref_a = a;

    // 5) Increment the int via the reference
    ref_a++;
    cout << "New value of a: " << a << endl;

    // 6) When you increment the int via the variable declared in #1, which
    // variables will be modified to see the changes? (the pointer , reference or both?)
    // Answer: Both the pointer and reference change
    a++;
    cout << "New value of a: " << a << endl;
    cout << "Let's see if reference or the pointer change..." << endl;
    cout << "Value of ptr_a " << *ptr_a << endl;
    cout << "Value of ref_a " << ref_a << endl;

    // 7) When you increment the int via the pointer declared in #2, which
    // variables will be modified to see the changes?
    // Answer: Both
    cout << "7" << endl;
    (*ptr_a)++;
    cout << "New value of a: " << a << endl;
    cout << "Value of ref_a " << ref_a << endl;

    // 8) When you increment the int via the reference declared in #4, which
    // variables will be modified to see the changes?
    // Answer: Both
    cout << "8" << endl;
    ref_a++;
    cout << "Value of ptr_a " << *ptr_a << endl;
    cout << "New value of a: " << a << endl;

    // 9) Write a function that takes an int * parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and function call below)
    ptr_function(ptr_a);

    // 10) Can you pass your reference from #4 to the function from #9 without accessing its address?
    // Answer: No
    //ptr_function(ref_a);

    // 11) Write a function that takes an int & parameter. How would you pass the 
    // variable from #1 into this function? (write the function header and call below)

    ref_function(a);

    // 12) Can you pass your pointer from #2 to the function from #11 without dereferencing it?
    // Answer: No 

    ref_function(*ptr_a);
    // 13) Can you pass your reference from #4 to the function from #11?
    // Answer: Yes

    ref_function(ref_a);
   
    // 14) Write a function that takes one const reference input parameter and one pointer
    // output parameter. The function should fill in the value of the output parameter based
    // on the value of the input parameter. (what it does exactly is up to you).
    // Call your function 3 times below. Be sure to include output as necessary to be sure
    // your function works as described.
    
    int num = 100;
    func3(num, ptr_a);
    func3(num, ptr_a);
    func3(num, ptr_a);
    cout << "New value of a: " << a << endl;
    
    // 15) What is/are the difference(s) between output parameters and return values?
    // Answer: A return value only returns one value but an output parameter lets you return more than one thing without technically returning anything..

    // 16) Create a custom class with at least one private field/class attribute. Overload the == and + operator for this class
    // such that == can be used to compare the objects of the class and + can be used to add
    // 2 objects of the class together. Implement an appropriate constructor for your class.
    // When you overload these operators, the resulting return value should make sense.
    // Instantiate at least 2 objects of this class and perform the == and + operations on them.
    // hint: for operator+, the function signature when implemented as a member function of the Object class is:
    // Object operator+(const Object &other)
    // Answer:

    Person p1("Abeal Sileshi", 170);
    Person p2("Luis Alvarez", 175);
    Person p3("Luis Alvarez", 175);

    if(p3 == p2){
        cout << "Same people!" << endl;
    }
    else{
        cout << "Different people!" << endl;
    }

    cout << "Let's add two people together " << endl;
    Person p4 = p1 + p2;
    cout << "Person 4 is: " << p4.getHeight() << p4.getName() << endl;
    p4.print();
}

//Resources I found helpful: https://www.geeksforgeeks.org/operator-overloading-c/
