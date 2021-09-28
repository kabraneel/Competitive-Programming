#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

#define MAXN 100
int d[MAXN][MAXN];

void FloydMarshall(int n){

  FOR(i,0,n){
    FOR(j,0,n){
      FOR(k,0,n){
        d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }

}

void solve(){
  int n;
  cin>>n;

  FOR(i,0,n){
    FOR(j,0,n){
      cin >> d[i][j];
    }
  }

  FloydMarshall(n);

}

int main(){

  #ifndef ONLINE_JUDGE
      freopen("inputfa.txt", "r", stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  while(t--){
    solve();
  }
  return 0;
}
