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

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


void solve(int count){

  int d,n,k; cin>>d>>n>>k;
  // vector<int> happies;
  vector<pair<pair<int,int>, int>> times;
  FenwickTree myfn(n);
  int ind = 0;

  FOR(i,0,n){
    int x,y,z; cin>>x>>y>>z;
    // happies.PB(x);
    times.PB(MP(MP(y,z), x));
  }

  sort(all(times));
  multiset<int, greater<int>> S;
  // multimap
  map<int, vector<int>> M;

  //value, index
  // multimap<int, int> M;
  map<int, vector<int>> DM;

  int currentf = 0;
  int currentb = 0;

  int fans = 0;

  for(int i = 0; i<d+1; i++){

    //if any event starts
    while(currentf < n && times[currentf].first.first == i){
      S.insert(times[currentf].second);
      M[times[currentf].first.second].PB(times[currentf].second);
      DM[times[currentf].second].PB(ind);
      myfn.add(ind, times[currentf.second]);
      ind++;
      currentf++;
    }

    // cout<<i<<"\n";
    // for(auto v: S){
    //   cout<<v<<" ";
    // }
    // cout<<'\n';

    int count = 0;
    int ans = 0;
    for(auto v: S){
      count++;
      ans += v;
      if(count==k) break;
    }

    fans = max(fans, ans);

    // while(currentb < n && times[currentb].first.second == i){
    //   cout<<times[currentb].second<<'\n';
    //   S.erase(S.lower_bound(times[currentb].second));
    //   currentb++;
    // }
    auto it = M.find(i);
    if(it == M.end()) continue;

    for(auto v: it->second){
      S.erase(S.lower_bound(v));
    }

    M.erase(it);
  }

  cout<<fans<<'\n';
}

signed main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  // freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  // freopen("/home/kabraneel/coding/error.txt","w",stderr);
  // #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // auto start = chrono::high_resolution_clock::now();

  int t;
  cin>>t;
  int count = 1;
  while(t--){
    cout<<"Case #"<<count<<": ";
    solve(count);
    count++;
  }

  // auto end = chrono::high_resolution_clock::now();
  // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  //
  // time_taken *= 1e-9;
  //
  // cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
