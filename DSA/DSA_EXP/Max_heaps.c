#include <stdio.h>
#include <stdlib.h>

//SOME BASIC HEAP FUNCTIONS
//THIS WILL BE A MAXHEAP
void swap(int *a, int *b);
int Parent(int i);
int Left(int i);
int Right(int i);
void Max_Heapify(int arr[], int i, int n);
void printarr(int arr[], int n);
void Extract_Max(int arr[], int *n);

void printarr(int arr[], int n){
  for(int i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b){
  int temp = *a;
  *a = *b ;
  *b = temp;
}

int Parent(int i){
  return i/2;
}

int Left(int i){
  return 2*i+1;
}

int Right(int i){
  return (2*i + 2);
}

void Max_Heapify(int arr[], int i, int n){
  int largest = i;
  int l = Left(i);
  int r = Right(i);
  if(arr[l]>arr[i] && l<n){
    largest=l;
  }
  else if(arr[r]>arr[i] && r<n){
    largest = r;
  }
  if(largest != i){
    swap(&arr[largest],&arr[i]);
    Max_Heapify(arr,largest,n);
  }
}

void Extract_MaxFE(int arr[], int *n){
  printf("Max = %d\n", arr[0]);
  swap(&arr[0],&arr[*n-1]);
  *n=*n-1;
  printf("n == %d\n", *n);
  if(*n==0){
    printf("HEAP IS EMPTY!\n");
  }
  else{
    Max_Heapify(arr,0,*n);
  }
}

void Extract_MaxFS(int arr[], int n){
  printf("Max = %d\n", arr[0]);
  swap(&arr[0],&arr[n-1]);
  n=n-1;
  printf("n == %d\n", n);
  if(n==0){
    printf("HEAP IS EMPTY!\n");
  }
  else{
    Max_Heapify(arr,0,n);
  }
}

int main(){
  int arr[14]={27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
  int n=sizeof(arr)/sizeof(int);
  printarr(arr,n);
  Max_Heapify(arr,2,n);
  printarr(arr,n);
  Extract_Max(arr,&n);
  printf(" n == %d\n",n);
  printarr(arr,n);
  return 0;
}
