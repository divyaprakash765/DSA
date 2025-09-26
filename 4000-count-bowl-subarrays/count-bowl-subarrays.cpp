class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngi(n,n);

        stack<int> st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(st.empty()) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }

        stack<int> st2;
        st2.push(0);
        vector<int> pgi(n,-1);

        for(int i=1;i<n;i++){
            while(!st2.empty() && nums[st2.top()] < nums[i]) st2.pop();
            if(st2.empty()) pgi[i] = n;
            else pgi[i] = i;
            st2.push(i);
        }

       long long ans = 0;

       for(int i=1;i<n-1;i++){
        if(pgi[i] != n && ngi[i] != n){
            ans++;
        }
       }
    return ans;
    }
};