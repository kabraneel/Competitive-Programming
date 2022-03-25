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

const int modn  = 998244353;

//function used to convert
int fast_pow(int a, int p) {
	int res = 1;
	while (p) {

		if (p % 2 == 0) {
		  a = a * 1ll * a % modn;
		  p /= 2;
		}

		else {
		  res = res * 1ll * a % modn;
		  p--;
		}

	}	
	return res;
}

int inverse(int a){
	return fast_pow(a,modn-2);
}


void solve(){
	int n,m,k,q; cin>>n>>m>>k>>q;

	vector<pair<int,int>> allpairs(q);
	// multiset<int> Xs;
	// multiset<int> Ys;

	// map<int,vector<int>> X;
	// map<int,vector<int>> Y;
	map<int,int> X;
	map<int,int> Y;

	for(int i = 0; i<q; i++){
		cin>>allpairs[i].first>>allpairs[i].second;
		// X[allpairs[i].first].PB(i);
		// Y[allpairs[i].second].PB(i);
		X[allpairs[i].first]++;
		Y[allpairs[i].second]++;

	}


	int colors = 0;
	for(int i = 0; i<q; i++){
		//process next query

		//will this color exist in the end?

		//this color will NOT exist IF:

		/*
		
		1 -> yi occurs and xi occurs
		2 -> all xi occur
		3 -> all yi occur

		*/

		X[allpairs[i].first]--;
		Y[allpairs[i].second]--;

		if(X[allpairs[i].first] == 0){
			// debug("")
			X.erase(allpairs[i].first);
		}

		if(Y[allpairs[i].second] == 0){
			Y.erase(allpairs[i].second);
		}

		debug(X);
		debug(Y);
		//case 2 + case 3
		if(sz(X) == n || sz(Y) == m){
			debug(i, "here1");
			continue;
		}

		if(X.find(allpairs[i].first) != X.end() && Y.find(allpairs[i].second) != Y.end()){
			debug(i, "here2");
			continue;
		}
		debug("here", i);
		colors++;


	}
	debug("done with test");
	cout<<fast_pow(k, colors)<<'\n';

	// for


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