class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
       
        vector<vector<int>> ans;
        for(int i = 1; i <= numRows; i++)
        {   
            int C = 1;
            vector<int> col;
            for(int j = 1; j <= i; j++)
            {
                col.push_back(C);
                C = (C*(i-j))/j;  
            }        
            ans.push_back(col);
        } 
        return ans;
    }
};