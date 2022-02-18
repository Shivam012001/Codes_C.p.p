#include<bits/stdc++.h>
using namespace std;


// Sort the array Bubble Sort 
void recursive(stack<int> &s)
{
    if(s.size()==0 || s.size()==1)
     return;

     int x=s.top();
     s.pop();

    recursive(s);

    int y=s.top();
    s.pop();
     if(x>=y)
     {
         s.push(y);
         s.push(x);
     }
     else{
         s.push(x);
         s.push(y);
         
     }


}

// Delete the middle element

void Delete(stack<int>&s,int n)
{
    if(s.size()==0 )   
    return;
   
  

   int x=s.top();
   s.pop();
   
if(n==0) return;
   
   Delete(s,n-1);
   
   
   s.push(x);


}


// Numbers till first -ve and then till n

void recursiveNumber(int n,vector<int>&v)
{
    v.push_back(n);
    
    if(n<0)
    return;

    recursiveNumber(n-5,v);

    v.push_back(n);
}

// Recursively maximum number in an array


void maximum(int a[],int n,int index,int *max)
{
    if(index==n)
   {  return;
   }
    if(a[index]> *max)
    *max =a[index];

    maximum(a,n,index+1,max);
}




class ListNode{
    public:
    int val;
    ListNode *next;

ListNode()
{
    this->next=NULL;
}
 ListNode(int val)
 {
     this->val=val;
     this->next=NULL;
 }

};

//Insert LinkedList
void Insert(ListNode* &head,int val)
{
    ListNode *temp=new ListNode(val);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    else {
        ListNode * p=head;
        while(p->next!=NULL)
         p=p->next;

        p->next=temp;
    }

}

// Print LinkedList

void print(ListNode *head)
{
    if(head==NULL)
    cout<<"head is NULL";

    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head=head->next; 
    }
    cout<<endl;
}

// Reverse LinkList
ListNode* Reverse(ListNode* head)
{
    ListNode* q=NULL;
    ListNode* r=NULL;

    while(head!=NULL)
    {
        r=q;
        q=head;
        head=head->next;
        q->next=r;
    }
    return q;

}


 void Delete(ListNode* &head)
 {
     if(head==NULL) return;
     
     if(head->next==NULL)
     {
         head=NULL;
         return;
     }
     ListNode *p=head;
     ListNode *q=NULL;

     while(p->next!=NULL)
     {
          q=p;
          p=p->next;
     }
     q->next=NULL;
     delete p;

 }
// Add Two Numbers in a linked list
 ListNode* AddTwo(ListNode*p,ListNode*q)
 {
   int carry=0;
   ListNode* third=NULL;
   ListNode* head1=NULL;
   ListNode* head2=NULL;
   // Reverse Numbers
   head1=Reverse(p);
   head2=Reverse(q);
int sum;
// While both ListNodes exist
    while(head1 && head2)
    {
         sum=0;
        sum=head1->val+head2->val+carry;
        if(carry>0)
        carry=0;

        if(sum>9)
        {
            Insert(third,sum%10);
            sum=sum/10;
            carry=sum;
        }
        else{
            Insert(third,sum);
        }
        head1=head1->next;
        head2=head2->next;
    }
    // while either of the ListNode exist
    while(head1){
     sum=0;
        sum=head1->val+carry;
        if(carry>0)
        carry=0;

        if(sum>9)
        {
            Insert(third,sum%10);
            sum=sum/10;
            carry=sum;
        }
        else{
            Insert(third,sum);
        }
        head1=head1->next;
    }
 while(head2)
 {
     sum=0;
     sum=0;
        sum=head2->val+carry;
        if(carry>0)
        carry=0;

        if(sum>9)
        {
            Insert(third,sum%10);
            sum=sum/10;
            carry=sum;
        }
        else{
            Insert(third,sum);
        }
        head2=head2->next;
 }
 // Last Carry

    if(carry)
    Insert(third,carry);
   


    third=Reverse(third);

    return third;
   

 }

int main()
{
   
 ListNode *first=NULL;



Insert(first,2);
Insert(first,4);
Insert(first,9);




ListNode *second=NULL;

 
 Insert(second,5);
 
 Insert(second,6);
 
 Insert(second,4);
 
 Insert(second,9);
 
ListNode *sum =AddTwo(first,second);

print(sum);
    


    
 return 0;

}