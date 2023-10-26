// P4 - Singly Linked List with tail pointer

// g++ --std=c++11 CE223_P4.cpp
//./a.out

#include <iostream>
using namespace std;

// Creating node struct with data and pointer

struct Node { 
  int data; 
  Node *next; 
};

// Creating linked list
class linkedList {
    // Initializing node with previous & tail pointer
    Node* tail;
    Node* prev_val;

    public:
    // Initializing tail pointer
    linkedList() {
        tail = prev_val = NULL;
        return;    
    }

    // INSERTION METHOD
    void insert(int val) { 
        Node* new_node = new Node;
        new_node->data = val;
        new_node->next = NULL;
        if (prev_val == NULL) {
            prev_val = tail = new_node;
            return;
        }
        else {
            tail->next = new_node;
            tail = new_node;
            
        }

    }

    // PRINTING METHOD
    void print() {
        Node* val = prev_val;
        while(val != NULL) {
            cout << val->data << " ";
            val = val->next;
        }
        cout << endl;

    }

    // SEARCH METHOD
    bool search(int val) {
        Node* temp = prev_val;
        while(temp != NULL) {
            if (temp->data == val) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // DELETION METHOD
    void deleteElement(int val) { 
        if (prev_val->data == val) {
            delete prev_val;
            prev_val = prev_val->next;
            return;
        }
        if (prev_val == tail) {
            if (prev_val->data == val) {
                delete tail;
                tail = NULL;
                return;
            }
            cout << "Value " << val << " not found in linked list." << endl;
            return;
        }
        Node* temp = prev_val;
        while(temp->next != NULL) {
            if (temp->next->data == val) {
                Node* temp_ptr = temp->next->next;
                delete temp->next;
                temp->next = temp_ptr;
                return;
            } 
            temp = temp->next;
        }
        cout << "Value " << val << " not found in linked list." << endl;
    }

    // LIST REVERSAL METHOD
    void reverse() {
        Node* current = prev_val;
        Node *prev = NULL;
        Node *next = tail;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        prev_val = prev;

    }

};

int main() {
    linkedList L;
    L.insert(1);
    L.insert(2);
    L.insert(3);
    L.insert(4);
    L.insert(5);
    L.insert(6);
    L.insert(7);
    L.insert(8);
    L.insert(9);
    L.insert(10);
    L.print();

    cout << "Searching Method" << endl;
    cout << "Searching for 52: " << L.search(52) << endl;
    cout << "Searching for 3: " << L.search(3) << endl;

    cout << "Deleting elements" << endl;
    cout << "Deleting value 3" << endl;
    L.deleteElement(3);
    L.print();

    cout << "Deleting value 3 (again)" << endl;
    L.deleteElement(3);
    L.print();

    cout << "Deleting value 5" << endl;
    L.deleteElement(5);
    L.print();

    cout << "Reversing the linked list" << endl;
    L.reverse();
    L.print();

}