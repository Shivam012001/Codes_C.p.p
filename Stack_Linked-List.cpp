#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next; 
    

Node(){
 
}
    Node(int data)
    {
        this->data=data;
        this->next=NULL;  
    }
};

class Stack{
    public:
    Node *head=NULL;

 // Functions
 void push(int);
 int pop();
 int peek();
 bool empty();
 Node* insert(int );


};

Node* Stack :: insert(int data)
{
      Node *temp =new Node(data);
      return temp;
}

void Stack :: push(int data)
{
    Node *temp = insert(data);
    if(head==NULL)
    {
      head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}

int Stack :: pop()
{
    if(head==NULL)
    {
        cout<<"Stack underflow";
        return -1;
    }
    else
    {
        int ele = head->data;
        Node* temp=head;
        head=head->next;
        delete temp;
       return ele;
    }
    
}

int Stack :: peek()
{
    if(head==NULL)
    {cout<<"No element is present";
     return -1;
    }
    
    return head->data;
}

bool Stack :: empty()
{
    if(head==NULL) return true;
    else
    return false;
}







int main()
{
   Stack s;


    return 0;
}