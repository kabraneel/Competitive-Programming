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

  int n; int d;
  cin>>n>>d;

  if(n == d){
    cout<<"1\n";
    return;
  }

  // for
  string s = to_string(n);
  int n1 = s.length();

  if(d == 0){
    // int x = 0;
    string temp = s;
    for(int i = 0; i<n1; i++){
      // x = 10*x + 1;
      if(s[i] == '0'){
        temp[i] = '1';
      }
    }
    int x = stoi(temp);
    // cout<<x<<'\n';
    cout<<x - n<<'\n';
    return;
  }

  // for(int i = n1)
  int ind = -1;
  for(int i = 0; i<n1; i++){
    if(s[i] == '0' + d){
      ind = i;
      break;
    }
  }

  if(ind == -1){
    cout<<"0\n";
    return;
  }

  string s1 = s.substr(ind+1, n1);
  // cout<<s<<" "<<s1<<'\n';
  int x = 1;
  for(int i = 0;  i< (int) s1.length(); i++){
    x *= 10;
  }
  // cout<<x<<'\n';
  cout<<x - stoi(s1)<<'\n';


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
