#include "header.h"

//Linear search with a given array
int linear_search(int* a, int n, int key) {
	for (int i = 0; i < n; i++) {
		if (*(a + i) == key) return i;
	}
	return -1;
}

// Binary search with a sorted array
int binary_search(int* a, int n, int key) {
	int mid, left= 0, right = n - 1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (*(a + mid) == key) return mid;
		else {
			if (*(a + mid) > key) right = mid - 1;
			else left = mid + 1;
		}
	} 
    return -1;
}
