class segTree {
public:
//CHECK FOR THE GIVEN POINTS
//1. MODIFY THE BASE CASES ACCORDINGLY
//2. MODIFY THE RETURN VAL ACCORDINGLY-> UPDATE, BUILD, QUERY
//3. IN QUERY RETURN UNFAVOURABLE IN NO OVERLAPS
//4. IN QUERY RETURN FAVOURABLE IN COMPLETE OVERLAPS
    vector<int>seg;
    void init(int n) {n *= 4; seg.resize(n);}
    void build(int ind, int lo, int hi, vector<int>&arr) {
        if (lo == hi) {
            seg[ind] = arr[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        build(2 * ind + 1, lo, mid, arr);
        build(2 * ind + 2, mid + 1, hi, arr);
        seg[ind] = (seg[2 * ind + 1] ^ seg[2 * ind + 2]);
    }
    void update(int ind, int lo, int hi, int i, int val) {
        if (lo == hi) {
            seg[ind] = val;
            return;
        }
        int mid = (lo + hi) / 2;
        if (i <= mid)update(2 * ind + 1, lo, mid, i, val);
        else update(2 * ind + 2, mid + 1, hi, i, val);
        seg[ind] = (seg[2 * ind + 1] ^ seg[2 * ind + 2]);
    }
    int query(int ind, int lo, int hi, int l, int r) {
        if (r < lo || l > hi) {
            //NO OVERLAP-> RETURN UNFAVOURABLE
            return 0;
        }
        if (lo >= l && hi <= r) {
            //COMPLETE OVERLAP-> RETURN FAVOURABLE
            return seg[ind];
        }
        int mid = (lo + hi) / 2;
        int left = query(2 * ind + 1, lo, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, hi, l, r);
        return (left ^ right);
    }
};
