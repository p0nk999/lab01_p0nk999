// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE
// Fengxun Daniel Li, 1/16

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //DEEP COPY
    //first check the casee for empty
    if (source.head==nullptr){
        head=nullptr;
        tail=nullptr;
        return;
    }



    head = new Node;
    head->info=source.head->info;
    head->next=nullptr;
    tail=head;

    Node*curr=source.head->next;

    while(curr!=nullptr){
        Node*newNode=new Node;
        newNode->info=curr->info;
        newNode->next=nullptr;
        tail->next= newNode;//attach
        tail=newNode;//update

        curr=curr->next;//+=1
        
    }

    
}

// destructor deletes all nodes
IntList::~IntList() {
    
    while (head!=nullptr){
        Node* nextNode=head->next; //make sure all the rest are still accessible
        delete head;
        head=nextNode;//+=1
    }
    
}


// return sum of values in list
int IntList::sum() const {
    int total =0;
    Node*curr=head;

    while(curr!=nullptr){
        total+=curr->info;
        curr=curr->next;
    }

    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node*curr= head;

    while(curr!= nullptr){
        if(curr->info==value){
            return true;
        }
        curr=curr->next;
    }
    return false;
    
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    //check if empty
    if(head==nullptr){
        return 0;
    }
    int max= head->info;
    Node*curr=head;
    while(curr!=nullptr){
        if(curr->info>max){
            max=curr->info;
        }
        curr=curr->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    //check if empty
    if(head==nullptr){
        return 0.0;
    }
    double avg=0.0;
    int total=0;
    int count=0;
    Node* curr=head;
    while (curr!=nullptr){
        total+=curr->info;
        curr=curr->next;
        count+=1;
    }
    avg=(double)total/count;
    
    return avg;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode=new Node;
    newNode->info=value;
    newNode->next= head;//attach
    head=newNode;//update

    //check if list empty so that tail points to here as well!!!!!!!!
    if(tail==nullptr){
        tail=head;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode=new Node;
    newNode->info= value;
    newNode->next=nullptr;

    if (head==nullptr){
        head=newNode;
        tail=newNode;
    }

    else{
        tail->next=newNode;
        tail=newNode;
    }
 
}

// return count of values
int IntList::count() const {
   Node*curr=head;
   int count=0;
   while (curr!=nullptr){
    count+=1;
    curr=curr->next;
   }
   return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if(this==&source){//check if self
        return*this;
    }

    while(head!=nullptr){
        Node*next=head->next;
        delete head;
        head=next;
    }
    tail=nullptr;

    if(source.head==nullptr){
        head=nullptr;
        tail=nullptr;
        return *this;

    }
    //copy the first node then do the rest.
    head=new Node;
    head->info=source.head->info;
    head->next=nullptr;
    tail=head;

    //rest
    Node*curr=source.head->next;
    while(curr!=nullptr){
        Node*newNode=new Node;
        newNode->info=curr->info;
        newNode->next=nullptr;
        
        tail->next=newNode;
        tail=newNode;

        curr=curr->next;
    }

    return *this;


    
}

// constructor sets up empty list
IntList::IntList(){ 
    head=nullptr;
    tail=nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

