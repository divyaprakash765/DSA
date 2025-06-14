class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int word_length = words[0].size();
        int word_count = words.size();
        int total_length = word_length*word_count;
        vector<int> ans;

        map<string, int> mp;
        for (auto& word : words) {
            mp[word]++;
        }

        for(int i=0;i<word_length;i++){
            map<string,int> window_map;
            int left = i;
            int right = i;
            int count = 0;

            while(right+word_length <= n){
              string sub = s.substr(right,word_length);
              right += word_length;

              if(mp.find(sub) == mp.end()){
                window_map.clear();
                count = 0;
                left = right;
              } else{
                window_map[sub]++;
                count++;

                while(window_map[sub] > mp[sub]){
                    string left_word = s.substr(left,word_length);
                window_map[left_word]--;
                left += word_length;
                count--;
                }
                if(count == word_count){
                    ans.push_back(left);
                    string left_word = s.substr(left,word_length);
                    window_map[left_word]--;
                    left += word_length;
                    count--;
                }
              }
              

            }
        }

        return ans;
    }
};