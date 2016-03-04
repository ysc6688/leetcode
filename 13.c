int mp[26] = {0};

int romanToInt(char *s)
{
    char pre;
    int i,result;

    mp['I'-'A'] = 1;
    mp['V'-'A'] = 5;
    mp['X'-'A'] = 10;
    mp['L'-'A'] = 50;
    mp['C'-'A'] = 100;
    mp['D'-'A'] = 500;
    mp['M'-'A'] = 1000;

    pre = *s;
    result = mp[pre-'A'];
    s++;
    while(*s != 0)
    {
        if(mp[*s-'A'] <= mp[pre-'A'])
            result += mp[*s-'A'];
        else
            result = result + mp[*s-'A'] - 2 * mp[pre-'A'];
        pre = *s;
        s++;
    }
    return result;
}
