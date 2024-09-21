#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;

    public:
        DisjointSet(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            size.resize(n);

            for(int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUltimateParent(int node){
            if(node == parent[node]) return node;

            parent[node] = findUltimateParent(parent[node]);

            return parent[node];
        }

        void unionByRank(int u, int v){
            int utp_u = findUltimateParent(u);
            int utp_v = findUltimateParent(v);

            if(utp_u == utp_v) return;

            if(rank[utp_u] < rank[utp_v]) parent[utp_u] = utp_v;
            else if(rank[utp_u] > rank[utp_v]) parent[utp_v] = utp_u;
            else {
                parent[utp_u] = utp_v;
                rank[utp_v]++;
            }
        }

        void unionBySize(int u, int v){
            int utp_u = findUltimateParent(u);
            int utp_v = findUltimateParent(v);

            if(utp_u == utp_v) return;

            if(size[utp_u] < size[utp_v]) {
                parent[utp_u] = utp_v;
                size[utp_v] += size[utp_u];
            }else {
                parent[utp_v] = utp_u;
                size[utp_u] += size[utp_v];
            }
        }
};

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "They have the same parent" << endl;
    else cout << "They have different parents" << endl;

    ds.unionByRank(3,7);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)) cout << "They have the same parent" << endl;
    else cout << "They have different parents" << endl;
}