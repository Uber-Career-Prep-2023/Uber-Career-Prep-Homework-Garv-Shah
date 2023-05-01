
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <numeric>
#include <cassert>
using namespace std;
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

Node *insertAtFront(Node* head, int n);
void insertAfter(Node* head, int n, Node* loc);
void insertAtBack(Node* head, int n);
Node* deleteFront(Node *head);
void deleteBack(Node *head);
Node* deleteNode(Node *head, Node *loc);
int length(Node *head);
Node* reverseIterative(Node *head);
Node* reverseRecursiveHelper(Node *current, Node *prev);
Node* reverseRecursive(Node *head);
bool isPalindrome(Node *head); // around 15 mins

int main() {
    // All my functions pass the tests I wrote
    Node* node1 = insertAtFront(NULL, 5); // 5
    Node* node2 = insertAtFront(node1, 6); // 6 5
    Node* node3 = insertAtFront(node2, 7); // 7 6 5
    insertAfter(node3, 9, node2); // 7 6 9 5
    cout<<length(node3)<<endl; // 4
    cout<<node1->data<<" "<<node1->prev->data<<" "<<node1->prev->prev->data<<" "<<
    node1->prev->prev->prev->data<<endl; // 5 9 6 7
    insertAtBack(node3, 10); // 7 6 9 5 10
    cout<<node3->data<<" "<<node3->next->data<<" "<<node3->next->next->data<<" "<<
    node3->next->next->next->data<<" "<<node3->next->next->next->next->data<<endl; // 7 6 9 5 10
    node3 = deleteFront(node3); // 6 9 5 10
    cout<<(node3==node2)<<endl; // 1
    node3 = deleteNode(node3, node1); // 6 9 10
    cout<<length(node3)<<endl; // 3
    insertAtBack(node3, 10); // 6 9 10 10
    insertAtBack(node3, 9); // 6 9 10 10 9
    insertAtBack(node3, 6); // 6 9 10 10 9 6
    cout<<isPalindrome(node3)<<endl; // 1
    deleteNode(node3, node3->next->next); // 6 9 10 9 6
    cout<<isPalindrome(node3)<<endl; // 1
    deleteBack(node3); // 6 9 10 9
    cout<<isPalindrome(node3)<<endl; // 0
    Node* node4 = reverseIterative(node3);
    cout<<node4->data<<" "<<node4->next->data<<" "<<node4->next->next->data<<
    " "<<node4->next->next->next->data<<" "<<endl; // 9 10 9 6
    Node* node5 = reverseRecursive(node4);
    cout<<node5->data<<" "<<node5->next->data<<" "<<node5->next->next->data<<
    " "<<node5->next->next->next->data<<" "<<endl; // 6 9 10 9
    return 0;
}

// Time Complexity : O(1)
// Space Complexity : O(1)
Node* insertAtFront(Node* head, int n){
    Node* temp1 = new Node; // create new node
    temp1 -> data = n; // assign data
    temp1 -> prev = NULL; // set previous to nullptr
    temp1 -> next = head; // set next to first node
    if(head != NULL)
        head -> prev = temp1;
    return temp1;
}

// Time Complexity : O(1)
// Space Complexity : O(1)
void insertAfter(Node* head, int n, Node* loc){
    assert(loc != NULL); // check if loc points to a valid node
    Node* temp1 = new Node;
    temp1 -> data = n;
    temp1 -> prev = loc; // set previous of newly created node to loc

    if(loc -> next != NULL) { // check if loc was last node
        Node *temp2 = loc->next; // create copy of node after loc
        temp2->prev = temp1; // set prev of the copy to newly created node
        loc->next = temp1; // set loc next to newly created node
        temp1->next = temp2; // set next of newly created node to loc
    }
    else
        temp1 -> next = NULL;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
void insertAtBack(Node *head, int n){
    Node* temp1 = new Node;
    temp1 -> data = n;
    temp1 -> next = NULL; // set next of newly created node to nullptr
    if(head == NULL) {
        head = temp1; // if list is empty, head is newly created node
        head -> prev = NULL;
    }
    else{
        while(head -> next != NULL){ // iterates until last element
            head = head -> next;
        }
        temp1 -> prev = head; // sets prev of newly created node to last element
        head -> next = temp1; // sets next of last node to newly created element
    }
}

// Time Complexity : O(1)
// Space Complexity : O(1)
Node* deleteFront(Node *head){
    assert(head != NULL); // ensures list is not empty
    if(head -> next == NULL){ // checks if list has only one element
        delete head;
        return NULL;
    }
    else{
        Node *temp1 = head -> next; // points to second element in list
        temp1 -> prev = NULL; // sets prev of second element to nullptr
        delete head;
        return temp1;
    }
}

// Time Complexity : O(n)
// Space Complexity : O(1)
void deleteBack(Node *head){
    assert(head != NULL); // ensures list is not empty
    if(head -> next == NULL){ // checks if list has only one element
        delete head;
        return;
    }
    Node *temp1 = head;
    while(temp1 -> next != NULL){ // iterate until last element
        temp1 = temp1 -> next;
    }
    Node *temp2 = head;
    while(temp2 -> next != temp1){ // iterate until second last element
        temp2 = temp2 -> next;
    }
    temp2 -> next = NULL; // set next of second last element to nullptr
    delete temp1;
}

// Time Complexity : O(1)
// Space Complexity : O(1)
Node* deleteNode(Node *head, Node *loc){
    assert(loc != NULL); // checks that loc points to a valid node
    assert(head != NULL); // ensures list is not empty
    if(loc == head){
        Node *temp1 = loc -> next;
        temp1 -> prev = NULL;
        delete loc;
        return temp1; // if loc points to first node, move to second node, make it's prev nullptr, and return it
    }
    else{
        Node *temp1 = loc -> prev;
        temp1 -> next = loc -> next; // set next of element before loc to element after loc
        if(loc -> next != NULL)
            loc -> next -> prev = temp1; // if loc is not last element, set the prev of the element after loc to the element before loc
        delete loc;
        return head;
    }
}

int length(Node *head){
    if(head == NULL)
        return 0; // list is empty
    else{
        int c=1; // counter
        Node *temp2 = head;
        while(temp2 -> next != NULL){ // iterate until last element
            c++;
            temp2 = temp2 -> next;
        }
        return c;
    }
}

// Time Complexity : O(n)
// Space Complexity : O(1)
Node* reverseIterative(Node *head){
    Node *temp1 = NULL;
    Node *current = head;

    while (current -> next != NULL) { // iterating until last element
        // swapping links between nodes
        temp1 = current -> prev;
        current -> prev = current -> next;
        current -> next = temp1;
        current = current -> prev; // moving to next node
    }

    // Adjust links for last node, which is the new head after reversing
    Node *temp2 = current -> prev;
    current -> prev = current -> next;
    current -> next = temp2;

    return current; // new head
}

Node* reverseRecursiveHelper(Node *current, Node *prev){
    if(current == NULL) // base case
        return prev; // this is the new head

    Node *temp1 = current -> prev;
    current -> prev = current -> next;
    current -> next = temp1;
    return reverseRecursiveHelper(current -> prev, current);
}

// Time Complexity : O(n)
// Space Complexity : O(n)
Node* reverseRecursive(Node *head){
    return reverseRecursiveHelper(head, head -> prev);
}

// Question 8
// Time Complexity : O(n)
// Space Complexity : O(1)
bool isPalindrome(Node *head){
    if(head == NULL) // if empty, return false
        return false;
    Node *front = head; // pointer to first element
    while(head -> next != NULL){
        head = head -> next;
    }
    Node *back = head; // pointer to last element
    while(front != back && front -> next != back){  // loops until front and back point to same element or
                                                    // back points to element after front
        if(front -> data == back -> data){
            front = front -> next;
            back = back -> prev;
        }
        else
            return false;
    }
    return true;
}

