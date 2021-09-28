//____ kabraneel's soln ____
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define PB push_back
#define MP make_pair
typedef long long ll;
#define FOR(i,a,b) for(int i=a; i<b; i++)

#define N 100005

vector<int> adj[N];
void addedge(int u, int v){
  adj[u].PB(v);
  adj[v].PB(u);
}

vector<int> intime(N,-1);
vector<int> dist(N,-1);
vector<bool> visited(N,false);

int timetaken = 1;

void DFS_visit(int u, int parent){

    // if(parent!=-1)
    //   cout<<u+1<<" "<<parent+1<<"\n";

    dist[u] = timetaken;
    intime[u] = timetaken;
    timetaken++;

    visited[u] = true;

    for(auto to: adj[u]){
      if(to==parent){
        continue;
      }

      if(!visited[to]){

          DFS_visit(to,u);
          dist[u] = min(dist[to], dist[u]);

          //if reached here, then all nieghbours explored//
          if(dist[to]>intime[u]){
            //edge v->to is a bridge//
            cout<<to+1<<" "<<u+1<<"\n";
          }
      }

      else{
          dist[u] = min(dist[u],intime[to]);
      }
    }

}

void DFS(int n){

  FOR(i,0,n){
    if(!visited[i]){
      DFS_visit(i,-1);
    }
  }

}

void solve(){

  int n,m;
  cin>>n>>m;

  FOR(i,0,m){
    int u,v;
    cin>>u>>v;
    addedge(u-1,v-1);
  }
  DFS(n);
  // FOR(i,0,n){
  //   cout<<dist[i]<<" ";
  // }
  // cout<<"\n";
  return;
}

int main(){

  #ifndef ONLINE_JUDGE
      freopen("inputf.txt", "r", stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
