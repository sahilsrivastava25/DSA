class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        
        for(int i = 0; i < details.size(); i++){
            int age1 = details[i][11] - '0';
            int age2 = details[i][12] - '0';
            if(age1 > 6)
            ans++;

            else if(age1 == 6 && (age2 > 0 && age2 <= 9))
            ans++;
        }

        return ans;
    }
};