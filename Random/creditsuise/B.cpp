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
  int z; cin>>z;
  vector<pair<int,int>> arr;

  int x;
  int i = 1;
  while((cin>>x)){
    arr.PB(MP(x, i));
    i++;
  }
  int n = sz(arr);

  sort(all(arr));

  int j = 0;
  int ans = 0;
  while(z>=0){
    if(arr[j].first * arr[j].second > z){
      int count = z / arr[j].first;
      // z -= count * arr[j].first;
      ans += count;
      break;
    }
    else{
      z -= arr[j].first * arr[j].second;
      ans += arr[j].second;
      j++;
    }
  }

  cout<<ans<<'\n';


}

signed main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  // freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  // freopen("/home/kabraneel/coding/error.txt","w",stderr);
  // #endif

  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();

  int t=1;
  // cin>>t;
  while(t--){
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  // cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
