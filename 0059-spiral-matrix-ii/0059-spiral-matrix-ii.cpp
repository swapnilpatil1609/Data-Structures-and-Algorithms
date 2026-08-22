class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0;
        int top = 0;
        int right = n-1;
        int bot = n-1;
        int ct = 1;
        vector<vector<int>> mat(n,vector<int> (n));
        while(top<=bot && left<=right){
            for(int i=left;i<=right && ct<= n*n;i++){
                mat[top][i] = ct++;
            }
            top++;

            for(int i=top;i<=bot && ct<=n*n ; i++){
                mat[i][right]=ct++;
            }
            right--;

            for(int i=right;i>=left && ct<=n*n ; i--){
                mat[bot][i]=ct++;
            }
            bot--;

            for(int i=bot;i>=top && ct<=n*n ; i--){
                mat[i][left]=ct++;
            }
            left++;
        }
        return mat;
    }
};