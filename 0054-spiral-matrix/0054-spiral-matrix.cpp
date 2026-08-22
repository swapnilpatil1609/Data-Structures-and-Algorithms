class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int right = m-1;
        int left = 0;
        int bot = n-1;
        vector<int> ans;
        while(left<=right && top<=bot){
            // left-right
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;

            // top-bottom
            for(int i=top;i<=bot;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;

            // right-left
            if(top<=bot){
            for(int i=right;i>=left;i--){
                ans.push_back(matrix[bot][i]);
            }
            bot--;
            }

            // bottom-top
            if(left<=right){
            for(int i=bot;i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        }
        return ans;
    }
};