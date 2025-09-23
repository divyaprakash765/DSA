class Solution {
public:
    vector<int> f(string& version1) {
        int n = version1.size();
        vector<int> ans;
        string temp = "";
        int i = 0;
        while (i < n) {
            if (version1[i] == '.') {
                ans.push_back(stoi(temp));
                temp = "";
            } else {
                temp += version1[i];
            }
            i++;
        }
        ans.push_back(temp.empty() ? 0 : stoi(temp));
        return ans;
    }

    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();

        vector<int> r1 = f(version1);
        vector<int> r2 = f(version2);

        if (r1.size() > r2.size()) {
            int diff = r1.size() - r2.size();
            for (int i = 0; i < diff; i++)
                r2.push_back(0);
        } else if (r1.size() < r2.size()) {
            int diff = r2.size() - r1.size();
            for (int i = 0; i < diff; i++)
                r1.push_back(0);
        }

        for (int i = 0; i < r1.size(); i++) {
            if (r1[i] > r2[i]) {
                return 1;
            } else if (r1[i] < r2[i]) {
                return -1;
            }
        }
        return 0;
    }
};