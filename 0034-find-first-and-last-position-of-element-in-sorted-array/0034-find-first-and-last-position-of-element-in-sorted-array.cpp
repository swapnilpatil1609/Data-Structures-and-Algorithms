class Solution {
public:
    int lowerbound(vector<int>& nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    int upperbound(vector<int>& nums,int target){
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ans = n;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]>target){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerbound(nums,target);
        int ub = upperbound(nums,target);
        if(lb==-1||nums[lb]!=target){
            return {-1,-1};
        }
        else{
            return {lb,ub-1};
        }
    }
};