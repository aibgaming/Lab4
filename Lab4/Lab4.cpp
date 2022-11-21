// Lab4.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// Team Members: Autri Banerjee, Kshitij Sawant, Vishesh Srivastava
//
// Resources Used: https://crackfaang.medium.com/sorting-algorithms-in-c-b0a601467dbf, zybooks
// 

#include <iostream>
#include <ctime>
#include <random>
using namespace std;


void bubbleSort(int array[], int length)
 {
     for(int i = 0; i < length-1; i++){
         for(int j=0;j<length-i-1;j++)
            if(array[j]>array[j+1]){
                array[j]+=array[j+1];
                array[j+1]=array[j]-array[j+1];
                array[j]-=array[j+1];
            }
     }
 }

void insertionSort(int arr[], int length) 
{
    int i, j, key;
    for (i = 1; i < length; i++) 
    {
        key = arr[i];
        j = i-1;
        
        while (j >= 0 && arr[j] >key) 
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j +1] = key;
        
    }
}

void merge(int *Arr, int start, int mid, int end) {
	int temp[end - start + 1];
	int i = start, j = mid+1, k = 0;
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}
	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}
	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}
	for(i = start; i <= end; i += 1) {
        Arr[i] = temp[i - start];
	}
}
void mergeSort(int *Arr, int start, int end) {
	if(start < end) {
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}


void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];  
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;   
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int a[], int p, int r)    
{
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quicksort(a, p, q-1);
        quicksort(a, q+1, r);
    }
}


int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
void countSort(int arr[], int n, int exp)
{
    int output[n]; 
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 


void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest]){}
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


int randomGen(int low, int high)
{
    return low + rand() % (high - low + 1);
}



 #include <chrono>
int main()
{
    srand(time(NULL));
    int n = 100;
    int myarr[n];
    for (int i = 0; i < n; i++) {
        myarr[i] = randomGen(1, n*2);
    }
    
    for (int i = 0; i < n; i++) {
        cout << myarr[i] << " ";
    }
    cout<< endl;

    typedef std::chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();
    auto t2 = Clock::now();
    cout << "Delta t2-t1: "  <<chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;


    cout << "Hello World! Lab 4 is here!\n";
    return 0;
}
