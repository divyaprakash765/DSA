class Solution {
public:
    vector<string> ans;

    void f(int n,string t){
      if(t.size() == n){
        ans.push_back(t);
        return;
      }

      if(t.empty() || t.back() == '1'){
        f(n,t+'0');
      }
      f(n,t+'1');
    }

    vector<string> validStrings(int n) {
        
     f(n,"");
     return ans;
    }
};