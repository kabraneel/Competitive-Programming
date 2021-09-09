// na ho paega humse
// nai_aati_coding
// i love PD
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
// #define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
// const int INF = 1e18;

void solve(){
  int n; cin>>n;
  vector<int> twos;
  string s; cin>>s;

  for(int i = 0; i<n; i++){
    if(s[i] == '2'){
      twos.PB(i);
    }
  }

  char ans[n][n];

  FOR(i,0,n){
    FOR(j,0,n) ans[i][j] = 'T';
  }

  if(sz(twos) == 0){
    cout<<"YES\n";
    for(int i = 0; i<n; i++){
      for(int j = 0; j<n; j++){
        if(i == j){
          ans[i][j] = 'X';
        }
        else{
          ans[i][j] = '=';
        }
        cout<<ans[i][j];
      }
      cout<<'\n';
    }
    return;
  }

  int m = (int) sz(twos);


  if(m<3){
    cout<<"NO\n";
    return;
  }

  cout<<"YES\n";

  for(int i = 0; i<m-1; i++){
    ans[twos[i]][twos[i+1]] = '+';
    ans[twos[i+1]][twos[i]] = '-';
  }

  ans[twos[m-1]][twos[0]] = '+';
  ans[twos[0]][twos[m-1]] = '-';


  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if((ans[i][j] == '+') || (ans[i][j] == '-')) continue;
      if(i == j) ans[i][j] = 'X';
      else ans[i][j] = '=';
    }
  }

  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      cout<<ans[i][j];
    }
    cout<<'\n';
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
