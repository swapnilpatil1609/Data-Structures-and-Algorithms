class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            string str = to_string(nums[i]);
            int d = str.length();
            if(d%2==0) cnt++;
        }
        return cnt;
    }
};