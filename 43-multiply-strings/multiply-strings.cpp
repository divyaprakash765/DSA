class Solution {
public:

     string SumUp(string s1, string s2) {
        if (s1.length() < s2.length()) swap(s1, s2);
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';
            ans += (sum % 10 + '0');
            carry = sum / 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }

    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        string ans = "0";
        for(int i=n2-1;i>=0;i--){
            int carry = 0;
            string curr = "";

            curr.append(n2 - 1 - i, '0');

            for (int j = n1 - 1; j >= 0; j--) {
                int mul = (num2[i] - '0') * (num1[j] - '0') + carry;
                curr += (mul % 10 + '0');
                carry = mul / 10;
            }

            if (carry) curr += (carry + '0');
            reverse(curr.begin(), curr.end());

            ans = SumUp(ans, curr);
        }
        for(int i=0;i<ans.size();++i){
            if(ans[i] != '0') return ans;
        }
        return "0";
    }
};