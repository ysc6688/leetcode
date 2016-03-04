class Solution {
    string ch[10] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> result;
public:
    void dfs(string dg,string letter){
        int index;
        if(dg.size() == 0)
        {
            if(letter != "")
                result.push_back(letter);
        }
        else
        {
            index = dg.at(0) - '0';
            for(int i=0;i<ch[index].size();i++)
            {
                dfs(dg.substr(1),letter+ch[index].at(i));
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        string letter;
        dfs(digits,letter);
        return result;
    }
};
