#include <stdio.h>
#include <stdlib.h>
//part 2:
void getinput(int **arr,int p,int q);

//part 3:
void printmatrix(int **arr, int p, int q);

//part 4:
void computetranspose(int **arr, int p, int q);

//part 6:
void getnewinput(int **arr, int p, int q, int x, int y);

//part 7:
int computesum(int **arr, int p, int q);


void getinput(int **arr,int p,int q){
  //here *(arr+i) represents the pointer to the row and *(*(arr + i) + j) represents each element of the row
  for(int i=0; i<p; i++){
    for(int j=0; j<q; j++){
      int temp;
      scanf("%d", &temp);
      *(*(arr+i) + j) = temp;
    }
  }
}


void printmatrix(int **arr, int p, int q){
  //we can access the elements in the same way as before
  for(int i=0 ; i<p ; i++){
    for(int j=0; j<q; j++){
      printf("%d  ", *(*(arr + i) + j));
    }
    //after every row is printed, we move to the next line
    printf("\n");
  }
}


void computetranspose(int **arr, int p, int q){
  //for computing new transpose matrix, we can create a new pointer to a pointer and repeat procedure
  int **arrtranspose;
  arrtranspose = (int **) malloc(sizeof(int*)*q);
  for(int i=0; i<q ; i++){
    *(arrtranspose + i) = (int*) malloc(sizeof(int)*p);
  }
  for(int i=0; i<q; i++){
    for(int j=0;j<p;j++){
      //by definition of transpose, we have
      *(*(arrtranspose + i) + j) = *(*(arr + j) + i);
    }
  }
  printf("---------TRANSPOSE--------\n");
  //we can use the printmatrix function to print the transpose
  //definition is printmatrix(int **, no_of_rows, no_of_columns)
  printmatrix(arrtranspose, q, p);
  //we can now free the memory
  for(int i=0; i<q;i++){
    free(*(arrtranspose + i));
  }
  free(arrtranspose);
}


void getnewinput(int **arr, int p, int q, int x, int y){
  //for first p rows, we only need to input y elements
  //in other words, i: 1----> p , j: q ---> q+y

  for(int i=0; i<p; i++){
    for(int j=q;j <(q+y); j++){
      int temp;
      scanf("%d", &temp);
      *(*(arr + i) + j)= temp;
    }
  }
  //for next x rows, we need to input q+y elements
  //in other words, i: p --> p+x , j: 1 --> q+y

  for(int i=p; i<p+x; i++){
    for(int j=0; j<q+y; j++){
      int temp;
      scanf("%d", &temp);
      *(*(arr + i) + j)=temp;
    }
  }
}

int computesum(int **arr, int p, int q){
  int sum=0;
  //to compute the sum, we can simply access all the elements like before, and go on adding them..
  for(int i=0; i<p; i++){
    for(int j=0; j<q; j++){
        sum= sum + *(*(arr + i) + j);
    }
  }
  return sum;
}

int main(){


  //part 1:
  // First, we can declare two integers p and q(rows and columns) and scan them
  printf("Enter number of rows and columns\n");
  int p,q;
  scanf("%d %d", &p, &q);

  //To create two dimensional matrices, we can make a pointer to an array of pointers, each pointer pointing to a row of the matrix.
  //Here, the pointer to the pointer is arr.
  //Under Malloc, we have to typecast it to int **
  int **array;

  array = (int **) malloc(sizeof(int *)*p);

  //now to each of the p pointers, allocate memory of q elements.
  for(int i=0; i<p; i++){
    *(array + i) = malloc(sizeof(int)*q);
  }


  //part 2:
  printf("Enter %d elements row-wise\n", p*q);
  getinput(array,p,q);


  //part 3:
  printf("--------MATRIX-------\n");
  printmatrix(array,p,q);


  //part 4:
  //here, printing transpose is inside computetranspose itself
  computetranspose(array,p,q);


  //part 5:
  // we need to scan two more integers and reallocate memory for them
  printf("Enter new number of rows and columns\n");
  int x,y;
  scanf("%d %d", &x, &y);

  array = (int**)realloc(array,sizeof(int *) *(p+x));
  for(int i=0; i< (p+x); i++){
    *(array + i) = realloc(*(array+ i),sizeof(int) * (q+y));
  }


  //part 6:
  //to read elements row-wise
  printf("Enter %d elements row-wise\n", (p+x)*(q+y) - p*q);
  getnewinput(array,p,q,x,y);
  printf("--------NEW MATRIX--------\n");
  printmatrix(array, p+x, q+y);


  //part 7:
  int sum=0;
  sum=computesum(array, p+x, q+y);
  printf("SUM == %d\n", sum);

  //Free the allocated memory for array
 for(int i=0; i<(p+x) ;i++){
   free(*(array + i));
 }
 free(array);

  //say everything went fine
  return 0;
}
