//given that int is defined as long long
int mod(int x, int m){
    return (x%m + m)%m;
}
int modMul(int a, int b, int m){
    return mod(mod(a,m)*mod(b,m),m);
}
int modAdd(int a, int b, int m){
    return mod(mod(a,m)+mod(b,m),m);
}
