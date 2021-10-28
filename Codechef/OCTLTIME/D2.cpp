#include <bits/stdc++.h>
#include <chrono>
using namespace std;
#define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int N = 2e5 + 5;
const int LOG = 19;

int sparse[N][LOG];

int query(int l, int r){

  int len = r - l + 1;
  int k = 31 - __builtin_clz(len);

  return __gcd(sparse[l][k], sparse[r-(1<<k)+1][k]);

}

void solve(){

  int n; cin>>n;
  // int q; cin>>q;

  // if(n == 1){
  //   cout<<"1\n";
  //   return;
  // }

  vector<int> arr(n);

  FOR(i,0,n) {
    cin>>arr[i];
    sparse[i][0] = arr[i];
  }

  // sparse[0][1] =
  for(int j = 1; j < LOG; j++){
    for(int i = 0; i+(1<<(j)) -1 <  n ; i++){
      sparse[i][j] = __gcd(sparse[i][j-1], sparse[i + (1<<(j-1))][j-1]);
      // cout<<"here\n";
    }
  }

  int ans = 0;

  for(int i = 0; i<n; i++){
    for(int j = i+1; j<n; j++){

      // cout<<"here\n";
      // int x1 = s.qeury(0, i).v;
      // x1 = __gcd(s.qeury(i+1))
      int x1 = 0;
      if(i){
        x1 = __gcd(query(0,i-1), x1);
      }

      if(i+1<n && i+2<=j){
        x1 = __gcd(query(i+1, j-1), x1);
      }

      if(j+1<n){
        x1 = __gcd(x1, query(j+1, n-1));
      }

      x1 = __gcd(x1, arr[i]*arr[j]);

      // s.rupd(i, i, temp1*temp2);
      // s.rupd(j, j, temp1*temp2);
      ans = max(ans, x1);
      // cout<<i<<" "<<j<<" "<<x1<<'\n';

      // for(int k = 0; k<n; k++){
      //   // cout<<arr[i]<<" ";
      //   cout<< s.query(k,k).v << " ";
      // }
      // cout<<'\n';
      //
      // cout<<s.query(0, n-1).v<<"\n";
      //
      // s.rupd(i, i, temp1);
      // s.rupd(j, j, temp2);
    }
  }

  cout<<ans<<'\n';


  // cout<<ans<<"\n";


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
