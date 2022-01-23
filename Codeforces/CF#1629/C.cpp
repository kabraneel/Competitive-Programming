// na ho paega humse
// nai_aati_coding
// i love PD
// Motivation when feeling low : http://bitly.com/98K8eH
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

#define int long long
#ifndef ONLINE_JUDGE
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

const int N = 2e5 + 5; 
vector<int> adj[N];

void solve(){
	int n; cin>>n;
	for(int i = 0; i<=n; i++){
		adj[i].clear();
	}

	for(int i = 0; i<n; i++){
		int x; cin>>x;
		adj[x].PB(i);
	}

	// vector<int> positions
	set<int> notdone;
	// for()
	// for(auto v: adj[i]){

	// }
	for(int i = 0; i<=n; i++){
		if(sz(adj[i])){
			notdone.insert(i);
		}	
		else{
			break;
		}
	}

	vector<int> pointers(n);
	vector<int> ans;

	debug(notdone);

	if(sz(notdone) == 0){
		cout<<n<<'\n';
		for(int i = 0; i<n; i++){
			cout<<"0 ";
		}
		cout<<'\n';
		return;
	}

	while(sz(notdone)){
		
		auto it = notdone.end();
		it--;

		int x = *it;
		int mex = -1;
		for(int i = 0; i<=x; i++){
			mex = max(mex, adj[i][pointers[i]]);
			// pointers[i]++;
		}
		// set<int> temp;

		for(int i = 0; i<=x; i++){
			while(pointers[i] < sz(adj[i]) && adj[i][pointers[i]] <= mex){
				pointers[i]++;
			}
			if(pointers[i] == sz(adj[i])){
				notdone.erase(i);
			}
		}

		ans.PB(x+1);
		int temp = 0;

		// int x1 = *(--notdone.end());
		// it = notdone.end();
		// it--;
		if(!notdone.count(0)){
			cout<<sz(ans) + n - mex - 1<<'\n'; 
			for(auto v: ans){
				cout<<v<<" ";
			}
			for(int i = mex + 1; i<n; i++){
				cout<<"0 ";
			}
			cout<<'\n';
			return;
		}

		for(int i = 0; i<=x; i++){
			if(notdone.count(temp+1)){
				temp++;
			}
			else{
				vector<int> temp1;
				for(auto v: notdone){
					if(v>temp){
						temp1.PB(v);
					}
				}
				for(auto v: temp1){
					notdone.erase(v);
				}
				break;
			}
		}		

	}

	for(auto v: ans){
		cout<<v<<" ";
	}
	cout<<'\n';

}

signed main(){

#ifndef ONLINE_JUDGE
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