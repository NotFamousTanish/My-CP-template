/*TIME COMPLEXITY IS: O(α(N)) where α(N) is the inverse ackermann function 
i.e you can relate it to somewhat close to O(1) complexity it is this much minimum time*/
int parent[N];
int size[N] = {0};
void make(int node){
    parent[node] = node;
    size[node] = 1;
}

int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}

void Union(int node1, int node2){
    node1 = find(node1);
    node2 = find(node2);
    if(node1 != node2){
        if(size[node1] < size[node2]){
            swap(node1, node2);
        }
        parent[node2] = node1;
        size[node1]+=size[node2];
    }
}
