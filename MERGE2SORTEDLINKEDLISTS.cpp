#include <bits/stdc++.h> 
#include <bits/stdc++.h>
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
void insertAttail(Node<int>* &tail , int value){
    
        Node<int>* temp  = new Node<int>(value);
        tail->next = temp;
        tail = temp;
       
}


Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    
    if(first==NULL)
        return second;
    
    else if(second == NULL)
        return first;
        
        
    Node<int>* temp = first;
    Node<int>* curr = second;
    Node<int>* ans = new Node<int>(-1);
    Node<int>* ansT = ans;
//     int v1 = temp->data;
//     int v2 = curr->data;
    
    while(temp!=NULL && curr!=NULL){
        
        if(temp->data<curr->data){
            insertAttail(ansT , temp->data);
            temp = temp->next;
        }
        
//      v1 aur v2 dynamically store nahi hota
// to tum constant variables istemaal nahi kar sakte
        else if(temp->data == curr->data){
            insertAttail(ansT , temp->data);
            insertAttail(ansT ,curr->data);
            temp = temp->next;
            curr = curr->next;
        }
        
        else if(temp->data>curr->data){
            insertAttail(ansT , curr->data);
            curr = curr->next;
          }
        
}
//     Bache kuche walon ke liye
    while(temp!=NULL){
        
        insertAttail(ansT,temp->data);
        temp = temp->next;       
    }
    
    while(curr!=NULL){
        
        insertAttail(ansT,curr->data);
        curr = curr->next;       
    }
    
    ans = ans->next ;
    ansT->next = NULL;
    
    return ans;
}