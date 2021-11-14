//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//the basic structure of each node
struct node{
  char data;
  struct node* next;
  struct node* prev;
};

//we need to initialise our start to NULL, which is the variable pointing to the first node
struct node* start=NULL;

//The list of basic functions required for the program
int ins_beg(char x);
int ins_end(char x);
int insertpos(char x, char y);
void printlistreverse();
int isempty();
int size_of();
void printlist();
int palindrome();
int search(char x);

//function to insert at the front
int ins_beg(char x){
  //the node which we will add
  struct node *temp;
  //we also need to allocate the memory for the node
  temp =(struct node *)malloc(sizeof(struct node));

  //we now need to check whether the list we initially had was empty
  //in that case, we need to create the node accordingly and make the next NULL
  if(start==NULL){
    start = temp;
    temp->next=NULL;
    temp->data = x;
    temp->prev=NULL;
  }


  else{

    //newNode Allocation
    temp->next = start;
    temp->prev = NULL;
    temp->data = x;

    //prev of second node points to newNode
    start->prev = temp;

    //start points to newNode
    start=temp;
  }
  return 1;
}

//fn to add node to the end
int ins_end(char x){
  struct node *temp = start;

  if(start==NULL){
    //start == NULL means the linked list is empty
    temp = (struct node*) malloc(sizeof(struct node));
    start = temp;
    temp -> next = NULL;
    temp -> data = x;
    temp -> prev = NULL;
  }

  else{
    //here temp is the newNode
    temp = (struct node*) malloc(sizeof(struct node));

    //we want temp to point to NULL(because its the last element)
    temp->data = x;
    temp->next = NULL;

    //now we traverse through the linked list
    struct node *q=start;
    while(q->next!=NULL){
      q=q->next;
    }
    q->next=temp;
    temp->prev = q;
  }
  return 1;
}

//fn to insert at a position with data as y
int insertpos(char x, char y){

  if(start==NULL){
    return -1;
  }

  struct node *temp,*temp1;

  temp=(struct node *) malloc(sizeof(struct node));
  struct node *q= start;

  //pos variable to check if the element with data y exists in the list
  int pos=1;

  while(q!=NULL){
    if((q->data)==y){
      pos=-1;
      break;
    }
    q=q->next;
  }

  //to check if element isnt present
  if(pos==1){
    return -1;
  }

  //here, temp is the newNode we created
  //simple array manipulations to add node temp at position q
  temp->prev=q;
  temp->data=x;
  temp->next=q->next;
  q->next=temp;
  q->next->prev=temp;

}

//fn to check if linked list is empty,we simply check the variable start
int isempty(){
  if(start == NULL){
    return 1;
  }
  return 0;
}

//size_of requires simple traversal from the start array till NULL, incrementing count
int size_of(){
  if(start==NULL){
    return 0;
  }

  int size=0;
  struct node* temp= start;
  while(temp!=NULL){
    size++;
    temp = temp->next;
  }
  return size;
}

//printing array requires to traverse through the linked list, printing the data of each node
void printlist(){
  struct node *temp=start;
  while(temp!=NULL){
    printf("%c\n",temp->data);
    temp=temp->next;
  }

  return;
}

//prints list in reverse
void printlistreverse(){
  //variable temp is used for traversal
  struct node *temp=start;
  if(temp==NULL){
    return;
  }

  //we now have the last nodes pointer in temp

  while(temp->next!=NULL){
    temp=temp->next;
  }

  //we can simply use prev to traverse backwards
  while(temp!=NULL){
    printf("%c\n",temp->data);
    temp=temp->prev;
  }
  return;
}

//fn to check if the linked list stores a palindrome
int palindrome(){
  //we simply need to traverse forwards and backwards, and keep comapring the values
  struct node* end=start;

  //variable end needs to traverse till the end
  while(end->next!=NULL){
    end=end->next;
  }

  //now we need two variables to traverse through the linked list
  struct node* tempfront=start;
  struct node* tempback=end;

  //we simply need to check first half to second half, in other words we need to (size/2) checks
  int n=size_of();
  n=n/2;
  int pos=1;

  //loop to check the the nodes
  for(int i=0; i<n; i++){
    if(tempfront->data!=tempback->data){
      pos = -1;
      break;
    }
    tempfront=tempfront->next;
    tempback = tempback->prev;
  }

  if(pos==-1){
    return 0;
  }
  return 1;
}

//to search the first occurance of x in the list
int search(char x){

  //empty check
  if(start==NULL){
      return -1;
  }

  //simply traverse till we hit a node with data x or hit NULL
  struct node *temp = start;
  int count =1;
  int pos=1;

  while(temp!=NULL){
    if(temp->data==x){
      pos=-1;
      break;
    }
    count++;
    temp=temp->next;
  }

  if(pos==-1){
    return count;
  }
  return -1;
}

int main()
{

  char* str;//the input string

  while(feof(stdin)==0){
    scanf("%s ",str);

    if (strcmp(str,"INS-B")==0){
      char x;
      scanf(" %c",&x);
      ins_beg(x);
    }

    if (strcmp(str,"INS-E")==0){
      char x;
      scanf(" %c",&x);
      ins_end(x);
    }

    if (strcmp(str,"INS-A")==0){
      char x,y;
      scanf(" %c %c",&x,&y);
      int a=insertpos(x,y);
      if(a<0)
        printf("-1\n");
    }

    if (strcmp(str,"PRT-R")==0){
      printlistreverse();
    }

    if(strcmp(str,"SZE")==0){
      printf("%d\n",size_of());
    }

    if (strcmp(str,"EMP")==0){
      printf("%d\n",isempty());
    }

    if (strcmp(str,"PRT")==0){
      printlist();
    }

    if (strcmp(str,"PAL")==0){
      printf("%d\n",palindrome());
    }

    if (strcmp(str,"SRCH")==0){
      char x;
      scanf(" %c",&x);
      printf("%d\n",search(x));
    }
  }
  return 0;
}
