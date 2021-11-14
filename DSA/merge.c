//111901057
//Neel

#include <stdio.h>
#include <stdlib.h>

void printarr(long long int *arr, int n);
void merge(long long int * arr1,long long int *arr2, int n, int m);

void printarr(long long int *arr, int n){
  for(int i=0; i<n; i++){
    printf("%lld\n", arr[i]);
  }
}//Runime = O(n), linear traversal


void merge(long long int * arr1,long long int *arr2, int n, int m){
  long long int *arrayfinal;
  //This is the new array required
  arrayfinal = (long long int*) malloc(sizeof(long long int)*(m+n));
  //this is a temporary array to store the required values in a sorted order
  //here m+n extra space is taken
  //let i1 represent traversal of first subarray, i.e. i1 : 0--->n
  int i1=0;
  //let i2 represent traversal of second subarray, i.e. i2 : 0--->m
  int i2=0;
  //let temppos represent the position of the temporary array
  int k=0;
  while(i1<n && i2<m){
    //till any of their ends isnt reached, we can simply keep comparing and inserting into the temporary array
    if(arr1[i1]>arr2[i2]){
      arrayfinal[k]=arr2[i2];
      i2++;
      k++;
    }
    else{
      arrayfinal[k]=arr1[i1];
      i1++;
      k++;
    }
  }
  //if i2==m, it means only values in second array are left.
  //adding them to the temporary array ..
  if(i2==m){
    while(i1<n){
      arrayfinal[k]=arr1[i1];
      i1++;
      k++;
    }
  }
  //if i1==n, it means only values in second array are left.
  //adding them to the temporary array ..
  if(i1==n){
    while(i2<m){
      arrayfinal[k]=arr2[i2];
      i2++;
      k++;
    }
  }
  //now the temporary is completed and sorted
  //we can simply replace values back to original arrays from 0 to n and 0 to m(for array1 and array2 respectively)

  for(int i=0;i<n;i++){
    arr1[i]=arrayfinal[i];
  }
  for(int i=0;i<m ;i++){
    arr2[i]=arrayfinal[i+n];
  }
  //now since the original values have all the values required, we no longer require arrayfinal
  free(arrayfinal);
}//The space complexity for this function would be O(n+m), since extra array of length n+m was required
 //The time complexity for this function would be O(n+m), since n+m elements are traveressed linearly

int main(){
  int n,m;
  long long int *array1;
  scanf("%d", &n);
  array1 = (long long int *) malloc(sizeof(long long int)*n);
  for(int i=0; i<n; i++){
    scanf("%lld", &array1[i]);
  }
  long long int *array2;
  scanf("%d", &m);
  array2 = (long long int *) malloc(sizeof(long long int)*m);
  for(int i=0; i<m ; i++){
    scanf("%lld", &array2[i]);
  }
  merge(array1,array2,n,m);
  //noe array1 and array2 are sorted arrays, we can simply print them
  printarr(array1, n);
  printarr(array2, m);
  //we no longer need this extra space
  free(array1);
  free(array2);
  return 0;
}
