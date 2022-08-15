// Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader.
// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> leaders(int a[], int n)
{

    vector<int> leaders{a[n - 1]};
    int maxi = 0;
    for (int i = n - 1; i > 0; i--)
    {
        maxi = max(maxi, a[i]); 
        cout<<maxi<<endl;
        if (a[i - 1] >= maxi){
            leaders.push_back(a[i - 1]);
            cout<<"a[i-1] = "<<a[i-1]<<endl;
        }
    }

    reverse(leaders.begin(), leaders.end()); // O(n)
    return leaders;
}

int main()
{
    int a[] = {63, 70, 80, 33, 33, 47, 20};
    // int a[] = {1,2,3,4,0};
    vector<int> v = leaders(a, sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}