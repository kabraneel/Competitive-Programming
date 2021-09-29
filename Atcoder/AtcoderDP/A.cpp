#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;

#define PB push_back
#define MP make_pair

typedef long long ll;

#define FOR(i,a,b) for(int i=a; i<b; i++)

int mod = 1e9 + 7;
#define maxn 1e5 + 1

vector<long long int> arr(maxn,-1);

long long int findcost(int n, int i, vector<int> &h){

 //base case
 if(i==n){
   return 0;
 }

 if(arr[i]!=-1){
   return arr[i];
 }

 if(i==n-1){
   arr[i] = abs(h[n-1]-h[i-1]) + findcost(n, i+1, h);
   return arr[i];
 }

 else{
   long long int a = abs(h[i+1] - h[i-1]) + findcost(n,i+2,h);
   long long int b = abs(h[i] - h[i-1]) + findcost(n,i+1,h);

   if(b<a){
     arr[i] = b;
   }
   else{
     arr[i] = a;
   }
   return arr[i];
 }
}

int main(){

 ios_base::sync_with_stdio(false);
 cin.tie(NULL);

 int t=1;

 while(t--){

   int n;
   cin>>n;

   vi h(n);

   FOR(i,0,n){
     cin>>h[i];
   }

   findcost(n,0,h);

   cout<<arr[1]<<"\n";
 }
 return 0;
}
