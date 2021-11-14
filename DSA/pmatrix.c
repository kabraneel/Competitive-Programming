#include <stdio.h>
#include <stdlib.h>

int main(){
  //First, we need to declare and scan rows and columns of the matrix

  int p,q;
  scanf("%d %d", &p, &q);

  //To create two dimensional matrices, we can make a pointer to an array of pointers, each pointer pointing to a row of the matrix.
  //Here, the pointer to the pointer is arr.
  //Under Malloc, we have to typecast it to int **

  int **arr;
  arr = (int **) malloc(sizeof(int*)*p);

  //Now, we can dynamically allocate memory 'p' number of times of size 'q'
  //each 'p' here represents each row of the matrix
  //*(arr + i) is equivalent to arr[i]

  for(int i=0;i<p;i++){
    *(arr + i)= (int *) malloc(sizeof(int)*q);
  }

  //Now since memory for the 2D array has been allocated, we can access the elements in two ways.
  // arr[i][j] can be used.
  //we can also use *(*(arr+i) + j), i: 1-->p and j : 1-->q
  //here *(arr+i) represents the pointer to the row and *(*(arr + i) + j) represents each element of the row


  //intializing all values to 1

  for(int i=0;i<p;i++){
    for(int j=0;j<q;j++){
      *(*(arr+i) + j)=1;
    }
  }

  //printing the matrix

  for(int i=0;i<p;i++){
    for(int j=0;j<q;j++){
      printf("%d ",*(*(arr+i) + j));
    }
    printf("\n");
  }

  //freeing dynamically allocated memory
  
  for(int i=0;i<p;i++){
    free(*(arr+i));
  }
  free(arr);
  return 0;
}
