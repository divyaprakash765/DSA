class ExamTracker {
public:
    vector<pair<int,int>> track;
    unordered_map<int,long long> pref;
    long long sum = 0;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        track.push_back({time,score});
        sum += score;
        pref[time] = sum;
    }
    int strt_bound(int time){
        int n = track.size();
        int low = 0;
        int high = n-1;
        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            if(track[mid].first < time){
                ans = track[mid].first;
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
        return ans;
    }

    int end_bound(int time){
        int n = track.size();
        int low = 0;
        int high = n-1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(track[mid].first <= time){
                ans = track[mid].first;
                low = mid+1;
            } else high = mid-1;
        }
        return ans;
    }
    
    long long totalScore(int startTime, int endTime) {
        startTime = strt_bound(startTime);
        endTime = end_bound(endTime);

        return pref[endTime] - pref[startTime];
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */