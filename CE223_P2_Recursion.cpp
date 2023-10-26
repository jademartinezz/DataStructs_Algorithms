// 25 Sep 2023
// CE 223 Project 2: Algorithm Toolbox, Finding the longest run of ascending numbers in an assorted array
// Recursion 

// Time complexity = O(e^n)
// Space complexity = O(e^n)

// g++ --std=c++11 CE223_P2_Recursion.cpp
//./a.out

#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;



int fullArray(int arr[], int n, int* maxRun) {
    // initializing the run value
    int maxLength = 1;
    int count = 1;
 
    // Finding the longest ascending run using recursion
    for (int i = 1; i < n; i++) {
        count = fullArray(arr, i, maxRun);
        if (arr[i - 1] < arr[n - 1] && count + 1 > maxLength) {
            maxLength = count + 1;
        }
    }
 
    // Assign run value
    if (*maxRun < maxLength){
        *maxRun = maxLength;
    }

    return maxLength;
}
 

int subArray(int arr[], int n) {
    // initialize the subarray max value
    int max = 1;
 
    fullArray(arr, n, &max);
 
    return max;
}
 

int main() {
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

    // creating random array 
    int randArray[n];
    for(int i=0;i<n;i++){
        randArray[i]=rand()%1000;
    }

    cout << "The values in the array are: " << endl;
    for(int i=0;i<n;i++) {
        cout<<randArray[i]<< " ";
    }
    
    // run time analysis
    auto s1 = high_resolution_clock::now();
    cout << endl << "The longest run of ascending numbers in the assorted array is " << subArray(randArray, n) << endl;
    auto e1 = high_resolution_clock::now();
    auto d1 = duration_cast<microseconds>(e1 - s1);
    cout << "The algorithm was run in " << d1.count() << "us" << endl;

    return 0;
}