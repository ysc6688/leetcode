/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        cur = 0;
        dfs(nestedList,vec);
    }

    int next() {
        int index = cur;
        ++ cur;
        return vec[index];
    }

    bool hasNext() {
        return cur == vec.size() ? false : true;
    }
private:
    vector<int> vec;
    int cur;
    void dfs(vector<NestedInteger> &nestedList, vector<int> &vec)
    {
        int size = nestedList.size();
        for(int i = 0; i < size; ++ i)
        {
            if(nestedList[i].isInteger())
                vec.push_back(nestedList[i].getInteger());
            else
                dfs(nestedList[i].getList(),vec);
        }
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
