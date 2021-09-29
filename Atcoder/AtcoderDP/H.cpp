#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;

#define PB push_back
#define MP make_pair

typedef long long ll;

void print(vector<int> &arr){

  int n = arr.size();
  for(int i=0; i<n; i++){
    cout<<arr[i]<<" ";
  }
  cout<<"\n";

}

#define FOR(i,a,b) for(int i=a; i<b; i++)

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin>>t;
  while(t--){

    int n,m;
    cin>>n>>m;

    vector<vector<char>> arr(n,vector<char> (m));

    FOR(i,0,n){
      FOR(j,0,m){
        cin>>arr[i][j];
      }
    }

    vector<vi> arrans(n,vi(m,0));

    int i=0;
    while(i<n){
      if(arr[i][0] =='.'){
        arrans[i][0] = 1;
        i++;
        continue;
      }
      else{
        while(i<n){
          arrans[i][0] = 0;
          i++;
        }
      }
    }

    i=0;
    while(i<m){
      if(arr[0][i] =='.'){
        arrans[0][i] = 1;
        i++;
        continue;
      }
      else{
        while(i<m){
          arrans[0][i] = 0;
          i++;
        }
      }
    }

    int maxn = 1e9 + 7;
    FOR(k,1,n){
      FOR(j,1,m){
        if(arr[k][j] == '.'){
          arrans[k][j] = (arrans[k-1][j] + arrans[k][j-1])%maxn;
        }
        else{
          arrans[k][j] = 0;
        }
      }
    }

    cout<<arrans[n-1][m-1]<<"\n";

  }
  return 0;
}
