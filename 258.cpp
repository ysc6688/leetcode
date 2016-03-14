class Solution {
public:
    int addDigits(int num) {
        if(num / 10 == 0) return num;
        
        while(num / 10 != 0)
        {
            char buf[20];
            sprintf(buf,"%d",num);
            int len = strlen(buf);
            num = 0;
            for(int i = 0; i < len; ++ i)
                num += buf[i] - '0';
        }
        return num;
    }
};
