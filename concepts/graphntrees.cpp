//TEMPLATE FOR GRAPH/TREES
//its a bad one but meh, ill improve it when i can
//kabra_neel's template

#include <bits/stdc++.h>
using namespace std;

struct graph_node{
  char color;
  int data;
  int pred;
  int first;
  int last;
};

const int maxn = pow(10,5);
vector<int> adj[maxn];
bool visited[maxn] = {false};
bool nvisited[maxn] = {false};
int ans=0;

void dfs(int n){

  for(int i=0; i<n; i++){
    if(visited[i]==false){
      dfs_visit(i);
    }
  }

}

dfs_visit(int i){

  visited[i] = true;
  for(auto& j: adj[i]){

    if(visited[j]==false){
      dfs_visit(j);
    }

    if(nvisited[i]==false && nvisited[j] == false){
      count++;
      nvisited[i]=true;
      nvisited[j] = true;
    }
  }
}


void bfs(int n, struct graph_node points[]){

  queue<int> q;
  for(int i=1; i<n; i++){
    points[i].color = 'W';
  }

  points[0].color = 'G';
  q.push(0);
  points[0].data = 1;

  while(!q.empty()){

    int y = q.front();
    q.pop();

    cout<<y<<" ";

    //this part is the customizable one
    for(auto& j:adj[y]){
      if(points[j].color == 'W'){
        points[j].color = 'G';
        if(points[j].data==1){
          points[j].data = 2;
        }
        else{
          points[j].data = 1;
        }
        q.push(j);
      }
    }

    points[y].color = 'B';
  }
}


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  cin>>t;
  while(t--){

    int n;
    cin>>n;

    for(int i=0; i<n-1; i++){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    struct graph_node points[maxn];

    dfs(n);
    cout<<ans<<"\n";

  }
  return 0;
}
