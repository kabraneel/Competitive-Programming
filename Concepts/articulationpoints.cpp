#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;

#define PB push_back
#define MP make_pair

typedef long long ll;
#define FOR(i,a,b) for(int i=a; i<b; i++)
#define N 10005

vector<int> dist(N,-1);
vector<int> intime(N,-1);

vector<bool> visited(N,false);
set<int> myset;

vector<int> adj[N];
void addedge(int u, int v){
  adj[u].PB(v);
  adj[v].PB(u);
}

int timetaken = 1;


void DFS_visit(int u, int parent){

  visited[u] = true;
  intime[u] = timetaken;
  dist[u] = timetaken;
  timetaken++;

  int x = 0;

  for(auto to: adj[u]){

    if(to == parent){
      continue;
    }

    if(!visited[to]){
      DFS_visit(to,u);
      dist[u] = min(dist[u], dist[to]);

      if(dist[to]>=intime[u] && parent!=-1){
        myset.insert(u);
      }
      x++;
    }

    else{
      dist[u] = min(dist[u], intime[to]);
    }
  }

  if(x>1 && parent == -1){
    myset.insert(u);
  }

}

void DFS(int n){

  FOR(i,0,n){
    if(!visited[i]){
      DFS_visit(i,-1);
    }
  }

}

void solve(int n, int m){

  FOR(i,0,n){
    adj[i].clear();
    visited[i] = false;
    intime[i] = -1;
    dist[i] = -1;
  }

  myset.clear();

  timetaken = 1;

  FOR(i,0,m){
    int u,v;
    cin>>u>>v;
    addedge(u-1,v-1);
  }

  DFS(n);
  // FOR(i,0,n){
  //   cout<<intime[i]<<" "<<dist[i]<<"\n";
  // }
  cout<<myset.size()<<"\n";

  // for(auto v:myset){
  //   cout<<v+1<<" ";
  // }
  // cout<<"\n";

}

int main(){

  #ifndef ONLINE_JUDGE
  freopen("inputf.txt", "r", stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  while(1){

    int n,m;
    cin>>n>>m;

    if(n==0 && m==0){
      break;
    }

    solve(n,m);

  }
  return 0;
}
