// na ho paega humse
// nai_aati_coding
// i love PD
// 2191
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

  ordered_set<pair<int,int>> oset1;
  // deque<int> dq;

  int n; cin>>n;

  int ans = 0;
  for(int i = 0; i<n; i++){

    int x; cin>>x;


    int smaller = oset1.order_of_key(MP(x, 0));
    int larger = oset1.size() - oset1.order_of_key(MP(x, INF));

    ans += min(smaller, larger);
    oset1.insert(MP(x, i));

  }

  cout<<ans<<'\n';



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
