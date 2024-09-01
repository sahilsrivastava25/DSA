class Solution {
public:
    std::vector<std::vector<int>> construct2DArray(std::vector<int>& original, int m, int n) {

        if (m * n != original.size()) {
            return {}; 
        }

        std::vector<std::vector<int>> result(m, std::vector<int>(n));

        for (int i = 0; i < m; ++i) {
            result[i] = std::vector<int>(original.begin() + i * n, original.begin() + i * n + n);
        }

        return result;
    }
};
static const auto kds = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

