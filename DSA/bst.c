//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//this contains a standard node of a tree
struct node {
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node Node;

//this takes a value x and makes a node from the data
Node* newNode(int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//prints the postorder traversal of the tree
void postorder(Node* root)
{
	if (root != NULL) {
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}

/*this function inserts a node into the tree and returns the root of the tree
*/
Node* insertnode(Node* node, int key){

  //base case of recursion
	if (node == NULL)
		return newNode(key);

  //if the key is less than the data, we have to insert into the left subtree
	if (key < node->data)
		node->left = insertnode(node->left, key);

  //if the key is more than the data, we have to insert into the right subtree
	else if(key>node->data)
		node->right = insertnode(node->right, key);

  //if the data == key, it means that the data already exists, so we return the node
	else
		return node;

	return node;
}

//this function returns the Node with the minimum value
Node* findmin(Node* node){
	Node* temp = node;

  //point to root, and go the left most leaf of the tree

	while (temp!=NULL && temp->left != NULL)
		temp = temp->left;

  //return the left most child
	return temp;
}

/*
similar to min, this function goes to right most leaf and returns the left node
*/
Node* findmax(Node* node){
	Node* temp = node;

	while (temp!=NULL && temp->right != NULL)
		temp = temp->right;

	return temp;
}

/*
this returns the root of the tree after the node is deleted
*/
Node* deleteNode(Node* root, int key){

	if (root == NULL){
		printf("-1\n");
		return root;
	}

  //if the key is less than roots data, we need to delete from the left subtree
	if (key < root->data)
		root->left = deleteNode(root->left, key);

  //if the key is more than roots data, we need to delete from the right subtree
	else if (key > root->data)
		root->right = deleteNode(root->right, key);

  //root is the node to be deleted
	else{

		//one child or no child case

		if (root->left == NULL){
			struct node* temp = root->right;
			free(root);
			return temp;
		}


		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

    //this is the inorder predecceser of the root node
		struct node* temp = findmax(root->left);

    //replacing data of the deleted node
		root->data = temp->data;

    //deleting the inorder predecceser
		root->left = deleteNode(root->left, temp->data);
	}

	return root;
}

int main(){

  char s[10];
  int n=0;

  //creating a root node of the tree
	Node* root = NULL;


  while(feof(stdin)==0){//until input is stopped

    scanf("%s", s);

  //  printf("%s\n", s);

    if(strcmp(s, "INS")==0){
      //scanning the value to be inserted
      int x;
      scanf("%d ", &x);

			root = insertnode(root, x);
    }

    if(strcmp(s, "DEL")==0){
      //scanning the value to be inserted
      int x;
      scanf("%d ", &x);

       root = deleteNode(root,x);
    }

    if(strcmp(s,"MAX")==0){

			Node* t = findmax(root);
			if(t==NULL){
				printf("-1\n");
			}
			else
      	printf("%d\n", t->data);

    }

    if(strcmp(s,"MIN")==0){

			Node *t = findmin(root);
			if(t==NULL)
				printf("-1\n");
			else
      	printf("%d\n", t->data);

    }

    if(strcmp(s,"PST")==0){

      if(root==NULL){
        printf("-1\n");
        continue;
      }
      postorder(root);
      printf("\n");
    }
  }
  return 1;
}
