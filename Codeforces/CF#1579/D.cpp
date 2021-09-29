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
  vector<int> arr(n);

  map<int, vector<int>> M;

  for(int i =0; i<n; i++) cin>>arr[i];

  multiset<int> S;
  for(int i = 0; i<n; i++){
    M[arr[i]].PB(i+1);
    if(arr[i]!= 0)
      S.insert(arr[i]);
  }

  int ans = 0;

  for(int i = 0; i<n; i++){
    ans += arr[i];
  }


  vector<pair<int,int>> A;

  // int count = 0;
  while(S.size() > 1){
    // count++;
    auto it1 = S.begin();
    auto it2 = S.end();
    it2--;
    // it1--;

    int x = *it2; int y = *it1;
    S.erase(S.lower_bound(x));
    S.erase(S.lower_bound(y));
    int yin = M[y].back();
    M[y].pop_back();
    int xin = M[x].back();
    M[x].pop_back();
    // for(int i = 0; i<y; i++){
    //   A.PB(MP(xin, yin));
    // }
    A.PB(MP(xin, yin));
    // if(x - y == 0){
    //   continue;
    // }
    x--;
    y--;

    if(x > 0){
      S.insert(x);
      M[x].PB(xin);
    }
    if(y > 0){
      S.insert(y);
      M[y].PB(yin);
    }

    // S.insert(x - 1);
    // M[x-y].PB(xin);

    // cout<<"The Set\n";
    // for(auto v: S){
    //   cout<<v<<" ";
    // }
    // cout<<'\n';
  }

  cout<<A.size()<<'\n';

  for(auto v: A){
    cout<<v.first<<" "<<v.second<<'\n';
  }
  //
  // cout<<"\n\n\n\n";





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
