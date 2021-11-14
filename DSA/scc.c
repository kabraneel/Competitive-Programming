//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//the following are global variables required

//itr is the sixe of each scc
int itr = 0;

//arr contains elements of an scc
int arr[100];

//edges contain edges of the original graph
int edges[100][100];

//edgesrev contain the edges of the reverse graph
int edgesrev[100][100];

//here struct graph_node represents the structure of the graph
struct graph_node{
  char color;
  int first;
  int last;
  int pred;
};

//node is an element in the stack
struct node{
  int data;
  struct node* next;
};


struct node* start=NULL;

int time = 0;

//ins_end is used to push into the linked list
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

//delete end is used to pop from the list
int delete_end(){
  if(start==NULL){
    return -1;
  }

  struct node* q=start;

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

void sortnprint();
void dfs();
void dfsvisit();


void sortnprint(){
  //this function sorts and prints the completed scc

  //using bubble sort on the array
  for(int i=0; i<itr; i++){
    for(int j=i+1; j<itr; j++){
      if(arr[j]<arr[i]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  //printing the array
  for(int i=0; i<itr; i++){
    printf("%d$", arr[i]);
  }
  printf("\n");
}


void dfs_visit(int n, struct graph_node points[], int i){

  //the dfsvisit on original graph function here

  //increment time, change color to visited and allocate the first visit time
  time ++;
  points[i].color = 'G';
  points[i].first = time;


  //if an edge exists and is unvisited, then we visit the edge
  for(int k=0; k<n; k++){
    if(edges[i][k] == 1){
      if(points[k].color == 'W'){
        points[k].pred = i;
        dfs_visit(n, points, k);
      }
    }
  }

  //now we allocate final time, and change color to explored
  time ++;
  points[i].color = 'B';
  points[i].last = time;

  //now, if the element is in the recursive call, then we need to add it in the SCC to be printed
  arr[itr] = i;
  itr++;
}


void dfs(int n, struct graph_node points[]){


  //we now have the stack which contains points last visited in increasing order

  //we need to make the color white again
  for(int i=0; i<n; i++){
    points[i].color='W';
  }


  //now, until the stack is empty, we need to keep visting the points
  int y = delete_end();

  //y == -1 indicates that the stack is empty
  while(y!=-1){
    //the variable itr represents the size of the scc
    itr= 0;

    //if point is unvisited, we visit it
    if(points[y].color == 'W'){
      //we visit this point
      dfs_visit(n,points,y);

      //after we visit the point, we have now completed one SCC
      //so we can sort and print it
      sortnprint();
    }

    //y is now the top of the stack again
    y = delete_end();
  }

}



void dfs_visitrev(int n, struct graph_node points[], int i);
void dfsrev(int n, struct graph_node points[]);


void dfs_visitrev(int n, struct graph_node points[], int i){

  //increment the time
  time++;

  //change the points first visit time
  points[i].first = time;

  //make the point visited
  points[i].color = 'G';

  //the main loop
  for(int j=0; j<n; j++){

    //this condition checks if an edge exists between point i and point j
    if(edgesrev[i][j]==1){

      //if the point is unvisited, then we visit it
      if(points[j].color == 'W'){
        //change the predecessor value and then visit the point j
        points[j].pred = i;
        dfs_visitrev(n , points,j);
      }
    }
  }

  //after the point is fully explored, which means the depth is fully explored
  //we change the color and the final visit time
  time++;
  points[i].color = 'B';
  points[i].last = time;

  //we the vertex into the stack
  ins_end(i);
}

void dfsrev(int n, struct graph_node points[]){

  //we first perform dfs on the reverse graph first

  //first make the color of the vertices white
  for(int i=0; i<n; i++){
    points[i].color='W';
  }

  //if the point isnt visited, we visit the point
  for(int i=0; i<n; i++){
    if(points[i].color == 'W'){
       dfs_visitrev(n, points, i);
    }
  }

  //after dfs on reverse graph is done, we need to make the time = 0 again
  time = 0;
}


int main(){

  //scaninng the number of vertices
  int n;
  scanf("%d", &n);

  //make an array of points
  struct graph_node points[n];

  //initialise the edges to zero, indicating no edges exist in the initial graph
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }

  //while input is given
  while(feof(stdin) == 0){
    int u,v;
    scanf("%d %d", &u, &v);

    //in the original graph, u to v edge exists
    edges[u][v] =1;

    //in the reverse, the edge is from v to u
    edgesrev[v][u] = 1;
  }

  //we first call dfsrev
  dfsrev(n,points);


  //then we call dfs
  dfs(n,points);
  
  return 0;
}
