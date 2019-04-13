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
	//We open the file 
	ifstream fin;
	fin.open("Lab11main.cpp", std::ios::in);
	queue<string> q;
	

	// as long as there are values in the files we will read them and then assign them to a wueue 
	while (fin)
	{
		string temp;
		fin >> temp;
		q.push(temp);
	}


	// we sorth the que 
	mergeSort(q);

	//wedisplay the queue 
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}


}



 