
// Approach 1
Node* sortList(Node *head)
{
    Node* temp =  head;
    int count_0 = 0 , count_1 = 0 , count_2 = 0;
//     map<int , int> m;
    while(temp!=NULL){
        
        if(temp->data == 0){
            count_0++;
        }
        
        else if(temp->data == 1){
            count_1++;
        }
        
       else if(temp->data == 2){
            count_2++;
        }
        
       temp = temp->next; 
    }
//     int i  = 0 , j = 0 , k = 0;
    temp = head;
   while(temp!=NULL){
       
       if(count_0!=0){
           temp->data = 0 ; 
           count_0--;
           
       }
       
       else if(count_1!=0){
           temp->data = 1 ; 
           count_1--;
//            temp = temp->next;
       }
       
       else if(count_2!=0){
           temp->data = 2 ; 
           count_2--;
//            temp = temp->next;
       }
       
       temp = temp->next;
   } 
    
   return head;
}

// Approach 2


/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

void insertAttail(Node* &tail , int value){
    
        Node* temp  = new Node(value);
        tail->next = temp;
        tail = temp;
   
//         Dikkat thi ki tum NULL pointer par data input the
//         tail->next hamesha Null par jayega
       
}
  


Node* sortList(Node *head)
{
    Node* zero = new Node(-1);
    Node* zeroT = zero;
    Node* one = new Node(-1);
    Node* oneT = one;
    Node* two = new Node(-1);
    Node* twoT = two;
    
    Node* temp = head;
    
    while(temp!=NULL){
        
        if(temp->data==0){
           insertAttail(zeroT , 0);
        }
        
        else  if(temp->data==1){
           insertAttail(oneT , 1);
        }
        
        else if(temp->data==2){
           insertAttail(twoT , 2);
        }
        
        temp = temp->next;
        
    }
    
   
    if(one->next!=NULL){
    zeroT->next = one->next;
    oneT->next = two->next;
    }
    
    else{
     zeroT->next = two->next;
    }
    
    twoT->next = NULL;
    head = zero ->next;
    
    delete zero ;
    delete one ; 
    delete two;
    
    return head;
}
