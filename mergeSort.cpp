/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void mergeTwo(int a[],int start,int mid,int end)
{
    int b[end+1]; 
    
   int i=start;
   int j=mid+1;
   int k=0;
   while(i<=mid && j<=end)
   {
       if(a[i]<=a[j])
        b[k]=a[i++];
        
       else
       b[k]=a[j++];
       
       k++;
       
   }
   
  while(i<=mid)
  b[k++]=a[i++];
   
  while(j<=end)
  b[k++]=a[j++];
   
  k=0;

// for(int i=0;i<=end;i++)
// cout<<" "<<b[i];

for(int i=start;i<=end;i++)
a[i]=b[k++];


    
}


void mergeSort(int a[],int start,int end)
{
    if(start>=end) return;
    
    int mid = start + (end-start)/2;
    
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);
    
    mergeTwo(a,start,mid,end);
    
}
int main()
{
    int size=10;
  int a[]={10,9,8,7,6,5,4,3,2,1};
  int start=0;
  int end=size-1;
  
  mergeSort(a,start,end);
  
for(int i=0;i<size;i++)
cout<<" "<<a[i];

    return 0;
}
