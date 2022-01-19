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

set<vector<int>> S;

int lis(int arr[], int n)
{
    int lis[n];
  
    lis[0] = 1;
  
    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
  
    // Return maximum value in lis[]
    return *max_element(lis, lis + n);
}

void printArr(int a[], int n)
{
    

     int arr1[n];
     for(int i = 0; i<n; i++){
     	arr1[i] = a[n-i-1];
     }

     if(lis(arr1, n) == lis(a, n)){
     		vector<int> temp;
     	for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // // printf("\n");
    //  		cout<<(lis(a, n))<<'\n';
     		temp.PB(a[i]);
     		// cout<<'\n';
     S.insert(temp);
     }

}
 
// Generating permutation using Heap Algorithm
void heapPermutation(int a[], int size, int n)
{
    // if size becomes 1 then prints the obtained
    // permutation
    if (size == 1) {
        printArr(a, n);
        return;
    }
 
    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1, n);
 
        // if size is odd, swap 0th i.e (first) and
        // (size-1)th i.e (last) element
        if (size % 2 == 1)
            swap(a[0], a[size - 1]);
 
        // If size is even, swap ith and
        // (size-1)th i.e (last) element
        else
            swap(a[i], a[size - 1]);
    }
}



void solve(){
	 // int arr[] = {1,2,3,4,5,6,7};
	 // int arr1[] = {7,1,3,5,8,6,4,2};
	 // cout<<lis(arr1, 8)<<'\n';
	 // heapPermutation(arr, 7, 7);
	 // for(auto v: S){
	 // 	for(auto u: v){
	 // 		cout<<u<<" ";
	 // 	}
	 // 	cout<<'\n';
	 // }

	int n; cin>>n;

	if(n == 2){
		cout<<"NO\n";
		return;
	}

	cout<<"YES\n";

	if(n%2 == 0){
		cout<<n-1<<" ";
		for(int i = 1; i<=n-3; i=i+2){
			cout<<i<<" ";
		}
		for(int i = n; i>0; i-=2){
			cout<<i<<" ";
		}
		cout<<'\n';
	}

	else{
		for(int i = n-1; i>=2; i-=2){
			cout<<i<<" ";
		}
		for(int i = 1; i<=n; i+=2){
			cout<<i<<" ";
		}
		cout<<'\n';
	}
	// if(n == 3){

	// }

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