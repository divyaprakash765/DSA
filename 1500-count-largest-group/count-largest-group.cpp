class Solution {
public:

    int sumOfDigit(int n){
        int sum = 0;
     while(n > 0){
      int rem = n % 10;
      sum += rem;
      n = n/10;
     }
     return sum;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int> mp;

        for(int i=1;i<=n;i++){
            int sum_of_digits = sumOfDigit(i);
            mp[sum_of_digits]++;
        }
        int maxi = 0;
        for(auto& it : mp){
        int num = it.first;
        int size = it.second;
        maxi = max(maxi,size);
        }
        int ans = 0;
        for(auto& it : mp){
        int size = it.second;
        if(size == maxi) ans++;
        }
        return ans;
    }
};