// Longest Common Prefix in an Array
// Given a array of N strings, find the longest common prefix among all strings present in the array.
// Expected Time Complexity: O(N*max(|arri|)).
// Expected Auxiliary Space: O(max(|arri|)) for result.

#include <iostream>
#include <string>
using namespace std;

string longestCommonPrefix(string arr[], int N)
{
    string s = "";
    int max_len = 0;
    for (int i = 0; i < N; i++)
    {
        int ar_len = arr[i].length();
        if (ar_len > max_len)
        {
            max_len = ar_len;
            s = arr[i];
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (s.compare(arr[i]) == 0)
            continue;
        else if (s.length() > arr[i].length()) // s is longer
        {
            if (s.compare(0, arr[i].length(), arr[i]) == 0)
            {
                s.resize(arr[i].length());
                continue;
            }
            else
            {
                int len = arr[i].length();
                string str = s;
                while (len > 0)
                {
                    if (str.at(len - 1) != arr[i].at(len - 1))
                    {
                        str.resize(len - 1);
                    }
                    len--;
                }

                s = str;
                if (str.length() == 0)
                    break;
            }
        }
        else if (s.length() < arr[i].length()) // s is shorter
        {
            if (s.compare(0, s.length(), arr[i], 0, s.length()) == 0)
            {
                // s.resize(arr[i].length()); // s is shorter...no need to reduce it's length.
                continue;
            }
            else
            {
                int len = s.length();
                string str = s;
                while (len > 0)
                {
                    if (str.at(len - 1) != arr[i].at(len - 1))
                    {
                        str.resize(len - 1);
                    }
                    len--;
                }

                s = str;
                if (str.length() == 0)
                    break;
            }
        }
        else if(s.length() == arr[i].length())
        {
            int len = s.length();
                string str = s;
                while (len > 0)
                {
                    if (str.at(len - 1) != arr[i].at(len - 1))
                    {
                        str.resize(len - 1);
                    }
                    len--;
                }

                    s = str;
                if (str.length() == 0)
                    break;
        }
    }

    if (s.length() != 0)
        return s;
    else
        return "-1";
}

int main()
{
    // string arr[4] = {"geeksforgeeks", "geeks", "geek", "geezer"}; // o/p: "gee"
    string arr[4] = {"geeksforgeeks", "geeks", "igeek", "geezer"}; // o/p: "-1"
    // string arr[2] = {"hello", "world"}; // o/p: "-1"
    // string arr[2] = {"geek", "igeeks"}; // o/p: "-1"
    cout << longestCommonPrefix(arr, 4);

    return 0;
}