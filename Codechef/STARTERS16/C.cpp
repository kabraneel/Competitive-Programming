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

// void qsort(string &s){
//
//
// }

void solve(){

  // cout<<(char) (25 + 'A')<<'\n';

  int n; cin>>n;
  string s; cin>>s;

  vector<vector<int>> prefixes(n+5, vector<int> (26));

  for(int i = 0; i<n; i++){
    prefixes[i+1][s[i] - 'A']++;
  }

  for(int i = 1; i<=n; i++){
    for(int j = 0; j<26; j++){
      prefixes[i][j] += prefixes[i-1][j];
    }
  }

  // for(int i = 0; i<n+1; i++){
  //   for(int j = 0; j<6; j++){
  //     cout<<prefixes[i][j]<<' ';
  //   }
  //   cout<<'\n';
  // }

  int q; cin>>q;
  while(q--){

    int l,r,k; cin>>l>>r>>k;

    if(r - l + 1 < k){
      cout<<"No\n";
      continue;
    }

    bool pos1 = false;
    int max_cnt = 0;

    int tsum = 0;
    for(int j = 0; j<26; j++){
      if(prefixes[r][j] - prefixes[l-1][j] > k){
        cout<<"No\n";
        pos1 = true;
        break;
      }
      max_cnt = max(max_cnt, prefixes[r][j] - prefixes[l-1][j]);
      tsum += prefixes[r][j] - prefixes[l-1][j];
    }

    // cout<<"tsum -> "<<tsum<<'\n';

    if(pos1){
      continue;
    }


    // ---------------------

    // vector<int> counts(26);
    // string temp;
    //
    // for(int i = l-1; i<r; i++){
    //   counts[s[i] - 'A']++;
    // }
    //
    //
    // bool pos = false;
    //
    // for(int i = 0; i<26; i++){
    //
    //   if(counts[i] > k){
    //     ;
    //   }
    //
    //   for(int j = 0; j<counts[i]; j++){
    //       temp.PB(i + 'A');
    //   }
    //
    // }
    //
    // // if(pos){
    // //   cout<<"No\n";
    // //   continue;
    // // }
    //
    // int n1 = temp.length();
    // // cout<<temp<<'\n';
    // string ans;
    // for(int i = n1 - 1; i>=k; i--){
    //   ans.PB(temp[i]);
    // }
    //
    // for(int i = 0; i<k; i++){
    //   ans.PB(temp[i]);
    // }
    //
    // bool pos = true;
    // int count = 0;
    //
    // for(int i = 0; i<n1-1; i++){
    //   if(ans[i+1] >= ans[i]){
    //     count++;
    //     if(count > k){
    //       pos = false;
    //       break;
    //     }
    //   }
    //   else{
    //     count = 0;
    //   }
    // }
    //
    // if(!pos){
    //   cout<<"No\n";
    //   continue;
    // }
    //
    cout<<"Yes\n";
    // cout<<ans<<'\n';

   string t = s.substr(l-1, r - l +1);
   sort(t.rbegin(), t.rend());

   if (max_cnt < k)
        reverse(t.end() - k, t.end());

   cout << t << "\n";





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
