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

map<string,long long int> knap;

long long int findmaxvalue(int n, vi &wieghts, vi &values, int w){

  if(n==0 || w==0){
    return 0;
  }

  string s = to_string(n) + "." + to_string(w);

  auto it = knap.find(s);

  if(it != knap.end()){
    return knap[s];
  }

  if(wieghts[n-1]>w){
    long long int temp = findmaxvalue(n-1,wieghts,values,w);
    knap[s] = temp;

    return knap[s];
  }

  else{

    long long int temp1 = findmaxvalue(n-1,wieghts,values,w);
    long long int temp2 = values[n-1] + findmaxvalue(n-1,wieghts,values,w-wieghts[n-1]);

    knap[s] = findmax(temp1,temp2);

    return knap[s];
  }
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

    findmaxvalue(n,wieghts, values,w);

    string ans = to_string(n) + '.' + to_string(w);

    cout<<knap[ans]<<"\n";
  }
  return 0;
}
