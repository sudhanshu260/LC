class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> h(26, 0);
        for (char c : s) {
            h[c - 'a']++;
        }

        for (char c : t) {
            h[c - 'a']--;
            if (h[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
