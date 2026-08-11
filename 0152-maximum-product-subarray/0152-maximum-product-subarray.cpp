class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pre = 1;
        int suf = 1;
        int maxp = INT_MIN;
        for(int i=0;i<n;i++){
            pre = pre*nums[i];
            suf = suf*nums[n-i-1];
            maxp=max(maxp,max(pre,suf));
            if(pre==0) pre=1;
            if(suf==0) suf=1;
        }
        return maxp;
    }
};