class Solution {

// [2,7,11,15]
// mp->{{2,0}}
// (target -nums[i])
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[nums[0]] = 0;

        for(int i=1;i<n;i++){
            int num = target - nums[i];
            if(mp.find(num) != mp.end()){
                return {i,mp[num]};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

// T.C = O(n*n)