class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        int maxi_top = -1;
        int maxi_bottom = -1;
         int maxi_top_freq = -1;
        int maxi_bottom_freq = -1;
        unordered_map<int,int> mpt;
        unordered_map<int,int> mpb;
        for(int i=0;i<n;i++){
         mpt[tops[i]]++;
         if(mpt[tops[i]] > maxi_top_freq){
            maxi_top_freq = mpt[tops[i]];
             maxi_top = tops[i];
            }
         mpb[bottoms[i]]++;
         if(mpb[bottoms[i]] > maxi_bottom_freq){
            maxi_bottom_freq = mpb[bottoms[i]];
             maxi_bottom = bottoms[i];
             }
        }
        
        if(maxi_top_freq > maxi_bottom_freq){
            for(int i=0;i<n;i++){
                if(tops[i] == maxi_top) continue;
                else if(bottoms[i] != maxi_top) return -1;
            }
        } else{
            for(int i=0;i<n;i++){
                if(bottoms[i] == maxi_bottom) continue;
                else if(tops[i] != maxi_bottom) return -1;
            }
        }
        return n - max(maxi_top_freq,maxi_bottom_freq);
    }
};