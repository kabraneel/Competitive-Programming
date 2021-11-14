//111901057
//Neel

#include <stdio.h>
#include <stdlib.h>

void insert(long long int *arr,long long int n);
void printarr(long long int *arr,long long int m);

void insert(long long int *arr,long long int n){
  long long int key;            //runtime = c1
  key = arr[n-1];               //runtime = c2
  long long int j=n-2;          //runtime = c3
  while(j>=0 && arr[j]>key){   //statement executes m-1 times (runtime = c4*(m-1))
    arr[j+1]=arr[j];          //statement can be executed anywhere between 1 and m-1 times(worse ca4se runtime = c5*(m-1))
    j=j-1;                   //statement can be executed anywhere between 1 and m-1 times(worse case runtime = c6*(m-1))
  }
  arr[j+1]=key;
}//overall runtime is approximately (c1 + c2 + c3 - c4 - c5 - c6 + m*(c4+c5+c6))
 //runtime is linear


void printarr(long long int *arr, long long int m){
  for(long long int i=0; i<m; i++){
    printf("%lld\n", arr[i]);   // statement excutes m times(runtime = k*m)
  }
}//overall runtime = k*m
 //runtime is linear

int main(){
  long long int n;
  long long int *arr;
  scanf("%lld", &n);
  arr = (long long int *) malloc(n*sizeof(long long int));
  for(long long int i=0; i<n; i++){
    scanf("%lld", &arr[i]);
  }
  insert(arr, n);
  //we can now print the required array
  printarr(arr,n);
  //we can now free the allocated memory
  free(arr);
  return 0;
}
