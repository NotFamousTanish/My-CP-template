const int MOD = 1e9+7;
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
int invMod(int a, int m){
    //(1/a)%m = a^(m-2)
    return modPow(a, m-2, m);
}
int modDiv(int a, int b, int m){
    return modMul(a, invMod(b,m), m);
}
 
const int factN = 2e6+5;
int fact[factN];
void preFact(int m){
    fact[0] = 1;
    for(int i = 1; i<=factN; i++){
        fact[i] = modMul(fact[i-1], i, m);
    }
}
 
int ncr(int n, int r, int m){
    int den = modMul(fact[r], fact[n-r], MOD);
    int num = fact[n];
    int ans = modDiv(num, den, m);
    return ans;
}
