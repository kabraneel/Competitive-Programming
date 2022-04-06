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
	int n, m;
	cin>>n>>m;

	string a,b;
	cin>>a>>b;

	int i = 0;
	int j = 0;

	while(i < n && j < m){

		if(b[j] == a[i]){
			i++;
			j++;
		}

		else{
			i++;
		}

		debug(i,j);

	}

	if(j == m){
		cout<<"-1\n";
		return;
	}

	// vector<char> temp = {'a', 'b', 'c', 'd', 'e'};
	map<char,int> M;
	for(int i = 0; i<5; i++){
		M['a' + i] = i;
	}
	debug(M);
	debug("here");

	string ans;
	i = 0;
	// while(i<n && a[i] == '?'){
	// 	ans.PB((M[b[0]] + 1) % 5 + 'a');
	// 	i++;
	// }

	// while(i<n)
	// if(b[i])
	j = 0;
	while(i < n && j < m){

		if(a[i] == '?'){
			debug(b[j]);
			ans.PB((M[b[j]] + 1) % 5 + 'a');
		}

		else{
			ans.PB(a[i]);
		}

		if(a[i] == b[j]){
			i++;
			j++;
		}
		else{
			i++;
		}


	}


	cout<<ans<<'\n';




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