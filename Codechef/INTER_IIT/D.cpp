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
vector<int> adj[N];
vector<int> C(N);

int dp1[N],dp2[N];

void dfs(int V, int pV){

    int sum1=0, sum2=0;

    for(auto v: adj[V]){
    if(v == pV) continue;
      dfs(v, V);
      sum1 += dp2[v];
      sum2 += max(dp1[v], dp2[v]);
    }

    dp1[V] = C[V] + sum1;
    dp2[V] = sum2;
}

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i<=n; i++){
      adj[i].clear();
      C[i] = 0;
      dp1[i] = 0;
      dp2[i] = 0;
    }

    int tsum = 0;
    for(int i = 1; i<=n; i++){
      cin>> C[i];
      tsum += C[i];
    }

    for(int i=1; i<n; i++){
      int u,v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(1, 0);

    // for(int i = 0; i<n; i++){
    //   cout<<C[i]<<" ";
    //   // cout<<dp1[i]<<" ";
    // }
    // cout<<'\n';
    //
    // for(int i = 0; i<n; i++){
    //   cout<<dp2[i]<<" ";
    // }

    int ans = max(dp1[1], dp2[1]);
    cout << ans << endl;
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
