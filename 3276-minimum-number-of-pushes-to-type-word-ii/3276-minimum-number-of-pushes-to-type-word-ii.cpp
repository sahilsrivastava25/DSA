class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26);
        priority_queue<pair<int, int>> store;
        int ans = 0, cnt = 0, i = 0;

        for(int i = 0; i < word.size(); i++) v[int(word[i] - 'a')]++;
        for(int i = 0; i < v.size(); i++) store.push({v[i], i});

        while(!store.empty()){
            if(cnt % 8 == 0) i++;
            ans = ans + store.top().first * i;
            cnt++;
            store.pop();
        }

        return ans;

    }
};