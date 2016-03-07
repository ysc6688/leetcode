class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        int sign1 = numerator >= 0 ? 1 : -1;
        int sign2 = denominator >= 0 ? 1 : -1;
        long long num = (long long)numerator;
        long long den = (long long)denominator;
        num = abs(num);
        den = abs(den);
        long long d = num / den;
        long long rem = num % den;
        unordered_map<long long, int> rec;
        string ans = to_string(d);
        if (sign1 * sign2 == -1 && (d > 0 || rem > 0)) ans = "-" + ans;
        if (rem == 0) return ans;
        ans = ans + ".";
        string r = "";
        for (int pos = 0; rem != 0; pos++) {
            if (rec.find(rem) != rec.end()) {
                r.insert(rec[rem], "(");
                r = r + ")";
                return ans + r;
            }
            rec[rem] = pos;
            r = r + to_string((rem * 10) / den);
            rem = (rem * 10) % den;
        }
        return ans + r;
    }
};
