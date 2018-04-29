#include <iostream>
#define CATCH_CONFIG_MAIN  
//using namespace std;
#include "CircularInt.hpp"
#include "catch.hpp"


TEST_CASE("PLUS","+"){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
	c3 = c3 + c1;
    REQUIRE(c3 == 1);
	c1 = c2 + 1;
	REQUIRE(c1 == 5);
	c2 = 9 + c2;
	REQUIRE(c2 == -3);
}

TEST_CASE("MINUS","-"){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
	c3 = c3 - c1;
    REQUIRE(c3 == 1);
	c1 = c2 - 1;
	REQUIRE(c1 == 7);
	c2 = 9 - c2;
	REQUIRE(c2 == -3);
}

TEST_CASE("DUPLICATE","*"){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
	c3 = c3 * c1;
    REQUIRE(c3 == 0);
	c1 = c2 * 2;
	REQUIRE(c1 == 4);
	c2 = 9 * c2;
	REQUIRE(c2 == -4);
}

TEST_CASE("MODOLO","%"){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
	c3 = c3 % c1;
    REQUIRE(c3 == -2);
	c1 = c2 % 2;
	REQUIRE(c1 == 4);
	c2 = 9 % c2;
	REQUIRE(c2 == -3);
}

TEST_CASE("PLUS=","+="){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
	c3 += c1;
    REQUIRE(c3 == 1);
	c1 += 1;
	REQUIRE(c1 == 4);
	c2 += 9;
	REQUIRE(c2 == -3);
}

TEST_CASE("MINUS=","-="){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
	c3 -= c1;
    REQUIRE(c3 == 1);
	c1 -= 1;
	REQUIRE(c1 == 10);
	c2 -= 9;
	REQUIRE(c2 == -1);
}

TEST_CASE("DUPLICATE=","*="){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
	c3 *= c1;
    REQUIRE(c3 == 0);
	c1 *= 2;
	REQUIRE(c1 == 6);
	c2 *= 9;
	REQUIRE(c2 == -4);
}

TEST_CASE("MODOLO=","%="){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
	c3 %= c1;
    REQUIRE(c3 == -2);
	c1 %= 2;
	REQUIRE(c1 == 9);
	c2 %= 9;
	REQUIRE(c2 == -4);
}

TEST_CASE("SMALL","<"){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
    CHECK(c3 < c1);
	CHECK(!(c1 < 2));
	CHECK(!(9 < c2));
}

TEST_CASE("BIG",">"){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
    CHECK(!(c3 > c1));
	CHECK(c1 > 2);
	CHECK(9 > c2);
}

TEST_CASE("SMALL=","<="){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
    CHECK(c3 <= c1);
	CHECK(!(c1 <= 2));
	CHECK(!(9 <= c2));
}

TEST_CASE("BIG=",">="){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
    CHECK(!(c3 >= c1));
	CHECK(c1 >= 2);
	CHECK(9 >= c2);
}

TEST_CASE("NOT=","!="){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
    CHECK(c3 != c1);
	CHECK(!(c1 != 3));
	CHECK(9 != c2);
}

TEST_CASE("YES=","=="){
	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
    CHECK(!(c3 == c1));
	CHECK(c1 == 3);
	CHECK(!(9 == c2));
}



//int main() {
//	CircularInt c1 {3, 10}, c2 {-4,-1}, c3 {-2,3}; 
//	c3 = c3 + c2;
//	cout << c3 << endl; //0
//	c3 += c1;  
//	cout << c3 << endl; //3  
//	c1 /= c3;
//	cout << c1 << endl; //9
//	c2 *= c1;
//	cout << c2 << endl; //-4
	
//	cout << c2++ << endl; //-4
//	cout << c1-- << endl; //9
//	cout << c2 << endl;   //-3
//	cout << c1 << endl;   //8

//	cout << c3+8 << endl; //-1
//	c3 += 7;  
//	cout << c3 << endl; //-2  
//	c1 /= 4;
//	cout << c1 << endl; //4
//	c2 *= -3;
//	cout << c2 << endl; //-3

	
//}