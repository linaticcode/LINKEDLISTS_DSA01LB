#include<iostream>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    //constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}


bool detectLoop(Node* head) {

    if(head == NULL)
        return false;

    map<Node*, bool> visited;

    Node* temp = head;

    while(temp !=NULL) {

        //cycle is present
        if(visited[temp] == true) {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;

    }
    return false;

}

Node* floydcycle(Node* head){
  if(head==NULL){
    return NULL;
  }

  Node* slow = head;
  Node* fast = head;

  slow = slow->next;
  fast = fast->next->next;

  while(fast!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow==fast){
      cout<<"present at "<<slow->data<<endl;
      return slow;
    }

  }

  return NULL;

}

Node* startingnode(Node* head){
    
    if(head==NULL){
        return NULL;
    }
    
    if(floydcycle(head)==NULL){
        return NULL;
    }

    map<Node* , bool> check;
    Node* temp = head;

    while(check[temp]!=true){
        check[temp] = true;
        temp = temp->next;
    }

    return temp;    
}

// babbar method

Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }

    if(floydcycle(head)==NULL){
        return NULL;
    }

    Node* slow  = floydcycle(head);
    Node* fast  = slow;
    slow = head;
     
    while(slow!=fast){
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
}

void removeLoop(Node* head){
    if(head==NULL){
        return;
    }

    if(floydcycle(head)==NULL){
        return;
    }

    Node* start = getStartingNode(head);
    Node* temp = start;

    // while(temp!= start){
    //         temp = temp -> next;
    // }

    // temp = temp->next;

    while(temp ->next !=start){
        temp = temp -> next;
    }

    temp->next = NULL;
}

// Node* getStartingNode(Node* head) {

//     if(head == NULL) 
//         return NULL;

//     Node* intersection = floydDetectLoop(head);
//     Node* slow = head;

//     while(slow != intersection) {
//         slow = slow -> next;
//         intersection = intersection -> next;
//     }  

//     return slow;

// }

// void removeLoop(Node* head) {

//     if( head == NULL)
//         return;

//     Node* startOfLoop = getStartingNode(head);
//     Node* temp = startOfLoop;

//     while(temp -> next != startOfLoop) {
//         temp = temp -> next;
//     } 

//     temp -> next = NULL;

// }


int main() {
    
    //created a new node
    Node* node1 = new Node(10);
    //cout << node1 -> data << endl;
   // cout << node1 -> next << endl;
    
    //head pointed to node1
    Node* head = node1; 
    Node* tail = node1;
    //print(head);

    insertAtTail(tail, 12);

    //print(head);
    
    insertAtTail(tail, 15);
    //print(head);

    insertAtPosition(tail,head, 4, 22);
    //print(head);    

    //cout << "head " << head -> data << endl;
    //cout << "tail " << tail -> data << endl;

    //deleteNode(4, head);
    

    tail -> next = head ->next;

    cout << "head " << head -> data << endl;
    cout << "tail " << tail -> data << endl;
    //print(head);

    if(floydcycle(head) != NULL) {
        cout << "Cycle is present " << endl;
    }
    else
    {
        cout << "no cycle" << endl;
    }

    Node* node  = startingnode(head);
    Node* node2  = getStartingNode(head);

    cout<<"The startingnode is " << node->data << endl;
    cout<<"The startingnode is " << node2->data << endl;

    removeLoop(head);
    if(floydcycle(head) == NULL){
        cout<<"No cycle"<<endl;
    }
    
    
    // Node* loop = getStartingNode(head);

    // cout << "loop starts at " << loop -> data  << endl;

    // removeLoop(head);
    // print(head);

    /*
    print(head);

    if(isCircularList(head)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
    */


    return 0;
}