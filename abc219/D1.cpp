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


int N = 305;
int tarx;
int tary;
vector<pair<int,int>> arr(N);

int dp[301][301][301] = {-1};

int findmin(int x, int y, int n){

  if(x >= tarx && y >= tary){
    return 0;
  }

  x = min(tarx, x);
  y = min(tary, y);

  if(n == 0){
    return 500;
  }

  if(dp[x][y][n]){
    return dp[x][y][n];
  }

  dp[x][y][n] = min(1 + findmin(x + arr[n-1].first, y + arr[n-1].second, n-1), findmin(x,y,n-1));

  return dp[x][y][n];
}

void solve(){
  int n; cin>>n;
  cin>>tarx>>tary;
  int xsum = 0, ysum = 0;

  FOR(i,0,n){
    int x,y;
    cin>>x>>y;
    arr[i] = MP(x,y);
    xsum += x;
    ysum += y;
  }

  if((xsum < tarx) || (ysum < tary)){
    cout<<"-1\n";
    return;
  }

  cout<<findmin(0,0,n)<<'\n';

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
