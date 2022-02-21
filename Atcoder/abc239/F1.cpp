class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;

        int count = 2;
        int tsum = 0;
        while(1){
            if(finalSum - tsum >= 0){
                tsum += count;
                ans.push_back(count);
                count += 2;
            }
            else{
                break;
            }
        }

        ans.pop_back();

        ans.push_back(finalSum - tsum);
        return ans;
    }
};