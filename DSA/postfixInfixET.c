//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



//this represents a node of the tree, for this program we need a pointer to the left child, a pointer to the right child, parent and the data value
struct tree_node{
  char data;
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

  //we need to traverse until we reach the end
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

//pop() is used for popping the last element out of the linked list
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


//top() is used to get the last element in the linked list
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


//this function is used to built the epression tree from the given string
struct tree_node* buildtree(char s[], int n){


  //traveral through string
  for(int i=0; i<n; i++){


    //we need to create a newNode to be inserted into the linked list
    struct tree_node *newnode;
    newnode = (struct tree_node*) malloc(sizeof(struct tree_node));

    newnode->data = s[i];

    //the left child is NULL
    newnode->left = NULL;

    //right is also NULL
    newnode->right = NULL;
    newnode->parent = top();


    //if the character is a operator, we need to pop two nodes from the linked list, make them the chilren,
    //and push the newNode back into the list
    if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){

      struct tree_node *temp1, *temp2;

      temp1 = pop();
      temp2 = pop();

      newnode->left = temp2;
      newnode->right = temp1;

      push(newnode);

    }

    //if its not character, then we simply push the newNode
    else{

      push(newnode);

    }
  }

  //now the linked list only contains one element, which is the root
  struct tree_node *root = pop();

  //return the root of the expression tree
  return root;

}


//after the expression tree is computed, to print the required string we need to
//do an inorder traversal

void printinfix(struct tree_node *root){

  if(root->left!=NULL && root->right!=NULL){

    //we dont print bracket for the root node
    if(root->parent!=NULL){
      printf("(");
    }

    printinfix(root->left);

    printf("%c", root->data);

    printinfix(root->right);

    //since we didn't print the opening bracket for root, we need same number of closing brackets
    if(root->parent!=NULL){
      printf(")");
    }

  }

  else{

    printf("%c", root->data);

  }
}

int main(){

  char sin[100];

  //input the postfix string
  scanf(" %s", sin);

  //n is the length of the string
  int n = strlen(sin);


  struct tree_node *root;

  //root is now the root of the expression tree
  root = buildtree(sin,n);

  root->parent = NULL;

  //once the expression tree is created, we now need to print the tree
  printinfix(root);

  return 1;
}
