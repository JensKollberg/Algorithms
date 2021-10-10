//0 Indexed!!!
vector<int> build_kmp(string s) {
	vector<int> f(s.size());
	int fp = f[0] = -1;
	for (int i = 1; i < s.size(); ++i) {
		while (~fp && s[fp + 1] != s[i]) fp = f[fp];
		if (s[fp + 1] == s[i]) ++fp;
		f[i] = fp;
	}
	return f;
}

//1 Indexed!!!
vector<int> build_kmp(string s) { 
	vector<int> f(s.size());
	for (int i = 1; i < s.size(); i++) {
		int fp = f[i - 1];
		while (fp > 0 && s[i] != s[fp])
			fp = f[fp - 1];
		if (s[i] == s[fp])
			fp++;
		f[i] = fp;
	}
	return f;
}