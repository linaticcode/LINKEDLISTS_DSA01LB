//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/



class Solution
{
    public:
    
    int getCount(Node* head)
{
    int count = 0; // Initialize count
    Node* current = head; // Initialize current
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

    void insertAttail(Node* &tail , int v){
        
         Node* temp = new Node(v);
         tail->next = temp;
         tail  = temp;
    }
    
    Node* reverse(Node* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        Node* rest = reverse(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int c1= getCount(first);
        int c2= getCount(second);
        
        
        Node* ans =  new Node(-1);
        Node* ansT =  ans;
        int sum = 0;
        
        first = reverse(first);
        second = reverse(second);
        
        Node* temp  = first ; 
        Node* curr  = second ;
        
        int rem = 0;
        
        while(temp!=NULL  && curr!=NULL){
            
            sum = temp->data + curr->data + rem;
            rem = 0;
            if(sum>=10){
                rem = sum / 10;
                sum = sum %10 ;
            }
            
            insertAttail(ansT  , sum);
            temp = temp->next;
            curr = curr->next;
            
        }
        
        while(temp!=NULL){
            
            sum = temp->data + 0 + rem;
            rem = 0;
            if(sum>=10){
                rem = sum / 10;
                sum = sum %10 ;
            }
            insertAttail(ansT , sum);
            temp  = temp->next;
        }
        
        while(curr!=NULL){
            
            sum = curr->data + 0 + rem;
            rem = 0;
            if(sum>=10){
                rem = sum / 10;
                sum = sum %10 ;
            }
            
            insertAttail(ansT , sum);
            curr  = curr->next;
        }
        
        if(rem!=0){
            insertAttail(ansT , rem);
        }
        
        ans = ans->next;
        ansT ->next = NULL;
        ans = reverse(ans);
        first = reverse(first);
        second = reverse(second);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends