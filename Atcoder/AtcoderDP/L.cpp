#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;

#define PB push_back
#define MP make_pair

typedef long long ll;

long long int maxnumber(long long int a, long long int b){
  if(a>b){
    return a;
  }
  return b;
}

#define FOR(i,a,b) for(int i=a; i<b; i++)

int maxn = 3005;

vector<vector<long long int>> arr(maxn, vector<long long int>(maxn,-1));

long long int MaxScore(vector<int> &a, int i, int j){

  if(arr[i][j]!=-1){
    return arr[i][j];
  }

  if(i>=j){
    return 0;
  }

  long long int n1 = a[i] + MaxScore(a,i+1,j-1);
  long long int n2 = a[i] + MaxScore(a,i+2,j);

  long long int n3 = a[j-1] + MaxScore(a,i+1, j-1);
  long long int n4 = a[j-1] + MaxScore(a,i,j-2);

  arr[i][j] = maxnumber(maxnumber(n1,n2),maxnumber(n3,n4));

  return arr[i][j];
}

int main(){

  #ifndef ONLINE_JUDGE
      freopen("inputf.txt", "r", stdin);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;

  while(t--){

    int n;
    cin>>n;

    vi a(n);
    long long int tsum = 0;

    FOR(i,0,n){
      cin>>a[i];
      tsum = tsum + a[i];
    }

    MaxScore(a,0,n);

    FOR(i,0,n+1){
      FOR(j,0,n+1){
        cout<<arr[i][j]<<" ";
      }
      cout<<"\n";
    }


    cout<<2*arr[0][n]-tsum<<"\n";

  }
  return 0;
}
