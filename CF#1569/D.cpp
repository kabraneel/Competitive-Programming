// na ho paega humse
// nai_aati_coding
// i love PD
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

void solve(){
  int n,m,k; cin>>n>>m>>k;
  vector<int> hors(n);
  vector<int> vers(m);

  for(int i = 0; i<n; i++){
    cin>>hors[i];
  }
  for(int i = 0; i<m; i++){
    cin>>vers[i];
  }

  set<int> HS;
  set<int> VS;

  for(auto v: hors){
    HS.insert(v);
  }

  for(auto v: vers){
    VS.insert(v);
  }

  int count1 = 1;
  int count2 = 1;
  map<int,int> MX;
  map<int,int> MY;
  int ans = 0;
  while(k--){
    int x,y; cin>>x>>y;

    auto it = HS.find(x);
    auto it1 = VS.find(y);

    if(it != HS.end()){
      // count1++;
      //this means its on horizontal
      //problem with all those who are on diff horizontal and NOT vertical
      if(it1 != VS.end()){
        ;
      }
      else{
        MX[x]++;
        ans += count1 - MX[x];
        cout<<"adding "<<(count1 - MX[x])<<" for "<<x<<" "<<y<<'\n';
        count1++;
        // total++;
      }

    }

    if(it1 != VS.end()){
      // count1++;
      //this means its on horizontal
      //problem with all those who are on diff horizontal and NOT vertical
      if(it != HS.end()){
        ;
      }
      else{

        MY[y]++;
        ans += count2 - MY[y];
        cout<<"adding "<<(count2 - MY[y])<<" for "<<x<<" "<<y<<'\n';

        count2++;

        // total++;
      }

    }

  }

  cout<<ans<<'\n';


}


signed main(){

  #ifndef ONLINE_JUDGE
  freopen("/home/kabraneel/coding/inputfa.txt", "r", stdin);
  freopen("/home/kabraneel/coding/outputfa.txt", "w", stdout);
  freopen("/home/kabraneel/coding/error.txt","w",stderr);
  #endif

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  auto start = chrono::high_resolution_clock::now();

  int t;
  cin>>t;
  while(t--){
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
