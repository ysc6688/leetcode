class Solution {
     bool hashMap[1024*1024];
public:
    vector<string> findRepeatedDnaSequences(string s) {
        std::vector<std::string> rel;
     if (s.length() <= 10) {
         return rel;
     }
 
     // map char to code
     unsigned char convert[26];
     convert[0] = 0; // 'A' - 'A'  00
     convert[2] = 1; // 'C' - 'A'  01
     convert[6] = 2; // 'G' - 'A'  10
     convert[19] = 3; // 'T' - 'A' 11
 
     // initial process
     // as ten length string
     memset(hashMap, false, sizeof(hashMap));
 
     int hashValue = 0;
 
     for (int pos = 0; pos < 10; ++pos) {
         hashValue <<= 2;
         hashValue |= convert[s[pos] - 'A'];
     }
 
      hashMap[hashValue] = true;
 
     std::unordered_set<int> strHashValue;
 
     // 
     for (int pos = 10; pos < s.length(); ++pos) {
         hashValue <<= 2;
         hashValue |= convert[s[pos] - 'A'];
         hashValue &= ~(0x300000);
         
         if (hashMap[hashValue]) {
             if (strHashValue.find(hashValue) == strHashValue.end()) {
                 rel.push_back(s.substr(pos - 9, 10));
                 strHashValue.insert(hashValue);
             }
         } else {
             hashMap[hashValue] = true;
         }
     }
 
     return rel; 

    }
};
