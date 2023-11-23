#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib> // for srand() and rand()
#include <ctime> // for time()
#include <time.h>
#include <cstring>
using namespace std;


void Create_SortedArray(int *a,int n);
void Create_RandomArray(int *a,int n);
void Create_ReverseArray(int *a,int n);
int *Create_Array(string state, int n);


int binary_search(int* a, int n, int key);
int linear_search(int* a, int n, int key);


void selection_sort(int *a, int n);
void insertion_sort(int *a, int n);
void binary_insertion_sort(int *a, int n);
void bubble_sort(int* a, int n);
void shaker_sort(int *a, int n);
void shell_sort(int *a, int n);
void heapify(int *a, int n, int i);
void heap_sort(int *a, int n);
void merge(int* a, int left, int mid, int right);
void merge_sort(int *a, int left, int right);
int partition(int *a, int left, int right);
void quick_sort(int *a, int left, int right);
void counting_sort( int *a, int n);
void radix_sort(int *a, int n);
void flash_sort(int *a, int n);