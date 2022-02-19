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
vector<vector<int>> components;
vector<bool> visited(N);
vector<int> temp;



void dfs(int i){
	visited[i] = true;
	temp.PB(i);
	for(auto to: adj[i]){
		if(!visited[to]){
			dfs(to);
		}
	}
}

map<int,int> M;

void solve(){
	int n,m; cin>>n>>m;
	for(int i = 0; i<n; i++){
		int x; cin>>x;
		M[i] = x;
	}

	for(int i = 0; i<m; i++){
		int u,v; cin>>u>>v;
		adj[u-1].PB(v-1);
		adj[v-1].PB(u-1);
		M[u-1]--;
		M[v-1]--;
	}

	vector<int> X;
	for(auto v: M){
		if(v.second < 0){
			cout<<"-1\n";
			return;
		}
		if(v.second == 0){
			X.PB(v.first);
		}
	}

	for(auto v: X){
		M.erase(v);
	}

	for(int i = 0; i<n; i++){
		if(!visited[i]){
			dfs(i);
			components.PB(temp);
			temp.clear();
		}
	}

	debug(components);
	debug(M);

	vector<pair<int,int>> Y;
	int x = 0;
	int total = 0;


	for(int i = 0; i<sz(components); i++){
		for(auto v: components[i]){
			x += M[v];

		}
		Y.PB({x, i});
		if(x > (n - m - 1)){
			cout<<"-1\n";
			return;
		}
		total += x;
		x = 0;
	}

	if(total != 2*(n - m - 1)){
		cout<<"-1\n";
		return;
	}

	sort(all(Y));
	debug(Y);

	if(sz(Y))
	for(auto v: Y){
		if(v.first == 0){
			cout<<"-1\n";
			return;
		}
	}



	vector<vector<int>> Scomp(sz(Y));
	for(auto x : Y){
		vector<int> temp;
		for(auto v: components[x.second]){
			for(int k = 0; k<M[v]; k++){
				temp.PB(v);
			}
		}
		Scomp[x.second] = temp;
	}

	debug(Scomp);
	int j = sz(Y)-1;
	int i = 0;

	vector<pair<int,int>> fans;
	set<pair<int,int>> S;

	for(auto v: Y){
		S.insert(v);
	}
	debug(S);

	while(sz(S) > 1){

		auto it = S.begin();
		pair<int,int> ff = *it;
		S.erase(it);

		it = S.end();
		it--;

		pair<int,int> ll = *it;
		S.erase(it);

		debug(ff, ll);

		fans.PB({Scomp[ff.second].back(), Scomp[ll.second].back()});
		Scomp[ff.second].pop_back();
		Scomp[ll.second].pop_back();

		if(ff.first > 1){
			S.insert({ff.first - 1, ff.second});
		}

		if(ll.first > 1){
			S.insert({ll.first - 1, ll.second});
		}

		debug(Scomp);
		debug(S);

	}

	if(sz(S) == 1){
		cout<<"-1\n";
		return;
	}

	for(auto v: fans){
		cout<<v.first+1<<" "<<v.second+1<<'\n';
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