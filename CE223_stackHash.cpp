// 25 October 2023
// Stack & Queue
// g++ --std=c++11 CE223_stackHash.cpp
// ./a.out

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void printQ(queue<int> Q) {
    queue<int> G = Q; // make copy of queue so it is not deleted
    while(!G.empty()) {
        cout << G.front() << ", ";
        G.pop();
    }
}

int main() {
    // STACK METHODS
    stack<int> stack;
    stack.push(10);
    stack.push(50);
    stack.push(101);
    stack.push(410);
    stack.push(10);

    stack.pop();
    
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;

    // QUEUE METHODS
    queue<int> myQ;
    myQ.push(77);
    myQ.push(12);
    myQ.push(32);
    myQ.push(543);
    myQ.push(771);
    myQ.push(177);
    
    printQ(myQ);
    cout << endl;
    myQ.pop();
    printQ(myQ);

    return 0;
};