//insertion sort
 

#include<stdio.h>
#define n 5


void print(int arr[]){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void insertionSort(int arr[]){
    int j;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    print(arr);
    
}

int main(){
    int arr[] = {2,3,7,5,4};
    insertionSort(arr);
    return 0;
}
