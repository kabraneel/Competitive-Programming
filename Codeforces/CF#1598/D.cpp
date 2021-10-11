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
const int N = 2e5 + 5;

void solve(){

  int n; cin>>n;
  int ans = ((n)*(n-1)*(n-2))/6;

  // int A[N], B[N];
  vector<int> a(n), b(n);
  vector<int> A(n+1), B(n+1);

  for(int i = 0; i<n; i++){
    // int x,y; cin>>x>>y;
    cin>>a[i]>>b[i];
    A[a[i]]++;
    B[b[i]]++;
  }

  for(int i = 0; i < n; i++){
    // cout<< (A[i]-1) * (B[i]-1)<<'\n';
    // if(A[i] > 0 && B[i] > 0)
      ans -= ((A[a[i]]-1) * (B[b[i]]-1));
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
