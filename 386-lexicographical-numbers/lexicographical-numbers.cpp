class Solution {
public:
   vector<int> ans;

   void f(int i,int n){
    if(i > n) return;

   if(i > 0) ans.push_back(i);

   if(i == 0){
    for(int j=1;j<=9;j++){
        f(i*10+j,n);
    }
   } else{
    for(int j=0;j<=9;j++){
        f(i*10+j,n);
    }
   }

   }

    vector<int> lexicalOrder(int n) {
        f(0,n);
        return ans;
    }
};