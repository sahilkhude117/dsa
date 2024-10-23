//Selection sort 

#include<stdio.h>
#define n 5


void print(int arr[]){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
}

void selectionSort(int arr[]){
    for (int i = 0; i < n - 1 ; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        } 
    }  
    print(arr);
}

int main(){
    int arr[] = {2,3,7,5,4};
    selectionSort(arr);
    return 0;
}
