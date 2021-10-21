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

  int k; cin>>k;

  vector<pair<pair<int,int>,int>> exes;
  vector<pair<pair<int,int>,int>> whys;

  for(int i = 0; i<k; i++){
    int x1,x2,y1,y2;
    cin>>x1>>x2>>y1>>y2;

    exes.PB({MP(x1, x2), i});
    whys.PB({MP(y1, y2), i});
  }

  sort(all(exes));
  sort(all(whys));



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

  int t;
  cin>>t;
  int tcount = 0;
  while(t--){
    tcount++;
    cout<<"Case #"<<tcount<<": ";
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
