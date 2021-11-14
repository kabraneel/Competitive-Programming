//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//structure for each node in the linked list
struct node{
  int data;
  struct node* next;
};

typedef struct node Node;

//insertion of a node into the linked list
//head would be head of ith linked list
//this function returns the head of the new linked list

Node* insert(int x, Node* head){

  Node* temp = head;

  Node* newNode = (Node*) malloc(sizeof(Node*));
  newNode->data = x;
  newNode->next = NULL;

  //if the linked list is empty, we add a node and return head
  if(head == NULL){
    head = newNode;
    return head;
  }

  //traversing through the list
  while(temp->next!=NULL){

    //if we find a node containing the data, we simply return NULL
    if(temp->data == x){
      return NULL;
    }
    temp=temp->next;
  }

  if(temp->data==x){
    return NULL;
  }

  //we add newNode at the end
  temp->next = newNode;

  return head;
}

Node* delete(int x, Node* head){

  Node* temp = head;

  //if list is empty, return NULL
  if(head==NULL){
    printf("-1\n");
    return head;
  }

  //if the heads data is x, then we can delete that node itself
  if(head->data ==x){
    head = head->next;
    return head;
  }

  //traverse till we hit a node with data x or the end
  while(temp->next!=NULL){
    if(temp->next->data == x){
      temp->next = temp->next->next;
      return head;
    }
    temp = temp->next;
  }

  //if the control reaches here, x wasnt found
  printf("-1\n");
  return head;
}

//simply traverse and print the data
void print(Node* head){

  if(head==NULL){
    printf("-1\n");
    return;
  }

  Node* temp = head;

  while(temp!=NULL){
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

//searching x is simply traversing and returning if we hit x
//if we hit x, we return Y
//if we reach the end, we return N
char search(int x, Node* head){

  Node* temp = head;

  while(temp!=NULL){
    if(temp->data==x){
      return 'Y';
    }
    temp = temp->next;
  }

  return 'N';
}

int main(){

  //we scan m and then we we allocate memory for m heads
  int m=0;
  scanf("%d ", &m);

  Node* *arr;

  //allocate memory for m heads
  arr = malloc(m*sizeof(Node*));
  for(int i=0; i<m; i++){
    arr[i] = NULL;
  }

  char s[10];
  //nt t=100;
  while(feof(stdin)==0){//until input is stopped

    scanf("%s ", s);
    Node* t;

    if(strcmp(s, "INS")==0){
      //scanning the value to be inserted
      int x;
      scanf("%d ", &x);

      //we have to add value to x%mth linked list
      int index = x%m;

      //if t is NULL, the value already exists
      //otherwise, we need to change the value of the head
      t = insert(x, arr[index]);
      if(t==NULL){
        printf("-1\n");
      }
      else{
        arr[index] = t;
      }

    }

    //print the required linked list
    if(strcmp(s,"PRT")==0){

      int x;
      scanf("%d ", &x);

      print(arr[x]);

    }

    //delete the element from the ith linked list
    //the node gets deleted and head gets updated
    if(strcmp(s,"DEL") == 0){

      int x;
      scanf("%d ", &x);

      int index = x%m;

      arr[index] = delete(x,arr[index]);
    }

    //searching function called here
    if(strcmp(s,"SRCH")==0){

      int x;
      scanf("%d ", &x);

      int index = x%m;
      printf("%c\n",search(x, arr[index]));

    }
  }
  return 1;
}
