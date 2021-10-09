#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;

int securitiesBuying(int z,int n, int security_value[])
{
    // int no_of_stocks=0;
    int ans = 0;
   // participants code here
   vector<pair<int,int>> arr(n);

   for(int i = 0; i<n; i++){
     arr[i] = make_pair(security_value[i], i+1);
   }

   sort(arr.begin(), arr.end());

   int j = 0;
   // int ans = 0;
   while(z>=0){
     if(arr[j].first * arr[j].second > z){
       int count = z / arr[j].first;
       // z -= count * arr[j].first;
       ans += count;
       break;
     }
     else{
       z -= arr[j].first * arr[j].second;
       ans += arr[j].second;
       j++;
     }
   }

   // cout<<ans<<'\n';


  return ans;
}

int main(){

int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);


while (iss >> data)
    input_data.push_back(data);

int n= input_data.size();


 int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }



int no_of_stocks_purchased = securitiesBuying(z,n,security_value);
cout << no_of_stocks_purchased;



}
