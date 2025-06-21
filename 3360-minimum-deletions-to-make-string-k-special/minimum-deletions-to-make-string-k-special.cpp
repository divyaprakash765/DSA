class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26,0);

        for(char ch : word){
            freq[ch-'a'] += 1;
        }
         int ans = 1e9;
        sort(freq.begin(),freq.end());

        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            int range = freq[i] + k;
            int tot = freq[i];

            for(int j=i+1;j<26;j++){
                if(freq[j] == 0) continue;
                if(freq[j] > range) tot += range;
                else tot += freq[j];
            }
            int rem = word.size() - tot;
            ans = min(ans,rem);
        }
        return ans;
    }
};