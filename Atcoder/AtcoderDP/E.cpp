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

    int n,w;
    cin>>n>>w;

    vi wts(n);
    vi vals(n);

    int maxval = 0;

    FOR(i,0,n){
      cin>>wts[i]>>vals[i];
      maxval = vals[i] + maxval;
    }

    vector<vi> arr(n+1, vi (maxval+1));

    FOR(i,0,n+1){
      arr[i][0] = 0;
    }

    FOR(i,1,maxval+1){
      arr[0][i] = 1e9;
    }

    FOR(i,1,n+1){
      FOR(j,1,maxval+1){
        if(j<vals[i-1]){
          arr[i][j] = arr[i-1][j];
        }
        else{
          arr[i][j] = min(arr[i-1][j],wts[i-1]+arr[i-1][j-vals[i-1]]);
        }
      }
    }


    int ans=0;
    FOR(j,0,maxval+1){
      if(arr[n][j]<=w){
        ans = j;
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}
