class Solution {
typedef long long ll;
public:
    long long maxKelements(vector<int>&v, int k) {
        ll n=v.size(), ans=0;
        priority_queue<ll>pq(begin(v), end(v));
        while(!pq.empty() && k--){
            ll it=pq.top();
            pq.pop();
            if(!it){ // no value in considering zeroes
                continue;
            }
            ans+=it;
            pq.push((it/3)+((it%3)!=0));
        }
        return ans;
    }
};