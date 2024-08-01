class Solution {
public:
    int twoPointers(vector<int>& nums1, vector<int>& nums2) {
        int first = 0;
        int second = 0;
        while (first < nums1.size() && second < nums2.size()) {
            if (nums1[first] < nums2[second]) {
                first++;
            } else if (nums1[first] > nums2[second]) {
                second++;
            } else {
                return nums1[first];
            }
        }
        return -1;
    }
    int bSearch(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); i++) {
            if (binary_search(nums2.begin(), nums2.end(), nums1[i])) {
                return nums1[i];
            }
        }
        return -1;
    }

    // Function to Choose the Best Method
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if (abs(static_cast<int>(nums1.size()) - static_cast<int>(nums2.size())) > min(nums1.size(), nums2.size()) / 2) {
            if (nums1.size() < nums2.size()) {
                return bSearch(nums1, nums2);
            } else {
                return bSearch(nums2, nums1);
            }
        } else {
            
            return twoPointers(nums1, nums2);
        }
    }
};