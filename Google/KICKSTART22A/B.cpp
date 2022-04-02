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

	int sum = 0;
	for(auto v : s){
		sum += v - '0';
	}

	int toadd = 9 - sum%9;
	if(toadd == 9){
		toadd = 0;
		cout<<s[0];
		cout<<"0";
		for(int i = 1; i<n; i++){
			cout<<s[i];			
		}
		cout<<"\n";
		return;
		// cout<<s<<'\n';
		// return;
	}

	//add it right before the largest number is hit
	int ind = -1;

	for(int i = 0; i<n; i++){
		if((s[i]-'0') > toadd){
			ind = i;
			break;
		}
	}

	if(ind == -1){
		s.push_back(toadd + '0');
		cout<<s<<"\n";
		return;
	}

	if(ind == 0){
		cout<<toadd;
		cout<<s<<'\n';
		return;
	}

	string ans;
	for(int i = 0; i<ind; i++){
		ans.PB(s[i]);
	}
	ans.PB(toadd + '0');
	for(int i = ind; i<n; i++){
		ans.PB(s[i]);
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
	int count = 1;
	while(t--){
		cout<<"Case #"<<count++<<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}