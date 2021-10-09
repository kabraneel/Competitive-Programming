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

const int N = 1e5+ 5;
vector<int> adj[N];

void solve(){


  int n,m,k; cin>>n>>m>>k;
  vector<int> subs(n);
  vector<int> times(n);

  for(int i = 0; i<n; i++){
    cin>>subs[i];
  }

  for(int i = 0; i<n; i++){
    cin>>times[i];
    adj[subs[i]-1].PB(times[i]);
  }

  for(int i = 0; i<m; i++){
    sort(all(adj[i]));
  }


  multiset<int> S;
  for(int i = 0; i<m; i++){

    int n1 = sz(adj[i]);
    // if(n1 )
    if(n1 == 0) continue;

    S.insert(adj[i][0]);

    if(n1%2 == 0) n1--;

    for(int j = 1; j+1<n1; j+=2){
      S.insert(adj[i][j] + adj[i][j+1]);
    }
  }

  // for(int i = 0; i<m; i++){
  //   for(auto v: adj[i]){
  //     cout<<v<<" ";
  //   }
  //   cout<<'\n';
  // }
  //
  // cout<<"THE SET:\n";
  // for(auto v: S){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';


  int ans = 0;
  while(k > 0 && !S.empty()){
    auto it = S.begin();
    k -= *it;
    if(k < 0) break;
    S.erase(it);
    ans++;
  }

  cout<<ans<<"\n";

  // cout<<"\n\n\n";

  for(int i = 0; i<m; i++){
    adj[i].clear();
  }

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
