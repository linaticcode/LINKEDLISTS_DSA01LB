
// O(N) AND O(1) Without map
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};



// } Driver Code Ends
class Solution
{   
    private:
       
       void insertattail(Node* &tail , int v){
           Node* temp =  new Node(v);
           tail->next = temp;
           tail = temp;
       }
    
    public:
    Node *copyList(Node *head)
    {
       Node* temp =  head;
       Node* clone =  new Node(-1);
       Node* cloneT = clone;
       
       
    //   Step:1 Clone
       while(temp!=NULL){
           insertattail(cloneT , temp->data);
           temp = temp->next;
           
       }
       
       temp =  head;
       clone  = clone->next;
       cloneT->next=  NULL;
       Node* curr  = clone;
    // Step : 2 Changing links
    
       while(temp->next!=NULL && curr->next!= NULL){
           
           Node* node =  temp->next;
           temp->next =  curr;
           temp = node;
           
           node =  curr->next;
           curr->next = temp;
           curr = node;
       }
       
       temp->next = curr;
       curr -> next =  NULL;
       
    // Step:3 Setting arbitrary points
    // Segmentation fault ka khatra
    
      temp = head;
      curr = clone;
      
      while(temp!=NULL){
          
          if(temp->next!=NULL){
              if(temp->arb !=NULL){
                  temp -> next -> arb = temp->arb->next;
              }
              
              else{
                  temp->next->arb = NULL;
              }
          }
          
          
          temp = temp->next->next;
          
      }
    
    // Step:4 Deset links
    
    temp =  head;
    
    while(temp->next!=NULL && curr->next !=NULL){
        
        temp->next = curr->next;
        temp = temp->next;
        
        curr->next = temp->next;
        curr = curr->next;
        
    }
    
    
    temp->next = NULL;
    curr->next = NULL;
    
    
    return clone;
            
    }

};

//{ Driver Code Starts.


void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}


void append(Node **head_ref, Node **tail_ref, int new_data) {

    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {


    Node *temp1 = head;
    Node *temp2 = res;

    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }

    /*if lengths not equal */

    if (len1 != len2) return false;

    temp1 = head;
    temp2 = res;
    map<Node*,Node*> a;
    while (temp1 != NULL) {
        
        if(temp1==temp2)
            return false;
        
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data)
                return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        a[temp1]=temp2;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    

    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (a[temp1->arb] != temp2->arb) return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}



int main() {

    int T, i, n, l, k;
    Node *generated_addr = NULL;
     /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
            append(&head2, &tail2, l);
        }
         for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;

            Node *tempA = head;
            Node *temp2A = head2;
            int count = -1;

            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
                temp2A = temp2A->next;
            }
            Node *tempB = head;
            Node *temp2B = head2;
            count = -1;

            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
                temp2B = temp2B->next;
            }

            // when both a is greater than N
            if (a <= n){
                tempA->arb = tempB;
                temp2A->arb = temp2B;
            }
        }
        /*read finished*/

        generated_addr = head;
        Solution ob;
        struct Node *res = ob.copyList(head);
        if(validation(head2,res)&&validation(head,res))
            cout << validation(head2, res) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
// } Driver Code Ends