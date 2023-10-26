// 22 Sep 2023
// CE 223 Project 2: Algorithm Toolbox, Finding the longest run of ascending numbers in an assorted array
// Brute force

// Time complexity = O(n)
// Space complexity = O(1)

// g++ --std=c++11 CE223_P2_BruteForce.cpp
//./a.out

#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

 

int longestRun(int assortArrray[], int n) {
    // Defining initial count
    int maxRun = 1;
    int currentRun = 1;
     
    // iterate through array to find the longest run
    for (int i=1; i<n; i++) {
        if (assortArrray[i] > assortArrray[i-1])
            currentRun++;
        else {
            if (maxRun < currentRun)
                maxRun = currentRun;  
            currentRun = 1;   
        }   
    }

    // assigning highest run value to max run 
    if (maxRun < currentRun)
        maxRun = currentRun;
    
    return maxRun;
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
    cout << endl << "The longest run of ascending numbers in the assorted array is " << longestRun(randArray, n) << endl;
    auto e1 = high_resolution_clock::now();
    auto d1 = duration_cast<microseconds>(e1 - s1);
    cout << "The algorithm was run in " << d1.count() << "us" << endl;

    return 0;
}