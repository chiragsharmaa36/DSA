// Find the "Kth" max and min element of an array
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(log(n))
#include <iostream>
#include <algorithm>

using namespace std;

// k is the kth smallest number

int kth(int arr[], int l, int r, int k)
{
    sort(arr, arr + r + 1); // Time: O(N log(N))
    return arr[k - 1];
}

int main()
{
    int arr[6] = {7, 10, 4, 3, 20, 15};
    int k = 3;
    // output: 7
    cout << kth(arr, 0, 5, k);
}