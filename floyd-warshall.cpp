class Solution {
  public:
	void shortest_distance(vector<vector<int>>&distance){
	    int n = distance.size();
	    for(int k = 0; k < n; k++){
	        for(int i = 0; i < n; i++){
	            for(int j = 0; j < n; j++){
	                long long cdis = (distance[i][j] == -1) ? INT_MAX : distance[i][j];
	                long long optimalDistance = distance[i][k] + distance[k][j];
	                if(optimalDistance < cdis && distance[i][k] != -1 && distance[k][j] != -1) {
	                    distance[i][j] = optimalDistance;
	                }
	            }
	        }
	    }
	}
};
