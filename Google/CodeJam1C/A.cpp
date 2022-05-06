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
	map<char, vector<string>> start;
	map<char, vector<string>> end;
	map<char, vector<string>> alls;

	int n; cin>>n;
	vector<string> arr(n);
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	set<int> middles;

	for(int i = 0; i<n; i++){

		int count = 0;
		string s = arr[i];
		int n1 = s.length();

		for(int j = 0; j<n1; j++){
			if(s[j] == s[0]){
				count++;
			}
		}

		// for(int j = 1; j<n1-1; j++){
		// 	if(middles.count(s[i])){

		// 	}
		// }

		if(count == n1){
			alls[s[0]].PB(s);
		}

		else{
			start[s[0]].PB(s);
			end[s[n1-1]].PB(s);
		}

	}

	// debug(start);
	// debug(end);
	// debug(alls);

	for(auto v: start){
		if(sz(v.second) > 1){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}

	for(auto v: end){
		if(sz(v.second) > 1){
			cout<<"IMPOSSIBLE\n";
			return;
		}
	}

	//	end[i1] alls[i] start[i1]
	//	end[last of ]
	map<char, vector<string>> nones;
	
	for(auto v: alls){
		if(start.count(v.first) || end.count(v.first)){
			continue;
		}
		nones[v.first] = v.second;
	}

	for(auto v : nones){
		alls.erase(alls.find(v.first));
	}

	// 	for(auto v: nones){
	// 	cout<<v.first<<" ";
	// 	for(auto u : v.second){
	// 		cout<<u<<' ';
	// 	}
	// 	cout<<'\n';
	// }

	for(auto v: arr){

		int count1 = 0;
		string ans = v;
		string starter = ans;
		bool temper = false;
		char last_char = ans.back();

		while(count1 < n - sz(nones)){
			
			for(auto v: alls[last_char]){
				if(starter == v && !temper){
					temper = true;
					continue;
				}
				count1++;
				for(auto u : v){
					ans.PB(u);
				}
			}

			if(start.find(last_char) == start.end()){
				break;
			}

			for(auto v: start[last_char]){

				if(starter == v && !temper){
					// count1--;
					temper = true;
					continue;
				}
				count1++;
				for(auto u:v){
					ans.PB(u);
				}
			}

			last_char = ans.back();

		}

		// cout<<count1<<'\n';
		// cout<<ans<<'\n';
		debug(count1, ans, temper);

		// if(count1 >= n - sz(nones) - 1){
			// cout<<"done, sanity check remains";
		for(auto v: nones){
			for(auto u : v.second){
				if(u == starter && !temper){
					temper = true;
					continue;
				}
				count1++;
				for(auto x : u){
					ans.PB(x);
				}
			}
		}

	// debug(ans);
		if(count1 != n-1){
			continue;
		}

		int n2 = ans.length();
		set<char> done;
		bool pos = false;

		for(int i = 1; i<n2; i++){
			if(done.count(ans[i])){
				pos = true;
				break;
			}

			if(ans[i] == ans[i-1]){

			}
			else{
				done.insert(ans[i-1]);
			}
			// debug(done);
		}

		if(!pos){
			cout<<ans<<'\n';
			return;
		}
			// }

	}

	cout<<"IMPOSSIBLE\n";


	
	


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
		cout<<"Case #"<<zcount++<<": ";
	  solve();
	}

	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	time_taken *= 1e-9;

	cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
	return 0;
}