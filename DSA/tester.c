#include <stdio.h>
#include <stdlib.h>

int* fsmart(int *arr, int m);

int* fcode(int *arr, int m);

int* fsmart(int *arr, int m){
  for(int i=0; i<m; i++){
    for(int j=0; j<m; j++){
      if(arr[i]<arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
  return arr;
}

int* fcode(int *arr, int m){
  int key;
  for(int i=0; i<m-1;i++){
    for(int j=0; j<m-1; j++){
      if(arr[i]<arr[j]){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
  printf("--------BEFORE SORTING LAST------\n");
  for(int i=0; i<m; i++){
    printf("%d ", *(arr+i));
  }
  printf("\n");
  key = arr[m-1];
  int j=m-2;
  while(j>=0 && arr[j]>key){
    arr[j+1]=arr[j];
    j=j-1;
  }
  arr[j+1]=key;
  return arr;
}

int main(){
  while(1){
    int m;
    int arr[20];
    int arrs[20];
    m = rand()%20;
    printf(" m == %d\n",m);
    for(int i=0; i<m;i++){
      arr[i]=rand()%100;
      arrs[i]=arr[i];
    }
    for(int i=0; i<m; i++){
      printf("%d ",arr[i]);
    }
    printf("\n");
    int *f1 = fsmart(arr , m);
    int *f2 = fcode(arrs , m);
    int pos = 1;
    for(int i=0; i<m; i++){
      if(*(f1+i) != *(f2+i)){
        pos = 0;
      }
    }
    printf("---AFTER SORTING-----\n");
    for(int i=0; i<m; i++){
      printf("%d ",*(f1+i));
    }
    printf("\n");
    if(pos==0){
      printf("WRONG ANS\n");
      break;
    }
    printf("RIGHT ANS\n");
  }
  return 0;
}
