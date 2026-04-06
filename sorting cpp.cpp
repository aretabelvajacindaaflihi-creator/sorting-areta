#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int arr[], int n, int step) {
    cout << "Iterasi " << step << ": ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}

// BUBBLE SORT
void bubbleSort(int arr[], int n) {
    int step = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
            printArray(arr, n, step++);
        }
    }
}

// SELECTION SORT
void selectionSort(int arr[], int n){
    int step = 1;
    for(int i=0;i<n;i++){
        int min_idx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
        printArray(arr, n, step++);
    }
}

// INSERTION SORT
void insertionSort(int arr[], int n){
    int step = 1;
    for(int i=1;i<n;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        printArray(arr, n, step++);
    }
}

// QUICK SORT
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low;j<high;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

// MERGE SORT
void merge(int arr[], int l, int m, int r){
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];

    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }

    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

// MAIN
int main(){
    int n;
    cout << "Jumlah data: ";
    cin >> n;

    int arr[n];
    cout << "Masukkan data: ";
    for(int i=0;i<n;i++) cin >> arr[i];

    int temp[n];

    copy(arr, arr+n, temp);
    cout << "\nBubble Sort:\n";
    bubbleSort(temp,n);

    copy(arr, arr+n, temp);
    cout << "\nSelection Sort:\n";
    selectionSort(temp,n);

    copy(arr, arr+n, temp);
    cout << "\nInsertion Sort:\n";
    insertionSort(temp,n);

    copy(arr, arr+n, temp);
    quickSort(temp,0,n-1);
    cout << "\nQuick Sort:\n";
    for(int i=0;i<n;i++) cout << temp[i] << " ";

    copy(arr, arr+n, temp);
    mergeSort(temp,0,n-1);
    cout << "\n\nMerge Sort:\n";
    for(int i=0;i<n;i++) cout << temp[i] << " ";

    return 0;
}