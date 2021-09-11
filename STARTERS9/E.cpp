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

const int N = 1e5 + 5;
vector<int> arr(N);
vector<int> ones(N);

const int modn  = 1e9 + 7;

//function used to convert
int fast_pow(int a, int p) {
  int res = 1;
  while (p) {

    if (p % 2 == 0) {
      a = a * 1ll * a % modn;
      p /= 2;
    }

    else {
      res = res * 1ll * a % modn;
      p--;
    }

  }
  return res;
}

void pre(){

  // cout<<"here\n";
  arr[0] = 1;
  arr[1] = 2;
  ones[0] = 1;
  ones[1] = 1;

  for(int i = 2; i<N; i++){
      // cout<<"here\n";
      ones[i] = (ones[i-1] + ones[i-2]) % MOD;
      arr[i]  = (arr[i-1] + arr[i-2]) % MOD;
  }

}

void solve(){

  int n; cin>>n;
  int ans  = fast_pow(2, arr[n-1] - 1);
  ans = ans % MOD;
  ans = (ans * ones[n-1])%MOD;
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
  pre();

  int t;
  cin>>t;
  while(t--){
    // cout<<"here\n";
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
