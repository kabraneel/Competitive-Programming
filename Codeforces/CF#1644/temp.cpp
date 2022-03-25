// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
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

double dp[55][55][55];

/*

dp[x][y][z] -> (x,y,z)
50,50,50 -> 49, 50, 50 +      50, 49, 50, + 50 50 49
            49 49 50    +     49, 49, 50  

~n^3 

*/


double solver(int x, int y, int z){

  if(dp[x][y][z] != -1){
    return dp[x][y][z];
  }

  if(x == 0 || y == 0 || z == 0){
    return 0;
  }

  return dp[x][y][z] = 1.00 + 0.33 * (solver(x-1,y,z) + solver(x, y-1, z) + solver(x,y,z-1));
}

void solve(){
    
  int x, y, z;
  cin>>x>>y>>z;

  for(int i = 0; i<55; i++){
    for(int j = 0; j<55; j++){
      for(int k = 0; k<55; k++){
        dp[i][j][k] = -1;
      }
    }
  }

  cout<< solver(50-x, 50-y, 50-z)<<'\n';

}

signed main(){

  int t=1;
  // cin>>t;
  while(t--){
    solve();
  }
  return 0;
}