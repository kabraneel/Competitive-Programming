/*
  find the next largest element of an array
  USES STACK
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin>>n;
  vector<int> arr(n);
  vector<int> ans(n);

  for(int i = 0; i<n; i++){
     cin>>arr[i];
  }

  stack<int> stck;
  stck.push(0);

  for(int i = 1; i<n; i++){
    while(!stck.empty() && arr[i] > arr[stck.top()]){
      ans[stck.top()] = arr[i];
      stck.pop();
    }
    stck.push(i);
  }

  while(!stck.empty()){
    ans[stck.top()] = -1;
    stck.pop();
  }

  for(auto v: ans){
    cout<<v<<" ";
  }
  cout<<'\n';

}
