class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxi = s, mini = s;

        // ---- MAXIMIZE: Replace first digit != 9 with 9 ----
        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        if (toReplaceMax) {
            for (char& c : maxi) {
                if (c == toReplaceMax) c = '9';
            }
        }

        // ---- MINIMIZE ----
        // Case 1: First digit != 1 → replace it with 1
        char toReplaceMin = 0;
        if (s[0] != '1') {
            toReplaceMin = s[0];
            for (char& c : mini) {
                if (c == toReplaceMin) c = '1';
            }
        } else {
            // Case 2: Replace first digit (after index 0) not 0 or 1 → with 0
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    break;
                }
            }
            if (toReplaceMin) {
                for (int i = 1; i < mini.size(); ++i) {
                    if (mini[i] == toReplaceMin) mini[i] = '0';
                }
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
