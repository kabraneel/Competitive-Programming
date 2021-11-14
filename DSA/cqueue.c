//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//initializing front as -1(denoting empty queue)
//rear as 0
int front=-1;
int rear=0;

//following are the various functions of the queue
int enqueue(int arr[], int x, int n);
int dequeue(int arr[], int n);
int peekfront(int arr[], int n);
int size(int n);
int isempty(int n);
int isfull(int n);
void printqueue(int arr[], int n);

//enqueue adds element at the end of the queue
//if rear becomes n, we have to reset the value of rear to 0
//time complexity = O(1), consant number of operations are performed
int enqueue(int arr[], int x, int n){
  if(n==0){
    return -1;
  }
  //check overflow, if queue is full, cannot enqueue an element
  if(isfull(n)==0){
    if(front<0){
      front = rear;
    }
    rear++;
    arr[rear-1]=x;
    if(rear==n){
      rear=0;
    }
    return 1;
  }
  return -1;
}

//deqeue is use to delete an element from the front of the queue
//as with rear, if front becomes n, we have to ensure that if queue becomes empty, we put the value of front as -1 again, denoting empty queue
//time complexity = O(1), consant number of operations are performed
int dequeue(int arr[], int n){
  if(front==-1){
    return -1;
  }
  front++;
  //if value of front becomes n, we make it zero again
  if(front==n){
    front = 0;
  }

  int temp = front;
  if(front == rear){
    //queue is empty, we need to make value of front -1 again
    front = -1;
  }
  //we now need to return the value deleted
  if(temp==0){
    return arr[n-1];
  }
  return arr[temp-1];
}

//isempty returns 0 when queue is not empty
int isempty(int n){
  //special codn for n=0(i.e array size = 1)
  if(n==0){
    return 0;
  }
  if(front == -1){
    return 1;
  }
  return 0;
}

//peekfront returns the element at the position first
//time complexity = O(1), consant number of operations are performed
int peekfront(int arr[],int n){
  //special case for n==0
  if(n==0){
    return -1;
  }
  //if queue is empty, we operation is unsuccessful, i.e. return -1
  if(isempty(n)==1){
    return -1;
  }
  return arr[front];
}

//returns the value of size
int size(int n){
  if(front==-1){
    return 0;
  }
  int temp = rear - front;
  if(temp<=0){
    temp = n - (-1)*temp;
  }
  return temp;
}

//returns 1 if the queue is is full
//simply checks if rear and front have same values
//time complexity = O(1), consant number of operations are performed
int isfull(int n){
  //special case for n==1
  if(n==0){
    return 1;
  }
  if(front==rear){
    return 1;
  }
  return 0;
}

//prints the queue
//diff cases are made for full and non-full queues
void printqueue(int arr[],int n){
  //special case for n==1
  if(n==0){
    return;
  }
  //for full queues
  if(isfull(n)==1){
    if(front==0){
        int i=0;
        while(i<n){
          printf("%d\n", arr[i]);
          i++;
        }
    }
    else{
      int i=front;
      while(i!=front-1){
        printf("%d\n", arr[i]);
        i++;
        if(i==n){
          i=0;
        }
      }
    printf("%d\n", arr[i]);
    }
  }
  //for non- full queues

  //checking underflow
  if(front>=0){
    int i=front;
    while(i!=rear){
      printf("%d\n", arr[i]);
      i++;
      if(i==n){
        i=0;
      }
    }
  }
}

int main(){
  int n;
  scanf("%d", &n);
  //dynamically allocating memory for arr
  n--;
  int *arr;
  arr = (int *) malloc(sizeof(int)*n);

  //s will be the input sting
  char s[10];

  //defining all other strings so we can use strmp function
  char qustr[10]="ENQ";
  char destr[10]="DEQ";
  char pestr[10]="FRN";
  char prstr[10]="PRT";
  char sistr[10]="SZE";
  char emstr[10]="EMP";
  char fustr[10]="FUL";

  while(feof(stdin)==0){
    scanf("%s", s);
    if(strcmp(s,qustr)==0){
      int temp,a;
      scanf("%d", &temp);
      if(temp>=0){
        a=enqueue(arr,temp,n);
      }
      if(a<0){
        printf("%d\n", a);
      }
    }
    if(strcmp(s,destr)==0){
      int a=dequeue(arr,n);
      printf("%d\n", a);
    }
    if(strcmp(s,pestr)==0){
      int a=peekfront(arr,n);
      printf("%d\n", a);
    }
    if(strcmp(s,prstr)==0){
      printqueue(arr,n);
    }
    if(strcmp(s,sistr)==0){
      int a=size(n);
      printf("%d\n", a);
    }
    if(strcmp(s,emstr)==0){
      int a=isempty(n);
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
