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

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int N = sz(primes);

vector<set<int>> adj(105);

void pre(){
  for(int i = 2; i<100; i++){
    for(auto v: primes){
      if(i%v == 0){
        adj[i].insert(v);
      }
    }
  }
}

void solve(){

  int n; cin>>n;
  set<int> divby;

  for(auto v: primes){
    if(n % v == 0){
      divby.insert(v);
    }
  }

  // for(auto v: divby){
  //   cout<<v<<" ";
  // }
  // cout<<'\n';

  if(n%2 == 0){
    cout<<2*n<<" "<<n<<'\n';
    return;
  }

  for(int x = 2; x<100 ; x++){
    // bool pos1 = false;
    // bool pos2 = false;
    //
    // for(auto v: divby){
    //   if(x % v == 0) pos1 = true;
    //   if((x+1) % v == 0) pos2 = true;
    // }

    // cout<<pos1<<" "<<pos2<<"\n";

    // if((pos1 && pos2) || (!pos1 && !pos2)){
    //   cout<<(x+1)*n<<" "<<x*n<<'\n';
    //   return;
    // }

    //if even one number of divby is in adj[x], then all numbers present
    // int pos1 = 0;
    // for(auto v: adj[x]){
    //   if(divby.find(v) == divby.end()){
    //
    //   }
    // }

    // bool pos1a = false;
    int count1 = 0;
    for(auto v: adj[x]){
      if(divby.find(v) != divby.end()){
        // pos1a = true;
        count1++;
      }
    }

    // bool pos2a = false;
    int count2 = 0;
    for(auto v: adj[x+1]){
      if(divby.find(v) != divby.end()){
        // pos2a = true;
        count2++;
      }
    }

    // if((count1 == sz(adj[x]) && count2 == sz(adj[x+1])) || (!pos2a && !pos1a && sz(adj[x]) == sz(adj[x+1])){
    //     // cout<<count1<<" "<<count2<<'\n';
    //     cout<<(x+1)*n<<" "<<x*n<<'\n';
    //     return;
    // }


    //x + 1 added sz
    if((sz(adj[x]) - count1) == (sz(adj[x+1]) - count2)){
          cout<<(x+1)*n<<" "<<x*n<<'\n';
          return;
    }

  }




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
  pre();

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
