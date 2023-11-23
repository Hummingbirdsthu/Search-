#include "header.h"

//phát sinh ngẫu nhiên mảng 1 chiều (đã sắp xếp) các số nguyên tăng dần 
void Create_SortedArray(int *a,int n){
    // khởi tạo số ngẫu nhiên
	srand(time(NULL));

    if (n > 0) {
	a[0] = rand() % 100;
    // khởi tạo ngẫu nhiên từng phần tử từ chỉ số 1 đến n – 1
	for (int i = 1; i < n; i++) 
		a[i] = a[i - 1] + rand() % 100;
    }
}

void Create_RandomArray(int *a,int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++) 
		a[i] = rand() ;
}

void Create_ReverseArray(int *a,int n) {
    int *b=new int[n];
    Create_RandomArray(b,n);
    for (int i = n -1; i >= 0; i--) a[i] = b[n-i-1];
}

int *Create_Array(string state, int n) {
    int *a=new int[n];
    if (state == "Random") Create_RandomArray(a,n);
    else if (state == "Reverse") Create_SortedArray(a,n);
    else Create_ReverseArray(a,n);
    delete[] b;
}