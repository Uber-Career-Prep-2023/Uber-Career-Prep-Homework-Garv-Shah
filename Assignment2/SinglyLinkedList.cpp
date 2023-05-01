
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <numeric>
#include <cassert>
#include <unordered_map>
using namespace std;
struct Node{
    int data;
    struct Node* next;
};
Node* insertAtFront(Node* head, int n);
void insertAfter(Node* head, int n, Node* loc);
void insertAtBack(Node *head, int n);
Node* deleteFront(Node *head);
void deleteBack(Node *head);
Node* deleteNode(Node *head, Node *loc);
int length(Node *head);
Node* reverseIterative(Node *head);
Node* reverseRecursive(Node *head);
Node* dedupSortedList(Node *head); // around 12 mins
Node* moveNthLastToFront(Node *head, int n); // around 20 mins
Node* disconnectCycle(Node *head); // around 15 mins

int main() {
    // All my functions pass the tests I wrote
    Node* node1 = insertAtFront(NULL, 5); // 5
    Node* node2 = insertAtFront(node1, 6); // 6 5
    Node* node3 = insertAtFront(node2, 7); // 7 6 5
    insertAfter(node3, 9, node2); // 7 6 9 5
    cout<<length(node3)<<endl; // 4
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
    deleteNode(node3, node3->next->next); // 6 9 10 9 6
    deleteBack(node3); // 6 9 10 9
    Node* node4 = reverseIterative(node3);
    cout<<node4->data<<" "<<node4->next->data<<" "<<node4->next->next->data<<
    " "<<node4->next->next->next->data<<" "<<endl; // 9 10 9 6
    Node* node5 = reverseRecursive(node4);
    cout<<node5->data<<" "<<node5->next->data<<" "<<node5->next->next->data<<
    " "<<node5->next->next->next->data<<" "<<endl; // 6 9 10 9
    deleteBack(node5);
    insertAtBack(node5, 10); // 6 9 10 10
    insertAtBack(node5, 10); // 6 9 10 10 10
    node5 = dedupSortedList(node5); // 6 9 10
    cout<<length(node5)<<endl; // 3
    insertAtBack(node5, 11); // 6 9 10 11
    insertAtBack(node5, 12); // 6 9 10 11 12
    node5 = moveNthLastToFront(node5, 3); // 10 6 9 11 12
    cout<<node5->data<<" "<<node5->next->data<<" "<<node5->next->next->data<<
    " "<<node5->next->next->next->data<<" "<<node5->next->next->next->next->data<<endl; // 10 6 9 11 12
    node5->next->next->next->next->next = node5->next; // now, 12 points back to 6
    cout<<node5->next->next->next->next->next->data<<endl; // 6
    node5 = disconnectCycle(node5);
    cout<<node5->next->next->next->next->next->data<<endl; // undefined behaviour because nullptr cannot have data
    return 0;
}

// Time Complexity : O(1)
// Space Complexity : O(1)
Node* insertAtFront(Node* head, int n){
    Node* temp1 = new Node; // creates a new node
    temp1 -> data = n; // assigns data
    temp1 -> next = head; // sets next node to head
    return temp1;
}

// Time Complexity : O(1)
// Space Complexity : O(1)
void insertAfter(Node* head, int n, Node* loc){
    assert(loc != NULL); // checks that loc points to a valid node
    Node* temp1 = new Node; // creates new node
    temp1 -> data = n; // assigns data

    Node* temp2 = loc -> next; // creates copy of the node after loc
    loc -> next = temp1; // creates a link between loc and newly created node
    temp1 -> next = temp2; // creates a link between newly created node and the copy
}

// Time Complexity : O(n)
// Space Complexity : O(1)
void insertAtBack(Node *head, int n){
    Node* temp1 = new Node; // creates new node
    temp1 -> data = n; // assigns data
    temp1 -> next = NULL; // sets the next to nullptr
    while(head -> next != NULL){ // iterates through the list until the last node is reached
        head = head -> next;
    }
    head -> next = temp1; // creates a link between the last node and the newly created node
}

// Time Complexity : O(1)
// Space Complexity : O(1)
Node* deleteFront(Node *head){
    assert(head != NULL); // ensures the list is not empty
    if(head -> next == NULL){ // checks if there is only one element in the list
        delete head;
        return NULL;
    }
    else{
        Node *temp1 = head -> next;
        delete head;
        return temp1; // returns the node after head
    }
}

// Time Complexity : O(n)
// Space Complexity : O(1)
void deleteBack(Node *head){
    assert(head != NULL); // ensures the list is not empty
    if(head -> next == NULL){ // checks if there is only one element in the list
        delete head;
        return;
    }
    Node *temp1 = head;
    while(temp1 -> next != NULL){ // iterating until last element
        temp1 = temp1 -> next;
    }
    Node *temp2 = head;
    while(temp2 -> next != temp1){ // iterating until second last element
        temp2 = temp2 -> next;
    }
    temp2 -> next = NULL; // setting next of second last element to nullptr
    delete temp1; // deleting last element
}

// Time Complexity : O(n)
// Space Complexity : O(1)
Node* deleteNode(Node *head, Node *loc){
    assert(loc != NULL); // checks that loc points to a valid node
    assert(head != NULL); // ensures list is not empty
    if(loc == head){
        Node *temp1 = loc -> next;
        delete loc;
        return temp1; // returning second element if loc points to first
    }
    else{
        Node *temp1 = head; // creating copy of head
        while(temp1 -> next != loc){ // iterating until one element before loc
            temp1 = temp1 -> next;
        }
        temp1 -> next = loc -> next; // creating a link between element before and after loc
        delete loc;
        return head;
    }
}

int length(Node *head){
    if(head == NULL) // checking if list is empty
        return 0;
    else{
        int c=1; // counter
        Node *temp2 = head;
        while(temp2 -> next != NULL){ // iterating until end of list
            c++;
            temp2 = temp2 -> next;
        }
        return c;
    }
}

// Time Complexity : O(n)
// Space Complexity : O(1)
Node* reverseIterative(Node *head){
    Node* current;
    Node* prev;
    Node* next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current -> next; // storing node after current
        current -> next = prev; // setting current to point to previous node
        // repeating process by moving to next node
        prev = current;
        current = next;
    }
    head = prev; // setting head to the last node of the list
    return head;
}

Node* reverseRecursiveHelper(Node *current, Node *prev) {
    if (current == NULL) { // base condition when prev points reaches last element of list before reversing
        return prev;
    }
    Node *next = current -> next; // storing node after current
    current -> next = prev; // setting current to point to previous node
    return reverseRecursiveHelper(next, current); // repeating process by moving to next node
}

// Time Complexity : O(n)
// Space Complexity : O(n)
Node* reverseRecursive(Node *head) {
    return reverseRecursiveHelper(head, NULL);
}

// Question 6
// Time Complexity : O(n)
// Space Complexity : O(1)
Node* dedupSortedList(Node *head){
    if(head == NULL)
        return head;

    Node *prev = head;
    Node *curr = prev -> next;

    while(prev != NULL && curr != NULL){
        if(prev -> data == curr -> data){
            prev -> next = curr -> next;
            delete curr;
            curr = prev -> next;
            // if two adjacent nodes have the same data, we delete the second and establish the necessary links
        }
        else{
            prev = curr;
            curr = curr -> next;
        }
    }

    return head;
}

// Question 7
// Time Complexity : O(n)
// Space Complexity : O(1)
Node* moveNthLastToFront(Node *head, int n){
    if(n > length(head)){
        cout<<"Error"<<endl;
        return head;
    }

    if(n == length(head)) // if n = size, nothing needs to be changed
        return head;

    Node *back = head;
    Node *front = head;
    for(int i=0; i < n-1; i++){
        back = back -> next; // move back to the nth node from the start
    }
    while(back -> next != NULL){
        back = back -> next;
        front = front -> next; // front now points to the nth node from the end
    }
    Node *temp = head;
    while(temp -> next != front){ // iterate until element before front, i.e. n-1th element from end
        temp = temp -> next;
    }
    temp -> next = front -> next;
    front -> next = head;
    return front;
}

// Question 9
// Time Complexity : O(n)
// Space Complexity : O(n)
Node* disconnectCycle(Node *head){
    if(head == NULL)
        return head;
    Node *temp1 = head;
    unordered_map<Node*, int> nodes; // map to keep track of nodes visited
    nodes[head]++;
    while(nodes.find(head -> next) == nodes.end() && head -> next != NULL){
        nodes[head -> next]++;
        head = head -> next;
    } // loop will end when a node gets visited twice

    head -> next = NULL;
    return temp1;
}

