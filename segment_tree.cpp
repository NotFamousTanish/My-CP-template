struct segtree{
    int size;
    vector<int>sums;
    void init(int n){
        size = 1;
        while(size <= n){
            size*=2;
        }
        sums.assign(2 * size , 0ll);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx - lx  == 1){
            sums[x] = v;
            return;
        }
        int mid = (lx+rx)/2;
        if(i < mid){
            set(i, v, 2 * x + 1, lx, mid);
        }else{
            set(i, v, 2 * x + 2, mid, rx);
        }

        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }

    void set(int i, int v){
        set(i , v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx){
        if(lx >= r || l >= rx){
            return 0;
        }
        if(lx >= l && rx <= r){
            return sums[x];
        }
        int mid = (lx + rx)/2;

        int sl = sum(l, r, 2 * x + 1, lx, mid);
        int sr = sum(l, r, 2 * x + 2, mid, rx);

        return sl + sr;
    }

    long long sum(int l , int r){
        return sum(l, r, 0, 0, size);
    }
};
