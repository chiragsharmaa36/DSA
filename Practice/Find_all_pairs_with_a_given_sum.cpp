// Find all pairs with a given sum
// Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.
// Your task is to complete the function allPairs() which takes the array A[], B[], its size N and M respectively and an integer X as inputs and returns the sorted vector pair values of all the pairs u,v where u belongs to array A and v belongs to array B. If no such pair exist return empty vector pair.
// Note : All pairs should be printed in increasing order of u. For eg. for two pairs (u1,v1) and (u2,v2), if u1<u2 then (u1,v1) should be printed first else second.

// Expected Time Complexity: O(NLog(N))
// Expected Auxiliary Space: O(N)

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> allPairs(int A[], int B[], int N, int M, int X) // Optimized: O(Nlog(N))
{
    vector<pair<int, int>> vect;
    sort(A, A + N); // We want the pair vector in sorted order.
    unordered_map<int, int> m;

    for (int i = 0; i < M; i++)
    {
        m[B[i]] = i;
    }

    for (int i = 0; i < N; i++)
    {
        if (m.count(X - A[i]))
        {
            vect.push_back(make_pair(A[i], X - A[i]));
        }
    }

    return vect;
}

int main()
{
    int A[] = {1, 2, 4, 5, 7};
    int B[] = {5, 6, 3, 4, 8};
    int X = 9;

    vector<pair<int, int>> vect = allPairs(A, B, sizeof(A) / sizeof(A[0]), sizeof(B) / sizeof(B[0]), X);

    for (int i = 0; i < vect.size(); i++)
    {
        cout << vect[i].first << " "
             << vect[i].second << endl;
    }

    return 0;
}