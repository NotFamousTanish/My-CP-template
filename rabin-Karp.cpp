    string text, pattern;
    cin >> text >> pattern;
    int prime = 31;
    int desiredHashValue = 0, pow = 1;
    for (int i = 0; i < pattern.length(); i++) {
        desiredHashValue = (desiredHashValue + (pattern[i] - 'a' + 1) * pow) % MOD;
        pow = (pow * 31) % MOD;
    }
    int m = (int)text.length();
    int powers[m];
    pow = 1;
    for (int i = 0; i < text.length(); i++) {
        powers[i] = pow;
        pow = (pow * 31) % MOD;
    }
    int prefixHash[m];
    for (int i = 0; i < text.length(); i++) {
        int pp = (i == 0) ? 0 : prefixHash[i - 1];
        int curr = (pp + ((text[i] - 'a' + 1) * powers[i])) % MOD;
        prefixHash[i] = curr;
    }
    vector<int>ans;
    int sp = 0, ep = pattern.length() - 1;
    while (ep < text.length()) {
        int currentWindowPrefix = prefixHash[ep];
        if (sp > 0) {
            currentWindowPrefix = currentWindowPrefix - prefixHash[sp - 1];
            if (currentWindowPrefix < 0)currentWindowPrefix += MOD;
        }
        int requiredHash = (desiredHashValue * powers[sp]) % MOD;
        if (currentWindowPrefix == requiredHash) {
            ans.push_back(sp + 1);
        }
        sp++, ep++;
    }
    return ans;
