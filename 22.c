//merge sort 

#include <stdio.h>

// Function to merge two halves of the array
void merge (int arr[],int low,int mid,int high){
    int i,j,k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1];
    int right[n2];

    //copy data
    for ( i = 0; i < n1; i++)
    {
        left[i] = arr[low + i];
    }
    for ( j = 0; j < n2; j++)
    {
        right[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;

    while(i < n1 && j < n2){
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    
    
}

void mergeSort(int arr[],int low,int high){
    if (low < high)
    {
        int mid = low + (high - low)/2;

        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);

        merge(arr,low,mid,high);
    }
    
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main function to demonstrate merge sort
int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array: \n");
    printArray(arr, size);

    return 0;
}