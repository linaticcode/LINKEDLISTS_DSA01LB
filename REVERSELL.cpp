#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long int li;

class Node
{
  public:
    int data;
    Node * next;
  // constructor
  Node(int data){
    this -> data = data;
    this -> next  = NULL;

  }
};

void reversell(Node* &head , int n){
           
           Node* start = head;
           Node* end = head;
           int count = 0;
         //  cout<<1;
        //  if(n-1>0)
        //  {
           while(count!=n-1){
            count++;
            end = end->next;
           }
        //  }
         // cout<<2;
           if(start==end || (end->next!=NULL && end->next==start)){

                return;   
                
           }
           
           swap(start->data  , end->data);
           start = start->next;
           reversell(start,n-2);

    }

void insertAtPosition(int position, int data, Node* &head){
     
     Node* temp = head;
     int count = 1;
    
     while(count!=position-1){
        temp = temp->next;
        count++;
     }

     Node * nodein = new Node(data);
     nodein->next = temp->next;
     temp ->next = nodein;
     
     }

void insertAtTail(Node* &tail,int d){
       //  new node create
       Node* temp =  new Node(d);
       tail->next = temp;
       tail = temp;
}


void insertAtHead(Node* &head , int d){
      //  new node create
       Node* temp =  new Node(d);
       temp->next = head;
       head = temp;

}

void print(Node* &head){
  Node* temp = head;

  while(temp!=NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
  cout<<endl;

}


int main(){
  // created a new
  Node * node1  = new Node(10);
  // cout<< node1 -> next<<endl;
  // cout<< node1 -> data<<endl;
  int count = 0;
  // head pointed to node1
  Node* head = node1;
  Node* tail = node1;
  print(head);

  insertAtTail(tail,12);
  print(head);

  insertAtTail(tail,15);
  print(head);

  insertAtPosition(3,14,head);
  print(head);

   insertAtTail(tail,17);
  print(head);
   insertAtTail(tail,22);
  print(head);
   insertAtTail(tail,43);
  print(head);
 
  Node* temp = head;
  while(temp != NULL){
    count++;
    temp = temp->next;
  }
  
   cout<<count<<endl;
 
  reversell(head,count);
  print(head);

  


}