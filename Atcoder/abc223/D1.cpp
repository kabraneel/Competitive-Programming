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

const int N = 2e5 + 5;
vector<int> visited(N);
bool cycle = false;
vector<int> S;

vector<int> adj[N];

// void dfs(int i){
//   visited[i] = 1;
//   for(auto to : adj[i]){
//     if(!visited[to]){
//       dfs(to);
//     }
//     else if(visited[to] == 1){
//       // cout<<"-1\n";
//       // exit(0);
//       cycle = true;
//     }
//   }
//   visited[i] = 2;
//   S.push_back(i);
// }

void solve(){

  int n,m; cin>>n>>m;
  vector<int> ind(n);

  for(int i = 0; i<m; i++){
    int u,v; cin>>u>>v;
    // adj[v-1].PB(u-1);
    adj[u-1].PB(v-1);
    ind[v-1]++;
  }

  set<int> S1;
  for(int i = 0; i<n; i++){
    if(ind[i] == 0){
      S1.insert(i);
    }
  }

  while(!S1.empty()){

    auto it = S1.begin();
    int x = *it;
    S1.erase(S1.begin());

    for(auto v: adj[x]){
      ind[v]--;
      if(ind[v] == 0){
        S1.insert(v);
      }
    }

    S.PB(x);
  }

  if(sz(S) != n){
    cout<<"-1\n";
    return;
  }

  for(auto v: S){
    cout<<v+1<<" ";
  }

  cout<<'\n';

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

  int t=1;
  // cin>>t;
  while(t--){
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
