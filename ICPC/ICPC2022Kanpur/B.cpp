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
int sizee[N];
vector<int> adj[N];
int visited[N];
vector<int> ans;
set<int> done;

void dfs(int i, int n){
	int x = 1;
	visited[i] = 1;
	for(auto v : adj[i]){
		if(!visited[v] and !done.count(v)){
			dfs(v, n);
			x += sizee[v];
		}
	}

	if((x * x) >= ceil((double) sqrt(n))){
		ans.PB(i);
		sizee[i] = 0;
	}

	sizee[i] = x;
}

void solve(){
	int n; cin>>n;
	int m; cin>>m;

	for(int i =1; i<=n; i++){
		adj[i].clear();
		visited[i] = 0;
		sizee[i] = 0;
		done.clear();
		ans.clear();	
	}

	for(int i = 1; i<=m; i++){
		int u; int v;
		cin>>u>>v;

		adj[u].PB(v);
		adj[v].PB(u);
	}


	dfs(1, n);
	cout << sz(ans) << '\n';
	for(auto v : ans){
		cout << v << ' ';
	}
	cout << '\n';
	
	for(int i = 1; i<=n; i++){
		cout << sizee[i] << ' ';
	}
	
	cout << '\n';


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
	cin>>t;

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