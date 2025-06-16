class Solution {
public:
    int getmaxarea(vector<int>&ht){
        int n=ht.size(), ans=0;
        vector<int>l(n,0),r(n,0);
        stack<int>s;
        for (int i=0; i<n; i++){
            while (!s.empty() && ht[s.top()]>=ht[i]) s.pop();
            if (s.empty()) l[i]=0;
            else l[i]=s.top()+1;
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i=n-1; i>=0; i--){
            while (!s.empty() && ht[s.top()]>=ht[i]) s.pop();
            if (s.empty()) r[i]=n-1;
            else r[i]=s.top()-1;
            s.push(i);
            ans = max(ans, (r[i]-l[i]+1)*ht[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size(), ans=0;
        vector<int>tp(m,0);
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (matrix[i][j]=='1'){
                    tp[j]++;
                }else{
                    tp[j]=0;
                }
            }
            // cout<<"Now working with tp=";for(auto &i:tp)cout<<i<<","; cout<<endl;
            ans = max(ans, getmaxarea(tp));
            // cout<<"getmaxarea="<<getmaxarea(tp)<<endl;
        }
        return ans;
    }
};