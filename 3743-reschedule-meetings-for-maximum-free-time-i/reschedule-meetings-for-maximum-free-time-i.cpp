class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        gaps.push_back(startTime[0]);

        for(int i = 1; i < startTime.size(); i++) {
            gaps.push_back(startTime[i] - endTime[i-1]);
        }

        gaps.push_back(eventTime - endTime[endTime.size()-1]);

        int i = 0;
        int j = 0;
        int ans = 0;
        int sum = 0;
        
        while(j<gaps.size()){
            sum += gaps[j];

            if(i<n && (j-i+1) > k+1){
                sum -= gaps[i];
                i++;
            }
            ans = max(ans,sum);
            j++;
        }

        return ans;
    }
};
