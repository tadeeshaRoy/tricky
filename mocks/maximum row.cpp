/*

Given a 2D array where each row consists of a sorted array of binary digits, find the row with the maximum number of truths.

Example: 

array:

[ [ 0 0 0 0 1 ]
  [ 0 1 1 1 1 ]
  [ 0 0 1 1 1 ]
  [ 0 0 0 1 1 ] ]
  
 
 here row with maximum number of truths is second one
 
 Solution is done in O(m+n) time complexity and O(1) space complexity.Traversal is done in following manner:
  
  We traverse from end of the row and whenever a 0 is encountered, we take step back to the previous 1 and move down a row
  
             |
            \|/
 
 [ [ 0 0 0 0 1 ]
        <----     
   [ 0 1 1 1 1 ]
       |
      \|/  
   [ 0 0 1 1 1 ]
       |
      \|/
   [ 0 0 0 1 1 ] ] //end

*/

#include<iostream>
using namespace std;

int findMaxRow(int arr[4][5], int m, int n)
{
    int col = n - 1, row = 0, mxrow = 0, mincol = n - 1;

    while(row<m)
    {
        int j;
        for(j=col;j>=0;j--)
        {
            if(arr[row][j]==0)
            {
                col = j+1;
                break;
            }
        }
        if(j==-1)
        {
            col = mincol=0;
            mxrow = row;
            break;
        }
        else if(mincol > col)
        {
            mxrow = row;
            mincol = col;
        }
        else col = mincol;

        row++;
    }

    return mxrow;
}

int main()
{
    int m = 4, n = 5;

    int arr[4][5]={ {0, 0, 0, 0, 1},
                    {0, 1, 1, 1, 1},
                    {0, 0, 1, 1, 1},
                    {1, 1, 1, 1, 1}};
    
    int row = findMaxRow(arr,m,n) + 1;
    cout<<"Maximum number of 1s is in row: "<<row;
    return 0;
}
