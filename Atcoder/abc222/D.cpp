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

const int MOD = 998244353;
const int INF = 1e18;

const int N = 3005;
int n;
vector<int> A(N);
vector<int> B(N);

int dp[N][N];

// int solve(int n, int x, int y){
//
//   dp[n][x] = solve(n-1, )
//
// }

void solve(){

  cin>>n;

  for(int i = 0; i<n; i++){
    cin>>A[i];
  }

  for(int j = 0; j<n; j++) cin>>B[j];

  // solve(n, B[n-1], A[n-1]);
  for(int i = 0; i<3003; i++){
    if( i >= A[0] && i<= B[0]) dp[i][0] = 1;
  }

  for(int j = 1; j<n; j++){
    int x = 0;
    for(int i = 0; i<A[j]; i++){
      x += dp[i][j-1];
    }
    for(int i = A[j]; i<=B[j]; i++){
      x += dp[i][j-1];
      x = x % MOD;
      dp[i][j] = x;
    }
  }

  // for(int i = 0; i<5; i++){
  //   for(int j = 0; j<5; j++){
  //     cout<<dp[i][j]<<" ";
  //   }
  //   cout<<'\n';
  // }

  int ans = 0;
  for(int i = A[n-1]; i<=B[n-1]; i++){
    ans += dp[i][n-1];
    ans = ans % MOD;
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
