class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();

        stack<char> st;
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        string ans = "";
        for(char ch : s){
            st.push(ch);
            freq[ch-'a']--;

            while(!st.empty()){
                bool canPop = true;
             for(int i=0;i<st.top()-'a';i++){
               if(freq[i] > 0){
                  canPop = false;
                  break;
               }
             }
             if(!canPop) break;
             ans += st.top();
             st.pop();
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
       return ans;
    }
};