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
 
 
//Function to get the largest element from an array
int getMax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++) if (array[i] > max)
      max = array[i];
  return max;
}

//Using counting sort to sort the elements in the basis of significant places
void countSort(int array[], int size, int place) 
{
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  //Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  //Calculating cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  //Placing the elements in sorted order
  for (int i = size - 1; i >= 0; i--) 
  {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

//Main function to implement radix sort
void radixSort(int array[], int size) 
{
  //Getting maximum element
  int max = getMax(array, size);

  //Applying counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countSort(array, size, place);
}
 


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
 
    //If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    //If right child largest 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    //If root is nor largest
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        //Recursively heapifying the sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    //One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        //Moving current root to end
        swap(arr[0], arr[i]);
 
        //Calling max heapify on the reduced heap
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
    int (*pMyarr) = myarr;
    
    typedef std::chrono::high_resolution_clock Clock;
    auto t1 = Clock::now();
    //Doing the sorts
    
    //bubbleSort(myarr, arrlength);
    //insertionSort(myarr, arrlength);
    //mergeSort(pMyarr, 0, n-1);
    //quickSort(myarr, 0, n-1);
    //countSort(pMyarr, n-1);
    radixSort(myarr, n);
    //heapSort(myarr,n);
    
    //Printing array after sorting



    auto t2 = Clock::now();
    cout << "Delta t2-t1: "  <<chrono::duration_cast<chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
    
    for (int i = 0; i < n; i++) {
        cout << myarr[i] << " ";
    }
    cout<< endl;


    cout << "Hello World! Lab 4 is here!\n";
    return 0;
}
