#include<iostream>
#include "Counter.hpp"
#include<map>


int main(){

    //string example
    std::vector<std::string> vec = {"string1", "string2", "string3"};
    Counter<std::string> test(vec);
    std::cout << test << std::endl;

    // //integer example
    // std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 2};
    // Counter<int> test2(vec2);
    // int b = test2.Count();
    // std::cout << "The total count so far is: " << b << std::endl;

    // std::cout << test << std::endl;

    // std::cout << "INCREMENTING" << std::endl;
    // test2.Increment(9);

    // std::cout << test2 << std::endl;
    
    // int c = test2.Count(1, 5);
    // std::cout << "The total count between min and max is: " << c << std::endl;

    // //test2.Remove(1);

    // test2.Increment(3, 10);
    // std::cout << test2 << std::endl;

    // test2.Decrement(2);
    // std::cout << test2 << std::endl;

    // test2.Decrement(2);
    // std::cout << test2 << std::endl;

    // auto var = test2.MostCommon();
    // std:: cout << "The most common key is: " << var << std::endl;

    // Counter<int> test3;
    //test2.MostCommon(3);

    // test2.LeastCommon();
    // auto var2 = test2.LeastCommon();
    // std:: cout << "The least common key is: " << var2 << std::endl;

    test.Increment("string3");
    std::cout << test << std::endl;

    test.Decrement("string3");
    std::cout << test << std::endl;
    
    std::map<std::string, double> testMap = test.Normalized();
    // std::cout << testMap << std::endl;


    return 0;
}
