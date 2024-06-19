class heap {
public:
	vector<int>heapi;
	int size = 0;
	void init(int n) {
		int sz = (4 * n) + 1;
		heapi.resize(sz);
		size = 1;
		heapi[0] = -1;
	}

	void insert(int _val) {
		int index = size;
		size = size + 1;
		heapi[index] = _val;
		int parentIndex = index / 2;
		while (index > 1) {
			parentIndex = index / 2;
			if (heapi[parentIndex] < heapi[index]) {
				swap(heapi[parentIndex], heapi[index]);
				index = parentIndex;
			} else {
				return;
			}
		}
	}

	vector<int> getMaxHeap() {
		vector<int>ans;
		for (int i = 1; i < size; i++) {
			ans.push_back(heapi[i]);
		}
		return ans;
	}
};
