// na ho paega humse
// nai_aati_coding
// i love CS
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
  int n,m; cin>>n>>m;
  // pair<int,int> mexes;
  // pair<int,int> mens;
  int minx = 0, maxx = 0;
  int miny = 0, maxy = 0;

  int currx = 0; int curry = 0;
  string s; cin>>s;
  int count = 0;

  for(auto v: s){

    count++;

    if(v == 'L') currx--;
    else if (v == 'R') currx++;
    else if (v == 'U') curry++;
    else curry--;

    minx = min(currx, minx);
    maxx = max(currx, maxx);
    miny = min(curry, miny);
    maxy = max(curry, maxy);


    if(maxx - minx >= m){
      // cout<<"due to cols\n";

      if(v == 'L')
        cout<<maxy + 1<<" "<<-1*minx<<" "<<count<<'\n';

      if(v == 'R')
        cout<<maxy + 1<<" "<<-1*minx + 1<<" "<<count<<'\n';
      // if(v == 'R')
      //
      // break;
      return;
    }

    if(maxy - miny >= n){
      // cout<<"due to rows\n";
      if(v == 'U')
        cout<<maxy<<" "<<-1*minx + 1<<" "<<count<<'\n';

      else
        cout<<maxy+1<<" "<<-1*minx + 1<<" "<<count<<'\n';

      // break;
      return;
    }

  }

  // cout<<minx<<" "<<maxx<<" "<<miny<<" "<<maxy<<'\n';
  // cout<<count<<'\n';

  cout<<maxy + 1<<" "<<-1*minx + 1<<" "<<count<<'\n';


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
