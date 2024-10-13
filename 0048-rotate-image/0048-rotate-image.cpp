class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        for(int i = 0; i < matrix.size() - 1; i++){
            for(int j = i + 1; j < matrix[i].size(); j++) swap(matrix[i][j], matrix[j][i]);
        }

        for(int i = 0; i < matrix.size(); i++) reverse(matrix[i].begin(), matrix[i].end());
    }
};