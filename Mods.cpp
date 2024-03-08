// int should be defined as long long
int mod(int x, int m){
    return (x%m + m)%m;
}
int modMul(int a, int b, int m) {
     a = a % m;
     b = b % m;
     return ((a * b) % m);
}
int modAdd(int a, int b, int m) {
     a %= m;
     b %= m;
     return ((a + b) % m);
}
int modSub(int a, int b, int m) {
     a %= m;
     b %= m;
     return ((a - b + m) % m);
}
int invMod(int a, int m){
    //(1/a)%m = a^(m-2)
    return powl(a, m-2);
}
int modPow(int x, int y, int m){
    if(y==0){
        return 1;
    }
    int ans1 = modPow(x,y/2,m);
    int ans2 = ans1;
    if(y&1){
        return modMul(ans1, modMul(ans2,x,m),m);
    }else{
        return modMul(ans1, ans2, m);
    }
}
