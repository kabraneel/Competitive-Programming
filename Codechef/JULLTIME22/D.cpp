// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define int long long
#ifdef KABRANEEL
#define LOCAL
#include "/home/kabraneel/coding/debug.h"
#else
#define debug(x...)
#define debugln(x...)
#endif

#define PB push_back
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define sz(x) (int)(x.size())

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

#define FOR(i,a,b) for(int i=a; i<b; i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;

const int N = 2e5 + 5;
const int LOG = 19;

int sparse[N][LOG];

int query(int l, int r){

  int len = r - l + 1;
  int k = 31 - __builtin_clz(len);

  return max(sparse[l][k], sparse[r-(1<<k)+1][k]);

}

void solve(){
	int n; int m;
	cin>>m>>n;
	vector<int> arr(n);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
    	sparse[i][0] = arr[i];
	}

	 for(int j = 1; j < LOG; j++){
    for(int i = 0; i+(1<<(j)) -1 <  n ; i++){
      sparse[i][j] = max(sparse[i][j-1], sparse[i + (1<<(j-1))][j-1]);
    }
  }

	int q; cin>>q;
	while(q--){
		int y1, x1, y2, x2; cin>>x1>>y1>>x2>>y2;
		int k; cin>>k;
		// go as low as you can
		int mex = (m - y1)/k;
		mex += 5;

		y1 += mex * k;
		debug(y1);
		while(y1 > m){
			y1 -= k;
			debug(y1);
		}
		debug(q, y1);

		// everything bw x2 and x1 should be less than y1
		if( (abs(x2 - x1)) % k != 0){
			cout<<"NO\n";
			continue;
		}

		int temp1 = max(x1-1, x2-1);
		int temp2 = min(x1-1, x2-1);
		int x = query(temp2, temp1);
		debug(x);
		if(x < y1){
			debug(y1, y2);
			if( (y1 - y2) % k == 0){
				cout<<"YES\n";
				continue;
			}
		}

		cout<<"NO\n";



	}
}

signed main(){

	#ifdef KABRANEEL
	freopen("/home/kabraneel/coding/Contests/inputfa.txt", "r", stdin);
	freopen("/home/kabraneel/coding/Contests/outputfa.txt", "w", stdout);
	freopen("/home/kabraneel/coding/Contests/error.txt","w",stderr);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	auto start = chrono::high_resolution_clock::now();

	int t=1;
	int zcount = 1;
	// cin>>t;

	while(t--){
		//cout<<"Case #"<<zcount++<<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}