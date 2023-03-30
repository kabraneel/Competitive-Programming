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

const int N = 1e4 + 10;

void solve(){
	queue<int> q;

	int n; cin>>n;
	int qu; cin>>qu;
	vector<int> adj[n+1];
	// for(int i = 0; i<=n; i++){
	// 	adj[i].clear();
	// }

	for(int i = 0; i<n-1; i++){
			int u; int v;
			cin>>u>>v;
			adj[u].PB(v);
			adj[v].PB(u);
	}

	for(int i = 0; i<qu; i++){
		int x; cin>>x;
	}

	// for(int i = 1; i<=n; i++){
	// 	debug(adj[i]);
	// }
	// debug(adj);

	q.push(1);
	vector<int> visited(n+1, 0);
	vector<int> level(n+1, 0);
	level[1] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		visited[x] = 1;
		// debug(x);
		for(auto v : adj[x]){
			if(!visited[v]){
				level[v] = level[x] + 1;
				q.push(v);
			}
		}
	}


	vector<int> levels(n+1);
	for(auto v: level){
		levels[v]++;
	}
	// debug(levels);



	int sum = 0;
	for(int i = 1; i<=n; i++){
		if(sum+levels[i] <= qu){
			sum += levels[i];
		}
		else{
			break;
		}
	}

	cout<< sum << '\n';


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
		cout<<"Case #"<<zcount++<<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}