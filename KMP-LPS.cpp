void getLps(string &pattern, vector<int>&lps) {
  int i = 1, len = 0;
  lps[0] = 0;
  int n = pattern.length();

  while (i < n) {
    if (pattern[i] == pattern[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0) {
        len = lps[len - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }
}



vector <int> search(string pat, string txt) {
  int n = pat.length();
  vector<int>lps(n, 0);
  getLps(pat, lps);
  vector<int>ans;
  int i = 0, j = 0;
  while (i < txt.length()) {
    if (txt[i] == pat[j]) {
      i++, j++;
      if (j == pat.length()) {
        ans.push_back(i - j + 1);
        j = lps[j - 1];
      }
    } else {
      if (j != 0) {
        j = lps[j - 1];
      } else {
        i++;
      }
    }
  }
  return ans;
}
