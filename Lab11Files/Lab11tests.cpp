#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include"sort.h"
#include<iostream>
#include<queue>



using std::queue;


TEST_CASE("Merge Sort function")
{
	queue<int> test;
	test.push(2);
	test.push(45);
	test.push(1);
	test.push(67);
	test.push(34);
	test.push(22);
	test.push(17);
	test.push(3);
	mergeSort(test);

	REQUIRE(test.front() == 1);
	
	test.pop();
	mergeSort(test);
	REQUIRE(test.front() == 2);

}


