//Bubble Sort 

#include<stdio.h>
#define n 5


void print(int arr[]){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void bubbleSort(int arr[]){
    for (int i = 0; i < n ; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        } 
    }  
    print(arr);
}

int main(){
    int arr[] = {2,3,7,5,4};
    bubbleSort(arr);
    return 0;
}


