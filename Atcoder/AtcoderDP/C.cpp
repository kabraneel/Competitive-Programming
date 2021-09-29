#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;

#define PB push_back
#define MP make_pair

typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<b; i++)

int maxn = 1e5 + 5;

vi arr(maxn);


int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;

  while(t--){
    int n,k;
    cin>>n;

    vector<vi> arr(n, vi (3));

    FOR(i,0,n){
      FOR(j,0,3){
        cin>>arr[i][j];
      }
    }

    for(int i=n-2; i>=0; i--){
      arr[i][0] = arr[i][0] + max(arr[i+1][2], arr[i+1][1]);
      arr[i][1] = arr[i][1] + max(arr[i+1][2], arr[i+1][0]);
      arr[i][2] = arr[i][2] + max(arr[i+1][0], arr[i+1][1]);

    }

    cout<<*max_element(arr[0].begin(),arr[0].end())<<"\n";

  }
  return 0;
}
