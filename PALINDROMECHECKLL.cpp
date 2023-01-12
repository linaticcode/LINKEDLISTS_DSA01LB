
// Appraoch 1
//  TC = O(N) , SC - O(1)

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
#include <map>
class Solution{
    
  private:
    
  Node* reverse(Node* head) {
        
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  
  
    Node* mid(Node* head){
    
        Node* slow =  head;
        Node* fast =  slow-> next;
 
       while(fast->next!= NULL && fast!=NULL){
           fast = fast->next->next;
           slow = slow->next;
        //   fast = fast->next->next;
           
       }    
      
      return slow;
        
    }
    
    
  public:
  
    
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
         
      if(head == NULL && head->next == NULL){
          return true;
      }    
        
    //   Node* temp = head;
      Node* middle = mid(head);
    //   reversed ll ka head;
      Node* midR = reverse(middle -> next);
      
      Node* temp = head;
      Node* curr = midR;
      
      while(curr!=NULL){
         
         if(temp-> data != curr->data){
             return false;
         } 
          
         temp = temp->next; 
         curr = curr-> next;
         
      }
    //   same ll banana
      middle -> next = reverse(midR);
      
      return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends


// Approach 2

// TC - O(N)  , SC - O(N)