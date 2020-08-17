
/**
* Title: Heaps
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 3
* Description: Heaps .cpp file
*/

#include "heap.h"
using namespace std;

//default constructor
Heap::Heap()
{
    arrSize = 100;
    heapArr = new int[100];
    comparisonCount = 0;
    lastIndex = 0;
}

//constructor to specify input size
Heap::Heap(int size)
{
    heapArr = new int[size];
    comparisonCount = 0;
    arrSize = size;
    lastIndex  = 0;
}

//destructor for the heap
Heap::~Heap()
{
    delete heapArr;
}

/**
*returns true if heap is empty and false if not
*/
bool Heap::heapIsEmpty() const
{
    return (lastIndex == 0);
}

/**
*helper method for insert method that swaps two integers
*/
void Heap::swapNum(int& a, int& b)
{
    int temp  = a;
    a = b;
    b = temp;
}

/**
*a method that inserts an integer into the max heap
*/
void Heap::insert(const int a)
{
    if (lastIndex == arrSize)
		{
		    return;
		}

	// Place the new item at the end of the heap
	heapArr[lastIndex] = a;

	// Trickle new item up to its proper position

	int place = lastIndex;
	int parent = (place - 1)/2;


	while ( (parent >= 0) && (heapArr[place] > heapArr[parent])) {

        //swap
		swapNum(heapArr[parent], heapArr[place]);
		place = parent;
		parent = (place - 1)/2;


	}

 	++lastIndex;
}


/**
*returns -1 if there are no elements in the max heap else returns the value of the root node
*/
int Heap::maximum()
{
    if (lastIndex == 0)
    {
        return -1;
    }
    else
    {
        return heapArr[0];
    }
}

/**
*returns the number of comparisons made in the heapsort algorithm
*/

int Heap::getComparisonCount()
{
    return comparisonCount;
}

/**
*returns the maximum integer in the max heap and deletes it
*/
int Heap::popMaximum()
{
    int result = maximum();

    comparisonCount++;
    if(lastIndex  == 0)
    {
        return -1;
    }

     lastIndex--;
     heapArr[0] = heapArr[lastIndex];

        heapRebuild();

    return result;
}


/**
*rebuilds the heap during the popMaximum() function
*/
void Heap::heapRebuild()
{


    int parent = 0;
    int l_child = 2 * parent + 1;
    int r_child;

    while(l_child < lastIndex)
    {

        comparisonCount++; //while loop

        r_child = l_child+1;

        comparisonCount++; //if loop
        if(heapArr[r_child] > heapArr[l_child] && r_child < lastIndex)
        {

            l_child = r_child;
        }

        comparisonCount++; //second if loop
        if(heapArr[parent] < heapArr[l_child])
        {

            swapNum(heapArr[parent], heapArr[l_child]);
        }

        parent = l_child;
        l_child = 2*parent + 1;

    }

}






