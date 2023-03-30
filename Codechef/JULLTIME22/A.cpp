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

vector<int> solve(string &s){
	int ans = 0;
	int n = s.length();
	vector<int> choices(n/2, -1);
	vector<int> fans;

	if(n == 2){
		fans.PB(s[0] != s[1]);
		fans.PB(1);
		return fans;
	}

	for(int i = 0; i<n; i+=2){
		if(s[i] != s[i+1]){
			ans++;
		}
		if(s[i] == s[i+1]){
			choices[i/2] = s[i] - '0';
		}
	}

	debug(choices);

	int i = 0;
	while(i<n/2 && choices[i] == -1){
		i++;
	}	

	if( i == n/2 ){
		fans.PB(ans);
		fans.PB(1);
		return fans;
	}


	else{
		for(int j = 0; j<i; j++){
			choices[j] = choices[i];
		}
	}

	debug(choices);

	int ans2 = 1;
	for(int i = 1; i<n/2; i++){
		if(choices[i] == -1){
			continue;
		}
		if(choices[i] != choices[i-1]){
			ans2++;
		}
	}


	fans.PB(ans);
	fans.PB(ans2);
	return fans;

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
		string s; cin>>s;
	  auto x = solve(s);
	  cout<<x[0]<<" "<<x[1]<<'\n';

	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}