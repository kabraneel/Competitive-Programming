//111901057
//Neel

#include <stdio.h>
#include <stdlib.h>


void printarr(long long int *arr,int m);

void printarr(long long int *arr, int m){
  for(int i=0; i<m; i++){
    printf("%lld\n", arr[i]);   // statement excutes m times(runtime = k*m)
  }
}//overall runtime = k*m
 //runtime is linear


void f2(long long int *arr, int i, int j, int l, int m);

void f2(long long int *arr, int i, int j, int l, int m){
  long long int temp_arr[m+j+2];
  //this is a temporary array to store the required values in a sorted order
  //here j+m+2 extra space is taken
  //let i1 represent traversal of first subarray, i.e. i1 : i ---> j
  int i1=i;
  //let i2 represent traversal of second subarray, i.e. i2 : l ---> m
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
  // in this function, we linearly travesed (j + m) and took the values into the temporary sorted array
  //time taken is approximately (j + m) since it is linear
}


//now we need the main recursive function
void mergeSort(long long int *arr, int l, int r);
//here, l represents left index, r represents right index

void mergeSort(long long int *arr, int l, int r){
  if(l<r){
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);

    //this function merges arr[l],arr[l+1].....,arr[m] and arr[m+1],arr[m+2],.....arr[r]

    //We will now have different cases if the subarray has even length or odd length
    //if odd, first subarray would have one more element than the second subarray, i.e., value of j is m+1.
    if((l+r)%2!=0){
      f2(arr,l,(mid-l),mid+1,mid-l);
    }
    else{
      f2(arr,l,mid-l,mid+1, mid-l-1);
    }
    //runtime of this function is approximately N*log2(N)(or NlogN)
    //this is because in each step the array is divided into 2, making the number of steps logN, and it takes linear time to combine them
    //compared to insertion sort, it also has a larger space complexity of O(n) because of the temp_array, whereas insertion sort has a space complexity of O(1)
  }
}

int main(){
  int n;
  long long int *arr;
  scanf("%d", &n);
  arr= (long long int*) malloc(sizeof(long long int)*n);
  for(int i=0; i<n; i++){
    scanf("%lld", &arr[i]);
  }
  //the initial values of l and r would be : l = 0 and r = n-1
  mergeSort(arr,0,n-1);
  //we can print the array after sorting it
  printarr(arr,n);
  //we dont need the memory now
  free(arr);
  return 0;
}
