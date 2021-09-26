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
  int n; cin>>n;

  vector<int> A(n);
  vector<int> B(n);

  FOR(i,0,n) cin>>A[i];
  FOR(j,0,n) cin>>B[j];

  map<int, vector<int>> M1;
  map<int, vector<int>> M2;

  for(int i = 0; i<n; i++){
    M1[A[i]].PB(i);
    M2[B[i]].PB(i);
  }

  int ans = 0;
  for(auto v: M1){
    int x = 0;
    // for(auto u : M2[v.first]){
    //   x +=
    // }
    int n1 = sz(v.second);
    for(int j = 0; j<n1; j++){
      x += (v.second[j] - M2[v.first][j]);
    }
    ans += x * v.first;
  }

  cout<<-1 * ans<<'\n';




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
