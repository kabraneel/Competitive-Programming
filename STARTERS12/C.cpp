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
  int n,k; cin>>n>>k;
  vector<int> arr(n);
  FOR(i,0,n) cin>>arr[i];


  int i = 0;

  while(i<k){
    vector<int> counter;
    if(arr[0]!=0){
      counter.PB(n-1);
      counter.PB(1);
    }
    if(arr[n-1]){
      counter.PB(n-2);
      counter.PB(0);
    }

    for(int j = 1; j<n-1; j++){
      if(arr[j]){
        counter.PB(j-1);
        counter.PB(j+1);
      }
    }


    for(auto v: counter){
      arr[v]++;
    }

    if(!(sz(counter))){
      cout<<"0\n";
      return;
    }


    if(sz(counter) == 2*n){
      break;
    }
    i++;

  }

  int ans = 0;
  for(auto v: arr){
    ans+= v;
  }
  if(i != k)
    ans += (2*n*(k-i-1));
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
