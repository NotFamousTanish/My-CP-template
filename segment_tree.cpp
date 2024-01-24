//left child index  = 2*x + 1
//right child index = 2*x + 2
//x is the index of parent element
//mid element = (l+r)/2;
//left segment = l to mid-1
//right segment = mid to r-1
//leaf nodes are the parent array elements
//so no(leaf nodes) = size of parent array
//range can be of three condns
//1. no overlaps
//2. overlaps
//3. partial overlaps
//to make segtree-> o(n)
//to query-> o(log n)

int a[(int)1e5], seg[4* (int)1e5];

void build(int ind, int low, int high){
    if(low == high){
        seg[ind] = a[low];
        return;
    }
    int mid = (low+high)/2;
    build(2*ind +1, low, mid);
    build(2*ind +2, mid+1, high);

    //whaterver you want to do
    seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
}

int query(int ind, int low, int high, int l, int r){
    // l and r are taken here to check if my range overlaps or not or is it completely outside
    if(low >= l && high <= r){
        return seg[ind];
    }

    if(high < l || low > r){
        // answer does not lies
        // return as required
        return INT_MIN;
    }
    int left = query(2*ind+1, low, mid, l , r);
    int right = query(2*ind+2, mid+1, high, l , r);

    //return as required here
    return max(left, right);
}






