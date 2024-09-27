// Logical - Brute Approach

class MyCalendarTwo {
public:
    vector<pair<int,int>> vp;
    MyCalendarTwo() {
        // Don't Do anything
    }
    
    bool book(int x, int y) {
        for(auto &val:vp){
            int a = val.first, b = val.second;

            if((x<b) and (y>a)){
                // calculate sub-interval
                int new_x = max(a,x);
                int new_y = min(b,y);

                // checking if the sub-interval is valid or not
                if(check(new_x, new_y)){
                    return false;
                }
            }

        }

        vp.push_back({x,y});
        return true;
    }

    // checking if sub-interval get overlapped more than single time
    bool check(int x, int y){
        int overlapp_cnt = 0;

        for(int i=0;i<vp.size();i++){
            int a = vp[i].first, b = vp[i].second;

            if((x<b) and (y>a)){ // strict condition for overlapping
                overlapp_cnt++;
                if(overlapp_cnt == 2){
                    return true;
                }
            }
        }

        return false;
    }
};