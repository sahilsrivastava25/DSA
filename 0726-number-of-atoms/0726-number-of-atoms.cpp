class Solution {
public:
    using int3 = array<int, 3>; // (pos for right ')', real ending, multiplier)
    vector<int3> mult;
    int n;

    unordered_map<string, int> atom; 

    // Recursive function to count atoms TC: O(n)
    void f(int i, string& formula, int r, int times = 1) {
        while (i < r) {
            if (formula[i] == '(') {
                auto& m = mult[i];
                f(i+1, formula, m[0], m[2] * times);
                i = m[1]+1;
            } 
            else if (isupper(formula[i])) {
                string chemi = string(1, formula[i]);
                int start = i;
                while (i+1 < r && islower(formula[i+1])) {
                    chemi+= formula[i+1];
                    i++;
                }
                i++;

                int x = 0;
                while (i < r && isdigit(formula[i])) {
                    x=x*10 + (formula[i]-'0');
                    i++;
                }
                if (x== 0) x= 1;
                atom[chemi]+= x* times;
            } 
            else 
                i++;
        }
    }

    // Print the content of the container
    void print(auto& c) {
        int sz=c.size();
        for (int i=0; i<n; i++){
            auto& x=c[i];
            if (x[0]!=-1)
                cout<<i<<" ->[" << x[0] << "," << x[1] << "," << x[2]<<"]\n";
        }
    }

    // Convert atom to result string TC: O(klog k)
    inline string convert() {
        vector<pair<string, int>> satom(atom.begin(),atom.end());
        sort(satom.begin(), satom.end());
        string result;
        for (auto& [chemi, x]: satom) {
            result += chemi;
            if (x > 1)
                result += to_string(x);
            
        }
        return result;
    }

    string countOfAtoms(string& formula) {
        n=formula.size();
        atom.reserve(n);
        vector<int> st;
        mult.assign(n, {-1, -1, -1});
        for (int i = 0; i < n; i++) {// O(n)
            char c = formula[i];
            if (c == '(')
                st.push_back(i);
            else if (c == ')') {
                int x = 0, r = i;
                while (i + 1 < n && isdigit(formula[i + 1])) {
                    x = 10 * x + (formula[++i] - '0');
                }
                if (x == 0)
                    x = 1;
                int l = st.back();
                st.pop_back();
                mult[l] = {r, i, x};
            }
        }
    //    print(mult);
        
        f(0, formula, n, 1); // Start recursive function
        return convert();       // Convert the atom array to result string
    }

};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();