class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if( !digits.size() ) return digits;
        int carry = 0;
        int i = digits.size() - 1;
            
        int temp = digits[i] + 1;
        digits[i] = temp % 10;
        carry = temp / 10;
        --i;
        
        while(i >=0 )
        {
            temp = digits[i] + carry;
            digits[i] = temp % 10;
            carry = temp / 10;
            if( !carry ) break;
            --i;
        }
        if( carry )
            digits.insert(digits.begin(),1);
        return digits;
    }
};
