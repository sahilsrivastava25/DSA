class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;
        vector<int> ans;
        stack<int> st;

        int n2 = nums2.size();

        for(int i = n2 - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            nge[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]);
        }

        for(int i = 0; i < nums1.size(); i++) ans.push_back(nge[nums1[i]]);

        return ans;

    }
};