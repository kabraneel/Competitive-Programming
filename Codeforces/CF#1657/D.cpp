// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

// #define int long long

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
const long long int INF = 1e18;

#define MAXN   1000003
int n, C; 
map<int,long long int> recs;

vector<int> adj[MAXN];
vector<long long int> costs(MAXN);

void pre(){

	for(auto i : recs){
		for(int j = i.first; j<MAXN; j += i.first){
			adj[j].PB(i.first);
		}
	}
}


void solve(){

	cin>>n>>C;

	for(int i = 0; i<n; i++){
		int c;
		long long int d,h; cin>>c>>d>>h;
		// recs[c] = max(recs[c], d*h);
		if(recs.find(c) == recs.end()){
			recs[c] = d * h;
		}
		else{
			recs[c] = max(d*h, recs[c]);
		}
	}

	// debug(recs);



	pre();
	costs[0] = 0ll;

	for(int i = 1; i<C+1; i++){

		// vector<int> temp = adj[i];
		// debug(i, temp);
		costs[i] = costs[i-1] ;


		for(auto v: adj[i]){
			// if(recs.find(v) != recs.end()){
				costs[i] = max(costs[i], 1ll * (i/v) * recs[v]);
			// }
		}
	}
	// debug(costs);

	// sort(costs.begin(), costs.end());

	for(int i = 0; i<10; i++){
		cout<<costs[i]<<" ";
	}
	cout<<'\n';

	int q; cin>>q;
	while(q--){

		long long int d, h; cin>>d>>h;

		long long int target = d * h;

		auto p = lower_bound(costs.begin(), costs.begin() + C + 1, target +1);
		if( p == costs.begin()  + C + 1)
     		cout << "-1 ";
		else
    		 cout << p - costs.begin()<<" ";
	}

	cout<<'\n';

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
	// sieve();
	// pre();
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