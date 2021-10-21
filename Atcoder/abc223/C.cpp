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
  vector<int> A(n);
  vector<int> B(n);

  for(int i = 0; i<n; i++){
    cin>>A[i]>>B[i];
  }

  float total = 0;

  for(int i = 0; i<n; i++){
    total += (1.0 * A[i]) / B[i];
  }

  float halftime = total / 2.0;
  // cout<<halftime<<"\n";

  float thistime = 0.0;
  float ans = 0;
  for(int i = 0; i<n; i++){
    if(thistime + 1.0 * A[i] / B[i] <= halftime){
      thistime += 1.0 * A[i] / B[i];
      ans += 1.0 * A[i];
      // cout<<thistime<<" "<<ans<<'\n';

    }

    else{ // means im i can only take partial

      // float totaldis = 1.0 * A[i] * B[i];
      // A[i] * B[i] -> A[i]
      //
      ans += (halftime - thistime) * (1.0 * B[i]);
      break;
    }

  }

  // cout.setprecision(15);
  cout<<fixed<<setprecision(15) <<ans<<'\n';

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
