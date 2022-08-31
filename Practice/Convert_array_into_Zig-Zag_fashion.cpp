// Given an array arr of distinct elements of size N, the task is to rearrange the elements of the array in a zig-zag fashion so that the converted array should be in the below form:

// arr[0] < arr[1]  > arr[2] < arr[3] > arr[4] < . . . . arr[n-2] < arr[n-1] > arr[n].

// NOTE: In the mentioned complexity, only a unique solution will exist.

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

#include <iostream>
#include <algorithm>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void zigZag(int arr[], int n) // Optimized: O(n)
{

    bool flag = true; // ...'<'...
    for (int i = 0; i < n - 1; i++)
    {
        /* "<" relation expected 👇🏻 BUT if ">" is there, then swap. */
        if (arr[i] > arr[i + 1] && flag == true)
            swap(arr[i], arr[i + 1]);
        /* ">" relation expected 👇🏻 BUT if "<" is there, then swap. */
        else if (arr[i] < arr[i + 1] && flag == false)
            swap(arr[i], arr[i + 1]);

        flag = !flag; /* flip flag */
    }
}

int main()
{
    // int arr[] = {4, 3, 7, 8, 6, 2, 1};
    // // o/p: 3 < 7 > 4 < 8 > 2 < 6 > 1
    int arr[] = {1, 4, 3, 2};
    // o/p: 1 < 4 > 2 < 3

    zigZag(arr, sizeof(arr) / sizeof(arr[0]));
    print(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}