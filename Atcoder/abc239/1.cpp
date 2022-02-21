#include<bits/stdc++.h>
using namespace std;

vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;

        if(finalSum % 2){
            return ans;
        }

        int count = 2;
        int tsum = 0;
        while(1){
            if(finalSum - tsum >= 0){
                tsum += count;
                ans.push_back(count);
                count += 2;
            }
            else{
                // tsum -= count;
                break;
            }
        }

        // for(auto v: ans){
        //     cout<<v<<" ";
        // }
        // cout<<'\n';
        int x = ans.back();
        tsum -= x;

        ans.pop_back();


        x = ans.back();
        ans.pop_back();
        tsum -= x;

        ans.push_back(finalSum - tsum);
        return ans;
}

int main(){
    auto x = maximumEvenSplit(24);
    for(auto v: x){
        cout<<v<<" ";
    }
}