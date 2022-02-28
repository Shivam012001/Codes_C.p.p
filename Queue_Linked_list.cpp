#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
Node(){

}

    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

class Queue{
    public:
   Node* front;
   Node* rear;
   Queue()
   {
       front=rear=NULL;
   }

   void push(int data);
   int pop();
   bool isEmpty();
   int head();
   int size();
   

};

void Queue:: push(int data)
{
      
         Node*temp= new Node(data);
      if(isEmpty())  // if first element
     { 
          front=temp;
          rear=temp;
      }   
      else{  // Normal Insertion
      rear->next=temp;
      rear=temp;
      }
}
 
int Queue :: pop()
{
       if(isEmpty()){  //Empty or not 
        cout<<"Empty"<<endl;
        return -1;
       }
Node*temp=front;
int ans=front->data;


      if(front==rear){  // First Element

           front=rear=NULL;  
       }
       else{// Normal popping
              front=front->next;          
       }
       delete temp;
       return ans;
} 
int Queue:: head()
{
    if(front==NULL)
    return -1;
    else
    return front->data;
}


int Queue :: size()
{
    if(front==NULL)
    return 0;

    int count=1;
    Node*temp=front;
    while(temp!=rear && temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

bool Queue :: isEmpty()
{
    if(front==NULL)
    return true;
    else
    return false;
}

int main()
{
    Queue q;
   
    return 0;
}