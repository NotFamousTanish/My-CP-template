void bellmanFord(int source, vector<vector<int>>&adj, int n) {
	// HERE THE ADJ 2D VECTOR IS NOT THE SAME AS
	// RATHER IT'S OF FORM: {U, V, W}: {SOURCE, DESTINATION, EDGE WEIGHT}
	vector<int>distanceFromSouceOf(n, INT_MAX);
	distanceFromSouceOf[source] = 0;
	// RELAX NODES N-1 TIMES
	for (int i = 1; i <= n - 1; i++) {
		for (auto it : adj) {
			int u = it[0], v = it[1], w = it[2];

			if (distanceFromSouceOf[u] != INT_MAX && distanceFromSouceOf[v] > distanceFromSouceOf[u] + w) {
				distanceFromSouceOf[v] = distanceFromSouceOf[u] + w;
			}
		}
	}
	for (auto it : adj) {
		int u = it[0], v = it[1], w = it[2];
		if (distanceFromSouceOf[u] != INT_MAX && distanceFromSouceOf[v] > distanceFromSouceOf[u] + w) {
			// IT MEANS THAT NODE IS RELAXED ONE MORE TIME SO THERE IS THE PRESENCE OF NEGATIVE CYCLE
		}
	}
}
