// Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an element that appears more than N/2 times in the array.

// Your Task:
// The task is to complete the function majorityElement() which returns the majority element in the array. If no majority exists, return -1.
 
// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ N ≤ 10^7
// 0 ≤ Ai ≤ 10^6


// Function to find majority element in the array
// a: input array
// size: size of input array

// https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/

#include<bits/stdc++.h>
using namespace std;

// Boyer-Moore Majority Voting Algorithm
// idea: If an element comes more than N/2 times, then atleast once it will be adjacent to each other or will be the last element in case of odd N.
/* Function to find the candidate for Majority */
int findCandidate(int a[], int size)
{
    int maj_index = 0, count = 1;
    for (int i = 1; i < size; i++) {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

/* Function to check if the candidate
   occurs more than n/2 times */
bool isMajority(int a[], int size, int cand)
{
    int count = 0;
    for (int i = 0; i < size; i++)

        if (a[i] == cand)
            count++;

    if (count > size / 2)
        return 1;

    else
        return 0;
}

/* Function to print Majority Element */
void printMajority(int a[], int size)
{
    /* Find the candidate for Majority*/
    int cand = findCandidate(a, size);

    /* Print the candidate if it is Majority*/
    if (isMajority(a, size, cand))
        cout << " " << cand << " ";

    else
        cout << "No Majority Element";
}

/* Driver code */
int main()
{
    int a[] = { 1, 3, 3, 1, 2 };
    int size = (sizeof(a)) / sizeof(a[0]);

    // Function calling
    printMajority(a, size);

    return 0;
}