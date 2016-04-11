class MedianFinder {
public:

    MedianFinder() {
        flag = 0;
    }

    // Adds a number into the data structure.
    void addNum(int num) {
        m.insert(num);
        if(m.size() == 1) {
            it = m.begin();
            flag = 0;
            return ;
        }
        if(num >= *it) ++ flag;
        if(num < *it) -- flag;
        if(flag == 2) {
            ++ it;
            flag = 0;
            return ;
        }
        if(flag == -2) {
            -- it;
            flag = 0;
            return ;
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int size = m.size();
        if( !size ) return 0;
        if(size & 0x1) {
            return *it;
        }
        else {
            set<int>::iterator i = it;
            int n1 = *i;
            int n2;
            if(flag == 1) n2 = *(++ i);
            else n2 = *(-- i);
            return 1.0 * (n1 + n2) / 2;
        }
    }
private:
    multiset<int> m;
    multiset<int>::iterator it;
    int flag;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
