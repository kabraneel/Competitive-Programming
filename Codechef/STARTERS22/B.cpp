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

vector<int> arr;

void pre(){
	for(int i = 1; i<=(1ll<<20); i++){
		int count = 0;
		for(int j = 0; j<32; j++){
			if(i & (1ll<<j)){
				count++;
			}
		}

		if(count % 2 == 0){
			arr.PB(i);
		}
	}
}


void solve(){
	// for(int i = 0; i<100; i++){
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<'\n';
	int n; cin>>n;
	for(int i = 0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
	// cout<<sz(arr)<<'\n';
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

pre();
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