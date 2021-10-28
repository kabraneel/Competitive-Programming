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

void solve(){
  multiset<int> ans;
  int n; cin>>n;

  int i = 1;
  int tsum = 0;
  // int temp = 1;
  // for(int i = 0)
  while(i<n){
    // if( (1ll<<i) > temp){
      // temp = temp - (1ll<<i);
      ans.insert((1ll<<i) - 1);
      tsum += (1ll<<i) - 1;
      i++;
    // }
    // else{
    //   break;
    // }
  }

  int x = (1ll << n) - tsum;

  for(auto v: ans){
    int tofind = x - v;
    if(ans.find(tofind) == ans.end()){
      ans.insert(x - v);
      ans.insert(v);
      break;
    }
  }

  if(x % 2 == 0 && sz(ans) == n-1){
    ans.insert(x/2);
    ans.insert(x/2);
    // ans.insert()
  }

  // cout<<sz(ans)<<'\n';
  for(auto v: ans){
    cout<<v<<' ';
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
