class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int n1 = nums1.size();
        int n2 = nums2.size();
        int len = n1 + n2;
        double ans;
        vector<int> v(len);
        int i = 0, j = 0, k = 0;

        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]){
                v[k] = nums1[i];
                i++;
                k++;
            }

            else if(nums1[i] > nums2[j]){
                v[k] = nums2[j];
                j++;
                k++;
            }
        }

        while(i < n1){
            v[k] = nums1[i];
            i++;
            k++;
        }

        while(j < n2){
            v[k] = nums2[j];
            j++;
            k++;
        }

        if(len % 2 == 0){
            double ind1 = v[(len / 2) - 1];
            double ind2 = v[len / 2];

            ans = double((ind1 + ind2) / 2);
        }

        else ans = v[len / 2];

        return ans;
    }
};