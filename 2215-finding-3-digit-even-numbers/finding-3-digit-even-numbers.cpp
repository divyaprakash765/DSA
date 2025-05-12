class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int,int> mp;
        for(auto& num : digits) mp[num]++;
        vector<int> ans;
        for(int i=100;i<=999;i+=2){
            int x = i;
            int rem = x%10;
            x = x/10;
            int rem2 = x%10;
            x = x/10;
            int rem3 = x%10;
           if(mp.find(rem) != mp.end()){
            mp[rem]--;
            if(mp[rem] == 0) mp.erase(rem);
            if(mp.find(rem2) != mp.end()){
            mp[rem2]--;
            if(mp[rem2] == 0) mp.erase(rem2);
            if(mp.find(rem3) != mp.end()){
            ans.push_back(i);
           }
           mp[rem2]++;
           }
           mp[rem]++;
           }
        }
        return ans;
    }
};