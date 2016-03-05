class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 0) return b;
        if(b.size() == 0) return a;
        if(a.size() == 0 && b.size() == 0) return a;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        
        int i,carry;
        string result;
        i = carry = 0;
        result = "";
        while(i < a.size() && i< b.size())
        {
            int temp = a[i] - '0' + b[i] - '0' + carry;
            result += (temp % 2 + '0');
            carry = temp / 2;
            ++i;
        }
        while( i < a.size() )
        {
            int temp = a[i] - '0' + carry;
            result += (temp % 2 + '0');
            carry = temp / 2;
            ++i;
        }
        while( i < b.size() )
        {
            int temp = b[i] - '0' + carry;
            result += (temp % 2 + '0');
            carry = temp / 2;
            ++i;
        }
        if( carry )
        result += "1";
        reverse(result.begin(),result.end());
        return result;
    }
};
