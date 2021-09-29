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

vector<vi> arr(3005, vi (3005,-1));
/*
int finlength(string &s1, string &s2,int n, int m){

  if(n==0 || m==0){
    return 0;
  }

  if(arr[n][m]!=-1){
    return arr[n][m];
  }

  if(s1[n-1]==s2[m-1]){
    arr[n][m] = 1 + finlength(s1,s2,n-1,m-1);
  }

  else{
    arr[n][m] = max(finlength(s1,s2,n-1,m),finlength(s1,s2,n,m-1));
  }

  return arr[n][m];

}*/

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;
  // cin>>t;
  while(t--){

    int n,m;
    string s1,s2;
    cin>>s1>>s2;
    n = s1.length();
    m = s2.length();

    //bottom up for finding length of lcs
    FOR(i,0,n+1){
      arr[i][0] = 0;
    }

    FOR(i,0,m+1){
      arr[0][i] = 0;
    }

    FOR(i,1,n+1){
      FOR(j,1,m+1){
        if(s1[i-1]==s2[j-1]){
          arr[i][j] = arr[i-1][j-1] + 1;
        }
        else{
          arr[i][j] = max(arr[i][j-1], arr[i-1][j]);
        }
      }
    }


    int i=n;
    int j = m;
    string ans = "";

    while(i>0 && j>0){
        if(arr[i-1][j]==arr[i][j]){
          i--;
        }
        else if(arr[i][j-1] == arr[i][j] ){
          j--;
        }
        else{
          ans = ans + s1[i-1];
          i--;
          j--;
        }
    }

    for(int k=ans.length()-1; k>=0; k--){
      cout<<ans[k];
    }
    cout<<"\n";

  }
  return 0;
}
