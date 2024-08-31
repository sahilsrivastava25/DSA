class Solution {
public:
    int secondHighest(string s) {
        vector<int> v;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] >= '0' && s[i] <= '9') v.push_back(int(s[i] - '0'));
        }

        if(v.size() == 0) return -1;

        int maxi = v[0];
        for(int i = 0; i < v.size(); i++){
            if(v[i] > maxi) maxi = v[i];
        }

        int maxi2 = -1;
        for(int i = 0; i < v.size(); i++){
            if(v[i] > maxi2 && v[i] < maxi) maxi2 = v[i];
        }

        return maxi2;
    }
};