class Solution {
public:
    static vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        const int m=matrix.size(), n=matrix[0].size();
        int max_rmin=INT_MIN, posj=-1;
        for(int i=0; i<m; i++){
            int p=min_element(matrix[i].begin(), matrix[i].end())-matrix[i].begin();
            int x=matrix[i][p];
            if (x>max_rmin){
                max_rmin=x;
                posj=p;
            }
        }
        for(int i=0; i<m; i++){
            if (max_rmin<matrix[i][posj]) return {};
        }
            
        return {max_rmin};
    }
};





auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();