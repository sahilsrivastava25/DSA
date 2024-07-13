class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, vector<int>>> v(n);

        for(int i = 0; i < n; i++)
        v[i] = {positions[i],{i, healths[i], directions[i]}};

        sort(v.begin(), v.end());

        stack<pair<int, vector<int>>> st;
        vector<pair<int, vector<int>>> ans;

        for(int i = 0; i < n; i++){
            if(v[i].second[2] == 'R')
            st.push(v[i]);

            else{
                bool ok = true; // assume that upcoming robot with L will win.

                while(!st.empty()){
                    pair<int, vector<int>> tp = st.top();
                    st.pop();

                    if(tp.second[1] == v[i].second[1]){
                        ok = false;
                        break;
                    }

                    else if(tp.second[1] > v[i].second[1]){
                        tp.second[1]--;
                        ok = false;
                        st.push(tp);
                        break;
                    }

                    else{
                        v[i].second[1]--;
                    }
                }

                if(ok)
                ans.push_back(v[i]);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top()); // In case only R's are there.
            st.pop();
        }
        
        for(int i = 0; i < ans.size(); i++){
            swap(ans[i].first, ans[i].second[0]); // in order to sort it acc. to index now.
        }

        sort(ans.begin(), ans.end());

        vector<int> res;

        for(int i = 0; i < ans.size(); i++)
        res.push_back(ans[i].second[1]);

        return res;
    }

    
};