//Binary Search

#include<stdio.h>
#define MAX 5

int binarySearch(int array[], int key){
    int first = 0;
    int last = MAX - 1;

    while (first <= last)
    {
        int mid = first + (last - first)/2;

        if(key == array[mid]){
            return mid;
        }
        
        if (key > array[mid]){
            first = mid + 1;
        } else{
            last = mid - 1;
        } 
    }

    return -1; 
}

void main () {
    int arr[MAX];
    int key;

    for (int i = 0; i < MAX; i++)
    {
        printf("Enter %d element ", i + 1);
        scanf("%d",&arr[i]);
    }

    printf("Enter Value to be found ");
    scanf("%d",&key);

    int result = binarySearch(arr,key);
    if (result == -1)
    {
        printf("Element Not Found in Array");
    } else {
        printf("Element found at %d ", result);
    } 
}
