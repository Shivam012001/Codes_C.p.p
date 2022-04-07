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


void levelOrder(Node*root)
{
    if(root==NULL)
    return;


    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
            Node* front = q.front();
            q.pop();
            if(front!=NULL)
            {
               
                cout<<front->data<<" ";
                if(front->left)
                q.push(front->left);
                if(front->right)
                q.push(front->right);
            }
            else
            {
                
                 if(!q.empty())
                 {
                    q.push(NULL);
                 }
                 cout<<endl;
            }


    }

}


void inserterBST(Node* root,int x)
{
   
   if(root->data>x)
   {
       if(root->left)
       inserterBST(root->left,x);
       else
       root->left = new Node(x);
       
   }
   else
   {
       if(root->right)
       inserterBST(root->right,x);
       else
       root->right = new Node(x);
   }
   return;

}



int main()
{
   // BST 7 4 2 8 1 3 6 7 
//    13 7 5 12 3 6 9 15 1 4 8 10 13 17

   Node * root =NULL;
   int size;
   cin>>size;
   while(size--)
   {
       
       int x;
       cin>>x;
       if(root==NULL)
       {
            root=new Node(x);
            continue;
       }
       else{
             inserterBST(root,x);

       }
   }
     

 levelOrder(root);
 

    return 0;
}
