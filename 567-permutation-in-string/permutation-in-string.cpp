class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) return false;

        map<char,int> mp1;
        for(int i=0;i<n1;i++){
            mp1[s1[i]]++;
        }

        int i = 0;
        map<char,int> mp2;
        int j = 0;
        while(j < n1){
            mp2[s2[j]]++;
            j++;
        }
        if(mp1 == mp2) return true;
        while(j < n2){
           mp2[s2[j]]++;
            mp2[s2[i]]--;
            if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
            if(mp1 == mp2) return true;
            i++;
            j++;
        }

        return false;
    }
};