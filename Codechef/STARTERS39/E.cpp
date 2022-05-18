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
	string s; cin>>s;

	vector<int> ans(n+1);


	for(int i = 0; i<26; i++){

		vector<int> sizz;
		int key = 'a' + i;
		int j = 0;
		while(j<n){
			while(j<n && s[j] != key){
				j++;
			}
			int count = 0;
			while(j<n && s[j] == key){
				count++;
				j++;
			}
			sizz.PB(count);
		}
		sort(all(sizz));
		reverse(all(sizz));


		if(sizz[0] == 0){
			continue;
		}

		debug(sizz);
		int tsum = sizz[0];
		ans[0] = max(ans[0], tsum);
		for(int i = 1; i<sz(sizz); i++){
			tsum += sizz[i];
			ans[i] = max(ans[i], tsum);
		}

		// ans[sz(sizz)]


	}

	for(int i = 1; i<=n; i++){
		ans[i] = max(ans[i-1], ans[i]);
	}

	for(auto v: ans){
		cout<<v<<" ";
	}
	cout<<'\n';
	debug(ans);

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