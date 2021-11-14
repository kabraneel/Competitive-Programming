#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct node{
  int data;
  struct node* next;
};

struct node* start=NULL;


int ins_beg(int data);
int ins_end(int data);
int insertpos(int x, int y);
int delete(int x);
int isempty();
int size_of();
void printlist();
int findmind();
int search(int x);


int ins_beg(int data){
  struct node *temp;
  temp =(struct node *)malloc(sizeof(struct node));

  if(start==NULL){
    start = temp;
    start->data = data;  //see here
    start->next=NULL;   //see here
  }

  else{
    temp->next = start;
    temp->data = data;
    start=temp;
  }

  return 1;
}

int ins_end(int data){
  struct node *temp = start;

  if(start==NULL){
    //start == NULL means the linked list is empty
    temp = (struct node*) malloc(sizeof(struct node));
    start = temp;
    start -> next = NULL; //see here
    start -> data = data; //see here
    return 1;
  }

  else{
    //here temp is the newNode
    temp = (struct node*) malloc(sizeof(struct node));

    //we want temp to point to NULL(because its the last element)
    temp->data = data;
    temp->next = NULL;

    //now we traverse through the linked list
    struct node *q=start;
    while(q->next!=NULL){
      q=q->next;
    }
    q->next=temp;
  }
  return 1;
}

int insertpos(int x, int y){

  if(start==NULL){
    return -1;
  }

  struct node *temp,*temp1;

  temp=(struct node *) malloc(sizeof(struct node));
  struct node *q= start;

  //pos variable to check if the element with data y exists in the list
  int pos=1;
  while(q!=NULL){
  //  printf("%d \n", q->data);
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

  temp1 = q->next;
  q->next =temp;
  temp->next = temp1;
  temp->data = x;

}

int delete(int x){

  if(start==NULL){
    return -1;
  }

  struct node* q=start;
  int pos =1;

  //check if linked list has only one element
  if(q->next==NULL){
    if(q->data==x){
      start = NULL;
      return 1;
    }
    return -1;
  }

  //now to check if the first element itself has to be deleted
  if(q->data==x){
    start=q->next;
    return 1;
  }

  while(q->next!=NULL){
    if(q->next->data==x){
      pos = -1;
      break;
    }
    q=q->next;
  }

  if(pos==1){
    if(q->data==x){
      q->next=NULL;
      return 1;
    }
    return -1;
  }

  else{
    q->next = q->next->next;
    return 1;
  }
}

int isempty(){
  if(start == NULL){
    return 1;
  }
  return 0;
}

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


void printlist(){
  struct node* temp = start;

  while(temp!=NULL){
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

int findmid(){
  int size= size_of();

  if(size==0){
    return -1;
  }
  struct node* temp=start;

/*  if(size == 1){
    return temp->data;
  }*/

  size=size/2;


  for(int i=0; i<size; i++){
      temp = temp->next;
  }

  return temp->data;
}

int search(int x){

  if(start==NULL){
      return -1;
  }

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




char* str;


while(feof(stdin)==0)  //until input is stopped
{
scanf("%s",str);
if (strcmp(str,"INS-B")==0)
{
int x;
scanf("%d",&x);
ins_beg(x);

}
if (strcmp(str,"INS-E")==0)
{
int x;
scanf("%d",&x);
ins_end(x);
}

if (strcmp(str,"INS-A")==0)
{
int x,y;
scanf("%d %d",&x,&y);
int a=insertpos(x,y);
if(a<0)
printf("-1\n");
}
if (strcmp(str,"DEL")==0)
{
int x;
scanf("%d",&x);
int a=delete(x);
if(a<0)
printf("-1\n");
}
if (strcmp(str,"SZE")==0)
{
printf("%d\n",size_of());
}
if (strcmp(str,"EMP")==0)
{
printf("%d\n",isempty());
}
if (strcmp(str,"PRT")==0)
{
printlist();
}
if (strcmp(str,"MID")==0)
{
printf("%d\n",findmid());
}
if (strcmp(str,"SRCH")==0)
{
int x;
scanf("%d",&x);
printf("%d\n",search(x));
}
}
return 0;
}
