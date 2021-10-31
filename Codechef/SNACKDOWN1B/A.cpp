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
const int INF = 1e18;

void solve(){
  int n; cin>>n;
  char arr[n][n];

  // if(n == 3){
  //   cout<<"...\n";
  //   cout<<".Q.\n";
  //   cout<<"...\n";
  //   return;
  // }
  //
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      arr[i][j] = '.';
    }
  }

  if(n%2){
    for(int i = 0; i<n/2-1; i++){
      arr[i][i] = 'Q';
    }

    arr[n/2][n/2] = 'Q';

    for(int i = n/2+2; i<n; i++){
      arr[i][i] = 'Q';
    }
  }
  //
  // for(int i = 0; i<n; i+=2){
  //   arr[i][i] = 'Q';
  // }
  else{

    for(int i = 0; i<(n-4)/2; i++){
      arr[i][i] = 'Q';
    }
    arr[n/2 - 1][n/2 - 1] = 'Q';
    arr[n/2+1][n/2+1] = 'Q';
    //
    for(int i = n-1; i> (n/2); i--){
      arr[i][i] = 'Q';
    }

  }
  //
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      cout<<arr[i][j];
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
