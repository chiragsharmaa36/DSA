// Given an array, rotate the array by one position in clock-wise direction.
// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)
#include <iostream>
#include <algorithm>
using namespace std;

void rotate(int arr[], int n)
{
    for(int i=n-1; i>0; i--)
    {
        swap(arr[i], arr[i-1]);
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    rotate(arr,5);
    return 0;
}