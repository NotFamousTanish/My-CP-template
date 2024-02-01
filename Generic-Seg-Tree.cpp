struct node{
    int sum;
    node(){
        sum = 0;
    }
};

node t[4*200200];

node merge(node a, node b){
    node ans;
    ans.sum = a.sum+b.sum;
    return ans;
}

// i -> current index;
// [l,r] -> range represented by current node;
// pos -> the position that is to be updated
// [lo, hi] -> range that is to be updated
// val -> the value that the pos has to be updated with

void build(int i, int l, int r){
    if(l == r){
        t[i].sum = 0;
        return;
    }

    int mid = (l+r)/2;
    build(2*i, l, mid);
    build((2*i)+1, mid+1, r);
    t[i] = merge(t[2*i], t[(2*i)+1]);
}

void update(int i, int l, int r, int pos, int val){
    //out of the range
    if(pos < l || pos > r){
        return;
    }

    //reached the node
    if(l == r){
        t[i].sum += val;
        return;
    }

    int mid = (l+r)/2;
    update(2*i, l, mid, pos, val);
    update((2*i)+1, mid+1, r, pos, val);

    t[i] = merge(t[2*i], t[(2*i)+1]);
}

node query(int i, int l, int r, int lo, int hi){
    //no intersection of the segments
    if(lo > r || hi < l){
        return node();
    }

    if(l >= lo && r <= hi){
        return t[i];
    }
    int mid = (l+r)/2;

    return merge(query(2*i, l, mid, lo, hi) , query(2*i+1, mid+1, r, lo, hi));
}
