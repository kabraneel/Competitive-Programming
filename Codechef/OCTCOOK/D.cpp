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
  int n; cin>>n;
  vector<int> arr(n);
  for(int i = 0; i<n; i++){
    cin>>arr[i];
  }

  vector<int> odds;
  vector<int> eves;

  for(int i = 0; i<n; i++){
    if(i%2) odds.PB(arr[i]);
    else eves.PB(arr[i]);
  }

  sort(all(odds));
  sort(all(eves));
  reverse(all(eves));

  vector<int> final;
  int counte = 0;
  int counto = 0;
  for(int i = 0; i<n; i++){
      if(i%2){
        final.PB(odds[counto]);
        counto++;
      }
      else{
        final.PB(eves[counte]);
        counte++;
      }
  }

  int ans = 0;
  for(int i = 0; i<n; i+=2){
    for(int j = i+1; j<n; j+=2){
      ans += final[i] * final[j];
    }
  }

  // for(auto v: odds){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';
  //
  // for(auto v: eves){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';


  for(auto v: final){
    cout<<v<<" ";
  }
  cout<<'\n';
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
