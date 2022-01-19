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


vector<int> A;
vector<int> B;
int n; 
string a; 
string b; 

int dp[1005][1005];

int solver(int i, int j, int sum1, int sum2){
	if(i == sz(A) && j == sz(B)){
		return 0;
	}

	if(j == sz(B)){
		return dp[i][j] = A[i] + solver(i+1, j, 0,0);
	}

	if(i == sz(A)){
		return dp[i][j] = B[j] + solver(i, j+1, 0, 0);
	}

	if(dp[i][j] != -1){
		return dp[i][j];
	}


	return dp[i][j] = min(A[i] + B[j] + solver(i+1, j, 0, 0), A[i] + B[j] + solver(i, j+1, 0, 0));



}

void solve(){
	cin>>n;
	cin>>a;
	cin>>b;	

	A.clear();
	B.clear();

	for(int i = 0; i<n+2; i++){
		for(int j = 0; j<n+2; j++){
			dp[i][j] = -1;
		}
	}

	int tsuma = 0;
	int tsumb = 0;

	int count = 0;
	for(int i = n-1; i>=0; i--){
		count += (a[i] == '0');
		if(a[i] == '1') A.PB(count);
	}

	for(auto v: A){
		tsuma += v;
	}

	count = 0;

	for(int i = n-1; i>=0; i--){
		count += (b[i] == '0');
		if(b[i] == '1') B.PB(count);
	}

	for(auto v: B){
		tsumb += v;
	}


	reverse(all(A));
	reverse(all(B));

	debug(A);
	debug(B);
	cout<<solver(0,0,tsuma, tsumb)<<'\n';


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