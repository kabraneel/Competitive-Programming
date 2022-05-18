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
vector<int> adj[N];

bool visited[N];
int sizes[N];

int dfs(int i){
	visited[i] = 1;
	int thissize = 1;

	for(auto to : adj[i]){
		if(!visited[to]){
			thissize += dfs(to);
		}
	}

	sizes[i] = thissize;
	return thissize;
}

vector<int> ans;
set<pair<int,int>> converts;

void dfs1(int i, int done = 0){

	visited[i] = true;
	if(done == 1){
		return;
	}
	for(auto to: adj[i]){
		if(!visited[to]){
			if(converts.count({i, to})){
				ans.PB(min(sizes[i], sizes[to]));
				dfs1(to, 1);
			}
			else if(converts.count({to, i})){
				ans.PB(min(sizes[i], sizes[to]));
				dfs1(to, 1);
			}
			else{
				dfs1(to, 0);
			}
		}
		
	}

}


void solve(){

	int n; cin>>n;
	int k; cin>>k;

	for(int i = 0; i<=n; i++){
		adj[i].clear();
		sizes[i] = 0;
		visited[i] = false;
	}


	for(int i = 0; i<n-1; i++){
		int u,v; cin>>u>>v;
		adj[u-1].PB(v-1);
		adj[v-1].PB(u-1);

		int x; cin>>x;
		if(x == 1){
			converts.insert({u-1, v-1});
		}

	}


	dfs(0);

	for(int i = 0; i<=n; i++){
		// adj[i].clear();
		// sizes[i] = 0;
		visited[i] = false;
	}

	// for(int i = 0; i<n; i++){
	// 	cout<<sizes[i]<<" ";
	// }
	// cout<<'\n';

	// vector<int> ans;
	// for(auto x : converts){

	// 	ans.PB(min(sizes[x.first], sizes[x.second]));

	// }
	dfs1(0);

	debug(ans);

	sort(all(ans));
	reverse(all(ans));

	int tsum = 0;
	int count = 0;
	// debug(k);
	if(k == n){
		ans.clear();
	converts.clear();
		cout<<"0\n";
		return;
	}
	for(auto v: ans){
		tsum += v;
		count++;
		debug(n - tsum);
		if(n - tsum <= k){
			cout<<count<<'\n';
			ans.clear();
			converts.clear();
			return;
		}
	}

	cout<<"-1\n";
	ans.clear();
	converts.clear();
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