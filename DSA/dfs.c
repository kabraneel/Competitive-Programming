//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int edges[100][100];

//this represents a node of the graph, for this program we only need the color of the node
struct graph_node{
  char color;
};



void dfs_visit(int n, struct graph_node points[], int i);
void dfs(int n, struct graph_node points[]);


//this is the dfs_visit function
void dfs_visit(int n, struct graph_node points[], int i){

  //change the color to visited
  points[i].color = 'G';

  for(int j=0; j<n; j++){

    //if an edge exits bw i and j condition
    if(edges[i][j]==1){

      //if the edge is already visited, it means the the edge i to j
      //is not required in the UNIQUE forest of graph G
      //hence if at any point we try to access a node which is already visited, we then remove the edge
      // the edge is removed by making the (u,v) cell in the matrix = 0

      if(points[j].color == 'B' || points[j].color == 'G'){
        edges[i][j] = 0;
      }

      //if the point is unvisited, then we visit it
      if(points[j].color == 'W'){
          dfs_visit(n , points,j);
      }
    }
  }

  //the point is now fully explored
  points[i].color = 'B';
}

void dfs(int n, struct graph_node points[]){

  //we first need to make all the color of the points unvisited
  for(int i=0; i<n; i++){
    points[i].color='W';
  }

  //so here, we are checking if an edge exists between the current node and any other node in the graph
  //if an edge doesnt exist from the current node, there is no point in visting the node
  for(int i=0; i<n; i++){
    int count =0;
    for(int j=0; j<n; j++){
      if(edges[i][j]==1){
        count =1;
        break;
      }
    }

    //the node is unvisited and there exists some edge from the node to another node
    if(points[i].color == 'W' && count ==1){
       dfs_visit(n, points, i);
    }
  }

  //after all the nodes are explored, then all the not required edges are removed, and hence we can simply
  //print all the edges in the required order
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(edges[i][j] == 1){
        printf("(%d,%d)\n", i,j);
      }
    }
  }
}



int main(){

  //input the number of vertices required
  int n;
  scanf("%d", &n);

  //make an array of n nodes
  struct graph_node points[n];

  //first we make sure there is no edge between any two nodes
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }

  //while the input is given
  while(feof(stdin)==0){
    int u,v;
    scanf("%d %d", &u, &v);

    //if u,v is given, there exists an edge between u and v
    edges[u][v] =1;
  }

  //call dfs on the graph
  dfs(n,points);
/*
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d ",edges[i][j]);
    }
    printf("\n");
  }
*/

  return 0;
}
