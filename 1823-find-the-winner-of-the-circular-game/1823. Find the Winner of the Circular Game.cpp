class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> lose;
        for (auto i=1; i<=n; i++) lose.push_back(i);
        int start = 0;
        while (lose.size()>1){
            int siz = lose.size();
            int next = (start + k-1)%siz;
            lose.erase(lose.begin()+ next);
            start = next; 
        }
        return lose[0];
    }
};