// na ho paega humse
// nai_aati_coding
// i love PD
#include <bits/stdc++.h>
#include <chrono>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


using namespace std;
#define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())


template <typename num_t>
using ordered_set = tree<num_t, null_type,less_equal<num_t>, rb_tree_tag,   tree_order_statistics_node_update>;

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;

void solve(){

  int n,m, tsum; cin>>n>>m>>tsum;

  vector<int> A(n);
  vector<int> B(m);

  FOR(i,0,n) cin>>A[i];
  FOR(i,0,m) cin>>B[i];

  vector<int> aprefixes(n);
  vector<int> bprefixes(m);

  aprefixes[0] = A[0];

  for(int i = 1; i<n; i++){
    aprefixes[i] = aprefixes[i-1] + A[i];
  }

  bprefixes[0] = B[0];

  for(int i = 1; i<m; i++){
    bprefixes[i] = bprefixes[i-1] + B[i];
  }

  ordered_set<pair<int,int>> S;

  for(int i = 0; i<m; i++){
    S.insert(MP(bprefixes[i], i+1));
  }

  // for(auto v: S){
  //   cout<<v.first<<" "<<v.second<<'\n';
  // }

  int ans = S.order_of_key(MP(tsum, INF));

  for(int i = 0; i<n; i++){

    if(aprefixes[i] > tsum) break;

    int remsum = tsum - aprefixes[i];

    int x = S.order_of_key(MP(remsum, INF));

    // cout<<remsum<<" "<<x<<'\n';

    ans = max(ans, i + x + 1);
  }

  cout<<ans<<'\n';


}

signed main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  // freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  // freopen("/home/kabraneel/coding/error.txt","w",stderr);
  // #endif

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

  // cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
