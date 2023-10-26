// 3 October 2023
// CE 223 Project 3: Search and Sort - Count Sort
// Recursion 

// Time complexity = O(k+n) where k is the range of values and n is the size of the array
// Space complexity = O(k+n)

// g++ --std=c++11 CE223_P3_CountSort.cpp
//./a.out

#include <iostream>
using namespace std;
using namespace std::chrono;


void countSort(int inputArray[], int size) {
    // initialize max value
    int max = inputArray[0];

    // finding the max value
    for (int i = 1; i < size; i++) {
        if (inputArray[i] > max)
            max = inputArray[i];
    }

    // initialize array for the count
    int countArray[max+1];

    // set array values to 0
    for (int i = 0; i <= max; ++i) {
        countArray[i] = 0;
    }

    // track count of elements at their index in count array
    for (int i = 0; i < size; i++) {
        countArray[inputArray[i]]++;
    }

    // putting cumulative sum of elements into count array 
    for (int i = 1; i <= max; i++) {
        countArray[i] += countArray[i - 1];
    }

    // initialize sorted array 
    int sorted[size];

    // setting sorted array values using index values from the counting array
    for (int i = size - 1; i >= 0; i--) {
        sorted[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }

    // printing sorted array
    cout << "The sorted array is:" << endl;
    for (int i = 0; i < size; i++) {
        cout << sorted[i] << " ";
    }
}

int main() {
    // user input size of array
    int n;
    // incorrect data input handling 
    while (true) {
        cout << "Please input the size of the array: ";
        cin >> n;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore();
            cout << "Please enter an integer. " << endl;
        } else break;
    }

    // user input array element values
    int assortedArray[n];
    // incorrect data input handling
    while (true) {
        cout << "Enter array values: ";
        for (int i = 0; i < n; ++i) {
            cin >> assortedArray[i];
        }
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore();
            cout << "Please enter an integer. " << endl;
        } else break;
    }

    
    // run time analysis
    auto s1 = high_resolution_clock::now();
    countSort(assortedArray, n);
    auto e1 = high_resolution_clock::now();
    auto d1 = duration_cast<microseconds>(e1 - s1);
    cout << endl << "The algorithm was run in " << d1.count() << "us" << endl;

    return 0;    
}