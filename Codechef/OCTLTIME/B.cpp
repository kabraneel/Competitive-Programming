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

void solve(){
  int n,v; cin>>n>>v;

  //for max cost
  //fill at every station
  //cost = 1 + 2 + 3 .. n - 1
  cout<< ((n-1)*(n))/2 <<' ';


  if(v >= n){
    cout<<n-1<<" ";
    return;
  }

  // int menfils = n/v;
  int mencost = 0;
  //first fill always costs v
  // if(menfils){
    mencost += v;
    n = n - v ;
    // menfils--;
  // }

  // cout<<menfils<<'\n';
  // if(n%v == 0) menfils--;
  //
  // //now, we need to fill it menfils times
  // mencost += v * v * (((menfils) * (menfils+1))/2);
  //
  // if(n%v){
  //   //some stuff left
  //   //reached till station n/v
  //
  //   int fstation = n/v;
  //   mencost += fstation * (n%v);
  //
  // }

  mencost += ((n) * (n+1))/2;

  cout<<mencost-1<<'\n';

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
