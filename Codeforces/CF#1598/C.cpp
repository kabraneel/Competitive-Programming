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

 tsum / n = rsum / (n-2)
 tsum * (n-2) = rsum * n
 tsum * (n-2) = (tsum - x) * n

 x = 2 * tsum / n ?


number of pairs such that sum = (2*tsum / n)

*/

void solve(){

  int n; cin>>n;
  vector<int> arr(n);

  int tsum = 0;

  for(int i = 0; i<n; i++) {
    cin>>arr[i];
    tsum += arr[i];
  }


  int tofind = 2*tsum;
  if((tofind % n) != 0){
    cout<<"0\n";
    return;
  }

  tofind = tofind / n;

  map<int,int> M;

  for(auto v: arr){
    M[v] ++;
  }

  int ans = 0;

  for(int i = 0; i<n; i++){
    M[arr[i]]--;
    if(M.find(tofind - arr[i]) != M.end()){
      ans += M[tofind - arr[i]];
    }

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
