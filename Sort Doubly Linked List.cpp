#include<iostream>

using namespace std;

class Node{
	  public:
	  int data;
	  Node* next;
	  Node* prev;

	  Node(int data)
	  {
		  this->data = data;
		  next=prev=NULL;
	  }
};

Node* createDDL(Node*root,int &data)
{
	if(root==NULL)
	{
		root = new Node(data);
		return root;
	}

     Node* curr =  createDDL(root->next,data);

      root->next=curr;
	  curr->prev = root;

	  return root;

}

Node* mergeTwo(Node* root1, Node*root2)
{
	  if(root1==NULL && root2==NULL)
		return NULL;
	if(root1==NULL)
		return root2;
	if(root2==NULL)
		return root1;
	
Node* head = NULL;
	Node* tail = NULL;
	
	if(root1->data<=root2->data)
	{
		head = tail = root1;	
		root1=root1->next;
	}
	else
	{head = tail = root2;
	 root2=root2->next;
	}
	while(root1!=NULL && root2!=NULL)
	{
		if(root1->data<=root2->data)
	{
		tail->next=root1;
			tail = root1;
			root1=root1->next;
	}
		else{
			tail->next=root2;
			tail=root2;
			root2=root2->next;
		}
	}
	
	if(root1)
		tail->next=root1;
	if(root2)
		tail->next=root2;
	
	return head;
	
}
Node* getMiddle(Node*root)
{
	if(root==NULL)
	return root;
	Node*fast= root->next;
	Node*slow=root;

	while(fast && slow)
	{
		fast=fast->next;
		if(fast)
		fast=fast->next;
		else
		break;
		slow=slow->next;
	}
	return slow;

}

Node* mergeSort(Node*root)
{
     if(root==NULL || root->next==NULL)
	 return root;

	 Node* mid = getMiddle(root);
	 Node* right = mid->next;
	 mid->next=NULL;

	 root = mergeSort(root);
	 right = mergeSort(right);

	 return mergeTwo(root,right);
}


int main() {
	// Your code goes here;

Node*root1=NULL;
	 int arr2[]={100,80,70,50,30,10};
	 for(int i=0;i<6;i++)
	 root1= createDDL(root1,arr2[i]);
    

      

	 root1 = mergeSort(root1);
Node*temp =root1;


	 while(temp)
	 {
		 cout<<temp->data<<' ';
		 temp = temp->next;
	 }




	return 0;
}