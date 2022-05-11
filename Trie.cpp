#include<iostream>
using namespace std;


class TrieNode{
public:
char data;
TrieNode* children[26];
bool isTerminal;


TrieNode(char ch)
{
    this->data = ch;
    isTerminal=false;
    for(int i=0;i<26;i++)
    {
        children[i]=NULL;
    }
}
};

class Trie{
public:
TrieNode* root;

Trie(){
root= new TrieNode('\0');
}

void insertUtil(TrieNode*root, string word)
{
   
  if(word.length() == 0 )
{
    root->isTerminal=true;
  
  return;
}
// assumption words will be in CAPITAL  
int index = word[0]-'A';
TrieNode*child=NULL;
// present case
if(root->children[index]!=NULL)
   {
       child = root->children[index];
       
   }
   else{// absent case
        child = new TrieNode(word[0]);
        root->children[index]=child;
   }

   // RECURSIVE CALL
   word=word.substr(1,word.size()-1);
   insertUtil(child,word);
  
 

}

void insertWord( string s)
{
    insertUtil(root,s);
    
   
    

}

bool searchUtil(TrieNode* root,string word)
{
     if(word.length()==0)
     {
        return root->isTerminal;

     }

       int index= word[0]-'A';
    TrieNode* child = root->children[index];
      
      if(child==NULL)
      return false;
      
     word=word.substr(1,word.size()-1);
      return searchUtil(child,word);
      


}

void search(string word)
{
    
   if( searchUtil(root,word))
   cout<<"Word is found";
   else
   cout<<"Word is not found";   
}

void deleteUtil(TrieNode*root, string word)
{
   if(word.length()==0)
   {
       if(root->isTerminal==true)
       root->isTerminal=false;
       return;
   }
    int index = word[0]-'A';
    TrieNode*child = root->children[index];

word=word.substr(1,word.size()-1);
    deleteUtil(child,word);


}

void deleteNode(string word)
{
    deleteUtil(root,word);

}

};


int main()
{
    Trie* t=new Trie();     
   
    t->insertWord("ARM");
     t->insertWord("DO");
      t->insertWord("TIME");
    

    
    

    
  


    return 0;
}