#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;

void print(vector<int> &arr){

  int n = arr.size();
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<"\n";

}

#define FOR(i,a,b) for(int i=a; i<b; i++)

#define PB push_back
#define MP make_pair

//change this to number of vertices
#define N 100

vi adj[N];
void addedge(int v, int u){
    adj[v].PB(u);
}

vi BFS(int v){

  bool visited(n,false);
  visited[v] = true;

  vi ans;
  ans.PB(v);

  queue<int> q;
  q.PB(v);

  while(!q.empty()){

    auto v1 = q.pop();

    for(auto u: adj[v1]){

      visited[u] = true;
      q.PB(u);
      ans.PB(u);

    }

  }

  return ans;
}

int main(){

  int n;
  cin>>n;

  int edges;
  cin>>edges;

  FOR(i,0,edges){
    int u,v;
    cin>>u>>v;
    addedge(u-1,v-1);
  }

  vi arrans = BFS(0);

  print(arrans);

}
