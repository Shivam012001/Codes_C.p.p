#include<bits/stdc++.h>

using namespace std;

class Stack{
    public:
    int top;
    int *arr;
    int size;

  
   void push(int ele);
   void pop();
   int peek();
   bool empty();
   int len();

  Stack(int size)
  {
      this->arr = new int[size];
      this->size=size;
      this->top = -1;
  }

};

void Stack:: push(int ele)
{
    if(top+1<size)
    {
        top++;
        arr[top]=ele;
    }
    else
    cout<<" \n Stack overflow \n";
    
}

void Stack :: pop()
{
    if(top>=0)
    top--;
    else
    cout<<"\n Stack underflow \n";
}

int Stack :: peek()
{
    if(top>=0 )
    return arr[top];
    
    else
    {cout<<"\n Stack is Empty \n";
      return -1;
    }

}

bool Stack ::  empty()
{
    if(top<0)
    return true;
    else
    return false;
}

int Stack :: len()
{
    return size;
}


int main()
{
     Stack s();
     



    return 0;
}


