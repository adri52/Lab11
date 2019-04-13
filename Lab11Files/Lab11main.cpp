#include<iostream>
#include<fstream>
#include<queue>
#include<string>
#include "sort.h"

using std::string;
using std::cout; 
using std::cin;
using std::endl;
using std::queue;
using std::ifstream;


int main()
{
	int qSize;
	ifstream fin;
	fin.open("Lab11main.cpp", std::ios::in);
	queue<string> q;
	
	while (fin)
	{
		string temp;
		fin >> temp;
		q.push(temp);
	}

	mergeSort(q);
	qSize = q.size();

	while(qSize !=0)
	{
		cout << q.front();
		q.pop();
		
	}
	


	










}



