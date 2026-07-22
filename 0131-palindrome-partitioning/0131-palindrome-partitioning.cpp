class Solution {
public:
    bool IsPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i, int j, string &s, vector<string> &temp, vector<vector<string>> &res) {
        if (i >= s.size()) {
            res.push_back(temp);
            return;
        }
        for (j = i; j < s.length(); j++) {
            if (IsPalindrome(s, i, j)) {
                temp.push_back(s.substr(i, j - i + 1));
                solve(j + 1, j, s, temp, res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> res;
        solve(0, 0, s, temp, res);
        return res;
    }
};