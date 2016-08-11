class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = { 0 };
        
        for(int i = 0; i < magazine.size(); ++ i)
            hash[magazine[i] - 'a'] ++;
        
        for(int i = 0; i < ransomNote.size(); ++ i)
            if(hash[ransomNote[i] - 'a'] <= 0) return false;
            else hash[ransomNote[i] - 'a'] --;
        
        return true;
    }
};
