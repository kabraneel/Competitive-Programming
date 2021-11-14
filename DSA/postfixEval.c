//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//we will create a stack using
struct node{
  int  data;
  struct node* next;
};

struct node* start=NULL;

//using the following functions for stack
int ins_end(int data);
int delete_end();

//inserting at end or push
int ins_end(int data){
  struct node *temp = start;

  if(start==NULL){
    temp = (struct node*) malloc(sizeof(struct node));
    start = temp;
    start -> next = NULL;
    start -> data = data;
    return 1;
  }

  else{
    temp = (struct node*) malloc(sizeof(struct node));

    temp->data = data;
    temp->next = NULL;

    struct node *q=start;
    while(q->next!=NULL){
      q=q->next;
    }
    q->next=temp;
  }
  return 1;
}

//deleting at end or pop
int delete_end(){
  if(start==NULL){
    return 0;
  }

  struct node* q=start;

  //check if linked list has only one element
  if(q->next==NULL){
      start = NULL;
      return q->data;
  }

  while(q->next->next!=NULL){
    q=q->next;
  }

  int temp=q->next->data;
  q->next=NULL;
  return temp;
}

//prints the top value
int top(){
  if(start==NULL){
    return 0;
  }

  struct node * temp=start;

  while(temp->next!=NULL){
    temp=temp->next;
  }

  return temp->data;
}

//prints the list
void printlist(){
  struct node* temp = start;

  while(temp!=NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
}

//isempty() is used to check if the list is currently empty
int isempty(){
  if(start == NULL){
    return -1;
  }
  return 1;
}


int main(){
  int pos = 0;
  int valid = 1;
  int flag=0;
  while(feof(stdin)==0){
    flag++;
    char str[100];
    scanf("%s ", str);
    int first,second;
    //if the character is an operator, we need to pop two operands
    if(strcmp(str,"+")==0 || strcmp(str,"-")==0 || strcmp(str,"*")==0|| strcmp(str,"/")==0){
      //checking if stack is empty before popping first
      if(isempty()==-1){
        valid =0;
        break;
      }
      first = delete_end();

      //checking if stack is empty before popping second
      if(isempty()==-1){
        valid = 0;
        break;
      }
      second = delete_end();

      //ans represents the value to be computed(based on operator)
      int ans=0;
      if(strcmp(str,"+")==0){
        ans = first + second;
      }
      else if(strcmp(str, "-")==0){
        ans = second - first;
      }
      else if(strcmp(str,"*")==0){
        ans = first*second;
      }
      else if(strcmp(str,"/")==0){
        if(first ==0){
          //if the divisor is zero, we need to break
          valid =2 ;
          break;
        }
        ans = second/first;
      }
      //inserting ans to the end of the list
      ins_end(ans);
    }
    else{
      //the atoi function converts a string to an integer
      int a = atoi(str);
      ins_end(a);
    }
  }

  //if the value of valid is 2, it means that divisor was zero sometime
  if(valid == 2){
      printf("division by 0");
      return 0;
  }

  //value is zero means we tried to pop and empty list
  if(valid ==0){
    printf("invalid\n");
    return 0;
  }

  //the last element in the stack should be the answer
  int y = delete_end();

  //after popping the last value, we need to check if the stack is empty,if not then input was invalid
  if(isempty()==-1 && flag>1){
    printf("%d", y);
  }

  //stack not empty
  else{
    printf("invalid\n");
  }

  //say everything went fine
  return 0;
}
