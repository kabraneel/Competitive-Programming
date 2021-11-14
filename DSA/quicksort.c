#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *x,int*y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int l,int h){
    int pivot = arr[h];
    int k = l;

    for(int i = l;i<h;i++)
    {
        if(arr[i] < pivot)
            swap(&arr[k],&arr[i]);
            k++;
    }
    swap(&arr[h],&arr[k]);
    return k;
}

void quicksort(int *arr, int l, int h)
{
    if(l<h)
    {
        int pi = partition(arr,l,h);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,h);
    }
}

void print(int *arr,int n)
{
    for(int i = 0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    srand(time(0));
    int n = rand()%20;
    int *arr = malloc(n*sizeof(int));
    for(int i = 0;i<n;i++)
        arr[i] = rand()%1000;

    print(arr,n);

    quicksort(arr,0,n-1);

    print(arr,n);

    free(arr);

    return 0;
}
