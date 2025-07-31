class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> curr;
        unordered_set<int> nxt;
        
        for(auto& a : arr){
          nxt.clear();
          nxt.insert(a);
          for(int x : curr){
            nxt.insert(x | a);
          }
          curr = nxt;
          ans.insert(curr.begin(),curr.end());
        }
        return ans.size();
    }
};