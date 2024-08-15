class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivebillcount=0,tenbillcount=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) fivebillcount++;
            else if(bills[i]==10){
                if(fivebillcount>=1){
                    tenbillcount++;
                    fivebillcount--;
                }
                else return false;
            }
            else{
                if(tenbillcount>=1 && fivebillcount>=1){
                    tenbillcount--;
                    fivebillcount--;
                }
                else if(fivebillcount>=3){
                    fivebillcount-=3;
                }
                else return false;
            }
        }
        return true;
    }
};