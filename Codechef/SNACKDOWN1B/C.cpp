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

int findval(int x){
  if(x >= (int) 1.5 * 1e9){
    return 2*INF;
  }
  // int temp = ((x)*(x-1))/2;
  return ((x)*(x-1))/2;
}

void solve(){

  int n; cin>>n;

  // n--;

  int l = 1;
  int high = n;
  int ans = 0;

  while(l <= high){

    // cout<<l<<" "<<high<<'\n';
    int mid = (l+high)/2;
    if(findval(mid) == n){
      // ans = mid;
      // break;
      cout<<2*mid-2<<'\n';
      return;
    }

    if(findval(mid) <= n && findval(mid+1) >= n){
      // ans = mid+1;
      cout<<2*mid<<'\n';
      // cout<<findval(mid)<<" "<<findval(mid+1)<<'\n';
      return;
      // break;
    }

    if(findval(mid) > n){
      high = mid -1;
    }

    else{
      l = mid + 1;
    }

  }

  cout<<l<<'\n';

}

signed main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  // // freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  // freopen("/home/kabraneel/coding/error.txt","w",stderr);
  // #endif

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
