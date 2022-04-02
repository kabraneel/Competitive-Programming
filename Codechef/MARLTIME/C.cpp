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

const int N = 1e5 + 5;
vector<int> adj[N];

void solve(){
	
	int n; int q; int m;
	cin>>n>>m>>q;

	for(int i = 0;i<m; i++){
		int u,v;
		cin>>u>>v;
		adj[u-1].PB(v-1);
		adj[v-1].PB(u-1);
	}


	set<int> frozen;
	queue<int> f;

	while(q--){
		int x; cin>>x;
		if(x == 3){
			int y; cin>>y;
			if(frozen.count(y-1)){
				cout<<"YES\n";
			}
			else{
				cout<<"NO\n";
			}
			continue;
		}
		if(x == 1){
			int y; cin>>y;
			if(!frozen.count(y-1)){
				f.push(y-1);
				frozen.insert(y-1);
			}
			continue;
		}


		if(x == 2){
			int y; cin>>y;
			// y--;

			if(sz(frozen) == n){
				continue;
			}

			for(int i = 0; i<y+1; i++){

				if(sz(frozen) == n){
					break;
				}

				queue<int> temp;
				while(!f.empty()){
					int x = f.front();
					f.pop();

					for(auto v: adj[x]){
						if(frozen.count(v) == 0)
							temp.push(v);
					}
					frozen.insert(x);
				}

				f = temp;

			}
			debug(frozen);


		}
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