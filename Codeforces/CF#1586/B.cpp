// na ho paega humse
// nai_aati_coding
// i love PD
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;

// vector<bool> visited(1e5 + )
const int N = 1e5 + 5;
vector<bool> visited(N);
vector<int> adj[N+5];

void dfs(int i){
  visited[i] = 1;
  for(auto to: adj[i]){
    if(!visited[to]){
      dfs(to);
    }
  }
}

void solve(){
  int n; cin>>n;
  int m; cin>>m;

  for(int i = 0; i<=n; i++){
    adj[i].clear();
    visited[i] = false;
  }

  set<int> S;
  for(int i = 1; i<=n; i++) S.insert(i);
  // int root = -1;

  for(int i = 0; i<m; i++){
    int a,b,c; cin>>a>>b>>c;
    // for
    // adj[a].PB(c);
    // adj[c].PB(a);
    // if(root == -1) root = a;
    // cout<<a<<" "<<c<<'\n';
    //
    // if(S.find(a) != S.end())
    //   S.erase(S.find(a));
    // if(S.find(c) != S.end())
    //   S.erase(S.find(c));
    if(S.find(b) != S.end()) S.erase(b);
  }

  // if(S.size())
  // if(root == -1){
  //   root = 1;
  //   S.erase(S.find(1));
  // }
  //
  // for(auto v: S){
  //   adj[root].PB(v);
  //   adj[v].PB(root);
  //   cout<<root<<" "<<v<<'\n';
  // }
  //
  // //now we hab to connect the components
  // vector<int> allvecs;
  // for(int i = 1; i<=n; i++){
  //   if(!visited[i]){
  //     dfs(i);
  //     // if(i != root){
  //     //   adj[root].PB(i);
  //     //   adj[i].PB(root);
  //     //   cout<<i<<" "<<root<<'\n';
  //     // }
  //     allvecs.PB(i);
  //   }
  // }
  //
  //
  // int x = sz(allvecs);
  //
  // for(int i =0; i<x-1; i++){
  //   cout<<allvecs[i]<<" "<<allvecs[i+1]<<'\n';
  // }
  int root = *S.begin();

  for(int i = 1; i<=n; i++){
    if(i != root) cout<<i<<" "<<root<<'\n';
  }

}

signed main(){

  #ifndef ONLINE_JUDGE
  freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  freopen("/home/kabraneel/coding/error.txt","w",stderr);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();

  int t;
  cin>>t;
  while(t--){
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
