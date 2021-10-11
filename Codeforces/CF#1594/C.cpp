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
  int n; char c; cin>>n>>c;
  string s; cin>>s;

  int count = 0;
  for(auto v: s){
    if(v == c) count++;
  }

  if(count == n){
    cout<<"0\n";
    return;
  }




  // if(count == n-1 && s[n-1] == c){
  //   cout<<"1\n";
  //   cout<<n-1<<"\n";
  //   return;
  // }

/*
 3 -> 1,2,3
 4 -> 1,2,3,4
*/

  for(int i = n; i >= (n+2)/2; i--){
    if(s[i-1] == c){
      cout<<"1\n";
      cout<<i<<'\n';
      return;
    }
  }

  // 2 ops below this
  //
  //


  vector<int> ans;
  ans.PB(n);


  //
   // if(s[n-1] != c){
  //   if(n%2 == 0){
  //     ans.PB(3);
  //   }
  //
  //   else{
  //     ans.PB(2);
  //   }
  // }

  ans.PB(n-1);

  cout<<sz(ans)<<'\n';
  for(auto v: ans){
    cout<<v<<" ";
  }
  cout<<'\n';


  // for(int i = 0; i<n-1; i++)

  /*
  i can for sure do it in 2 ops
  */

  // for(int i = n-1; i>=(n/2); i--){
  //   if(s[i] == c){
  //     if(count > 1){
  //       cout<<"2\n";
  //       cout<<i<<" "<<i-1<<"\n";
  //     }
  //   }
  // }


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
