class FindSumPairs {
public:
    vector<int> n1;
    vector<int> n2;
    unordered_map<int,int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(int i=0;i<n2.size();i++){
            mp[n2[i]]++;
        }
    }
    
    void add(int index, int val) {
        mp[n2[index]]--;
        n2[index] += val;
        mp[n2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i=0;i<n1.size();i++){
                ans += mp[tot-n1[i]];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */