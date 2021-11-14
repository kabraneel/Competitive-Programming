//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


//the node of the tree contains integer data
//it also contains pointers to left child, right child and parent
struct treenode{
  int treedata;
  struct treenode *parent;
  struct treenode *left;
  struct treenode *right;
};

//each element of the queue contains a node of the tree
struct listnode{

  struct treenode *data;
  struct listnode *next;

};


//making the root NULL
struct treenode *root = NULL;

//the head of the linked list points to NULL
struct listnode *start = NULL;

//enqueuing means adding a node to the list at the end
void enqueue(struct treenode *temp){

  struct listnode *newNode = (struct listnode *)malloc(sizeof(struct listnode));
  newNode->data = temp;
  newNode->next = NULL;

  if(start == NULL){
    start = newNode;
    return;
  }

  //traverse till the end of the list
  struct listnode *t = start;

  while(t->next!=NULL){
    t = t->next;
  }

  //make the next of the last point to newNode
  t->next = newNode;
}

//dequeue means removal of the first element of the linked list
//removing first element simply means making the start to next
void dequeue(){
  start = start -> next;
}

//peekfront() returns the element at the front of the queue
struct treenode* peekfront(){
  if(start == NULL){
    return NULL;
  }

  return start->data;
}

//createtree creates the first node in the tree
void createtree(int x){

  //allocating memory for the root node
  struct treenode *temp = (struct treenode *) malloc(sizeof(struct treenode));

  //making the data x
  temp->treedata = x;

  //making the parent point to NULL
  temp->parent = NULL;

  //both children point to NULL
  temp->left = NULL;
  temp->right = NULL;


  root = temp;

  //we now enqueue the root
  enqueue(root);
}


void insertnode(int x){

  //we take out the first element of the queue
  struct treenode *temp = peekfront();
  struct treenode *newNode = (struct treenode *) malloc(sizeof(struct treenode));


  newNode->treedata = x;
  newNode->parent = temp;
  newNode->left = NULL;
  newNode->right = NULL;

  //if there is no left child on then we make the left child point to new node
  if(temp->left == NULL){
    temp->left = newNode;
    enqueue(newNode);
  }

  //else, we make the right child point to newNode
  else if(temp->right == NULL){
    temp->right = newNode;
    enqueue(newNode);

    //both left and right child have been allocated, now we can simply remove the node from the list
    dequeue();
  }

}

//printing the inorder traversal output
void inorder(struct treenode *root, int n){

  //since recursion is not allowed, we will use stacks to complete the inorder traversal
  struct treenode* stack[n];
  int size=0;

  //make the traversing variable temp
  struct treenode *temp = root;


  //if the size is zero and temp is NULL, we are done traversing
  while((size!=0 || temp!=NULL )){

    //go till the left leaf of temp
    while(temp!=NULL){
      stack[size] = temp;
      size++;
      temp = temp->left;
    }

    //now, we need to pop the node before the temp became NULL
    struct treenode* temp1;

    //equivalent to top()
    temp1 = stack[size-1];
    //equivalent to pop()
    size--;

    //printing the data of the node
    printf("%d ", temp1->treedata);

    //now we need to repeat the same procedure for the right subtree
    temp = temp1->right;
  }

  printf("\n");
}

void preorder(struct treenode *root, int n){

  //similar to inorder, we can just change the postioning of the printf statement..
  struct treenode* stack[n];
  int size=0;

  struct treenode *temp = root;

  //same as inorder traversal
  while((size!=0 || temp!=NULL )){


    while(temp!=NULL){
      stack[size] = temp;
      size++;
      //in this case, we have to print the data of the node when we visit it
      printf("%d ", temp->treedata);
      temp = temp->left;
    }

    struct treenode* temp1;

    //equivalent to top()
    temp1 = stack[size-1];

    //equivalent to pop()
    size--;

    //repeat the same procedure for right subtree
    temp = temp1->right;
  }
  printf("\n");
}


void postorder(struct treenode *root, int n){

  //post order traversal is different from inorder and preorder

  /*
  here we need to use two stacks for the implementation
  nodes are pushed into the first stack when they are visited
  for each node, we need to print left subtree, followed by right subtree, followed by the nodes data
  so when we encounter a node, we push into another stack, and then push their right subtree and then their left subtree
  when printing the second stack, this ensure that the nodes data is printed last ..
  */

  //the two stacks
  struct treenode* stack1[n];
  struct treenode* stack2[n];
  int size1=0;
  int size2 = 0;

  //pushing root into stack1
  stack1[0] = root;
  size1++;

  //we now need to repeat until stack1 isnt empty
  while(size1!=0){
    struct treenode *temp = stack1[size1-1];
    size1--;

    //now push the children of the popped node into stack1
    if(temp->left!=NULL){
      stack1[size1] = temp->left;
      size1++;
    }

    if(temp->right!=NULL){
      stack1[size1] = temp->right;
      size1++;
    }

    //push node into stack2
    stack2[size2] = temp;
    size2++;

  }

  //we can simply print values of stack2

  for(int i=0; i<size2; i++){
    printf("%d ", stack2[size2-i-1]->treedata);
  }
  printf("\n");
}

//function used to find the path
void findpath(struct treenode* root, int x){

  /*
  we will use the concept that parent of each node is (x-1)/2 (for zero based indexing)
  so, given a node, we can keep finding parents until we reach the root
  and then we can print the nodes's data in reverse order

  if x is 5, list will store [5,2,0]
  then print node(0), node(2), node(5)
  */
  int traverse[100];
  int i=0;
  while(x!=0){

    traverse[i] = x;
    x = (x-1)/2;
    i++;

  }

  printf("%d$", root->treedata);

  struct treenode *temp = root;

  for(int j=0; j<i; j++){
    if(traverse[i-j-1]%2 == 0){
      temp=temp->right;
    }
    else{
      temp= temp->left;
    }

    printf("%d$", temp->treedata);
  }
  printf("\n");
}


int main(){

  char *s;
  int n=0;
  while(feof(stdin)==0){//until input is stopped

    scanf("%s ", s);

    if(strcmp(s, "INS")==0){
      //scanning the value to be inserted
      int x;
      scanf("%d ", &x);
      n++;
      //if there is only one node, then we create, else we insertnode
      if(n == 1){
        createtree(x);
        continue;
      }
      insertnode(x);
    }

    if(strcmp(s,"INO")==0){

      inorder(root,n);

    }

    if(strcmp(s,"PRE") == 0){

      preorder(root,n);

    }

    if(strcmp(s,"PST")==0){

      postorder(root,n);

    }

    if(strcmp(s,"PTH") == 0){

      int x;
      scanf("%d ", &x);

      findpath(root,x);

    }

  }
  return 1;
}
