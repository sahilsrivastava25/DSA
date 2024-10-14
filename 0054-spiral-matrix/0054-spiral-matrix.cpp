class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();

        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        while(top <= bottom && left <= right){
            for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);
            top++;

            for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
            right--;

            if(left <= right && top <= bottom){
                for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            
            if(left <= right && top <= bottom){
                for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
            }
            left++;
        }

        return ans;
    }
};