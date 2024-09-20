class Solution{
    public:
    string shortestPalindrome(string s){
        if(s.empty()) return s;

        string rev_s =s;
        reverse(rev_s.begin(),rev_s.end());

        string combined =s+"#" +rev_s;

        int n=combined.length();

        vector<int> kmp(n,0);

        buildKMP(combined,n,kmp);

        int palindrome_suffix_length =kmp[n-1];
        string non_palindrome_suffix= s.substr(palindrome_suffix_length);

        reverse(non_palindrome_suffix.begin(),non_palindrome_suffix.end());

        return non_palindrome_suffix + s;


    }

    private:
    void buildKMP(string combined,int n, vector<int>&kmp){
        int j=0;
        kmp[0]=0;

        for(int i=1; i<n;i++){
            if(combined[i]==combined[j]){
                j++;
                kmp[i]=j;
            }
            else{
                if(j!=0){
                    j=kmp[j-1];
                    i--;//to stay at same index
                }
                else{
                    kmp[i]=0;
                }
            }
        }
    }

};