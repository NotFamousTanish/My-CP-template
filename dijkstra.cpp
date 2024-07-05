vector <int> dijkstra(int V, vector<vector<int>> adj[], int source){
    vector<int>distanceOfSourceFrom(V, INT_MAX);
    set<pair<int,int>>st;
    
    distanceOfSourceFrom[source] = 0;
    st.insert({0, source});
    
    while(st.size()){
        auto tempPair = *st.begin();
        st.erase(st.begin());
        int currentNode = tempPair.second;
        int optimalDistanceOfCurrentNodeFromSourceNode = tempPair.first;
        
        for(auto it: adj[currentNode]){
            int thisNode = it[0];
            int distanceOfThisNodeFromCurrentNode = it[1];
            
            int optimalDistance = optimalDistanceOfCurrentNodeFromSourceNode + distanceOfThisNodeFromCurrentNode;
            if(distanceOfSourceFrom[thisNode] > optimalDistance){
                distanceOfSourceFrom[thisNode] = optimalDistance;
                if(st.find({distanceOfSourceFrom[thisNode], thisNode}) != st.end()){
                    st.erase(st.find({distanceOfSourceFrom[thisNode], thisNode}));
                }
                st.insert({optimalDistance, thisNode});
            }
        }
    }
    
    return distanceOfSourceFrom;
}
