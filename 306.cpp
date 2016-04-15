class Solution {
public:
    string add(string a, string b)
    {
        string sum;

        int carry = 0;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int i = 0;
        while(i < a.size() && i < b.size())
        {
            int c = (a[i] - '0') + (b[i] - '0') + carry;
            sum += c % 10 + '0';
            carry = c / 10;
            ++ i;
        }

        while(i < a.size())
        {
            int c = (a[i] - '0') + carry;
            sum += c % 10 + '0';
            carry = c / 10;
            ++ i;
        }
        while(i < b.size())
        {
            int c = (b[i] - '0') + carry;
            sum += c % 10 + '0';
            carry = c / 10;
            ++ i;
        }
        if( carry ) {
            sum += carry + '0';
        }

        reverse(sum.begin(),sum.end());

        return sum;
    }

    bool isAdditiveNumber(string num) {
        int size = num.size();
        for(int i = 0; i < size - 2; ++ i)
        {
            if(num[0] == '0' && i > 0) return false;
            string num1 = num.substr(0,i + 1);
            for(int j = 1; j < size - 1 - i; ++ j)
            {
                if(num[i + 1] == '0' && j > 1) break;
                string num2 = num.substr(i + 1,j);
                string sum = add(num1,num2);
                if(sum.size() > size - i - 1 - j) break;
                else
                {
                    string num3 = num.substr(i + 1 + j,sum.size());
                    if(num3 != sum) continue;
                    else if(i + 1 + j + sum.size() == size) return true;
                    else if(isAdditiveNumber(num.substr(i + 1))) return true;
                }
            }
        }

        return false;
    }
};
