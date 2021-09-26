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
const int MAXN = 2e5 + 5;
int factorial[MAXN];

// const int modn  = 1e9 + 7;

//function used to convert
int fast_pow(int a, int p) {
  int res = 1;
  while (p) {

    if (p % 2 == 0) {
      a = a * 1ll * a % MOD;
      p /= 2;
    }

    else {
      res = res * 1ll * a % MOD;
      p--;
    }

  }
  return res;
}

int inverse(int a){
  return fast_pow(a,MOD-2);
}

void pre(){
  factorial[0] = 1;
  FOR(i,1,MAXN){
    factorial[i] = (factorial[i-1] * (i)) % MOD;
  }
}

void solve(){
  int n; cin>>n;
  vector<int> arr(n);

  for(int i = 0; i<n; i++) cin>>arr[i];

  // vector<int> X = arr;
  // sort(all())
  sort(all(arr));
  // for(int i = 0; i<n; i++){
  //
  // }
  int mex = arr[n-1];
  int count = 0;
  for(int i = 0; i<n; i++){
    if(arr[i] == mex) count++;
  }

  if(count == 1){
    //problem
    int count1 = 0;
    for(int i = 0; i<n; i++){
      if(arr[i] == mex-1) count1++;
    }

    int ans = factorial[n];
    ans = (((ans * count1)%MOD) *inverse(count1+1))%MOD;
    cout<<ans<<'\n';
  }

  else{
    cout<<factorial[n]<<'\n';
  }

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
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
