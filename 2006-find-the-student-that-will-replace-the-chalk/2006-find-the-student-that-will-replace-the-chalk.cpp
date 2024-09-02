class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
       long long int n = chalk.size(), sum = 0;
        vector<long long int> v(n);

        v[0] = chalk[0];
        for(int i = 1; i < n ; i++) v[i] = v[i-1] + chalk[i];

        for(int i = 0; i < n; i++) sum += chalk[i];

        long long int ans = k % sum;
        
        int i = 0;
        for(i = 0; i < n; i++){
            if(ans < v[i]) break;
        }

        return i;
    }
};