class Solution {
public:
    vector<int> generateRow(int row){
        vector<int> ans;
        ans.push_back(1);

        long long res = 1;

        for(int i = 1; i < row; i++){
            res = res * (row - i);
            res = res / i;
            ans.push_back(res);
        }

        return ans;
    }
    vector<vector<int>> generate(int numRows) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++){
            vector<int> temp = generateRow(i);
            ans.push_back(temp);
        }
        return ans;
    }
};