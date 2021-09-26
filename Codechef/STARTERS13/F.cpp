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
  map<pair<int,int>, int> M;
  map<pair<int,int>, int> DM;

  int n; cin>>n;

  vector<int> arr(n);
  for(int i = 0; i<n; i++) cin>>arr[i];

  int ans = 0;

  for(int i = 0; i<n; i++){

    int x = i + 1;

    int temp = __gcd(x, arr[i]);
    pair<int,int> p1 = MP(arr[i]/temp, x/ temp);
    pair<int,int> p2 = MP(x/temp, arr[i]/temp);



    if(M.find(p2) != M.end())
      ans += M[p2];
    if(DM.find(p1) != DM.end())
      ans += DM[p1];

    M[p1]++;
    DM[p2]++;
    
  }

  for(auto v: M){
    cout<<v.first.first<<"/"<<v.first.second<<": "<<v.second<<'\n';
  }

  cout<<"DM:\n";
  for(auto v: DM){
    cout<<v.first.first<<"/"<<v.first.second<<": "<<v.second<<'\n';
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
