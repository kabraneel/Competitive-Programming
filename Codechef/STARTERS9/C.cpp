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
  int n,m,q;
  cin>>n>>m>>q;
  set<int> S;

  // cout<<q<<'\n';

  bool pos = true;

  FOR(i,0,q){

    char x; int temp; cin>>x>>temp;
    // cout<<sz(S)<<'\n';
    // cout<<x<<' ';
    if(x == '+'){
      S.insert(temp);
      if(sz(S)>m){
        // cout<<"Inconsistent\n";
        pos = false;
      }
      continue;
    }

    auto it = S.find(temp);
    if(it == S.end()){
      pos = false;
    }

    S.erase(temp);

  }

  if(!pos){
    cout<<"Inconsistent\n";
    return;
  }

  cout<<"Consistent\n";


}

signed main(){

  #ifndef ONLINE_JUDGE
  freopen("inputfa.txt", "r", stdin);
  freopen("outputfa.txt", "w", stdout);
  freopen("error.txt","w",stderr);
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
