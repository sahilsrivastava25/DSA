class Solution {
public:
    int maximumLength(vector<int>& nums) {
        vector<int> par;

        for(int i = 0; i < nums.size(); i++)
        par.push_back(nums[i] % 2);

        int odd = 0, even = 0, diff = 1;

        for(int i = 0; i < par.size(); i++){
            if(par[i])
            odd++;

            if(par[i] == 0)
            even++;

        }

        int i = 0, j = 1;
        while(i < nums.size() && j < nums.size()){
            if(par[i]!=par[j]){
                diff++;
                i = j;
                j++;
            }

            else
            j++;
        }

        int ans;

        if(even > odd){
            if(even > diff)
            ans = even;

            else
            ans = diff;
        }

        else{
            if(odd > diff)
            ans = odd;

            else
            ans = diff;
        }

        return ans;
    }
};