class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int, int>> check;

        for(int i = 0; i < arr.size(); i++){
            int diff = abs(arr[i] - x);
            check.push_back({diff,arr[i]});
        }

        sort(check.begin(), check.end());

        vector<int> res;

        for(int i = 0; i < k; i++){
            res.push_back(check[i].second);
        }

        sort(res.begin(),res.end());

        return res;
    }
};