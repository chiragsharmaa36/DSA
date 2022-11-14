// Given an integer x, find the square root of x. If x is not a perfect square, then return floor(√x).

// Your Task:
// You don't need to read input or print anything. The task is to complete the function floorSqrt() which takes x as the input parameter and return its square root.
// Note: Try Solving the question without using the sqrt function. The value of x>=0.

// Expected Time Complexity: O(log N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ x ≤ 10^7

// Function to find square root
// x: element to find square root

long long int floorSqrt(long long int x)
// binary search algo
// idea: sq. root of a no. is b/w 1 to that no.
// Time - O(log N)
{
    // Your code goes here
    long int low = 0, high = x;
    while (low <= high)
    {
        long int mid = (low + high) / 2;
        if (mid * mid > x)
            high = mid - 1;
        else if (mid * mid < x)
            low = mid + 1;
        else
            return mid;
    }
    return high;
}