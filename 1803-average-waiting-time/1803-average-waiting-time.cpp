class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int timing = customers[0][0] + customers[0][1];
        double ans =  customers[0][1];

        for(int i = 1; i < customers.size(); i++){
           if(timing > customers[i][0]){
            ans = ans + timing + customers[i][1] - customers[i][0];
            timing = timing + customers[i][1];
           }

           else if(timing <= customers[i][0]){
            timing = customers[i][0] + customers[i][1];
            ans = ans + customers[i][1];
           }
        }

        return ans/customers.size();
    }
};