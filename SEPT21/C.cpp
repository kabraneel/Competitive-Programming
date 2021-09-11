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

void solve(){
  int n, x; cin>>n>>x;
  vector<int> arr(n);

  FOR(i,0,n) cin>> arr[i];

  map<int,int> M;
  map<int,int> MX;

  for(auto v: arr){
    M[v]++;
    MX[(v^x)]++;
  }

  int ans = 0;
  int minop = INF;

  for(auto v: M){
      int x1 = 0;
      auto it = MX.find(v.first);
      int y = 0;
      if(it != MX.end()){
        x1 += it -> second;
        y = it -> second;
      }
      x1 += v.second;
      if(x1 > ans || (x1 == ans && ((y) < minop))){
        ans = x1;
        minop = y;
      }
  }

  for(auto v: MX){
      int x1 = 0;
      auto it = M.find(v.first);
      int y = 0;
      if(it != M.end()){
        x1 += it -> second;
        y = it -> second;
      }
      x1 += v.second;
      if(x1 > ans || (x1 == ans && ((y) < minop))){
        ans = x1;
        minop = y;
      }
  }

  if(x == 0){
    cout<<ans/2<<" 0\n";
    return;
  }

  cout<<ans<<" "<<minop<<'\n';

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
