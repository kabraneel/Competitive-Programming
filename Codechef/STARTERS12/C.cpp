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
  int n,m;
  cin>>n>>m;
  n--;
  m--;
  int x,y; cin>>x>>y;

  if(y > 2*x){
    cout<< (n+m) * x <<'\n';
    return;
  }

  int ans = (n + m)*x;

  int mex = max(n, m);
  int men = min(n,m);

  // cout<< men * y + (mex - men) * x <<'\n';
  int diags = mex/men;
  // if(diags % 2 == 0) diags--;
  // cout<< diags<<'\n';

  // cout<< diags*men*y + (mex - men*diags)*x<<'\n';
  if(diags%2 == 1){
    cout<<min(ans,diags * men * y + (mex - men * diags) * x) <<'\n';
    return;
  }

  int ans1 = men * diags * y + (mex - men * diags) * y + ((men) * (diags + 1) - mex) * x;
  int ans2 = men * (diags - 1 )* y + (mex  - men * (diags - 1)) * x;
  cout<<ans1<<" "<<ans2<<'\n';
  cout << min(min(ans,ans1), ans2)<<'\n';

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
