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

  bool done[n][m];
  char arr[n][m];

  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      cin>>arr[i][j];
      done[i][j] = false;
    }
  }


  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      if(arr[i][j] == '.') continue;
      // if(!done[i][j]){
        //assume this is the top left corner of the star
        int ix = i; int jy = j;
        int count = 0; bool pos = true;
        while(ix<n && jy < m && count < k){
          //go down and right
          if(arr[ix][jy] == '*'){
            ix++;
            jy++;
            count++;
          }
          else{
            pos = false;
            break;
          }
        }

        if(!pos){
          continue;
        }

        // cout<<"Am i ever here -> "<<count<<" "<<ix<<" "<<jy<<'\n';

        //now reached a k-point
        //im allowed to go up from here

        while(ix < n && jy < m && arr[ix][jy] == '*'){
          //check if there exists a tick with this ix and iy as centre
          int tx = ix; int ty = jy; bool pos1 = true;
          for(int x = 0; x<=count; x++){
            if(tx < 0 || ty >= m || arr[tx][ty] == '.'){
              pos1 = false;
              break;
            }
            tx--;
            ty++;
          }

          if(pos1){
            //we got a hit with ix and jy as center, length is count
            // done[ix][jy] = true;
            // cout<<"Did i ever get here? -> "<<ix<<" "<<jy<<" "<<arr[ix][jy]<<"\n";
            for(int x = 0; x<=count; x++){
              done[ix - x][jy - x] = true;
              done[ix - x][jy + x] = true;
            }

            // cout<<"now done looks like\n";
            // for(int ki = 0; ki<n; ki++){
            //   for(int kj = 0; kj<m; kj++){
            //     cout<<done[ki][kj]<<' ';
            //   }
            //   cout<<'\n';
            // }
          }

          // if(arr[i][j])
          ix++;
          jy++;
          count++;

        }

      // }
    }
  }

  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      if(arr[i][j] == '*' && !done[i][j]){
        cout<<"NO\n";
        return;
      }
    }
  }

  cout<<"YES\n";

  // 1
  // 5 5 1
  // .....
  // *...*
  // .*.*.
  // ..*.*
  // ...*.


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
