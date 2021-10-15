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

  string s = to_string(n);

  int n1 = s.length();
  int ans = n1;

  for(int i = 0; i<n1; i++){
    string temp;
    temp.PB(s[i]);
    for(int j = i+1; j<n1; j++){
      string temp1 = temp;
      temp1.PB(s[j]);
      // cout<<temp1<<'\n';
      if((temp1 == "25") || (temp1 == "50") || (temp1 == "00") || (temp1 == "75")){
        //cost is
        //     2  0   5 3 3
        //     0  1   2 3 4
        // ... i .... j ...
        //     (2 - 0 - 1) + (5 - 2 - 1)
        ans = min(ans, n1 - j - 1 +  (j - i - 1));

      }
    }

  }

  cout<<ans<<'\n';
  // for(int i = n1 - 1; i>=1; i--){
  //   string temp;
  //   temp.PB(s[i]);
  //   temp.PB(s[i-1]);
  //   reverse(all(temp));
  //   if((temp == "25") || (temp == "50") || (temp == "00") || (temp == "75")){
  //     cout<< n1 - i - 1  <<'\n';
  //     return;
  //   }
  // }
  // cout<<n1<<'\n';

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
