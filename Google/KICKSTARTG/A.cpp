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
  int n,d,c,m;
  cin>>n>>d>>c>>m;

  string s; cin>>s;
  int cfood = c;
  int dfood = d;
  int j = n-1;
  while(j >= 0 && s[j] == 'C') j--;

  // cout<<s[j]<<'\n';
  // if(j == 0){
  //
  // }
  for(int i = 0; i<=j; i++){
    if(s[i] == 'C'){
      if(cfood == 0){
        cout<<"NO\n";
        return;
      }
      cfood--;
    }
    else{
      if(dfood == 0){
        cout<<"NO\n";
        return;
      }
      dfood--;
      cfood += m;
    }
  }
  // cout<<cfood<<" "<<dfood<<'\n';
  cout<<"YES\n";
}

signed main(){

  // #ifndef ONLINE_JUDGE
  // freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  // freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  // freopen("/home/kabraneel/coding/error.txt","w",stderr);
  // #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();

  int t;
  cin>>t;
  int tcount = 0;
  while(t--){
    tcount++;
    cout<<"Case #"<<tcount<<": ";
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
/*
50/100 -> 0
*/
