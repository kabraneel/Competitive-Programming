//111901057
//Neel


#include <stdio.h>
#include <stdlib.h>

void f2(int *arr, int i, int j, int l, int m, int n);

void f2(int *arr, int i, int j, int l, int m,int n){
  int temp_arr[m+j+2];
  //this is a temporary array to store the required values in a sorted order
  //here j+m+2 extra space is taken
  //let i1 represent traversal of first subarray, i.e. i1 : i--->j
  int i1=i;
  //let i2 represent traversal of second subarray, i.e. i2 : l--->m
  int i2=l;
  //let temppos represent the position of the temporary array
  int temppos=0;
  while(i1 <i+j+1 && i2 < l+m+1){
    //till any of their ends isnt reached, we can simply keep comparing and inserting into the temporary array
    if(arr[i1]>arr[i2]){
      temp_arr[temppos]=arr[i2];
      i2++;
      temppos++;
    }
    else{
      temp_arr[temppos] = arr[i1];
      i1++;
      temppos++;
    }
  }
  //if i1==j, it means only values in second array are left.
  //adding them to the temporary array ..
  if(i1 == i+j+1){
    while(i2< l+m+1){
      temp_arr[temppos]=arr[i2];
      temppos++;
      i2++;
    }
  }
  //if i2==m, it means only values in the first array are left.
  //adding them to the temporary array
  if(i2 == l+m+1){
    while(i1<i+j+1){
      temp_arr[temppos]=arr[i1];
      temppos++;
      i1++;
    }
  }
  //now the temporary is completed and sorted
  //we can simply replace values back to original array from k = i --> i+j and k = l --> l+m
  //all the other elements should remain unchanged ..
  temppos=0;
  //now to assign the values back to original array
  //for k : i --> i+j
  int k=i;
  while(k<i+j+1){
    *(arr + k) = temp_arr[temppos];
    temppos++;
    k++;
  }
  //for k : l --> l+m
  k=l;
  while(k<m+l+1){
    *(arr+k)=temp_arr[temppos];
    temppos++;
    k++;
  }
  //done with required task
  //we can free memory of temporary array
  //free(temp_arr);
  // in this function, we linearly travesed (j + m) and took the values into the temporary sorted array
  //time taken is approximately (j + m) since it is linear
}

void printarr(int *arr,int m);

void printarr(int *arr, int m){
  for(int i=0; i<m; i++){
    printf("%d\n", arr[i]);   // statement excutes m times(runtime = k*m)
  }
}//overall runtime = k*m
 //runtime is linear

int main(){
  int *arr,i,j,l,m,n;
  scanf("%d", &n);
  scanf("%d", &i);
  scanf("%d", &j);
  scanf("%d", &l);
  scanf("%d", &m);
  //takes in all the values
  arr= (int*)malloc(sizeof(int)*n);
  //dynamically allocates the value of required integers
  for(int k=0;k<n; k++){
      scanf("%d", &arr[k]);
  }
  f2(arr,i,j,l,m,n);
  //we can print the array after required operation is done
  printarr(arr,n);
  //we can now free the allocated memory
  free(arr);
  return 0;
}
