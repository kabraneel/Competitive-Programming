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

vector<int> dx = {1, -1, 1, -1};
vector<int> dy = {1, 1, -1, -1};
int n; int m; 

bool isvalid(int x, int y){
	return (x >= 0 && y>=0 && y<m && x<n);
}

void solve(){
	
	int fans = 2;
	cin>>n>>m;

	vector<vector<int>> ans(n, vector<int> (m, 0));
	// int arr[n+1][m+1];
	queue<vector<int>> q;

	int x1; int y1; cin>>x1>>y1;
	// x1--; y1--;
	ans[--x1][--y1] = 1;
	q.push({x1, y1,1});
	cin>>x1>>y1;
	ans[--x1][--y1] = 2;
	q.push({x1,y1,2});
	
	while(!q.empty()){
		vector<int> temp = q.front();
		q.pop();

		for(int i = 0; i<4; i++){
			if(isvalid(temp[0] + dx[i], temp[1] + dy[i]) && ans[temp[0] + dx[i]][temp[1] + dy[i]] == 0){
				ans[temp[0] + dx[i]][temp[1] + dy[i]] = temp[2];
				q.push({temp[0] + dx[i], temp[1] + dy[i], temp[2]});
			}
		}
	}


	debug(ans);
	// for(auto v: ans){
	// 	for(auto &u: v){
	// 		if(u == 0){
	// 			// fans++;
	// 			// cout<<3<<'\n';
	// 			// return;
	// 			u = 3;
	// 		}
	// 		// cout<<u<<

	// 	}
	// }
	for(int i = 0; i<n; i++){
		for(int j = 0; j<m; j++){
			if(ans[i][j] == 0)
				ans[i][j] = 3;
		}
	}

	for(auto v: ans){
		for(auto &u: v){
			// if(u == 0){
				// fans++;
				cout<<u<<' ';
				// return;
				// u = 3;
			// cout<<u<<

		}
		cout<<'\n';
	}



	// cout<<2<



	// for(int i = 0; i<n; i++){
	// 	for(int j = 0; j<m; j++){
	// 		int temp = 0;
	// 		for(int k = 0; k<4; k++){
	// 			// temp += isvalid(i+dx[k], j+dy[k]) && ans[i+dx]
	// 			if(isvalid(i+dx[k], j+dy[k])){

	// 			}
	// 		}	
	// 		// fans = max()	
	// 	}
	// }


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