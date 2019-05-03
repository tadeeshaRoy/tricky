/*

Problem Statement: 
===================

Given positive integers from 1 to n in an array containing n-1 elements like below:

n=5
numbers: 1, 2, 3, 5 -> n-1 elements

find the missing element from 1 to n. In the case above, it is element 4.

Strategy:
=========

1. Calculate sum of existing elements and substract the sum from the sum of natural numbers from 1 to n, which is [n(n+1)]/2, as below:

Example: n = 5

sum of natural numbers from 1 to 5 is 15

array given: 1, 2, 3, 5 -> sum is 11

Hence missing number is 15 - 11 which is 4.

Time Complexity: O(n) during calculating sum of the array.

Drawback: possible out of bounds violation while multiplying n*(n+1)

2. Constructing a map with keys 1 to n and maintaining a flag for the presence of the element in the array.

Drawback: extra space utilization is proportional to the number of elements

3. (Optional) arr[abs(arr[i])-1]*=-1; and then answer would be i+1 for positive element after modification.

Edge case: arr[i]=n solution: swap the element with the last element and decrement array elements to compare.

Example: 

n = 5

array = {1,5,4,2}

modified array = {-1,-2,4,-5}

third element (i=2) is positive. Hence output is i+1 = 3

*/

#include<iostream>
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n = 6;
    int arr[6]={1, 7, 5, 3, 6, 4};
    for(int i=0;i<n;i++)
    {
        if(abs(arr[i])==(n+1))
        {
            swap(&arr[i],&arr[n-1]);
            n--;
        }

        arr[abs(arr[i])-1]*=-1;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {  
            std::cout<<i+1;
            break;
        }
    }
    return 0;
}
