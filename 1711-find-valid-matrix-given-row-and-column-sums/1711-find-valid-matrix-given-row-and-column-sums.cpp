class Solution {
public:
    std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
        int m = rowSum.size();
        int n = colSum.size();
        std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
        int i = m - 1, j = n - 1;

        while (i >= 0 && j >= 0) {
            if (rowSum[i] <= colSum[j]) {
                matrix[i][j] = rowSum[i];
                colSum[j] -= rowSum[i];
                i--;
            } else {
                matrix[i][j] = colSum[j];
                rowSum[i] -= colSum[j];
                j--;
            }
        }

        return matrix;
    }
};