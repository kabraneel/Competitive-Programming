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
	vector<int> arr(n);
	// vector<int> temp(n);
	// multiset<int> pos;
	// multiset<int> neg;
	int count = 0;

	for(int i = 0; i<n; i++){
		cin>>arr[i];
		// temp[i] = abs(arr[i]);
		if(arr[i] < 0){
			count++;
		}
		// if(arr[i] >= 0){
		// 	pos.insert(arr[i]);
		// }
		// else{
		// 	neg.insert(arr[i]);
		// }
	}

	// int count1 = 0;
	// int i = 0;
	// while(i<n && count1 < count){
	// 	if(arr[i] < 0){
	// 		count1++;
	// 		arr[i] = arr[i] * -1;
	// 	}
	// 	i++;
	// }

	// for(int j = i; j<n; i++){

	// }
	for(int i = 0; i<count; i++){
		if(arr[i] > 0){
			arr[i] = arr[i] * -1;
		}
	}

	for(int i = count; i<n; i++){
		if(arr[i] < 0){
			arr[i] = arr[i] * -1;
		}
	}

	vector<int> temp = arr;
	sort(all(temp));

	for(int i = 0; i<n; i++){
		if(temp[i] != arr[i]){
			cout<<"NO\n";
			return;
		}
	}

	cout<<"YES\n";
	return;
	// int posswap = 0;
	// int negswap = 0;

	// int i = 0;

	// for(int i = 0; i<n-1; i++){

	// 	if(arr[i] > arr[i+1]){
	// 		posswap += (arr[i] > 0);
	// 		negswap += (arr[i] < 0);
	// 		arr[i] = arr[i] * -1;
	// 		// i += 2;
	// 		// continue;
	// 	}

	// }
	int i = 0;
	int count1 = 0;
	while(i<n-1){
		while(i<n-1 && temp[i+1] < temp[i]){
			if(count1 > 0){
				count1++;
			}
			i++;
		}
		break;
	}

	// while(i<n-1){
	// 	while(i<n-1 && temp[i+1] > temp[i]){

	// 	}
	// }

	for(int j = i+1; j<n-1; j++){

		if(temp[j+1] - temp[j] < 0){
			// break;
			cout<<"NO\n";
			return;
		}

	}


	int rem = n - i - 1;
	debug(i, rem);
	int count2 = 0;

	for(int j = 0; j<i; j++){
		count2 += (arr[j] > 0);
	}

	for(int j = i+1; j<n; j++){
		count1 += (arr[j] < 0);
	}

	if(arr[i] > 0){
		count2++;
	}
	else{
		count1++;
	}

	debug(count1, count2);
	if(abs(count1 - count2) == 0 || abs(count1 - count2) == 2){
		cout<<"YES\n";
		return;
	}

	cout<<"NO\n";

		// debug(posswap, negswap);



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