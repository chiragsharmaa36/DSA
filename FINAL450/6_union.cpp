// Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

// Union of the two arrays can be defined as the set containing distinct elements from both the arrays.
// If there are repetitions, then only one occurrence of element should be printed in the union.

// Expected Time Complexity : O((n+m)log(n+m))
// Expected Auxilliary Space : O(n+m)
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// int doUnion(int a[], int n, int b[], int m)
// {
//     int c = n;
//     bool find;

//     for (int i = 0; i < m; i++)
//     {
//         find = false;
//         for (int j = 0; j < n; j++)
//         {
//             if (b[i] == a[j])
//             {
//                 find = true;
//                 break;
//             }
//         }
//         if(find == false)
//             c++;
//     }

//     return c;
// }

// int doUnion(int a[], int n, int b[], int m)
// {
//     int c = n;
//     bool find;

//     for (int i = 0; i < m; i++)
//     {
//         find = false;
//         int j = 0;
//         if (b[i] == a[j])
//         {
//             find = true;
//         }
//         if(find == false)
//             c++;
//         j++;
//     }

//     return c;
// }

// int doUnion(int a[], int n, int b[], int m)
// {
//     sort(a, a + n); // O(N log(N))
//     sort(b, b + m);

//     int c[n];
//     for (int i = 0; i < n; i++)
//     {
//         c[i] = a[i];
//     }

//     int count = n;

//     for (int i = 0; i < m; i++)
//     {
//         if (binary_search(a, a + n, b[i]) == false)
//             count++;
//     }

//     return count;
// }

// int doUnion(int a[], int n, int b[], int m)
// {
//     sort(a, a + n); // O(N log(N))
//     sort(b, b + m);

//     int count = n;

//     for (int i = 0; i < m; i++)
//     {
//         if (binary_search(a, a + n, b[i]) == false)
//             count++;
//     }

//     return count;
// }

// int doUnion(int a[], int n, int b[], int m)
// {
//     unordered_map<int, int> ma;
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ma[a[i]] = i;
//     }

//     for (int i = 0; i < m; i++)
//     {
//         if (ma.count(b[i]))
//         {
//             if (ma.at(b[i]) != -1)
//                 count++;
//             ma[b[i]] = -1;
//         }
//         else
//         {
//             count++;
//         }
//     }

//     for (int i = 0; i < n; i++)
//     {
//         if (ma.at(a[i]) != -1)
//             count++;
//     }
//     return count;
// }

int doUnion(int a[], int n, int b[], int m) //Optimized: O(n+m)
{
    unordered_map<int, int> ma;
    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            ma[a[i]] = i;
        else
            ma[b[i - n]] = i - n;
    }

    return ma.size(); 
}

int main()
{
    // int a[3] = {4, 5, 6};
    // int b[4] = {1, 2, 4, 6};

    int a[] = {85, 25, 1, 32, 54, 6};
    int b[] = {85, 2};

    cout << "final c = " << doUnion(a, sizeof(a) / sizeof(a[0]), b, sizeof(b) / sizeof(b[0]));
}