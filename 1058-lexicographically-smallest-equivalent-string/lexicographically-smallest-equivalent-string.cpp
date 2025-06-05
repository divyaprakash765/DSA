class Solution {
public:
int find(vector<int>& parent,int x){

    return parent[x] = (parent[x] == x) ? x : find(parent,parent[x]);
}

 bool Union(vector<int>& parent,vector<int>& rank,int a,int b){

     a = find(parent,a);
     b = find(parent,b);
     if(a == b) return true;
     if (a < b)
            parent[b] = a;
        else
            parent[a] = b;

    return false;

 }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
        }
        vector<int> rank(26);

        for(int i=0;i<s1.size();i++){
            Union(parent,rank,s1[i]-'a',s2[i]-'a');
        }
        string ans = "";
        for(char ch : baseStr){
            char smallest = find(parent,ch-'a') + 'a';
            ans += smallest;
        }
        return ans;
    }
};