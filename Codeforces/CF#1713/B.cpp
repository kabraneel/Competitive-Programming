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
	string s; cin>>s;

	string temp;
	for(auto v: s){
		temp.PB(v);
	}

	for(auto v: s){
		temp.PB(v);
	}

	int n = s.length();
	vector<int> X;

	for(int i = 0; i<n; i++){
		bool pos = false;
		for(int j = i; j< i +n; j++){
			if(temp[j] == s[i]){
				pos = true;
				break;
			}
		}
		if(!pos){
			X.PB(i);
		}
	}

	int N; int M;
	cin>>N>>M;

	

	/*
	
		abcdef abcdef
		
		cdefab
		
		efabcd

		abcdef

		6

		def abc
		
		abc abc

		abc abc abc abc
		n, m+n, m+2*n, 2*(n + m) --> rotations, should be starting pos

		t * (n + m)
	
	*/

	int ans = INF;

	if( ( N + M ) / __gcd( n, (N + M) )  == 0){
		ans = min(ans, );
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