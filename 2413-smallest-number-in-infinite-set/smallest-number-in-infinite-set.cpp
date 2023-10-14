class SmallestInfiniteSet {
public:
    set<int>pq;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            pq.insert(i);
        }
    }
    
    int popSmallest() {
        if(pq.size()==0)return 0;
        int k=*pq.begin();
        pq.erase(pq.begin());
        return k;
    }
    
    void addBack(int num) {
        pq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */