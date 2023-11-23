#include "header.h"

//Selection Sort with a random array
void selection_sort(int *a, int n) {
    for (int i=0;i<n;i++) {
        int min=i;
        for (int j=i+1;j<n;j++) {
            if (a[j] < a[min]) min = j;
        }
        if (min != i) swap(a[min], a[i]);
    }
}

//Insertion Sort with a random array
void insertion_sort(int *a, int n) {
    int j, key;
    for (int i=1; i<n; i++) {
        key = a[i];
        j= i -1;
        while (j>=0 && a[j] >key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

//Binary search for position just greater than key in array
int BinarySearch_pos(int* a, int n, int key){
    int mid, left= 0, right = n ;
	while (left < right)  {
        mid = (left + right) / 2;
		if (*(a + mid) <= key) left= mid +1;
        else right = mid;
    }
    return left;
}
//Binary Insertion Sort with a sorted array
void binary_insertion_sort(int *a, int n) {
    int key, pos, j;
    for (int i = 1; i < n; i++) {
        key = a[i];
        pos = BinarySearch_pos(a, i, key);
        j = i ;
        while (j > pos) {
            a[j] = a[j -1];
            j--;
        }
        a[pos] = key;
    }
}

//Bubble Sort with a random array
void bubble_sort(int* a, int n){
    for (int i=0;i<n-1;i++) {
        for (int j = n-1; j > i; j--) 
            if (a[j] < a[j - 1]) swap(a[j], a[j - 1]);
    }
}

//Shaker Sort with a random array
void shaker_sort(int *a, int n) {
    int left = 0, k = 0, right = n-1;
    while (left < right) {
        for (int i = 0; i < n-1; i++) {
            if (a[i] > a[i +1]) {
                swap(a[i], a[i +1]);
                k++;
            }
        }
        right = k;
        for (int i = k; i > left; i--) {
            if (a[i] < a[i -1]) {
                swap(a[i], a[i -1]);
                k = i;
            }
        }
        left = k;
    }
}

//Shell Sort with a random array
void shell_sort(int *a, int n){
    for (int gap = n/2; gap >0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -=gap) 
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}

//heapify a subtree rooted with node i
void heapify(int *a, int n, int i) {
    int saved = a[i];
    while (i < n/2) {
        int child = 2*i +1;
        if (child < n -1) {
            if (a[child] < a[child +1]) child++;
        }
        if (saved >= a[child]) break;
        a[i] = a[child];
        i = child;
    }
    a[i] = saved;
}
//Heap Sort with a random array
void heap_sort(int *a, int n){
    for (int i = n/2 -1; i >= 0; i--) heapify(a, n, i);
    for (int i = n -1; i >= 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

//Merge
void merge(int* a, int left, int mid, int right) {
    int n1 = mid - left +1;
    int n2 = right - mid;
    int *L = new int[n1];
    int *M = new int[n2];

    //L[n1] = a[left]...a[mid]
    //M[n2] = a[mid + 1]...a[right]
    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) M[j] = a[mid + 1 + j];

    int i =0, j =0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) a[k++] = L[i++];
        else a[k++] = M[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = M[j++];
    delete []L;
    delete []M;
}
//Merge Sort with a random array
void merge_sort(int *a, int left, int right) {
    if (left < right){
        int mid = (left + right)/2;
        merge_sort(a, left, mid);
        merge_sort(a, mid +1, right);
        merge(a, left, mid, right);
    }
}

//Participant
int partition(int *a, int left, int right) {
	int mid = a[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j) {
		while (a[i] < mid) i++;
		while (a[j] > mid) j--;
		if (i <= j ) swap(a[i++], a[j--]);
	}
	return i;
}
//Quick Sort with a random array
void quick_sort(int *a, int left, int right) {
    if (right <= left) return;
    int index = partition(a, left, right);
	if (left < index - 1)
		quick_sort(a, left, index - 1);
	if (index < right)
		quick_sort(a, index, right);
}

//Counting Sort with a random array
void counting_sort( int *a, int n) {
    int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];

	int *count = new int[max + 1];
	for (int i = 0; i <= max; i++) count[i] = 0;

	for (int i = 0; i < n; i++) count[a[i]]++;  // Lưu trữ số lượng từng phần tử  

	for (int i = 1; i <= max; i++) count[i] += count[i - 1];

	int *temp = new int[n];
	for (int i = 0; i < n; i++) {
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	for (int i = 0; i < n; i++) a[i] = temp[i];
	delete[] count;
	delete[] temp;
}

//Radix Sort with a random array
void radix_sort(int *a, int n){
    int b[n], m = a[0], exp = 1;

	for (int i = 0; i < n; i++)
		if (a[i] > m)
			m = a[i];

	while (m / exp > 0) {
		int bucket[10] = {0};
		for (int i = 0; i < n; i++)
			bucket[a[i] / exp % 10]++;
		for (int i = 1; i < 10; i++)
			bucket[i] += bucket[i - 1];
		for (int i = n - 1; i >= 0; i--)
			b[--bucket[a[i] / exp % 10]] = a[i];
		for (int i = 0; i < n; i++)
			a[i] = b[i];
		exp *= 10;
	}
}

// //Flash Sort with a random array
void flash_sort(int *a, int n) {
    //phân lớp dữ liệu
    int minVal = a[0];
	int max = 0;
	int m = int(0.45 * n);
	int* l = new int[m];
	for (int i = 0; i < m; i++)	l[i] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] < minVal) minVal = a[i];
		if (a[i] > a[max]) max = i;
	}
	if (a[max] == minVal) return;
	double c1 = (double)(m - 1) / (a[max] - minVal);
	for (int i = 0; i < n; i++) {
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}
	for (int i = 1; i < m; i++) l[i] += l[i - 1];
	swap(a[max], a[0]);
    //hoán vị toàn cục
	int nmove = 0, j = 0, t = 0;
	int k = m - 1;
	int flash;
	while (nmove < n - 1) {
		while (j > l[k] - 1) {
			j++;
			k = int(c1*(a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k]) {
			k = int(c1*(flash - minVal));
            swap(flash,a[--l[k]]);
			++nmove;
		}
	}
	delete[] l;
    //sắp xếp cục bộ
	insertion_sort(a, n);
}

