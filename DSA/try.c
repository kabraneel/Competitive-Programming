#include <stdio.h>
#include <stdlib.h>

int* function(int *arr){

  for(int i =0; i<3; i++){
    arr[i] = i;
  }
  return arr;

}


int main(){

  int a[3];
  function(a);

  for(int i=0; i<3; i++){
    printf("%d ", *(a+i));
  }

  printf("\n");
  return 1;

}
