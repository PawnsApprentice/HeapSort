/**
* Title: Heaps
* Author: Hassam Abdullah
* ID: 21701610
* Assignment: 3
* Description: heapsort main file
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "heap.h"

using namespace std;

int main(int argc, char **argv) {

   if (argc == 3) {

        int noOfNodes = 0;

        ifstream inputFile;
        inputFile.open(argv[1]);

        //number of numbers in input files
        string counter;
        while (inputFile >> counter) {
            noOfNodes++;
        }



        //Creates a max heap whose size is the size of the numbers in the file
        Heap maxHeap(noOfNodes);

        inputFile.clear();
        inputFile.seekg(0);


        while (inputFile >> counter) {
            maxHeap.insert(atoi(counter.c_str())); //converts the integers into string
        }

        inputFile.close();

        ofstream outFile;
        outFile.open(argv[2]);

        // Prints number of elements and number of comparisons


        // Writes the numbers in the input file in descending order to specified file
        for (int i = 0; i < noOfNodes; i++) {
            outFile << maxHeap.popMaximum() << "\n";
        }

         cout << "n = " << noOfNodes << ", Number of comparisons = " << maxHeap.getComparisonCount() << endl;
        outFile.close();

    }

    else
    {
    	cout << "The name of the input file or output file are not correct" << endl;
    }

    return 0;
}
