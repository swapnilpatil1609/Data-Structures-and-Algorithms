class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int presum = 0;
        int cnt = 0;

        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i = 0; i < nums.size(); i++) {
            presum += nums[i];

            int rem = presum % k;

            if(rem < 0)
                rem += k;

            cnt += mp[rem];

            mp[rem]++;
        }

        return cnt;
    }
};