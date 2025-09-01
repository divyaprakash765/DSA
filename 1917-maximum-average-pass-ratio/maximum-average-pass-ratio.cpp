class Solution {
public:

 double gain(int pass,int total){
    return (double)(pass + 1)/(double(total + 1)) - double(pass)/double(total);
 }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,pair<int,int>>> pq;

        for(int i=0;i<n;i++){
            int pass = classes[i][0];
            int total = classes[i][1];
            double g = gain(pass,total);
            pq.push({g,{pass,total}});
        }

        while(extraStudents > 0){
            auto it = pq.top();
            pq.pop();
            int pass = it.second.first + 1;
            int total = it.second.second + 1;
            double g = gain(pass,total);
            pq.push({g,{pass,total}});
            extraStudents--;
        }

        double ans = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans += (double)(it.second.first)/double(it.second.second);
        }

        ans = ans/double(n);

        return ans;

    }
};