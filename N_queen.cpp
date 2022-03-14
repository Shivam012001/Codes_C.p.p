#include<iostream>
using namespace std;

int totalQueen=4;

bool safe(int mat[4][4],int row,int col)
{
    int size=4;
    //Check for row
    int newRow = row-1;
    while(newRow>=0)
    {
        if(mat[newRow][col]==1)
        return false;
        newRow--;
    }

    // check col
    int newCol = 0;

    while(newCol<size)
    {
        if(mat[row][newCol]==1)
        return false;
        newCol++;
    }

    //check left diagonal
    newRow =row-1;
    newCol =col-1;

    while(newRow>=0 && newCol>=0)
    {
        if(mat[newRow][newCol]==1)
        return false;
        newRow--;
        newCol--;
    }

     // Check right diagonal

     newRow = row-1;
     newCol=col-1;

     while(newRow>=0 && newCol<size)
     {
         if(mat[newRow][newCol]==1)
         return false;
         newRow--;
         newCol++;
     }

    return true;
  
}

                 // Checking Queens

bool nQueen(int mat[4][4], int row, int col, int nOQ)
{
     if(row==4) // if row is out of bound
     {
   for(int i=0;i<4;i++)
   {
    for(int j=0;j<4;j++)
    cout<< mat[i][j];

    cout<<endl;
}

cout<<endl;

     }

     // check all the possibilities of given row

     for(int col=0;col<4;col++)
     {
         if(safe(mat,row,col))
         {
               // It's safe to give an one
               mat[row][col]=1;

               // check if rest is true
               if(nQueen(mat,row+1,col,nOQ))
               return true;

               //If upper statement is not true
               // not a right place to place a queen 
               // make it zero
               mat[row][col]=0;

         }


     }

     // After so many iterations couldn't get the answer
       return false;

}






int main()
{

int mat[4][4];
for(int i=0;i<4;i++)
{
    for(int j=0;j<4;j++)
    mat[i][j]=0;
}

nQueen(mat,0,0,0);



return 0;

}