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
	int n = s.length();
	int ind = -1;
	for(int i = 0; i<n; i++){
		if(s[i] == '0'){
			ind = i;
			break;
		}
	}

	if(s[n-1] == 1){
		cout<<"1\n";
		return;
	}

	if(n == 1){
		cout<<"1\n";
		return;
	}

	debug(s, ind);

	if(ind == -1){
		int x = n-1;
		int ans = 1;

		/*
			111???11?????
		*/
		while(x >= 0 && s[x] == '?'){
			x--;
			ans++;
		}
		if(x == -1){
			ans--;
		}
		cout<<ans<<'\n';
		return;
	}

	int ans = 0;
	ind--;
	while(ind >= 0 && s[ind] == '?'){
		ans++;
		ind--;
	}

	if(ind == -1){
		ans--;
	}

	cout<<ans + 2<<'\n';

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