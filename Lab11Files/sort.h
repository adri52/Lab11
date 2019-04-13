#ifndef SORT_H
#define SORT_H
#include<iostream> 
#include<queue>

using std::queue; 
using std::cout;

//using namespace std; 


template<class T>
void split(queue<T> & whole, queue<T>& half1, queue<T>& half2)
{
	int tempSize = (whole.size()) / 2;

	for(int i = 0; i < tempSize; i++)
	{
		half1.push(whole.front());
		whole.pop();
	}

	while (whole.size() > 0)
	{
		half2.push(whole.front());
		whole.pop(); 
	}

}





template<class T>
void merge(queue<T>& a, queue<T>& b, queue<T> & q)
{
	

	while (!a.empty() || !b.empty())
	{
		if (!a.empty() && b.empty())
		{
			q.push(a.front());
			a.pop();
		}

		else if (!b.empty() && a.empty())
		{
			q.push(b.front());
			b.pop();
		}

		else if (!a.empty() && !b.empty())
		{
			if (a.front() < b.front())
			{
				q.push(a.front());
				a.pop();
	
			}
			else
			{
				q.push(b.front());
				b.pop();
			}
		}
	
	}

}



//this function it sorts the contents of queue in place
template<class T>
void mergeSort(queue<T> & q)
{

	//base case if there is one item or none, meaning is already sorted
	if (q.size() <= 1)
	{
		return;
	}
	else {
		queue<T> a, b;
		split(q, a, b);
		mergeSort(a);
		mergeSort(b);
		merge(a, b, q);
	}

}



template<class T>
std::ostream& operator<<(std::ostream& out, const queue<T>& q)
{
	queue<T> cpy = q; 
	out << "[";
	while (!cpy.empty())
	{
		out << cpy.front();
		cpy.pop();
		if (!cpy.empty())
			out << ", ";
	}
	out << "]";
	return out;
}



#endif // !SORT_H

