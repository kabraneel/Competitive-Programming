#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair

#define FOR(i,a,b) for(int i=a; i<b; i++)
vector<pair<int,int>> edges;

//cost of all edges
map<pair<int,int>, int> costs;

void solve(){

  int n,m;
  cin>>n>>m;
  FOR(i,0,m){

    int u,v,w;
    cin>>u>>v>>w;

    edges.PB(MP(u-1,v-1));
    costs[MP(u-1,v-1)] = w;
  }

  vector<int> finalcosts(n,INT_MAX);
  finalcosts[0] = 0;


  FOR(i,0,n-1){
    FOR(j,0,m){

      int u = edges[j].first;
      int v = edges[j].second;

      if(finalcosts[u]!=INT_MAX){
        finalcosts[v] = min(finalcosts[v], finalcosts[u] + costs[MP(u,v)]);
      }
    }
  }

  for(auto v: finalcosts){
    cout<<v<<" ";
  }
  cout<<"\n";
}

int main(){

  #ifndef ONLINE_JUDGE
      freopen("inputfa.txt", "r", stdin);
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
