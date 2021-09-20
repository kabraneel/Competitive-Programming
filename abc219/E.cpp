// na ho paega humse
// nai_aati_coding
// i love PD
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
// #define int long long
#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
// const int INF = 1e18;

vector<int> dx  = {1,-1,0,0};
vector<int> dy  = {0,0,1,-1};
int visited[6][6];
vector<vector<int>> testmat(6, vector<int>(6,0));

bool validpoint(int i, int j, int tester){
  if(i>=0 && j>=0 && j<6 && i<6 && testmat[i][j] == tester && !visited[i][j])
    return true;
  return false;
}

int flag = 0;

void dfs(int i, int j, int tester ){
  visited[i][j] = 1;
  for(int k = 0; k<6; k++){
    if(validpoint(i + dx[k], j+ dy[k], tester)){
      dfs(i + dx[k], j+dy[k], tester);
    }
  }
}

bool isvalid(){

  int ans = 0;
  for(int i = 0; i<6; i++){
    for(int j = 0; j<6; j++){
      visited[i][j] = 0;
    }
  }

  // flag = 1;

  for(int i = 0; i<6; i++){
    for(int j = 0; j<6; j++){
      if(testmat[i][j] == 0 && !visited[i][j]){
        dfs(i,j,0);
        ans++;
      }
    }
  }

  // int ans = 0;
  bool pos = (ans == 1);
  ans = 0;
  for(int i = 0; i<6; i++){
    for(int j = 0; j<6; j++){
      visited[i][j] = 0;
    }
  }

  // flag = 1;

  for(int i = 0; i<6; i++){
    for(int j = 0; j<6; j++){
      if(testmat[i][j] == 1 && !visited[i][j]){
        dfs(i,j,1);
        ans++;
      }
    }
  }

  if(pos == true && ans == 1){
    return true;
  }
  return false;

}

void solve(){
  int mat[4][4];
  FOR(i,0,4){
    FOR(j,0,4) cin>>mat[i][j];
  }

  int ans = 0;
  int count = 0;

  // set<vector<vector<int>>> S;

  for(int i = 1; i<(1<<16); i++){
    // count++;
    for(int j = 0; j<16; j++){
      //if j is on, im trying to put j inside the moat
      if((1<<j) & i){
        testmat[1+j/4][1+j%4] = 1;
      }
      else{
        testmat[1+j/4][1+j%4] = 0;
      }
    }

    // S.insert(testmat);
    //test mat is ready
    //now check if those in mat are on in test or not
    bool ok = true;
    for(int k1 = 0; k1<4; k1++){
      for(int k2 = 0; k2<4; k2++){
        if(mat[k1][k2]){
          if(!testmat[k1+1][k2+1]){
            ok = false;
            // break;
          }
        }
      }
    }

    if(!ok){
      for(int k1 = 0; k1<6; k1++){
        for(int k2 = 0; k2<6; k2++){
          testmat[k1][k2] = 0;
        }
      }
      continue;
    }



    if(isvalid()){
      ans++;
      // for(int k1 = 0; k1<4; k1++){
      //   for(int k2 = 0; k2<4; k2++){
      //     // testmat[k1][k2] = 0;
      //     cout<<testmat[k1][k2]<<' ';
      //   }
      //   cout<<'\n';
      // }
      // cout<<'\n';
    }

    for(int k1 = 0; k1<4; k1++){
      for(int k2 = 0; k2<4; k2++){
        testmat[k1][k2] = 0;
      }
    }


  }
  // cout<<S.size()<<'\n';
  // cout<<count<<"\n";
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

  int t=1;
  // cin>>t;
  while(t--){
    solve();
  }

  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

  time_taken *= 1e-9;

  cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
  return 0;
}
