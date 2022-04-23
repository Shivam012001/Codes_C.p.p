#include<iostream>
using namespace std;



class heap{
public:
int arr[100];
int size;

heap(){
    arr[0]=-1;
    size=0;
}


void insert(int val){

 arr[++size]=val;
 int index=size;

 while(index>1)
 {
     int parent = index/2;
     if(arr[parent]<arr[index])
     {swap(arr[parent],arr[index]);
     index=parent;
    }
    else
    return;


}
}

void print()
{
    for(int i=1;i<=size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

void deleteFromHeap()
{
    if(size==0)
    {cout<<" Nothing to delete "<<endl;
         return;
    }
    // Last element goes to first and the size decreases by one
    arr[1]=arr[size--];

    int i=1;
    while(i<size)
    {
       int left = 2*i;
       int right = (2*i)+1;

if(right<size && arr[i]<arr[right])
    {
        swap(arr[i],arr[right]);
        i=right;
    }
      
    else if(left<size && arr[i]<arr[left])
       {swap(arr[i],arr[left]);
         i=left;
       }

    else
    return;    
    
    }


     


}




};

void heapify(int arr[],int size,int i)
{
    int largest=i;
    int left=2*i;
    int right= 2*i + 1;

    if(left<=size && arr[largest]<arr[left])
    {
       
        largest=left;
    }
     if(right<=size && arr[largest]<arr[right])
    {
        
        largest=right;
    }

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        heapify(arr,size,largest);
    }

}

void heapifyMin(int arr[],int n,int i)
{
    int smallest=i;
    int left=2*i +1;
    int right= 2*i +2;

    if(left<n && arr[smallest]>arr[left])
    {
       
    smallest=left;
    }
    if(right<n && arr[smallest]>arr[right])
    {
        
        smallest=right;
    }

    if(smallest!=i)
    {
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }

}




int main()
{

   // heap sort
   int arr[6]={-1,5,4,3,2,1};
   int n=5;
   while(n>1)
   {
       swap(arr[1],arr[n]);
       n--;
       heapify(arr,n,1);
   }
for(int i=1;i<=5;i++)
cout<<arr[i]<<" ";



    return 0;
}