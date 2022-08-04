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

int n;

bool check(int mid){

  if(mid > 1e9){
    return false;
  }

  if( (mid * (mid + 1))/2 > n ){
    return false;
  }
  return true;
}



void solve(){

  cin>>n;
  int l = 1, r = n;
  int ans = -1;
  while (l <= r) {
      int mid = (l+r)/2;
      if (check(mid)) { // check is the function that checks if answer is possible.
          ans = mid;
          l = mid+1;
      }
      else r = mid-1;
  }

  if((ans * (ans + 1))/2 == n){
    cout<<ans<<'\n';
    return;
  }
  cout << n - (ans * (ans + 1))/2  << '\n';
}

signed main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  // freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  // freopen("/home/kabraneel/coding/error.txt","w",stderr);
  // #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();

  int t = 1;
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
