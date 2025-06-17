class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int prev_start = intervals[0][0];
        int prev_end = intervals[0][1];
        for(int i=1;i<n;i++){
            int curr_start = intervals[i][0];
            int curr_end = intervals[i][1];
            if(curr_start <= prev_end){
                prev_end = max(prev_end,curr_end);
                prev_start = min(curr_start,prev_start);
            } else{
                ans.push_back({prev_start,prev_end});
                prev_start = curr_start;
                prev_end = curr_end;
            }
        }
        ans.push_back({prev_start,prev_end});
        return ans;
    }
};