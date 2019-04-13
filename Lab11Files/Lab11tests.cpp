#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include"sort.h"
#include<iostream>
#include<queue>
#include<string>



using std::queue;
using std::string;
//using namespace std; 


TEST_CASE("Merge Sort function")
{
	SECTION("Integers")
	{
		queue<int> test;
		test.push(2);
		test.push(45);
		test.push(1);
		test.push(67);


		REQUIRE(test == queue<int>({ 2, 45, 1, 67 }));

		mergeSort(test);
		REQUIRE(test == queue<int>({ 1, 2, 45, 67 }));


		REQUIRE(test.front() == 1);
		test.pop();
		REQUIRE(test.front() == 2);
		test.pop();
		REQUIRE(test.front() == 45);

	}

	SECTION("Strings")
	{
		queue<string> test;
		test.push("Dina");
		test.push("Diego");
		test.push("Kerven");
		test.push("Maksat");
		test.push("Adriana");
		test.push("Kimber");
		test.push("David");


		REQUIRE(test == queue<string>({ "Dina", "Diego", "Kerven", "Maksat","Adriana", "Kimber", "David"}));

		mergeSort(test);
		REQUIRE(test == queue<string>({ "Adriana", "David", "Diego", "Dina","Kerven", "Kimber", "Maksat" }));


		REQUIRE(test.front() == "Adriana");
		test.pop();
		REQUIRE(test.front() == "David");
		test.pop();
		test.pop();
		test.pop();
		REQUIRE(test.front() == "Kerven");

	}


}





TEST_CASE("Merge function")
{
	queue<int> a, b, q;
	q.push(7);
	q.push(5);
	q.push(23);
	q.push(1);

	merge(a, b, q);
	REQUIRE(a == queue<int>({ 2, 45}));
	REQUIRE(b == queue<int>({ 1, 67 }));


	





}
