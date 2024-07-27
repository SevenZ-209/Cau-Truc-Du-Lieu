#include <iostream>
#include<fstream>
using namespace std;
#define MAX 1000000
void swap(int &a, int &b) {
	a = a + b;
	b = a - b;
	a = a - b;
}
void selectionSort(int a[], int n) {
	int pos;
	for (int i = 0; i < n - 1; i++) {
		pos = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[pos])
				pos = j;
		}
		swap(a[i], a[pos]);
	}
}
void insertionSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int x = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}
void quickSort(long a[], int left, int right) {
	int l = left, r = right;
	int pivot = a[(left + right) / 2];
	while (left <= right) {
		while (a[l] < pivot)
			l++;
		while (a[r] > pivot)
			r--;
		if (l <= r)
			swap(a[l++], a[r--]);
	}
	if (left < r)
		quickSort(a, left, r);
	if (l < right)
		quickSort(a, l, right);
}
void heapify(long a[], int n, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int maxPos = i;
	if (left<n&&a[left]>a[maxPos])
		maxPos = left;
	if (right<n&&a[right]>a[maxPos])
		maxPos = right;
	if (maxPos == i)
		return;
	swap(a[i], a[maxPos]);
	heapify(a, n, maxPos);
}
void heapSort(long a[], int n) {
	int i = n / 2 - 1;
	while (i >= 0) {
		heapify(a, n, i);
		i--;
	}
	int right = n - 1;
	for (; right > 0; right--) {
		swap(a[0], a[right]);
		heapify(a, right, 0);
	}
}
void printList(int a[], int n) {
	ofstream outFile("DaySo.txt");
	if (outFile.is_open());
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[MAX];
	int n;
	ifstream inFile("DaySo.txt");
	if (inFile.is_open()) {
		inFile >> n;
		for (int i = 0; i < n; i++) {
			inFile >> a[i];
		}
		inFile.close();
	}
	heapSort(a, n);
	printList(a, n);
	system("pause");
	return 0;

}