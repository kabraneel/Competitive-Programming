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

const int N = 1e6 + 3;
int ans[N + 5];
int factors[N + 5];

int spf[N + 5];

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<N; i++)
        spf[i] = i;

    for (int i=4; i<N; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<N; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

int getFactors(int x)
{
    int ret = 1;
    // map<int,int> M;
    while (x != 1){

        int count = 0;
        int temp = spf[x];
        while(x%temp == 0){
          x = x / temp;
          count++;
        }
        ret *= (count + 1);

    }

    return ret ;
}

/*
i mean its pretty cool
yea
*/

void pre(){
  sieve();
  // for(int i = 0; i<10; i++) cout<<spf[i]<<" ";
  for(int i = 1; i<=(int) 1e6; i++){
      factors[i] = getFactors(i);
  }

  for(int i = 1; i<= (int) 1e6; i++){
    int thisans = factors[i]/2;
    thisans = ((thisans)*(thisans - 1))/2;
    ans[i] = thisans += ans[i-1];
  }
  // cout<<'\n';
  // for(int i = 0; i<10; i++) cout<<factors[i]<<" ";

}

void solve(){
  int n; cin>>n;
  cout<<ans[n]<<'\n';
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
