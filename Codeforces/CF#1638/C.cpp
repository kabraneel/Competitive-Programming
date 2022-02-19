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

const int N = 4e5 + 10;

int parent[N];
int sizee[N];
int total;

int find_set(int x){
    if (parent[x] == x) return x;
    parent[x] = find_set(parent[x]);
    return parent[x];
}

void union_sets(int x, int y){
    x = find_set(x);
    y = find_set(y);
    if (x == y) return;
    total--;
    if (sizee[x] > sizee[y]) swap(x,y);
    parent[x] = y;
    if (sizee[x] == sizee[y]) sizee[y]++;
}

void initialize(int n){
    FOR(i,0,n+1){
        parent[i] = i;
        sizee[i] = 1;
    }
    total = n;
}

void solve(){
	// set<int> S;
	int n; cin>>n;
	map<int,int> M;

	vector<int> perm(n);
	for(int i = 0; i<n; i++){
		cin>>perm[i];
		M[perm[i]] = i;
	}

	initialize(n);

	// for(int i = 0; i<n; i++){
	// 	//to eval perm of i 
	// 	//if i get a 3, then i need to do all values less than three
	// 	vector<int> temp;

	// 	for(auto v: S){
	// 		if(v < perm[i]){
	// 			temp.PB(v);
	// 			union_sets(v, perm[i]);
	// 		}
	// 		else{
	// 			break;
	// 		}
	// 	}

	// 	temp.PB(perm[i]);

	// 	for(auto v: temp){
	// 		S.erase(v);
	// 	}

	// }
	// debug(perm);

	int after1 = n;
	set<int> S;

	for(int i = n; i>=1; i--){

		int x = M[i];
		if(x > after1) continue;



		debug(i, S);

		// for()
		// int x = S.upper_bound(i);
		auto it = S.begin();

		// if(it == S.begin() ){
		// 	;
		// }
		if(sz(S) && *it < i){
			// debug("here");
			union_sets(*it, i);
		}

		if(total == 1){
			break;
		}

		for(int j = x; j < after1; j++){
			S.insert(perm[j]);
			union_sets(perm[j], i);
		}

		after1 = x;
		// debug(after1);

	}

	cout<<total<<'\n';

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