// Segregate -ve nos. to the left side of an array.
// Order doesn't matter
// Time complexity: O(N) 
// Auxiliary Space: O(1)
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
}

int main()
{
	int n = 9;
	int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};

	// cout << "n = ";
	// cin >> n;
	// for (int i = 0; i < n; i++)
	// {
	// 	cin >> arr[i];
	// }

	// Algo starts here

/*	In the whole process, j is always less than i.
	j only moves forward when elements before and equal to j are -ve.
	j points to a +ve no. so that, any -ve no. after it (as i) can be swapped out with it.
	Thus, segregating -ve no. to the left side.  */
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0)
		{
			if (arr[j] > 0 && j<i)
			{
				int c = arr[i];
				arr[i] = arr[j];
				arr[j] = c;
			}
			j++;
		}
		
	}
	// Algo ends here
	
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}