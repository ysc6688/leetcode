class Solution {
public:
int atoi(string str)
{
    long result;
    int i,neg;

    if( !str.size() )
        return 0;

    i = 0;
    while(1){
        if(str.at(i) == ' ')
            i++;
        else
            break;
    }
    str = str.substr(i);
    neg = ( str.at(0) == '-' ) ? 1 : 0;
    if( neg || str.at(0) == '+' )
        str = str.substr(1,str.size()-1);

    result = 0;
    for (i = 0; i < str.size(); ++i)
    {
        char c = str.at(i);
        if(c >= '0' && c <= '9')
            result = result * 10 + str.at(i) - '0';
        else
            break;
        if(result > 0x7fffffff)
        {
            result = (neg) ? INT_MIN : INT_MAX;
            return result;
        }
    }
    if( neg )
        result = -result;
    return result;
}
};
