// Your Task:
// The task is to complete the function countOne() which takes the array arr[] and its size N as inputs and returns the count of 1s in the input array.

// Expected Time Complexity: O(LogN).
// Expected Auxiliary Space: O(1).

// Constraint:
// 1 <= N <= 5*10^6
// arr[i] = 0,1

// Function to count number of Ones
// arr: input array
// N: size of input array
int countOnes(int arr[], int N) // binary search algo
// O(logN)
{
    // Your code here
    int i = 0, j = N - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;

        if (arr[mid] == 0)
            j = mid - 1;
        if (arr[mid] == 1)
        {
            if ((arr[mid + 1] == 0 && mid + 1 < N) || (mid == N - 1))
                return mid + 1;
            else if (arr[mid + 1] == 1 && mid + 1 < N)
                i = mid + 1;
        }
    }
    return 0;
}