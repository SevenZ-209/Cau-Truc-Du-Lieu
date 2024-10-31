#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int getMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void shellSort(int a[], int n, int t)
{
	for (int gap = n/t; gap >0 ; gap/= 2)
	{
		for (int i = gap; i < n; i++)
		{
			int j = i;
			int value = a[i];
			for (j = i; j >= gap && a[j-gap]  > value ; j-=gap)
			{
				cout << "[" << a[j] << ", " << a[j-gap] << "]";
				a[j] = a[j - gap];
			}
			a[j] = value;	
		}
	}
}

void CountingSort(int a[], int n) {
	int max = getMax(a, n);

	int* count = new int[max + 1]();
	int* output = new int[n];

	for (int i = 0; i < n; i++) {
		count[a[i]]++;
	}

	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		output[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}


	for (int i = 0; i < n; i++) {
		a[i] = output[i];
	}

	delete[] count;
	delete[] output;
}

void countSort(int arr[], int n, int exp) {

	int* output = new int[n];
	int count[10] = { 0 };


	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;


	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];


	for (int i = n - 1; i >= 0; i--) {
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}


	for (int i = 0; i < n; i++)
		arr[i] = output[i];

	delete[] output;
}

void radixsort(int arr[], int n) {
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void insertionSort(vector<float>& bucket) {
	for (size_t i = 1; i < bucket.size(); ++i) {
		float key = bucket[i];
		int j = i - 1;
		while (j >= 0 && bucket[j] > key) {
			bucket[j + 1] = bucket[j];
			j--;
		}
		bucket[j + 1] = key;
	}
}


void bucketSort(float arr[], int n) {
	vector<vector<float>> buckets(n);

	for (int i = 0; i < n; i++) {
		int bi = static_cast<int>(n * arr[i]);

		if (bi == n) bi--;
		buckets[bi].push_back(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		insertionSort(buckets[i]);
	}

	int index = 0;
	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < buckets[i].size(); j++) {
			arr[index++] = buckets[i][j];
		}
	}
}


void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void randomnum(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
	}
}



int main() {
	const int SIZE = 10;
	int arr[SIZE];
	srand(time(0));
	randomnum(arr, SIZE);

	int chon;
	do
	{
		cout << "Chon thuat toan sap xep: \n"
			<< "1. Shell Sort\n"
			<< "2. Couting Sort\n"
			<< "3. Radix Sort\n"
			<< "4. Bucket Sort\n"
			<< "5. Thoat\n";
		cout << "Chon: ";
		cin >> chon;
		if (chon <= 0 || chon > 5)
		{
			cout << "Vui long nhap lai\n";
		}
		switch (chon)
		{
		case 1:
		{
			int t;
			cout << "==========ShellSort==========\n"
				<< "Nhap gap chia: "; cin >> t;
			printArray(arr, SIZE);
			shellSort(arr, SIZE, t);
			printArray(arr, SIZE);
			break;
		}

		case 2:
		{
			cout << "==========CoutingSort==========\n";
			printArray(arr, SIZE);
			CountingSort(arr, SIZE);
			printArray(arr, SIZE);
			break;
		}

		case 3:
		{
			cout << "==========Radix Sort==========\n";
			printArray(arr, SIZE);
			radixsort(arr, SIZE);
			printArray(arr, SIZE);
			break;
		}
		default:
			break;


		}
	} while (chon <= 0 || chon > 5);
	
	system("pause");
	return 0;
}