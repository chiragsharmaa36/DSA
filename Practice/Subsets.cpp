#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(vector<int> &A, vector<vector<int>> &ans, vector<int> temp, int index, int n)
    {
        if (index == n)
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(A[index]);
        solve(A, ans, temp, index + 1, n);
        temp.pop_back();
        solve(A, ans, temp, index + 1, n);
    }

public:
    vector<vector<int>> subsets(vector<int> &A)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        int n = A.size();
        solve(A, ans, temp, 0, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        vector<int> array;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            array.push_back(x);
        }

        Solution ob;
        vector<vector<int>> res = ob.subsets(array);

        // Print result
        for (int i = 0; i < res.size(); i++)
        {

            for (int j = 0; res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}