// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// string isSubset(int a1[], int a2[], int n, int m) //Optimised: O(n)
// {
//     unordered_map<int, int> map1; // <no., no. of occurrences>
//     // unordered_set<int> s; // set stores unique values of a2 elements.
//     unordered_map<int, int> map2; // <no., no. of occurrences>
//     // unordered_set<int> s; // set stores unique values of a2 elements.

//     // for (int i = 0; i < m; i++)
//     // {
//     //     s.insert(a2[i]);
//     // }

//     for (int i = 0; i < n; i++)
//     {
//         if(map1.count(a1[i]))
//             map1[a1[i]] = map1.at(a1[i])+1;
//         else
//             map1[a1[i]] = 0;
//     }

//     for (int i = 0; i < m; i++)
//     {
//         if(map2.count(a2[i]))
//             map2[a2[i]] = map2.at(a2[i])+1;
//         else
//             map2[a2[i]] = 0;
//     }

//     int count = 0;
//     // unordered_set<int>::iterator it = s.begin();
//     for (auto i:map2)
//     {
//         if (map1.find(i.first) != map1.end()) // another method to check if a key is present in the map or not.
//         {
//             if((map1.at(i.first)>=map2.at(i.first)))
//             count++;
//         }
//     }

//     if (count == map2.size())
//         return "Yes";
//     else
//         return "No";
// }

string isSubset(int a1[], int a2[], int n, int m) //Optimised: O(n)
{
    unordered_map<int, int> map1; // <no., no. of occurrences> // a1 array
    unordered_map<int, int> map2; // <no., no. of occurrences> // a2 array

    for (int i = 0; i < n; i++)
    {
        if(map1.count(a1[i]))
            map1[a1[i]] = map1.at(a1[i])+1;
        else
            map1[a1[i]] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        if(map2.count(a2[i]))
            map2[a2[i]] = map2.at(a2[i])+1;
        else
            map2[a2[i]] = 0;
    }

    int count = 0;
    for (auto i:map2) // traversing map2.
    {
        if (map1.find(i.first) != map1.end()) // another method to check if a key is present in the map or not.
        {
            if((map1.at(i.first)>=map2.at(i.first)))
            count++;
        }
    }

    if (count == map2.size())
        return "Yes";
    else
        return "No";
}

int main()
{
    // o/p: no👇🏻
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int a2[] = {1, 2, 3, 1};
    // // o/p: yes👇🏻
    // int a1[] = {1, 2, 3, 4, 5, 1, 1, 1};
    // int a2[] = {1, 2, 3, 1};

    cout << isSubset(a1, a2, sizeof(a1) / sizeof(a1[0]), sizeof(a2) / sizeof(a2[0]));

    return 0;
}