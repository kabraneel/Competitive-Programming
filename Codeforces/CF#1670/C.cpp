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
int visited[N];
vector<int> temp;

const int modn  = 1e9 + 7;

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


void dfs(int i){
	
	visited[i] = true;

	for(auto v: adj[i]){
		if(!visited[v]){
			dfs(v);
		}
	}
	debug(i);
	temp.PB(i);

}

void solve(){
	int n; cin>>n;
	vector<int> A(n);
	vector<int> B(n);

	for(int i = 0; i<n+1; i++){
		adj[i].clear();
		visited[i] = false;
	}
	// map<int,int> MA;
	// map<int,int> MB;

	for(int i = 0; i<n; i++){
		cin>>A[i];
		// MA[A[i]] = i;
	}

	for(int i =0; i<n; i++){
		cin>>B[i];
		// MB[B[i]] = i;
	}

	vector<int> C(n);
	for(int i = 0; i<n; i++){
		cin>>C[i];
	}

	// for(int i = 0; i<n; i++){
	// 	if(C[i] != 0){
	// 		if(C[i] == A[i]){
	// 			C[]
	// 		}
	// 	}
	// }

	set<int> S;
	for(int i = 0; i<n; i++){
		if(C[i] > 0){
			S.insert(C[i]);
		}
	}

	for(int i = 0; i<n; i++){
		adj[A[i]].PB(B[i]);
	}

	int count1 = 0;
	for(int i = 0; i<n; i++){
		if(!visited[A[i]]){
			
			dfs(A[i]);
			
			bool pos = false;
			for(auto v: temp){
				if(S.count(v)){
					pos = true;
					break;
				}
			}

			if(!pos && sz(temp) > 1){
				count1++;
			}



			debug(temp, count1);
			temp.clear();
		}

	}

	cout<<fast_pow(2, count1) % MOD <<'\n';

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