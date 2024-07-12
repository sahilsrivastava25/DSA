class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int max = 0;

        if(y > x){
            for(int i = 0; i < s.size(); i++){
              if(i+1 < s.size() && s[i] == 'b' && s[i+1]=='a'){
                max += y;
                s.erase(i, 2);

                if(i > 0)
                i = i - 2;

                else
                i--;
              }
            }

            for(int i = 0; i < s.size(); i++){
              if(i+1 < s.size() && s[i] == 'a' && s[i+1]=='b'){
                max += x;  
                s.erase(i, 2);
                
                if(i > 0)
                i = i - 2;

                else
                i--;
              }   
            }

        }

        else{
            for(int i = 0; i < s.size(); i++){
              if(i+1 < s.size() && s[i] == 'a' && s[i+1]=='b'){
                max += x;
                s.erase(i, 2);
                
                if(i > 0)
                i = i - 2;

                else
                i--;
              }
            }

            for(int i = 0; i < s.size(); i++){
              if(i+1 < s.size() && s[i] == 'b' && s[i+1]=='a'){
                max += y;  
                s.erase(i, 2);
                
                if(i > 0)
                i = i - 2;

                else
                i--;
              }   
            }

        }
        return max;


    }
};