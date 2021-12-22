// na ho paega humse
// nai_aati_coding
// i love CS
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
// const int INF = 1e18;

void solve(){
  int n; cin>>n;
  string s; cin>>s;

  vector<vector<int>> Y(n, vector<int> (3,0));

  // YBR
  // for(auto v: S){
  //   if(v == 'U'){
  //     // Y.PB(0);
  //
  //   }
  // }
  for(int i = 0; i<n; i++){
    if(s[i] == 'U'){
      Y[i][0] = 0;
      Y[i][1] = 0;
      Y[i][2] = 0;
    }

    if(s[i] == 'R'){
      Y[i][0] = 0;
      Y[i][1] = 0;
      Y[i][2] = 1;
    }

    if(s[i] == 'Y'){
      Y[i][0] = 1;
      Y[i][1] = 0;
      Y[i][2] = 0;
    }

    if(s[i] == 'B'){
      Y[i][0] = 0;
      Y[i][1] = 1;
      Y[i][2] = 0;
    }

    if(s[i] == 'G'){
      Y[i][0] = 1;
      Y[i][1] = 1;
      Y[i][2] = 0;
    }

    if(s[i] == 'O'){
      Y[i][0] = 1;
      Y[i][1] = 0;
      Y[i][2] = 1;
    }

    if(s[i] == 'P'){
      Y[i][0] = 0;
      Y[i][1] = 1;
      Y[i][2] = 1;
    }

    if(s[i] == 'A'){
      Y[i][0] = 1;
      Y[i][1] = 1;
      Y[i][2] = 1;
    }

  }

  // for(int i = 0; i<3; i++){
  //   for(int j = 0; j<n; j++){
  //     cout<<Y[j][i]<<' ';
  //   }
  //   cout<<'\n';
  // }

  int ans = 0;

  for(int j = 0; j<3; j++){
    //     Y[i][j]
    int count = 0;
    int key = Y[0][j];

    int i = 0;
    // for(int i = 1; )
    while(i<n){
      key = Y[i][j];
      while(i<n && Y[i][j] == key){
        i++;
      }
      if(key == 1)
        count++;
    }
    // cout<<count<<'\n';
    ans += count;
  }

  cout<<ans<<'\n';
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
  int count = 1;
  while(t--){
    cout<<"Case #"<<count<<": ";
    count+=1;
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
