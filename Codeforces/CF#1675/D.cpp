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

const int N = 2e5 + 7;
vector<int> adj[N];
int visited[N];

vector<int> temp;
vector<vector<int>> ans;

// set<int> done;
int done[N];

void dfs(int i, int p = -1){

	/*
	 1
	 
	 [2,5]


	*/
	visited[i] = true;
	temp.PB(i);
	if(sz(adj[i]) == 0){
		// temp.PB(i);
		// reverse(all(temp));
		ans.PB(temp);
		temp.clear();
		return;
	}

	for(auto v: adj[i]){
		if(!visited[v]){
			dfs(v, i);
		}
	}

}

void solve(){
		
	int n; cin>>n;

	// for(int i = 0; i<sz(ans); i++){
	// 	// ans[i].clear();
	// }
	ans.clear();

	for(int i = 0; i<n+5; i++){
		visited[i] = 0;
		done[i] = 0;
		adj[i].clear();
	}
	int root = -1;

	for(int i = 0; i<n; i++){
		int x; cin>>x;
		if(x == i+1){
			root = i+1;
			continue;
		}
		// adj[i+1].PB(x);
		adj[x].PB(i+1);
	}
	
	for(int i = 0; i<n+1; i++){
		debug(root ,i, adj[i]);
	}

	vector<pair<int,int>> X;

	for(int i = 1; i<n+1; i++){
		X.PB({-1 * sz(adj[i]), i});
	}
	sort(all(X));

	// for(int i = 1; i<n+1; i++){
		// vector<int> temp = dfs(i);
		// if(!visited[X[i-1].second]){
			dfs(root);
			// reverse(all(temp));
			// debug(temp);
			// ans.PB(temp);
			// temp.clear();
		// }
	// }

	cout<<sz(ans)<<'\n';
	for(int i = 0; i<sz(ans); i++){
		cout<<sz(ans[i])<<'\n';
		for(auto v: ans[i]){
			cout<<v<<" ";
		}
		cout<<'\n';
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