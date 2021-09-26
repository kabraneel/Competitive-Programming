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
  vector<pair<int,int>> arr;

  FOR(i,0,n){
    int x,y; cin>>x>>y;
    arr.PB(MP(x,y));
  }

  set<pair<int,int>> S;
  for(auto v: arr){
    S.insert(v);
  }

  int ans = 0;

  for(int i = 0; i<n; i++){
    for(int j = i+1; j<n; j++){
      //arr[i] and arr[j] are opposite corners
      pair<int,int> X = MP(arr[i].first, arr[j].second);
      pair<int,int> Y = MP(arr[j].first, arr[i].second);
      auto it1 = S.find(X);
      auto it2 = S.find(Y);

      if(X == arr[i] || X == arr[j] || Y == arr[i] || Y == arr[j] || X == Y){
        continue;
      }

      if(it1 == S.end() || it2 == S.end()){
        ;
      }
      else{
        // cout<<"Rectangle is :\n";
        // cout<<arr[i].first<<" "<<arr[i].second<<'\n';
        // cout<<arr[j].first<<" "<<arr[j].second<<'\n';
        // cout<<X.first<<" "<<X.second<<'\n';
        // cout<<Y.first<<" "<<Y.second<<'\n';

        ans++;
      }
    }
  }

  cout<<ans/2<<'\n';

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
