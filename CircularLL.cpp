#include<iostream>
using namespace std;

class node{
  public:
  int data;
  node* next;
  
// Constructor
 
   node(int data){
    this->data = data;
    this->next = NULL;
   }

   ~node(){
    int value  = this->data;
    if(this->next!=NULL){
        delete next;
        this->next = NULL;
    }
   }
};

void insertAtNode(node* &tail,int value, int data){
      
      if(tail==NULL){
        node* temp = new node(data);
        tail = temp;
        temp -> next = temp;
      }

      else {
          node* curr = tail;
          
          while(curr->data != value){
            curr = curr->next;
          }

          node* temp = new node(data);
          temp->next = curr -> next;
          curr->next = temp; 
      }
      
}

void deletenode(node* tail , int v){
      if(tail==NULL){
        cout<<"The list is empty"<<endl;
      }
      else{
        node* prev = tail;
        node* curr = prev->next;
        while(curr->data != v){
            prev = curr;
            curr = curr->next;            
        }

        if(tail==curr){
            tail = prev;
        }
        prev->next = curr->next;


        curr->next = NULL;
        delete curr;

      }
} 

void print(node* tail){
      node* temp =  tail;

      do{
        cout<<tail->data<<" ";
        tail = tail->next;
      }while(tail!=temp);

      cout<<endl;
}

int main(){

   node* tail = NULL;
   
   insertAtNode(tail,7,3);
   print(tail);

  
   insertAtNode(tail,3,5);
   print(tail);

   insertAtNode(tail,5,7);
   print(tail);


   insertAtNode(tail,5,6);
   print(tail);

   

   deletenode(tail , 3);
   print(tail);

    cout<<tail->data<<" "<<endl;
   

}