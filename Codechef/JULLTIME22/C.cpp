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

bool checkvalid(string &s){
	int count = 0;
	for(auto v: s){
		if(v == '('){
			count++;
		}
		else{
			if(count == 0) return false;
			count--;
		}
	}
	return count == 0;
}

void solve(){
	string s; cin>>s;
	int num = 0;
	int n = s.length();
	int op = 0;
	int cl = 0;
	vector<int> pos;

	for(int i = 0; i<n; i++){
		if(s[i] == '?'){
			num++;
			pos.PB(i);
		}
		op += s[i] == '(';
		cl += s[i] == ')';
	}

	if(op + num == cl){
			cout<<"YES\n";
			return;
	}

	if(cl + num == op){
			cout<<"YES\n";
			return;
	}

	if(num > 10){
		cout<<"NO\n";
		return;
	}


	int ans = 0;	 
	for(int i = 0; i <(1ll << num); i++){
		for(int j = 0; j<num; j++){
			if(i & (1ll<<j)){
				s[pos[j]] = '(';
			}
			else{
				s[pos[j]] = ')';
			}
		}
		ans += checkvalid(s);
		if(checkvalid(s)){
			debug(s);
		}
	}

	if(ans == 1){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
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