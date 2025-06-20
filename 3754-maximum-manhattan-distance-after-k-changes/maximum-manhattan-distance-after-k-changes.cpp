class Solution {
public:
    int maxDistance(string t, int k) {
        int m = t.size();
        int ans  = 0;
        int n = 0,w = 0,s = 0, e = 0;

        for(int i=0;i<m;i++){
          char ch = t[i];
          if(ch == 'N') n++;
          else if(ch == 'S') s++;
          else if(ch == 'E') e++;
          else w++;

          int x = abs(e-w);
          int y = abs(s-n);

          int m = x + y;
          int dist = m + min(2*k,i+1-m);
          ans = max(ans,dist);
        }
        return ans;
    }
};