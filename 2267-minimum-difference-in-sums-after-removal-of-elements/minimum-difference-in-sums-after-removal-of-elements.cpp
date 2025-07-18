class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
       int n = nums.size();
       int k = n/3;

       priority_queue<int> max_heap;
       long long left_sum = 0;
       vector<long long> left(n);

       for(int i=0;i<n;i++){
        max_heap.push(nums[i]);
        left_sum += nums[i];
        if(max_heap.size() > k){
            left_sum -= max_heap.top();
            max_heap.pop();
        }
        if(max_heap.size() == k){
            left[i] = left_sum;
        }
        else{
            left[i] = LLONG_MAX;
        }
       }

       long long right_sum = 0;
       vector<long long> right(n);
       priority_queue<int,vector<int>,greater<int>> min_heap;

       for(int i=n-1;i>=0;i--){
        right_sum += nums[i];
        min_heap.push(nums[i]);
        if(min_heap.size() > k){
            right_sum -= min_heap.top();
            min_heap.pop();
        }
        if(min_heap.size() == k){
            right[i] = right_sum;
        } else{
            right[i] = LLONG_MIN;
        }
       }

       long long ans = LLONG_MAX;
      for (int i = k - 1; i < n - k; i++) {
            if (left[i] != LLONG_MAX && right[i + 1] != LLONG_MIN)
                ans = min(ans, left[i] - right[i + 1]);
        }

       return ans;

    }
};