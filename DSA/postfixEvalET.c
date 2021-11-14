//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



//this represents a node of the tree, for this program we need a pointer to the left child, a pointer to the right child, parent and the data value
struct tree_node{
  char chardata;
  int intdata;
  struct tree_node *left;
  struct tree_node *right;
  struct tree_node *parent;
};


//we will now make a linked list containing tree nodes
struct node{
  struct tree_node *data;
  struct node* next;
};


struct node* start=NULL;

//we will require the below functions for implementation of the algorithm
//push, pop, top
int push(struct tree_node *temp);

struct tree_node* pop();
struct tree_node* top();

//push() is used to push into the linked list
int push(struct tree_node *newNode){

  struct node *temp = start;

  if(start==NULL){
    temp = (struct node*) malloc(sizeof(struct node));
    start = temp;
    start -> next = NULL;
    start -> data = newNode;
    return 1;
  }

  else{
    temp = (struct node*) malloc(sizeof(struct node));

    temp->data = newNode;
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
struct tree_node* pop(){
  if(start==NULL){
    return NULL;
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

  struct tree_node *temp=q->next->data;
  q->next=NULL;
  return temp;
}

struct tree_node* top(){
  if(start==NULL){
    return NULL;
  }

  struct node * temp=start;

  while(temp->next!=NULL){
    temp=temp->next;
  }

  return temp->data;
}

int isempty(){
  if(start == NULL){
    return 1;
  }
  return -1;
}

int flag = 1;

//this function is used to add a node to the expression tree from the given string
void add_node(char s[]){

    struct tree_node *newnode;
    newnode = (struct tree_node*) malloc(sizeof(struct tree_node));

    //make the left and right children nodes NULL
    newnode->left = NULL;
    newnode->right = NULL;


    //if the character is a operator, we need to pop two nodes from the linked list, make them the chilren,
    //and push the newNode back into the list
    if(strcmp("+",s)==0 || strcmp("-",s)==0 || strcmp("*",s)==0 || strcmp("/",s)==0){

      struct tree_node *temp1, *temp2;

      newnode->chardata = s[0];

      //if it is empty, we cannot pop, and the input becomes invalid
      if(isempty()==1){
        flag =0;
        return;
      }

      temp1 = pop();

      //if it is empty, we cannot pop, and the input becomes invalid
      if(isempty()==1){
        flag = 0;
        return;
      }
      temp2 = pop();

      newnode->left = temp2;
      newnode->right = temp1;

      push(newnode);

    }

    //if its not character, then we simply push the newNode
    else{

      newnode->intdata = atoi(s);
      push(newnode);

    }
}


int compute(struct tree_node *root){

  //the compute function is a simply in order traveral of the expression tree
  if(root->left!=NULL && root->right!=NULL){

      int a =compute(root->left);
      int b =compute(root->right);

      //get the operation of the chardata, and then apply that operation to a and b
      if(root->chardata == '+'){
        return a+b;
      }

      if(root->chardata == '*'){
        return a*b;
      }

      if(root->chardata=='-'){
        return a-b;
      }

      if(root->chardata =='/'){
        if(b==0){
          //if b==0, then we are attempting a div by zero
          printf("division by 0");
          exit(0);
        }
        return a/b;
      }
  }

  else{
      //base case of recursion
      return root->intdata;
  }

}

int main(){

  int tempflag=0;

  while(feof(stdin) == 0){

    tempflag++;
    char temp[10];
    scanf("%s ", temp);
    add_node(temp);

  }

  //if there is no input
  if(tempflag==1){
    printf("invalid");
    return 2;
  }

  struct tree_node *root=pop();

  //if the linked list has more than zero nodes, its invalid
  if(isempty()==-1){
    printf("invalid");
    return 1;
  }

  //if we try to pop an empty list
  if(flag == 0){
    printf("invalid");
    return 1;
  }

  //if we reach here, the input is not invalid,
  //we can simply print the result...
  printf("%d",compute(root));

  return 1;
}
