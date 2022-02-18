#include<bits/stdc++.h>

using namespace std;

class Stack{
   private:
   void extender();


    public:
    int top;
    int *arr;
    int size;

  
   void push(int ele);
   void pop();
   int peek();
   bool empty();
   int len();


Stack()
{
    this->arr=new int[3];
    this->size=3;
    top= -1;
}
  Stack(int size)
  {
      this->arr = new int[size];
      this->size=size;
      this->top = -1;
  }

};

void Stack:: push(int ele)
{
    if(top==size-1)
    extender();

        top++;
        arr[top]=ele;

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

//Extender
void Stack :: extender()
{   // create an array of double the size
    int *temp= new int[size*2];
    
    // Copy Elements
    for(int i=0;i<size;i++)
     temp[i]=arr[i];

     size=size*2;

     // Deleting old array
      delete[] arr;
     
     //Assigning old to new
     arr=temp;
}





int main()
{
     Stack s;

  



    return 0;
}


