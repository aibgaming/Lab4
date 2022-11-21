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

void quickSort(int a[], int p, int r)    
{
    if(p < r)
    {
        int q;
        q = partition(a, p, r);
        quickSort(a, p, q-1);
        quickSort(a, q+1, r);
    }
}
 
 
int getMax(int array[], int size) {
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max; //the max element from the array
}
void countSort(int *array, int size) {
   int output[size+1];
   int max = getMax(array, size);
   int count[max+1];     //create count array (max+1 number of elements)
   for(int i = 0; i<=max; i++)
      count[i] = 0;     //initialize count array to all zero
   for(int i = 1; i <=size; i++)
      count[array[i]]++;     //increase number count in count array.
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];     //find cumulative frequency
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1; //decrease count for same numbers
   }
   for(int i = 1; i<=size; i++) {
      array[i] = output[i]; //store output array to main array
   }
}


void countSortRadix(int arr[], int n, int exp)
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
 

void radixSort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp);
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
    //Generating n random numbers from 1 to n*2
    srand(time(NULL));
    int n = 10;
    int myarr[n];
    for (int i = 0; i < n; i++) {
        myarr[i] = randomGen(1, n*2);
    }
    
    //Printing generated array
    for (int i = 0; i < n; i++) {
        cout << myarr[i] << " ";
    }
    cout<< endl;
    
    int arrlength = sizeof(myarr)/sizeof(myarr[1]);
    //bubbleSort(myarr, arrlength);
    //insertionSort(myarr, arrlength);
    int (*pMyarr) = myarr;
    //mergeSort(pMyarr, 0, n-1);
    //quickSort(myarr, 0, n-1);
    countSort(pMyarr, n-1);
    //radixSort(myarr, n-1);
    
    //Printing array after sorting
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
