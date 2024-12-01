class Solution {
public:
    // Main function that finds the largest combination of numbers from candidates
    // that have at least one common set bit (1) in their binary representation
    int largestCombination(vector<int>& candidates) {
        // Create vector to store count of 1's at each bit position (32 bits for integers)
        vector<int> ans(32, 0);
        
        // Iterate through each number in candidates vector
        for(int x : candidates) {
            // Count the number of 1's at each bit position for current number
            find(x, ans);
        }
        
        // Find the maximum count of 1's across all bit positions
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res = max(res, ans[i]);
        }
        
        // Return the largest possible combination
        return res;
    }
    
    // Helper method to count number of 1's at each bit position
    // Parameters:
    // n - the number to analyze
    // ans - vector to store bit counts at each position
    void find(int n, vector<int>& ans) {
        // Start from rightmost bit (31st position)
        int j = 31;
        
        // Continue until all bits are processed
        while(n > 0) {
            // Get the rightmost bit using bitwise AND with 1
            int a = (n & 1);
            
            // Add the bit count to corresponding position in ans vector
            ans[j] += a;
            
            // Right shift n by 1 to process next bit
            n >>= 1;
            
            // Move to next bit position from right to left
            j--;
        }
    }
};