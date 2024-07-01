class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd = 0;
        for(int i = 0; i < arr.size(); i++){

            if(arr[i] % 2 == 0)
            odd = 0;

            else
            odd++;

            if(odd == 3)
            return true;
        }

        return false;
    }
};