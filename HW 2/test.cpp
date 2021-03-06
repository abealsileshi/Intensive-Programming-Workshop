/*
CSCI 3010 - Spring 2021
HW2 - Unit Testing
Abeal Sileshi
*/

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "Counter.hpp"

TEST_CASE("Count Public Method", "[Count]"){
    SECTION("Checking the total count"){ 
        std::vector<std::string> vec = {"string1", "string2", "string3"};
        Counter<std::string> test(vec);
        int a = test.Count();
        REQUIRE(a == 3);
    }
    SECTION("Checking the Count Method with one parameter"){
        std::vector<std::string> vec = {"string1", "string2", "string3"};
        Counter<std::string> test(vec);
        int a = test.Count();
        REQUIRE(a == 3);
    }
        SECTION("Checking the count between intervals"){
        std::vector<int> vec2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        Counter<int> test2(vec2);
        int c = test2.Count(1, 5);
        REQUIRE(c == 4);
    }
}

TEST_CASE("Removing Method", "[Remove]"){
    SECTION("Checking the removal of a key"){
        std::vector<double> vec = {19.0, 20.0, 21.5, 22.6, 30.5};
        Counter<double> test(vec);
        test.Remove(22.6);
        REQUIRE(test.Count() == 4);
    }
}

TEST_CASE("Increment Method", "[Increment]"){
    SECTION("Checking the incrementation of one key"){
        std::vector<std::string> vec = {"string1", "string2", "string3"};
        Counter<std::string> test1(vec);
        test1.Increment("string1");
        REQUIRE(test1.Count("string1") == 2);
    }
    SECTION("Checking the incrementation of one key by n counts"){
        std::vector<std::string> vec = {"string1", "string2", "string3"};
        Counter<std::string> test(vec);
        test.Increment("string1", 10);
        REQUIRE(test.Count("string1") == 11);       
    }
}

TEST_CASE("Decrementing a key", "[Decrement]"){
    SECTION("Checking the decrementation of an integer key"){
        std::vector<double> vec = {19.0, 20.0, 21.5, 22.6, 22.6, 30.5};
        Counter<double> test(vec);
        test.Decrement(22.6);
        REQUIRE(test.Count(22.6) == 1);
    }
    SECTION("Checking the decrementation of a string key"){
        std::vector<std::string> vec = {"hola", "adios", "hola", "fin", "cumpleado"};
        Counter<std::string> test(vec);
        test.Decrement("hola");
        REQUIRE(test.Count("hola") == 1);
    }

}

TEST_CASE("Checking normalization", "[Normalized]"){
    SECTION("Checking if normalized"){
    std::vector<std::string> vec = {"string1", "string2", "string3"};
    Counter<std::string> test(vec);
    std::map<std::string, double> testMap = test.Normalized();
    int num = testMap.at("string1");
    REQUIRE((num < 0.34));
    // REQUIRE((num > 0.32));
    }
}
