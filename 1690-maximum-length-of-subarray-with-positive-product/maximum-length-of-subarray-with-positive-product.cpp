class Solution {
public:
     int getMaxLen(vector<int> nums) 
    { 
        int framestart = -1, firstneg = -2, len = 0, neg = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (nums[i] == 0) 
            {  
                neg = 0;framestart = i;firstneg = -2;
            } 
            else 
            {
                if (nums[i] < 0) neg++;
                if (neg == 1 && firstneg == -2) firstneg = i; 
                if (neg % 2 == 0) len = max(len, i - framestart);
                else len = max(len, i - firstneg); 
            }
        }
        return len;

    }
};