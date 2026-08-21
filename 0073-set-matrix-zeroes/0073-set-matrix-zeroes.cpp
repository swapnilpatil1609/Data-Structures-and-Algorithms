class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> newrow(n,0);
        vector<int> newcol(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    newrow[i]=1;
                    newcol[j]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(newrow[i]==1 || newcol[j]==1){
                    matrix[i][j]=0;
                }
            }
        }
    }
};