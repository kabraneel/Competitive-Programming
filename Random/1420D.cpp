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

const int modn  = 998244353;
const int N = 3e5 + 5;
int fact[N];

//function used to convert
int fast_pow(int a, int p) {
  int res = 1;
  while (p) {

    if (p % 2 == 0) {
      a = a * 1ll * a % modn;
      p /= 2;
    }

    else {
      res = res * 1ll * a % modn;
      p--;
    }

  }
  return res;
}

int inverse(int a){
  return fast_pow(a,modn-2);
}

void factmod(){

  fact[0] = 1;
  int fact1 = 1;
  for(int i = 1; i<= (int) 3e5 + 3; i++){
    fact1 = fact1 * i;
    fact1 = fact1 % modn;
    fact[i] = fact1;

  }
  // return fact;
}

int ncr(int n, int r){
  int ncr_n = fact[n];
  int ncr_r = fact[r];
  int ncr_n_r = fact[n - r];

  int ans = (((ncr_n * inverse(ncr_r)) % modn) * inverse(ncr_n_r)) % modn;
  return ans;
}

void solve(){
  int n,k; cin>>n>>k;

  map<int,int> M;
  vector<pair<int,int>> allpairs;
  // vector<int> arr(n);

  for(int i = 0; i<n; i++){
    // cin>>arr[i];
    int x,y; cin>>x>>y;
    allpairs.PB(MP(x, 1));
    allpairs.PB(MP(y+1, -1));

  }

  sort(all(allpairs));

  int ans = 0;
  int count = 1;
  for(int i = 1; i<2*n; i++){
    // M[count] += 1;
    // there are M[count] pairs
    // if(count-1 >= k-1)
    //   ans += ncr(count-1 , k-1);
    // ans = ans % modn;
    count += allpairs[i].second;
    cout<<count<<'\n';
    // if(allpairs[i].first != allpairs[i-1].first){
      // cout<<allpairs[i].first<<" "<<count<<'\n';
    // }
  }

  cout<<ans<<'\n';

  // int count1 = 0;
  // for(auto v: M){
  //   cout<<v.first<<" "<<v.second<<'\n';
  //   if(v.first >= k){
  //     count1 += v.second * ncr(v.first, k);
  //     count1 = count1 % modn;
  //   }
  // }
  //
  // cout<<count1<<'\n';

  // if(count1 < k){
  //   cout<<"0\n";
  //   return;
  // }

  // int ncr_n = factmod(count1);
  // int ncr_r = factmod(k);
  // int ncr_n_r = factmod(count1 - k);
  //
  // int ans = (((ncr_n * inverse(ncr_r)) % modn) * inverse(ncr_n_r)) % modn;
  //
  // cout<<ans<<'\n';
  // return;

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
  factmod();
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
