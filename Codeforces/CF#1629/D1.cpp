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

void solve(){

	map<string,int> M31;
	map<string,int> M32;
	map<string,int> M33;

	map<string,int> M21;
	map<string,int> M22;

	map<string,int> M1;
	vector<string> arr;
	int n; cin>>n;
	int count = 0;

	for(int i = 0; i<n; i++){
		string s; cin>>s;
		arr.PB(s);

		string temp = s;
		reverse(all(temp));

		if(temp == s) count++;

		// M3[]
		string s1;
		if(s.length() == 3){
			// M3[]
			s1.PB(s[2]);
			// M31[s1]++;
			if(s[0] == s[1]){
				M31[s1] = i;
			}
			// else M31[s1].PB(i);
			// M2[]
			// s1.PB(s[1]);
			string s2; s2.PB(s[1]); s2.PB(s[2]);
			// if(sz(M32[s2]))
			M32[s2] = i;
			// else M32[s2].PB(i);
		
		

			// s1.PB(s[2]);
			string s3 = s;
			reverse(all(s3));
			// if(sz(M33[s3]))
			M33[s3] = i;
			// else M33[s3].PB(i);
		}

		if(s.length() == 2){
			s1.PB(s[1]);
			// if(sz(M21[s1]))
			M21[s1] = i;
			// M2[]
			// s1.PB(s[1]);
			string s2 = s;
			reverse(all(s));
			// if(sz(M22[s2]))
				M22[s2] = i;
			// else M22[s2].PB(i);
		}

		if(s.length() == 1){
			count++;
			s1.PB(s[0]);
			// if(sz(M1[s1])){
			M1[s1] = i;
			// }
			// else M1[s1].PB(i);
		}

	}

	debug(count);
	if(count){
		cout<<"YES\n";
		return;
	}

	// debug(M33);
	// debug(M32);
	// debug(M31);
	// debug(M22);
	// for(auto v: M32){
	// 	cout<<v.first<<'\n';
	// 	for(auto u: v.second){
	// 		cout<<u<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	// debug(M21);
	// debug(M1);


	// for(auto v: M3){

	// }
	for(int i = 0; i<n; i++){
		//try to find match for temp[i]
		string temp = arr[i];
		if(temp.length() == 1){
			//for all len 3 strings, x x temp[0] works
			string s1; s1.PB(temp[0]);
			if(M31.find(s1) != M31.end()){
				if(M31[s1] > i){	
					cout<<"YES\n";
					return;
				}
			}
			//for all 2 len strings x temp[0] works
			string s2; s2.PB(temp[0]);
			if(M21.find(s2)!= M21.end()){
				if(M21[s2] > i){	
					cout<<"YES\n";
					return;
				}
			}

			//for all 1 length strings temp[0] works
			string s3; s3.PB(temp[0]);
			if(M1.find(s3) != M1.end()){
				if(M1[s3] > i){	
					cout<<"YES\n";
					return;
				}
			}
		}

		if(temp.length() == 2){
			//for all len 3 strings, x temp[1] temp[0] works
			string s1; s1.PB(temp[1]); s1.PB(temp[0]);
			if(M32.find(s1)!=M32.end()){
				if(M32[s1] > i){	
					cout<<"YES\n";
					return;
				}
			}

			//for all len 2 strings, temp[1] temp[0] works
			string s2; s2.PB(temp[1]); s2.PB(temp[0]);
			if(M22.find(s2) != M22.end()){
				if(M22[s2] > i){	
					cout<<"YES\n";
					return;
				}
			}

			//for all len 1 strings, temp[0] works
			string s3; s3.PB(temp[0]);
			if(M1.find(s3) != M1.end()){
				if(M1[s3] > i){	
					cout<<"YES\n";
					return;
				}
			}

		}

		if(temp.length() == 3){
			//for all three length strings, temp[2] temp[1] temp[0] works
			string s1; s1.PB(temp[2]); s1.PB(temp[1]); s1.PB(temp[0]);
			if(M33.find(s1)!=M33.end()){
				if(M33[s1] > i){	
					cout<<"YES\n";
					return;
				}
			}

			//for all len 2 strings, temp[1] temp[0] works
			string s2; s2.PB(temp[1]); s2.PB(temp[0]);
			if(M22.find(s2) != M22.end()){
				if(M22[s2] > i){	
					cout<<"YES\n";
					return;
				}
			}

			//for all len 1 strings, temp[0] works, if(temp[1] == temp[2])
			string s3; s3.PB(temp[0]);
			if(M1.find(s3) != M1.end()){
				if(M1[s3] > i && temp[1] == temp[2]){	
					cout<<"YES\n";
					return;
				}
			}
		}
	}

	cout<<"NO\n";


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