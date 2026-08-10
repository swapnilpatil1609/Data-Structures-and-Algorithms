class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(n+m);
        int l = 0;
        int r = 0;
        int index = 0;
        while(l<m && r<n){
            if(nums1[l]<=nums2[r]){
                nums3[index]=nums1[l];
                l++;
                index++;
            }
            else{
                nums3[index]=nums2[r];
                r++;
                index++;
            }
        }
        while(l<m){
            nums3[index++]=nums1[l++];
        }
        while(r<n){
            nums3[index++]=nums2[r++];
        }
        for(int i=0;i<m+n;i++){
            nums1[i]=nums3[i];
        }
        
    }
};