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

const int N = 4e5 + 5;
set<int> adj[N];
bool visited[N];
vector<int> depths(N);

void solve(){

  int n, k; cin>>n>>k;
  vector<bool> completed(n);

  if(n == 1){
    cout<<"0\n";
    return;
  }

  for(int i = 0; i<n; i++){
    adj[i].clear();
    depths[i] = -1;
    visited[i] = false;
  }

  for(int i = 0; i<n-1; i++){
    int u,v; cin>>u>>v;
    adj[u-1].insert(v-1);
    adj[v-1].insert(u-1);
  }

  // vector<int> temp;
  queue<pair<int,int>> q;
  for(int i = 0; i<n; i++){
    if(adj[i].size() == 1){
      // temp.PB(i);
      q.push({i,1});
    }
  }

  vector<int> done;

  while(!q.empty()){

    pair<int,int> v = q.front();
    q.pop();

    if(v.second > k){
      // break;
      ;
    }
    else{
      done.PB(v.first);
    }

    auto p = adj[v.first].begin();
    int val = *p;
    adj[v.first].clear();
    adj[val].erase(v.first);

    if(adj[val].size() == 1){
      q.push({val, v.second + 1});
    }

  }

  cout<< n - sz(done) <<'\n';

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
