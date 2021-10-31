// na ho paega humse
// nai_aati_coding
// i love CS
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

const int N = 1e5 + 5;
vector<set<int>> adj(N);
vector<bool> visited(N);

int dfs(int i){
  visited[i] = true;
  int ans = 1;
  for(auto to : adj[i]){
    // int x = to;
    // adj[i].erase(x);
    // adj[x].erase(i);
    if(!visited[to])
      ans += dfs(to);
  }

  return ans;
}


void solve(){
  int n; cin>>n;
  int m; cin>>m;

  int k; cin>>k;

  for(int i = 0; i<n; i++) {
    adj[i].clear();
    visited[i] = 0;
  }

  for(int i = 0; i<m; i++){
    int u,v; cin>>u>>v;
    adj[u-1].insert(v-1);
    adj[v-1].insert(u-1);
  }

  int count1 = 0;
  vector<int> sizes;

  dfs(k-1);

  for(int i = 0; i<n; i++){
    if(!visited[i]){
      sizes.PB(dfs(i));
    }
  }

  int count = 0;
  for(auto v: sizes){
    // cout<<v<<" ";
    if(v>1) count++;
  }

  if(count >= 1){
    cout<<"NO\n";
    return;
  }
  // cout<<'\n';
  // int count
  for(int i = 0; i<n; i++){
    if(sz(adj[i])%2) count1++;
  }

  if(count1 == 0 || count1 == 2){
    cout<<"YES\n";
  }
  else cout<<"NO\n";

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
