
#include<bits/stdc++.h>
using namespace std;


// Insert at the last in stack
void Insert(stack<int>&s,int ele)
{
  if(s.size()==0)
  s.push(ele);
  else{
  int x=s.top();
  s.pop();
  Insert(s,ele);
  s.push(x);
  }

}

// Reverse the stack using recursion
void Reverse(stack<int>&s)
{
   if(s.size()==1)
   return;
  
  int x=s.top();
  
  s.pop();
Reverse(s);
  Insert(s,x);

}

// Print subset of a string
void Subset(string ip,string op,vector<string>&v)
{
  if(ip.length()==0)
  {
    cout<<op<<endl;
    v.push_back(op);
    return;
  }
string op1=op;
string op2=op; 
op2.push_back(ip[0]);
ip.erase(ip.begin()+0);

Subset(ip,op1,v);

Subset(ip,op2,v);

}

void permuteSpace(string op,string ip)
{
  if(ip.length()==0)
  {
    cout<<op<<endl;
    return;
  }
  string op1=op+"_"+ip[0];
  string op2=op+ip[0];
  ip.erase(ip.begin()+0);

  permuteSpace(op1,ip);
  permuteSpace(op2,ip);

}

void permuteCase(string op, string ip)
{
  if(ip.length()==0)
  {
    cout<<op<<endl;
    return;
  }
   string op1=op;
   op1+=(ip[0]-32);
   string op2=op+ip[0];
   ip.erase(ip.begin()+0);

   permuteCase(op1,ip);
   permuteCase(op2,ip);

}

void mixCase(string op, string ip)
{
       if(ip.length()==0)
    {
        cout<<op<<endl;
         return;
    }
    string op1=op;
    string op2=op;

    char x=ip[0];
    if(x>93)
    {
       op2+=x;
       x-=32;
       op1+=x;
    }
    else if(x>64){
      op1+=x;
      x+=32;
      op2+=x;
    }
    
    else
    {
      op1+=ip[0];
      op2+=ip[0];
    }


ip.erase(ip.begin()+0);

// Calling functions
mixCase(op1,ip);
mixCase(op2,ip);

}

void parenthesis(string op,int open,int close)
{
     if(open==0 && close==0)
     {
       cout<<op<<endl;
       return;
     }

    string op1=op;
     if(open!=0 && open==close)
     {
        
       op1+="(";
       parenthesis(op1,open-1,close);
     }
     else if(open==0 && close!=0)
     {
         op1+=")";
         
         parenthesis(op1,open,close-1);
     }
     else 
     {
       string op2=op;
       op1+="(";
       op2+=")";
       parenthesis(op1,open-1,close);
       parenthesis(op2,open,close-1);
     }

}

void binaryPrefix(string ip)
{
   if(ip.length()==0)
   return;
 
   int ones=0,zeroes=0;
   for(int i=0;i<ip.size();i++)
   {
     if(ip[i]=='1')
     ones++;
     else
     zeroes++;
   }
   if(ones>=zeroes)
   cout<<ip<<endl;
 

   ip.pop_back();
   binaryPrefix(ip);

}

string numberToBinary(int n)
{
  string str;
  while(n!=0)
  {
    int rem=n%2;
    str+=rem+48;
    n=n/2;
  }
  reverse(str.begin(),str.end());
  return str;
}

void binaryPREFIX(int n,string op,int o=0,int z=0)
{
    if(n==0)
    {
        cout<<op<<endl;
        return;
    }

string op1=op;
op1+='1';

    if(o==z)
    { 
        binaryPREFIX(n-1,op1,o+1,z);
    
    }
    else
    {
        binaryPREFIX(n-1,op1,o+1,z);
        string op2=op;
        op2+="0";
        binaryPREFIX(n-1,op2,o,z+1);
    }
    
}


int main()
{
   
  // string ip,op="";
  // cout<<"Enter the string \n";
  // getline(cin,ip);

 int n;
 cout<<"Enter the number \n";
 cin>>n;
string ip=numberToBinary(n);
cout<<"Binary representation = "<<ip<<endl;
binaryPrefix(ip);
 

 
    return 0;
}