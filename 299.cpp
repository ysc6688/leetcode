class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        
        int a,b;
        a = b = 0;
        
        int size = secret.size();
        int map[10] = { 0 };
        for(int i = 0; i < size; ++ i)
        {
            if(secret[i] == guess[i])
            { 
                ++ a;
                continue;
            }
            else map[secret[i] - '0'] ++;
        }
        for(int i = 0; i < size; ++ i)
        {
            if(secret[i] != guess[i] && map[guess[i] - '0'] > 0)
            {
                ++ b;
                -- map[guess[i] - '0'];
            }
        }
        
        char buf[80];
        sprintf(buf,"%dA%dB",a,b);
        res = string(buf);
        return res;
    }
};
