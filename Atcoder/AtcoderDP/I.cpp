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
float bar(float x){
  float a = 1.0;
  return a-x;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.precision(20);

  int t=1;
  // cin>>t;
  while(t--){

    int n;
    cin>>n;

    vector<double> coins(n);

    FOR(i,0,n){
      cin>>coins[i];
    }

    vector<vector<double>> ans(n+1,vector<double>(n));
    float tails = 1;

    ans[0][0] = 0;

    FOR(i,1,n+1){
      tails = tails*bar(coins[i-1]);
      ans[i][0] = tails;
    }

    float heads = 1;
    FOR(i,1,n+1){
      heads = heads*coins[i-1];
      ans[i][i] = heads;
    }
    //checked till here

    FOR(i,1,n+1){
      FOR(j,1,i){
        ans[i][j] = coins[i-1]*ans[i-1][j-1] + bar(coins[i-1])*ans[i-1][j];
      }
    }

    FOR(i,0,n+1){
      FOR(j,0,n+1){
        cout<<ans[i][j]<<"   ";
      }
      cout<<"\n";
    }

    float fans = 0;

    FOR(i,(n+1)/2, n+1){
      fans = fans + ans[n][i];
    }
    cout<<setprecision(20)<<fans<<"\n";

  }
  return 0;
}
