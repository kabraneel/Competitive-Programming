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

// const int N = 1e4 + 5;
// vector<pair<int,int>> arr(N);

void solve(){
	int n; cin>>n;
	int modu = -1;
	vector<pair<int,int>> arr(n);
	for(int i = 0; i<n; i++){
		int x; int y; cin>>x>>y;
		if(modu == -1){
			modu = y;
		}

		arr[i] = {x, y};
	}

	vector<int> X;
	vector<int> Y;

	for(auto v: arr){
		if(v.second == 0) X.PB(v.first);
		else Y.PB(v.first);
	}

	int i = 0; int j = 0;
	int currtime = 0;

	int count = 0;

	while(i < sz(X) && j < sz(Y)){

		if(count > 100){
			break;
		}
		count++;

		if(modu == 0){ // moving in X dxn
			// currtime = X[i] + 10;
			while( i+1 < sz(X) ){
				if(X[i+1] - X[i] < 10){
					currtime = X[i] + 10;
				}
				i++;
			}
			int t = j;
			while(t < sz(Y)){
				if(Y[t] < currtime)
					Y[t] = currtime;
				t++;
			}
			modu = 1;
		}

		else{ // moving in X dxn
			// currtime = Y[j] + 10;
			while( j+1 < sz(Y) ){
				if(Y[j+1] - Y[j] > 10){
					currtime = Y[j] + 10;
				}
				j++;
			}
			int t = i;
			while(t < sz(X)){
				if(X[t] < currtime)
					X[t] = currtime;
				t++;
			}
			modu = 0;
		}

		debug(currtime);
	}

	debug("hi");
	debug(X);
	debug(Y);

	if( i < sz(X)){
		currtime = X[sz(X)-1] + 10;
	}

	if( j < sz(Y)){
		currtime = Y[sz(Y)-1] + 10;
	}

	cout << currtime << '\n';



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