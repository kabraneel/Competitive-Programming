#include <stdio.h>
#include <stdlib.h>

int main(){
  //part 1:
  // First, we can declare two integers p and q(rows and columns)

  int p,q;
  scanf("%d %d", &p, &q);


  //We can dynamically allocate for p*q integers using malloc

  int *array;
  array=(int *) malloc(p*q*(sizeof(int)));


  //part 2:
  //Now we can scan the elements of the matrix rowwise.
  //First q elements will be in row one, second 'q' elements will be in row 2 and so on..
  //each element can be represented as *(arr + i*number_of_columns + j) , i: 1-->p , j: 1-->q

  for(int i=0; i<p; i++){
    for(int j=0;j<q;j++){
      int temp;
      scanf("%d", &temp);
      *(array + i*q + j)=temp;
    }
  }


  //part 3:
  //Now to print the array we just obtained

  for(int i=0;i<p;i++){
    for(int j=0;j<q;j++){
      printf("%d  ", *(array + i*q + j));
    }
    //go to next line after printing one row
    printf("\n");
  }


  //part 4:
  //for printing transpose of the matrix, we need to print the first column as the first row
  // in other words, we need to put the for loop of columns outside

  for(int j=0;j<q;j++){
    for(int i=0;i<p;i++){
      printf("%d  ", *(array+ i + j*p ));
    }
    printf("\n");
  }


  //part 5:
  //to use realloc, we first need to know how much to increase the size by
  //to know how much to increase size, we need to know how many new rows(x) and new columns(y)

  int x,y;
  printf("Enter the number of added rows and columns : ");
  scanf("%d %d", &x, &y);

  //we can return a pointer pointing to the same intial location, but the new memory being sizeof(int)*(p*q + x*y)

  array = realloc(array , sizeof(int)*((p+x)*(q+y)));

  //first we can intialize all the new elements to zero

  for(int i=p*q; i<((p+x)*(q+y)); i++){
    *(array + i)=0;
  }

  //now, array is a pointer pointing to starting location of the original one.
  //now, we add the new elements to the end of the array
  //for that, we need to run i from p*q --> (p+x)*(q+y)

  for(int i=p*q; i<(p+x)*(q+y); i++){
    int temp;
    scanf("%d", &temp);
    *(array + i)=temp;
  }


  //part 6:
  //to print the new matix
  //slightly complicated as the newer elements are added to the end


  printf("New matrix ===\n");

  for(int i=0; i<p ; i++){

    //First, we print ith row of matrix before adding new elements

    for(int j=0; j<q; j++){
      printf("%d  ", *(array + i*q + j));
    }

    //Now, we print the newly added elements in the ith row
    //We will have to print 'y' elements in the first p rows

    for(int k=0; k<y;k++){
        printf("%d  ", *(array + p*q + i*y + k));
    }

    //After printing the ith row, we need to go to next line

    printf("\n");
  }

  // we have now printed the first p rows of the matrix
  //to print the last x rows, a simple nested for where j: 1-->(q+y) will do the trick


  for(int i=p; i<p+x; i++){
    for(int j=0; j<q+x; j++){
      printf("%d  ",*(array + i*(q+y) + j));
    }
    printf("\n");
  }

  //_______End of printing new array_______


  //part 7:
  // to print sum of all the elements of the matrix
  // we can simply treat the matrix as a normal 1D array and proceed

  int sum=0;
  for(int i=0; i<(p+x)*(q+y);i++){
    sum=sum + *(array +i);
  }

  //printing the sum

  printf("SUM = %d\n", sum);


  //Now, we have to free the allocated memory

  free(array);

  //say everything went fine

  return 0;

}
