//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//to implement the stack, the set of basic functions are listed below
int top=0;
int push(int arr[],int x, int n);
int pop(int arr[]);
int peek(int arr[]);
void printstack(int arr[]);
int size();
int isempty();
int isfull(int n);

//pushing means adding an element to the end/top
//here we need to change the value of the pointer to top+1, since the size of the stack is increasing
//time complexity : O(1) constant number of operations are being performed
int push(int arr[], int x, int n){
  //check for stack overflow
  if(top<n){
  arr[top]=x;
  top++;
  return 1;
  }
  return -1;
}

//popping means we are removing the top-most element from the stack
//we can simply decrease the value of the pointer, so next time when an element is pushed, the value gets overwrriten..
//time complexity : O(1) constant number of operations are being performed
int pop(int arr[]){
  //check if stack is empty
  if(top>0){
    top--;
    return arr[top];
  }
  return -1;
}

//peeking means returning the value stored at the top of the list.
//we can simply print the value at the top using arr[top-1]
//time complexity : O(1) constant number of operations are being performed
int peek(int arr[]){
  if(top>0){
    return arr[top-1];
  }
  return -1;
}

//size of the list is represented by the pointer TOP.
//time complexity : O(1) constant number of operations are being performed
int size(){
  return top;
}

//We can simply compare value of top to determine if stack is empty or is full
//if the value of top is zero, stack is empty
//time complexity : O(1) constant number of operations are being performed
int isempty(){
  if(top==0){
    return 1;
  }
  return 0;
}

//similarly, if the stack is full, top will be equal to n(max size)
//time complexity : O(1) constant number of operations are being performed
int isfull(int n){
  if(top==n){
    return 1;
  }
  return 0;
}

//printing stack is a simple function
//time complexity : O(n)
void printstack(int arr[]){
  for(int i=top-1; i>=0; i--){
    printf("%d\n", arr[i]);
  }
}

int main(){
  int n;
  scanf("%d", &n);
  //dynamically allocating memory for arr

  int *arr;
  arr = (int *) malloc(sizeof(int)*n);

  //s will be the input sting
  char s[10];

  //defining all other strings so we can use strmp function
  char pustr[10]="PSH";
  char postr[10]="POP";
  char tostr[10]="TOP";
  char prstr[10]="PRT";
  char sistr[10]="SZE";
  char emstr[10]="EMP";
  char fustr[10]="FUL";

  while(feof(stdin)==0){
    scanf("%s", s);
    if(strcmp(s,pustr)==0){
      int temp,a;
      scanf("%d", &temp);
      //if input is more than or equal to 0, we push it
      if(temp>=0){
        a=push(arr,temp,n);
      }
      //if the input is less than zero, we simply output -1 and then continue the while loop
      if(temp<0){
        printf("-1\n");
        continue;
      }
      if(a<0){
        printf("%d\n", a);
      }
    }
    if(strcmp(s,postr)==0){
      int a=pop(arr);
      printf("%d\n", a);
    }
    if(strcmp(s,tostr)==0){
      int a=peek(arr);
      printf("%d\n", a);
    }
    if(strcmp(s,prstr)==0){
      printstack(arr);
    }
    if(strcmp(s,sistr)==0){
      int a=size(arr);
      printf("%d\n", a);
    }
    if(strcmp(s,emstr)==0){
      int a=isempty(arr);
      printf("%d\n", a);
    }
    if(strcmp(s,fustr)==0){
      int a=isfull(n);
      printf("%d\n", a);
    }
  }

  //freeing the dynamically allocated memory
  free(arr);

  //saying everything went fine
  return 0;
}
