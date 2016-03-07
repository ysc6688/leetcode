class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int a = std::max(A,E);
        int b = std::min(C,G);
        
        int c = std::max(B,F);
        int d = std::min(D,H);
        
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        
        int share = 0;
        if(a < b && c < d) share = (b - a) * (d - c);
        
        return area1 + area2 - share;
    }
};
