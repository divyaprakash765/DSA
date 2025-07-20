class Solution {
public:

    bool canBeEaten(int speed,vector<int>& piles,int time){
        long long total_time = 0;

        for(int i=0;i<piles.size();i++){
            if(piles[i]%speed == 0){
                total_time += (piles[i]/speed);
            } else{
                total_time += (piles[i]/speed) + 1;
            }
        }
        return total_time <= time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = high;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canBeEaten(mid,piles,h)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        }

        return ans;
    }
};