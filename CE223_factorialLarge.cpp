// Linked list large number factorial
// 23 October 2023
// CE223 class practice
// g++ --std=c++11 CE223_factorialLarge.cpp
// ./a.out

#include <chrono>
#include <iostream>
using namespace std;

class Node {
    public: 
    int data;
    Node *prev;

    Node (int n) {
        data = n;
        prev = NULL;
    }
};


void Multiply(Node* tail, int n) {
    // shifting node method
    Node *temp = tail;
    Node *prevNode = tail;
    int carry = 0;

    while (temp != NULL) {
        int data = temp->data * n + carry;
        temp->data = data%10;
        carry = data/10;
        prevNode = temp;
        temp = temp->prev;
    }

    while (carry != 0) {
        prevNode->prev = new Node(carry%10);
        carry /= 10;
        prevNode = prevNode->prev;
    }
}

void print (Node* tail) {
    if (tail == NULL) {
        return;
    }
    print(tail->prev);
    cout << tail->data;
}


// driver code
int main() {
    int n = 1000;
    Node tail (1);

    for (int i = 2; i <= n; i++) {
        Multiply(&tail, i);
    }

    print(&tail);
    cout << endl;

    return 0;
}