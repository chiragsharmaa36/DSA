// Minimum number of jumps
// Given an array of N integers arr[] where each element represents the max length of the jump that can be made forward from that element. Find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then you cannot move through that element.

// Note: Return -1 if you can't reach the end of the array.

// Expected Time Complexity: O(N)
// Expected Space Complexity: O(1)

#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

// int minJumps(int arr[], int n) // Time Limit Exceeded.
// {
//     int jump = 0;
//     for (int i = 0; i < n;)
//     {
//         int max_jump = arr[i]; // each element represents the max length of the jump that can be made forward from that element.

//         int index_to_go;
//         if (arr[i] == 0 && i != n - 1)
//         {
//             jump = -1;
//             break;
//         }

//         if (i == n - 1)
//             break;

//         int big_jump_no = 0;
//         for (int j = i + 1; j <= max_jump + i; j++)
//         {
//             // find index_to_go

//             if (arr[j] > big_jump_no)
//             {
//                 big_jump_no = arr[j];
//                 index_to_go = j;
//             }

//             if (index_to_go == n - 1)
//                 break;
//         }

//         i = index_to_go;
//         // cout<<i<<endl; // debug
//         jump++;
//     }

//     return jump;
// }

int minJumps(int arr[], int n)
{
    int jump = 0;
    int pos = 0;
    int des = 0;

    for (int i = 0; i < n - 1; i++)
    {
        des = max(des, arr[i] + i); // 1 4 7 11 13

        if (pos == i) // i--> 0 1 4
        {
            pos = des; // 1 4 13
            jump++;
        }
    }
    if (pos >= n - 1)
        return jump;
    else
        return -1;
}

int main()
{
    // int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}; // o/p: 3
    // int arr[] = {1, 4, 3, 2, 6, 7}; //o/p: 2
    // int arr[] = {2, 3, 1, 1, 4}; // o/p: 2
    // int arr[] = {2, 3, 0, 1, 4}; // o/p: 2
    // int arr[] = {3, 2, 1}; // o/p:1
    int arr[] = {0, 1, 1, 1, 1}; // o/p:-1

    cout << "jump = " << minJumps(arr, sizeof(arr) / sizeof(arr[0]));

    return 0;
}
