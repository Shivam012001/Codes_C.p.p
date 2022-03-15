#include<bits/stdc++.h>

using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;

   Node()
   {
       left=NULL;
       right=NULL;
   }
Node(int data)
{
       this->data=data;
       left=NULL;
       right=NULL;
}

};


                                 //Building a tree
 
Node* buildTree(Node* root)
{

   int data;
   cout<<"Enter the data \n";
   cin>>data;


 root = new Node(data);
  
   

if(data== -1)
return NULL;


cout<<endl<<"Enter data for inserting in left of "<<root->data<<endl;


root->left= buildTree(root->left);

cout<<endl<<"Enter data for inserting in right of "<<root->data<<endl;

root->right= buildTree(root->right);

return root;


}



                          //   Level order traversal



void levelOrder(queue<Node*>&q)
{
    if(q.empty())
    return;

    Node* root = q.front();
    q.pop();
    

    cout<<root->data<<" ";

    if(root->left!=NULL)
    q.push(root->left);

    if(root->right!=NULL)
    q.push(root->right);

    levelOrder(q);     



}

                                                   // PreOrder Traversal

void preOrder(Node* root)
{
    if(root==NULL)
    return;
     
     cout<<" "<<root->data;

     preOrder(root->left);

     preOrder(root->right);


}
     
void inOrder(Node* root)
{
    if(root==NULL)
    return;

    inOrder(root->left);
     
     cout<<" "<<root->data;

     

     inOrder(root->right);


}

void postOrder(Node* root)
{
    if(root==vNULL)
    return;

     postOrder(root->left);
    
     postOrder(root->right);

     cout<<" "<<root->data;
}

     




int main()
{
    Node* root=NULL;

 // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);



//    queue<Node*>q;

//    q.push(root);

//    levelOrder(q);
    

// preOrder(root);
// inOrder(root);
// postOrder(root);

    
    return 0;
}