#include <bits/stdc++.h>
using namespace std;

void mostRecentlyUsedApps(int* arr, int N, int K)
{
	int app_index = 0;

	app_index = (K % N);
	int x = app_index, app_id = arr[app_index];
	while (x > 0) {
		arr[x] = arr[x - 1];
        x--;
	}

	arr[0] = app_id;
}

void printArray(int* arr, int N)
{
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
}

int main()
{
	int K = 3;
	int arr[] = { 3, 5, 2, 4, 1 };
	int N = sizeof(arr) / sizeof(arr[0]);

	mostRecentlyUsedApps(arr, N, K);
	printArray(arr, N);
}
