    vector <int> search(string pattern, string text) {
        ll dhv = 0;
        ll pow = 1;
        ll prime = 31;
        for (ll i = 0; i < pattern.length(); i++) {
            dhv = (dhv + (pattern[i] - 'a' + 1) * pow) % MOD;
            pow = (pow * prime) % MOD;
        }
        ll m = text.length();
        ll prefixHash[m], power[m];
        pow = 1;
        for (ll i = 0; i < text.length(); i++) {
            ll ph = (i == 0) ? 0 : prefixHash[i - 1];
            ll ch = (ph + (text[i] - 'a' + 1) * pow) % MOD;
            prefixHash[i] = ch;
            power[i] = pow;
            pow = (pow * prime) % MOD;
        }
        vector<int>ans;
        int i = 0, j = pattern.length() - 1;
        while (j < m) {
            ll cp = prefixHash[j];
            if (i > 0) {
                cp = cp - prefixHash[i - 1];
                if (cp < 0)cp += MOD;
            }
            ll crhv = (dhv * power[i]) % MOD;
            if (cp == crhv) {
                ans.push_back(i + 1);
            }
            i++, j++;
        }
        return ans;
    }
