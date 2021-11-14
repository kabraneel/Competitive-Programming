//111901057
//Neel
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int edges[100][100];

struct graph_node{
  char color;
};

void dfs_visit(int n, struct graph_node points[], int i);
void dfs(int n, struct graph_node points[]);


void dfs_visit(int n, struct graph_node points[], int i){
  points[i].color = 'G';

  for(int j=0; j<n; j++){
    if(edges[i][j]==1){
    //  printf("%c\n", points[j].color);
      if(points[j].color == 'B' || points[j].color == 'G'){
      //  printf("ha its already explored %d %d\n", i, j);
        edges[i][j] = 0;
      }

      if(points[j].color == 'W'){
          dfs_visit(n , points,j);
      }
    }
  }
  points[i].color = 'B';
}

void dfs(int n, struct graph_node points[]){
/*
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      printf("%d ",edges[i][j]);
    }
    printf("\n");
  }
*/

  for(int i=0; i<n; i++){
    points[i].color='W';
  }

  for(int i=0; i<n; i++){
    int count =0;
    for(int j=0; j<n; j++){
      if(edges[i][j]==1){
        count =1;
        break;
      }
    }

    if(points[i].color == 'W' && count ==1){
       dfs_visit(n, points, i);
    }
  }


  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(edges[i][j] == 1){
        printf("(%d,%d)\n", i,j);
      }
    }
  }
}

int main(){
  int n;
  scanf("%d", &n);
  struct graph_node points[n];
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      edges[i][j]=0;
    }
  }

  while(feof(stdin)==0){
    int u,v;
    scanf("%d %d", &u, &v);
    edges[u][v] =1;
  }

/*
  int m = 1;
  while(m>0){
    int u,v;
    scanf("%d %d", &u, &v);
    edges[u][v] =1;
    m--;
  }

*/


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
