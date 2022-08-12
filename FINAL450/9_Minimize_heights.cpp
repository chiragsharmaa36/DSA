#include <iostream>
#include <climits>
#include <Algorithm>
#include <math.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// int getMinDiff(int arr[], int n, int k)
// {
    
//     int diff;
//     sort(arr, arr + n); // Nlog(N)
//     print(arr, n);
//     cout << endl;
//     diff = arr[n - 1] - arr[0];
//     int min = arr[0];
//     int max = arr[n - 1];
//     for (int i = 1; i < n; i++)
//     {
//         // if (arr[i] == k)
//         //     continue;

//         if (arr[i] >= k)
//         { 
//             arr[i] = std::min(min, arr[i]-k);
//             // arr[i] = arr[i] - k;
//         }
//         else
//         { 
//             arr[i] = std::max(max,arr[i]+k);
//             // arr[i] = arr[i] + k;
//         }
//         diff = std::min(diff, arr[i]-arr[i-1]);
//     }
//     print(arr, n);
//     cout << endl;

//     sort(arr, arr + n); // Nlog(N)
//     print(arr, n);
//     cout << endl;
//     // max = std::min(max, arr[n - 1]);
//     // min = std::max(min, arr[0]);
//     // int diff = std::min(arr[n-1]-arr[0], diffSimple);

//     return diff;
// }

// int getMinDiff(int arr[], int n, int k)
// {
//      for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= k)
//             arr[i] = arr[i] - k;
//         else
//             arr[i] = arr[i] + k;
//     }

// int count=0;
// for(int i=0; i<n; i++)
// {
//     if(arr[i]<=0)
//         count++;
// }

//    sort(arr, arr + n); // Nlog(N)
//    print(arr,n);

//     int diff = arr[n - 1] - arr[0];
//     return diff;
// }

// int getMinDiff(int arr[], int n, int k)
// {
//     int min = INT_MAX;

//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] >= k)
//         {
//             min = std::min(min, arr[i]);
//             if (arr[i] - k >= (2 * k - 1) && arr[i] + k >= (2 * k - 1))
//                 arr[i] = std::min(arr[i] + k, arr[i] - k);
//             else if (arr[i] - k >= (2 * k - 1))
//             {
//                 if (arr[i] + k >= k)
//                     arr[i] = arr[i] + k;
//                 else
//                     arr[i] = arr[i] - k;
//             }
//             else if (arr[i] + k >= (2 * k - 1))
//             {
//                 if (arr[i] - k >= k)
//                     arr[i] = arr[i] - k;
//                 else
//                     arr[i] = arr[i] + k;
//             }
//             // else
//             // {
//             //     arr[i] = std::min(arr[i] + k, arr[i] - k);
//             // }
//             arr[i] = std::min(min, arr[i]);
//         }
//         else
//         {
//             arr[i] = arr[i] + k;
//         }
//     }

//     cout << "Before sort" << endl;
//     print(arr, n);
//     sort(arr, arr + n); // Nlog(N)
//     cout << "After sort" << endl;
//     print(arr, n);
//     cout << endl;
//     int diff = arr[n - 1] - arr[0];

//     return diff;
// }


int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n); // Nlog(N)
     print(arr,n);
    cout<<endl;
    int Diff = arr[n-1] - arr[0];
    
    // Two-pointer method // Nlog(N)
    int i = 0; int j = n-1;
    
    while(i<j)
    {
        if(arr[j] - arr[i] >= Diff)
            {
                arr[j] = arr[j] - k;
                arr[i] = arr[i] + k;
                Diff = abs(arr[j] - arr[i]);
                cout<<Diff<<endl;
                i++;
                j--;
            }
            else
            {
                i++;
                j--;
            }
    }
    print(arr,n);
    cout<<endl;
    return Diff;
}

int main()
{
    int arr[10] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1}; // k=5; output:7
    // int arr[10] = {5, 5, 8, 6, 4, 10, 3, 8, 9, 10}; // k=5; output:7
    // int arr[4] = {1, 5, 8, 10};    // k=2; output:5
    cout << getMinDiff(arr, 10, 5); // Output: 7
}