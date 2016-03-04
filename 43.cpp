class Solution {
public:
    //2014-1-27
    string multiply(string num1, string num2) 
    {
        string rs(num1.length()+num2.length(), '0');

        for (int i = num1.length()-1, d = rs.length()-1; i >= 0; i--, d--)
        {
            int carry = 0, k = d;
            for (int j = num2.length()-1; j >= 0; j--, k--)
            {
                int a = num1[i] - '0';
                int b = num2[j] - '0';
                a = a*b+carry + (rs[k]-'0');
                carry = a/10;
                rs[k] = a%10 + '0';
            }
            while (carry)
            {
                int sum = carry + (rs[k]-'0');
                carry = sum / 10;
                rs[k--] = sum % 10 + '0';
            }
        }
        while (rs.size() > 1 && rs[0] == '0') rs.erase(rs.begin());
        return rs;
    }
};
