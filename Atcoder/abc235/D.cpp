// na ho paega humse
// nai_aati_coding
// i love PD
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

void solve(){
	int a; int n; cin>>a>>n;
	queue<pair<int,int>> q;
	q.push({1,0});

	set<int> S; S.insert(1);

	while(!q.empty()){

		auto x = q.front();
		q.pop();
		int y = x.first;



		if(y == n){
			cout<<x.second<<'\n';
			return;
		}

		//first op
		if(y*a < 10*n && (!S.count(y*a))){
			S.insert(y*a);
			q.push({y*a, x.second + 1});
		}


		if(y%10 == 0){
			continue;
		}

		int x1 = 0;
		while(y > 0){
			x1++;
			y = y/10;
		}

		int temp = (pow(10,x1-1)) * (x.first % 10) + x.first/10;

		if(temp < 10*n && (!S.count(temp))){
			S.insert(temp);
			q.push({temp, x.second + 1});
		}

	}

	// for(auto v: S){
	// 	cout<<v<<" ";
	// }

	cout<<"-1\n";
	return;



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
// cin>>t;
while(t--){
  solve();
}

auto end = chrono::high_resolution_clock::now();
double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

time_taken *= 1e-9;

cerr <<fixed<<time_taken<<setprecision(9)<< " sec"<<endl;
return 0;
}