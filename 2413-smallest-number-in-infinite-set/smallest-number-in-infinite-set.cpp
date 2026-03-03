class SmallestInfiniteSet {
    set<int> st;
    int start;
public:
    SmallestInfiniteSet() {
        start = 1;
    }
    
    int popSmallest() {
        if(st.empty()) {
            start++;
            return start-1;
        } else {
            int x = *st.begin();
            st.erase(st.begin());
            return x;
        }
    }
    
    void addBack(int num) {
        if(start > num) st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */