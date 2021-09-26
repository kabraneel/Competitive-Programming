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
  vector<int> arr(n);

  int tsum = 0;
  // map<int,int> M;
  set<int> S;
  int mex = -1;
  FOR(i,0,n){
    cin>>arr[i];
    S.insert(arr[i]);
    tsum += arr[i];
    mex = max(mex, arr[i]);
  }

  int m; cin>>m;
  while(m--){

    int x; int y; cin>>x>>y;
    if(x > mex){
      //solve
      // cout<<"Greater Case\n";
      int ans = x - mex;
      // ans +=
      int rem_hel = tsum - mex;
      ans += max(0ll, y - rem_hel);
      cout<<ans<<'\n';
      continue;
    }

    auto it = S.lower_bound(x);

    if((*it) == x){
      //solve
      // cout<<"Equal case\n";
      int rem_hel = tsum - x;
      cout<<max(0ll, y - rem_hel)<<'\n';
      continue;
    }

    // cout<<"Else Case\n";
    // cout<<*it<<'\n';
    int a1 = *it;
    int rem1 = tsum - a1;
    int ans1 =  max(0ll, y - rem1);

    if(it != S.begin())
      it--;
    // cout<<*it<<'\n';
    int a2 = *it;
    // cout<<"a2 -> "<<a2<<'\n';
    int rem2 = tsum - a2;
    int ans2 = max(0ll, x - a2) + max(0ll, y - rem2);

    cout<<min(ans1, ans2)<<'\n';

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
