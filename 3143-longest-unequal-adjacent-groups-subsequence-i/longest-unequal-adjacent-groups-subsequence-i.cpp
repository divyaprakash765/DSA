class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
    
    // Initialize dp and prev arrays
    vector<int> dp(n, 1);  // dp[i] will hold the longest alternating subsequence ending at i
    vector<int> prev(n, -1);  // prev[i] will track the previous index in the subsequence

    int maxLength = 1, lastIndex = 0;

    // Fill dp and prev arrays
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (groups[i] != groups[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        // Update maxLength and lastIndex
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }

    // Reconstruct the longest alternating subsequence
    vector<string> result;
    while (lastIndex != -1) {
        result.push_back(words[lastIndex]);
        lastIndex = prev[lastIndex];
    }

    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());
    
    return result;
    }
};