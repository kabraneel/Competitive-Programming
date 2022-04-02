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

void solve(){
	int n; cin>>n;
	vector<pair<int,int>> arr;
	map<int,vector<int>> M;

	vector<int> a(n);
	vector<int> b(n);


	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	for(int i = 0; i<n; i++){
		cin>>b[i];
		arr.push_back({b[i], a[i]});
		M[b[i]].push_back(a[i]);
	}

	sort(all(arr));
	vector<int> ans(n+1, -INF);
	multiset<int, greater<int>> S;
	ans[0] = 0;

	vector<int> temp;
	for(int i = 1; i<n+1; i++){
		temp.PB(i-1);
	}


	for(auto v: temp){

		if(M.find(v) != M.end()){

			for(auto u: M[v]){
				S.insert(u);
			}

			M.erase(v);
		}


		if(ans[v] == -INF){
			break;
		}

		debug(S);

		// debug(ans);

		if(sz(S) == 0){
			break;
		}

		ans[v + 1] = max(ans[v+1], ans[v] + *S.begin());
		S.erase(S.lower_bound(*S.begin()));
		// ans[v.first+1] =  

	}

	debug(ans);
	double fans = 0;
	// for(auto v: ans){
	// 	fans = max(fans, v/)
	// }
	for(int i = 1; i<n+1; i++){
		fans = max(fans, ((1.0*ans[i] )/ (1.0 * (i))));
	}

	cout<<setprecision(15);
	cout<<fans<<'\n';



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