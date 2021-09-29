#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;

#define PB push_back
#define MP make_pair

typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<b; i++)

int maxn = 1e5 + 5;

long long int findmax(long long int a, long long int b){
  if(a>b){
    return a;
  }
  return b;
}

int main(){

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t=1;

  while(t--){
    int n,w;
    cin>>n>>w;

    vi values(n+1);
    vi wieghts(n+1);

    FOR(i,0,n){
      cin>>wieghts[i]>>values[i];
    }

    vector<long long int> v1(w+1,0);
    vector<long long int> v2(w+1,0);

    FOR(i,1,n+1){
      FOR(j,0,w+1){
        if(i%2==1){
          //v2
          if(wieghts[i-1]>j){
            v2[j] = v1[j];
          }
          else{
            v2[j] = findmax(v1[j], values[i-1] + v1[j-wieghts[i-1]]);
          }
        }
        else{
          if(wieghts[i-1]>j){
            v1[j] = v2[j];
          }
          else{
            v1[j] = findmax(v2[j], values[i-1] + v2[j-wieghts[i-1]]);
          }
        }
      }
    }

    if(n%2==0){
      cout<<v1[w]<<"\n";
    }
    else{
      cout<<v2[w]<<"\n";
    }


  }
  return 0;
}
