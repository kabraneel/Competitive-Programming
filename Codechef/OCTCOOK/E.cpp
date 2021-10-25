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
  // map<int,int> M;
  vector<int> counts(2*n + 5);

  for(int i = 0; i<n; i++){
    int x,y; cin>>x>>y;
    // M[x+y]++;
    counts[x+y]++;
  }

  // for(int i = 0; i<2*n; i++){
  //   cout<<counts[i]<<' ';
  // }

  for(int i = 0; i<2*n; i++){
      int t = i;
      if(!counts[i]) continue;
      if(t > n){
        //say  t = n+2, then i want to compare with n - 1
        t = 2*n - t + 1;
        // cout<<t<<" "<<counts[i]<<'\n';
        if(t == counts[i]){
          cout<<"NO\n";
          return;
        }
        continue;
      }
      if(t == counts[i] + 1){
        cout<<"NO\n";
        return;
      }

  }

  cout<<"YES\n";

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
