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

map<int,int> M;

bool comparetwo(const string &a, const string &b){

  int n = sz(a);
  int m = sz(b);

  int i = 0, j = 0;
  while(i<n && j<m){

    if(M[a[i]] == M[b[j]]){
      i++;
      j++;
      continue;
    }

    return M[a[i]] < M[b[j]];

  }

  return n<m;

}

void solve(){
  string t; cin>>t;
  int count = 0;

  for(auto v: t){
    M[v] = count;
    count++;
  }

  int n; cin>>n;
  vector<string> arr(n);

  FOR(i,0,n) cin>>arr[i];

  sort(all(arr), comparetwo);

  for(auto v: arr){
    cout<<v<<"\n";
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
