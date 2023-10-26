// Singly Linked List

// g++ --std=c++11 CE223_singlyLinkedList.cpp
//./a.out

#include <iostream>
using namespace std;

struct Node{
  int data;
  Node *next;
};

class LinkedList {
  Node* head;

  public:
    LinkedList() {
      head = NULL;
    }

    void insert(int val) {
      Node* new_node = new Node;
      new_node -> data = val;
      new_node -> next = NULL;

      if(head == NULL){
        head = new_node;
      }
      else{
        new_node -> next = head;
        head = new_node;
      }
    }

    void print(){
      Node* temp = head;
      while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
      }
      cout << endl;
    }

    void erase(int val){
      Node* temp = head;
      Node* prev = NULL;
      while(temp != NULL){
        if(temp -> data == val){
          if(prev == NULL){
            head = temp -> next;
            delete temp;
            return;
          }
          prev -> next = temp -> next;
          delete temp;
          return;
        }
        prev = temp;
        temp = temp -> next;
      }
    }

    // // remove by data point, first value in list
    // void remove(int val){
    //     if (head->data == val){
    //         delete head;
    //         head = head->next;
    //         return;
    //     }
    //     if (head->next = NULL){
    //         if (head->data == val){
    //             delete head;
    //             head = NULL;
    //             return;
    //         }
    //         cout << "Couldnt find your data." << endl;
    //     }
    //     Node* temp = head;
    //     while (temp->next != NULL){
    //         temp->next->data == val{
    //             Node* temp_ptr = temp->next->next;
    //             delete temp->next;
    //             temp->next = temp_ptr;
    //             return;
    //         }
    //         temp = temp->next;
    //     }
    //     cout << "Couldnt find your data." << endl;
    // }

    void search(int val) {
        Node* temp = head;
        while(temp->next != NULL){
            if (temp->data == val) {
                cout << "Value is found" << endl;
            }
            else {
                cout << "Value is NOT found" << endl;
            }
            return;
        }
    }

    void swap (int val1, int val2){
        Node*

    }

};


int main(){

  LinkedList test;
  test.insert(5);
  test.insert(4);
  test.insert(3);
  test.insert(2);
  test.insert(1);

//   test.print();

//   test.erase(3);
//   test.print();

//   test.erase(5);
  test.print();

  test.search(1);
  test.search(10);

  return 0;
}
