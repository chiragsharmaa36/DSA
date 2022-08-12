// Sort an array which contains only 0, 1 or 2.
// O(N) and space complexity - O(1)

#include <iostream>
using namespace std;

void sort012(int arr[], int N)
{
    int zero = 0, one = 0, two = 0;

    for (int i = 0; i < N; i++)
    {
        switch (arr[i])
        {
        case 0:
            zero++;
            break;
        case 1:
            one++;
            break;
        case 2:
            two++;
            break;
        }
    }
    int i;
    for (i = 0; i < zero; i++)
    {
        arr[i] = 0;
    }

    for (; i < one + zero; i++)
    {
        arr[i] = 1;
    }

    for (; i < N; i++)
    {
        arr[i] = 2;
    }
}
