//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//for conversion of infix to post fix, we require a stack, which we will build using linked lists
struct node{
  char data;
  struct node* next;
};


struct node* start=NULL;

//we will require the below functions for implementation of the algorithm
//push(ins_end), pop(delete_end), top, printlist
int ins_end(char data);
char delete_end();
char top();
void printlist();

//ins_end is used to push into the linked list
int ins_end(char data){
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

//delete_end is used for popping out of the linked list
char delete_end(){
  if(start==NULL){
    return 'a';
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

  char temp=q->next->data;
  q->next=NULL;
  return temp;
}

//top is used to peek in the linked list
char top(){
  if(start==NULL){
    return 'a';
  }

  struct node * temp=start;

  while(temp->next!=NULL){
    temp=temp->next;
  }

  return temp->data;
}

//printlist is for printing the list
void printlist(){
  struct node* temp = start;

  while(temp!=NULL){
    printf("%c ", temp->data);
    temp = temp->next;
  }
}

//main starts here
int main(){
  //the string to be inputted
  char s[100];
  scanf("%s", s);

  //storing the length of the string in an integer n
  int n=strlen(s);

  //now we need to traverse through the string
  for(int i=0; i<n; i++){
    //if the character is a lowercase alphabet, then we simply print it
    if(s[i]<='z' && s[i]>='a'){
      printf("%c", s[i]);
      continue;
    }

    //if the character is an open bracket, we push it into the stack
    //calling ins_end to insert at the end
    else if(s[i]=='('){
      ins_end('(');
      continue;
    }

    //if the character is a closed bracket, we pop till we hit an open bracket
    else if(s[i]==')'){
      char y=delete_end();
      while(y!='('){
        printf("%c", y);
        y=delete_end();
      }
      continue;
    }

    //else, the character is a operation
    else{
      //we will store the value of top in y
      char y=top();

      //y == a denotes the stack is empty
      //if the stack is empty, simply push the operator
      if(y=='a'){
        ins_end(s[i]);
      }

      //if top is an open bracket, we need to push the operator
      else if(y=='('){
        ins_end(s[i]);
        continue;
      }

      //if the character is a '+' or '-'
      //all characters have a precedence lower or equal to '+' or '-'
      //so we pop all characters till we the stack is empty or we hit a '('
      else if(s[i]=='+' || s[i]=='-'){
        char temp = top();
        while(temp!='a' && temp!='('){
          char x = delete_end();
          temp = top();
          printf("%c",x);
        }
        ins_end(s[i]);
      }

      //if the character is '*' or '/'
      //if top has a char of lower precedence, we push it
      else if((s[i]=='*' || s[i]=='/') && (y == '+' || y == '-')){
        ins_end(s[i]);
      }

      //else we pop till we hit '+' or '-' or '(' or the stack is empty
      else if((s[i]=='*' || s[i]=='/') && (y == '/' || y == '*')){
        char temp = top();
        while(temp=='*' || temp=='/'){
          char x = delete_end();
          printf("%c",x);
          temp=top();
        }
        ins_end(s[i]);
      }
    }
  }

  //once all the elements have been traversed, we need to empty the stack
  char y=delete_end();

  while(y!='a'){
    printf("%c",y);
    y=delete_end();
  }
  return 0;
}
