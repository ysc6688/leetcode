class Solution {
public:
string preProcess(string s) {
  int n = s.length();
  if (n == 0) return "^$";
  string ret = "^";
  for (int i = 0; i < n; i++)
    ret += "#" + s.substr(i, 1);
 
  ret += "#$";
  return ret;
}
 
int longestPalindrome(string s) {
  string T = preProcess(s);
  int n = T.length();
  int *P = new int[n];
  int C = 0, R = 0;
  for (int i = 1; i < n-1; i++) {
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)
    
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
    
    // Attempt to expand palindrome centered at i
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
      P[i]++;
 
    // If palindrome centered at i expand past R,
    // adjust center based on expanded palindrome.
    if (i + P[i] > R) {
      C = i;
      R = i + P[i];
    }
  }
 
  // Find the maximum element in P.
  int maxLen = 1;
  for (int i = n - 2; i >= 1; i--) {
    if (P[i] == i - 1) {
      maxLen = i - 1;
      break;
    }
  }
  delete[] P;
  
  return maxLen;
}
    string shortestPalindrome(string s) {
        int size = s.size();
        if( size < 2 ) return s;
        
        string rv = s;
        reverse(rv.begin(),rv.end());
        
        int l = longestPalindrome(s);
        
        return rv.substr(0,size - l) + s;
    }
};
