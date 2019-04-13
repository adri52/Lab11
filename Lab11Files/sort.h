#ifndef SORT_H
#define SORT_H
#include<iostream> 
#include<queue>

using std::queue; 
using std::cout;

//using namespace std; 



//This function will take 3 queues, two of them will be empy and one will be full
//the full queue will have half of its contenent stored in one queue, and the other half in the other.
//At the end of the function the original quie that was full will be emptied out 
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




// This function takes  3 queues, two have values and one empty
//Throughut the function it will get the two values togeter already sorted from smaller to the greatest 
template<class T>
void merge(queue<T>& a, queue<T>& b, queue<T> & q)
{
	
	//we repeat the function as long as one of the queues have a value stored inside
	while (!a.empty() || !b.empty())
	{

		//if only one is epmty we just push the one that is not 
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

		//if neither is empty we compared them and put them together in order. 
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




//We overload the output operator se we can output the queue
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

