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


/*
  4^0
  4^1
  4^0 + 4^1

  1   2      4               8 + 6
  {0, 1, 01, 2, 02, 12, 012, 3, }


*/

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

int inverse(int a){
  return fast_pow(a,modn-2);
}

void solve(){

  int n,k; cin>>k>>n;
  string s;
  while(n!=0){

    int ans = 0;
    for(int i = 31; i>=0; i++){
      if(n & (1<<i)){
        ans = i;
        break;
      }
    }

    n = n - (1<<ans);
    s.push_back(ans - 32 + '0');

  }

  // cout<<s<<"\n";
  int ans = 0;
  for(auto v: s){
    int x = v - '0';
    ans += fast_pow(k,x);
    // cout<<ans<<'\n';
    ans %= MOD;
  }

  // cout<<"ANS\n";
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
