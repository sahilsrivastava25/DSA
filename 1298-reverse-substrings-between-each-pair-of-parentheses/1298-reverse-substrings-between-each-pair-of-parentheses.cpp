class Solution {
public:
    string reverseParentheses(string s) {
        int itr1, itr2;
        vector<int> itr;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(')     
            itr.push_back(i);
            

            if(s[i] == ')')
            {
                itr2 = i;
                itr1 = itr[itr.size()-1];
                itr.pop_back();

                string prev, con = "", suc;
                prev = s.substr(0, itr1);

                if(itr2 < s.size()-1)
                suc = s.substr(itr2+1, s.size() - itr2 - 1);

                else
                suc = "";

                con = s.substr(itr1 + 1,itr2-itr1-1);

                reverse(con.begin(), con.end());

                s = prev + con + suc;

                i = i - 2;
            }     
        }
        return s;

    }
};