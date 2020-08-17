
/**
* Title: Heaps
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 3
* Description: Heap Header file
*/

#ifndef HEAP_H
#define HEAP_H

#include <iostream>

using namespace std;




class Heap {
public:
	Heap();
	Heap(int size);
	~Heap();
	bool heapIsEmpty() const;
	void heapDelete(int& rootItem) ;
	void insert(const int a);
	int maximum();
	int popMaximum();
	void swapNum(int& a, int& b);
	int getComparisonCount();

protected:
	void heapRebuild();

private:
	int* heapArr;
	long long comparisonCount;
	int arrSize;
	int lastIndex;
};

#endif // HEAP_H
