#include <iostream>
#include <CLIMITS>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// long long maxSubarraySum(int arr[], int n) //Brute-Force✅
// {
//     int sum = 0; int max_sum = INT_MIN;
//     for(int i=0; i<n; i++)
//     {
//         sum = 0;
//         for(int j=i; j<n;j++)
//         {
//             sum = sum + arr[j];
//             max_sum = max(sum, max_sum);
//         }
//     }

//     return max_sum;
// }

long long maxSubarraySum(int arr[], int n) // O(N) ✅
{
    // Logic: Discard that subarray which gives a negative no.
    int sum =0; int maxSum = INT_MIN;
    for(int i=0; i<n; i++)
    {
        sum = sum + arr[i];
        maxSum = max(sum, maxSum);
        cout<< "sum = "<<sum<<endl;
        if(sum<0)
        {
            sum = 0;
            continue;
        }
    }

    return maxSum;
}

// long long maxSubarraySum(int arr[], int n)
// {

//     // Your code here
//     long long int sum =0;
//     int largest = arr[0];
//     int largIndex = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > largest)
//         {
//             largest = arr[i];
//             largIndex = i;
//         }
//     }

//     int arrLeft[largIndex];
//     int arrRight[n - (largIndex + 1)];

//     int leftSum = largest;
//     int rightSum = largest;
//     int i = largIndex - 1;
//     while (i >= 0)
//     {
//         arrLeft[i] = arr[i];
//         leftSum = leftSum + arr[i];
//         i--;
//     }

//     i = largIndex + 1;
//     int j = 0;
//     while (i < n)
//     {
//         if(j< n - (largIndex + 1))
//             arrRight[j] = arr[i];
//         rightSum = rightSum + arr[i];
//         i++;
//         j++;
//     }

//     if (leftSum > largest || rightSum > largest)
//     {
//         if (leftSum > rightSum)
//             sum = leftSum;
//         else
//             sum = rightSum;
//     }
//     else
//         sum = largest;

// cout<<"arrLeft"<<endl;
// print(arrLeft, largIndex);
// cout<<"arrRight"<<endl;
// print(arrRight, n - (largIndex + 1));

//     if (sum < maxSubarraySum(arrLeft, largIndex))
//         return maxSubarraySum(arrLeft, largIndex);
//     else if (sum < maxSubarraySum(arrRight, n - (largIndex + 1)))
//         return maxSubarraySum(arrRight, n - (largIndex + 1));
//     else
//         return sum;
// }

int main()
{
    // int arr[9] = {5, 3, -4, -5, 6, 1, 2, -3, 1};
    // int arr[4] = {-1,4,7,2};
    int arr[4] = {-4,-3,-2,-1};
    cout << maxSubarraySum(arr, 4);
}