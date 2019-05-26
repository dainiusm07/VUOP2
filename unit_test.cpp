#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "header.h"

TEST_CASE("Tikrina ar visos raides")
{
	CHECK(isLetters("Dainius"));                                //ok
	CHECK(isLetters("99g"));                                    //neok
	CHECK_FALSE(isLetters("565gfdhdfg5"));                      //ok
}

TEST_CASE("Tikrina ar kelia kvadratu teisingai")
{
	CHECK(involution(5,3) == 125);                            //ok
	CHECK(involution(2,6) == 65);                             //neok  
	CHECK_FALSE(involution(6,0) == 1);                        //neok
}

TEST_CASE("Tikrina vidurki ir mediana")
{
	std::vector<int> v1(10, 5);
	CHECK(average(v1) == 5);                                  //ok
	std::vector<int> v2{1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 };
	CHECK(median(v2) == 5);                                  //ok
}