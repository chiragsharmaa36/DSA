// Merge Without Extra Space
// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order without using any extra space. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
// Expected Time Complexity:  O((n+m) log(n+m))
// Expected Auxilliary Space: O(1)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void print(long long arr[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// void merge(long long arr1[], long long arr2[], int n, int m)
// {
//     int i = n-1, j = 0;
//     while (i >= 0 && j < m)
//     {
//         while (arr1[i] < arr2[j] && j < m)
//         {
//             j++;
//         }
//         if(arr1[i] > arr2[j])
//         swap(arr1[i], arr2[j]);
//         j=i;
//         i--;
//     }

//     // sort(arr1, arr1+n);
//     // sort(arr2, arr2+m);
// }

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        while (arr1[i] < arr2[j] && j < m)
        {
            j++;
        }
        if (arr1[i] > arr2[j])
            swap(arr1[i], arr2[j]);
        j = i;
        i--;
    }

    // print(arr1, n);
    // print(arr2, m);
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{
    long long arr1[] = {1, 3, 5, 7};
    long long arr2[] = {0, 2, 6, 8, 9};

    merge(arr1, arr2, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr2) / sizeof(arr2[0]));

    print(arr1, sizeof(arr1) / sizeof(arr1[0]));
    print(arr2, sizeof(arr2) / sizeof(arr2[0]));

    return 0;
}