#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"


TEST_CASE("Rectangle is initialized with p1 and p2" , "[Rectangle]"){
    SECTION("checking get_p1 and get_p2"){
        Point p1;
        p1.x = 0;
        p1.y = 0;
        Point p2;
        p2.x = 1;
        p2.y = 1;
        Rectangle rec = Rectangle(p1,p2);
        REQUIRE(rec.get_p1().x == p1.x);
        REQUIRE(rec.get_p1().y == p1.y);
        REQUIRE(rec.get_p2().x == p2.x);
        REQUIRE(rec.get_p2().y == p2.y);
    }
    //if person tries to make something that's not a rectangle
    
}

TEST_CASE("Rectangle has width of p2.x-p1.x" , "[GetWidth]"){
    SECTION("checking width of p2.x-p1.x"){
          Point p1;
          p1.x=0;
          p1.y=0;
          Point p2;
          p2.x=2;
          p2.y=1;
          Rectangle *rec = new Rectangle(p1,p2);
          REQUIRE(rec->GetWidth() == (p2.x-p1.x));
    } 
    SECTION("checking width of p2.x-p1.x - with neg coordinates"){
        Point p1;
        p1.x=-1;
        p1.y=-1;
        Point p2;
        p2.x=2;
        p2.y=1;
        Rectangle rec(p1,p2);
        //width should be 2 (p2.x-p1.x)
        REQUIRE(rec.GetWidth() == (p2.x-p1.x));
    }  
}

TEST_CASE("Rectangle has height of p2.y-p1.y" , "[GetHeight]"){
    SECTION("checking height of p2.y-p1.y"){
        Point p1;
        p1.x=0;
        p1.y=0;
        Point p2;
        p2.x=2;
        p2.y=1;
        Rectangle rec(p1,p2);
        //height should be 1 (p2.y-p1.y)
        REQUIRE(rec.GetHeight() == (p2.y-p1.y));
    } 
    SECTION("checking height of p2.y-p1.y - with neg coordinates"){
        Point p1;
        p1.x=-1;
        p1.y=-1;
        Point p2;
        p2.x=2;
        p2.y=1;
        Rectangle rec(p1,p2);
        //height should be 2 (p2.y-p1.y)
        REQUIRE(rec.GetHeight() == (p2.y-p1.y));
    }  
}

TEST_CASE("Overlap check is tested" , "[Overlaps]"){
    SECTION("checking if they overlap"){
    Point p1;
    p1.x=0;
    p1.y=0;
    Point p2;
    p2.x=2;
    p2.y=1;
    Rectangle rec(p1,p2);
    
    SECTION("checking that it overlaps"){ //exact same rectangles here
        Point p1;
        p1.x=0;
        p1.y=0;
        Point p2;
        p2.x=2;
        p2.y=1;
        Rectangle recOther1(p1,p2);
        REQUIRE(rec.Overlaps(recOther1));
    }
        SECTION("checking that it overlaps"){ //1 point different
        Point p1;
        p1.x=0;
        p1.y=0;
        Point p2;
        p2.x=4;
        p2.y=4;
        Rectangle recOther3(p1,p2);
        REQUIRE(rec.Overlaps(recOther3));
    } 
    SECTION("checking that it doesn't overlap"){ //both points different
        Point p1;
        p1.x=1;
        p1.y=1;
        Point p2;
        p2.x=3;
        p2.y=2;
        Rectangle recOther2(p1,p2);
        REQUIRE(!rec.Overlaps(recOther2));
    }   
    }   
}

TEST_CASE("Checking the area" , "[CalculateArea]"){
    SECTION("Rectangle has height of getWidth * getHeight"){
        Point p1;
        p1.x=0;
        p1.y=0;
        Point p2;
        p2.x=2;
        p2.y=1;
        Rectangle rec(p1,p2);
        REQUIRE(rec.CalculateArea() == (rec.GetWidth()*rec.GetHeight()));
    }   
}

//abeal expansion
TEST_CASE("Rectangle expands" , "[Expand]"){
  // moves the bottom left coordinate down one and to the left one
  // moves the upper right coordinate up one and to the right one
    SECTION("checking expansion"){
        Point p1;
        p1.x=1;
        p1.y=1;
        Point p2;
        p2.x=3;
        p2.y=2;
        Rectangle rec(p1,p2);

        Point p3;
        p3.x=1;
        p3.y=1;
        Point p4;
        p4.x=3;
        p4.y=2;
        Rectangle rec2(p3,p4);
        //after expanding p1 should be (0,0) and p2 (4,3)
        rec2.Expand();

        REQUIRE(rec2.get_p1().x == (p1.x-1));
        REQUIRE(rec2.get_p1().y == (p1.y-1));
        REQUIRE(rec2.get_p2().x == (p2.x+1));
        REQUIRE(rec2.get_p2().y == (p2.y+1));
    }  
    SECTION("checking expansion -- into a negative p1"){
        Point p1;
        p1.x=0;
        p1.y=0;
        Point p2;
        p2.x=2;
        p2.y=1;
        Rectangle rec(p1,p2);
        //after expanding p1 should be (-1,-1) and p2 (3,2)
        Point p3;
        p3.x=0;
        p3.y=0;
        Point p4;
        p4.x=2;
        p4.y=1;
        Rectangle rec2(p3,p4);
        rec2.Expand();

        REQUIRE(rec2.get_p1().x == (p1.x-1));
        REQUIRE(rec2.get_p1().y == (p1.y-1));
        REQUIRE(rec2.get_p2().x == (p2.x+1));
        REQUIRE(rec2.get_p2().y == (p2.y+1));
        //after expanding p1 should be (0,0) and p2 (4,3)
        //REQUIRE(rec2.Expand().get_p2().y == (p2.y+1));
    }   
}

TEST_CASE("Rectangle shrinks" , "[Shrink]"){
    SECTION("checking shrinkage"){
      // moves the bottom left coordinate up one and to the right one
  // moves the upper right coordinate down one and to the left one
        Point p1;
        p1.x=0;
        p1.y=0;
        Point p2;
        p2.x=2;
        p2.y=1;
        Rectangle rec(p1,p2);
        //after expanding p1 should be (1,1) and p2 (1,1)
        rec.Shrink();

        REQUIRE(rec.get_p1().x == (p1.x+1));
        REQUIRE(rec.get_p1().y == (p1.y+1));
        REQUIRE(rec.get_p2().x == (p2.x-1));
        REQUIRE(rec.get_p2().y == (p2.y-1));
    }
      SECTION("checking if shrink 'reverses' rectangle"){
        Point p1;
        p1.x=0;
        p1.y=0;
        Point p2;
        p2.x=0;
        p2.y=0;
        Rectangle rec(p1,p2);
        //after shrinking p1 would be (1,1,) and p2 (-1,-1)
        //which would be wrong
        rec.Shrink();
        REQUIRE(!(rec.get_p1().x == (p1.x+1)));
        REQUIRE(!(rec.get_p1().y == (p1.y+1)));
        REQUIRE(!(rec.get_p2().x == (p2.x-1)));
        REQUIRE(!(rec.get_p2().y == (p2.y-1)));
    }
}