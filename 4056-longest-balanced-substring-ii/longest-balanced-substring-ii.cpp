class Solution {
public:
    int f(string s,string t){
        int n = s.size();
        int cnt1 = 0;
        map<int,int> mp;
        mp[0] = -1;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i] == t[0]){
                cnt1++;
            }
            else if(s[i] == t[1]){
                cnt1--;
            }
            else{
                mp.clear();
                cnt1 = 0;
            }
            if(mp.find(cnt1) == mp.end()) mp[cnt1] = i;
            ans = max(ans,i-mp[cnt1]);
        }
        return ans;
    }

    int f2(string s){
        int n = s.size();
        map<pair<int,int>,int> mp;
        int v1 = 0;
        int v2 = 0;
        mp[{v1,v2}] = -1;
        int ans = 0;
        for(int i=0;i<n;i++){
        if(s[i] == 'a') v1++;
        else if(s[i] == 'c') v2++;
        else{
            v1--;
            v2--;
        }

       if(mp.find({v1,v2}) == mp.end()) mp[{v1,v2}] = i;
            ans = max(ans,i-mp[{v1,v2}]);
        }
        return ans;
    }

    int longestBalanced(string s) {
        int n = s.size();

        int ans = 0;
        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'a'){
                cnt0++;
                cnt1 = 0;
                cnt2 = 0;
            } else if(s[i] == 'b'){
                cnt1++;
                cnt0 = 0;
                cnt2 = 0;
            } else{
                cnt2++;
                cnt0 = 0;
                cnt1 = 0;
            }
            ans = max(ans,max(cnt0,max(cnt1,cnt2)));
        }

        cnt0 = f(s,"ab");
        ans = max(ans,cnt0);
        cnt0 = f(s,"bc");
        ans = max(ans,cnt0);
        cnt0 = f(s,"ac");
        ans = max(ans,cnt0);
        ans = max(ans,f2(s));

        return ans;

    }
};