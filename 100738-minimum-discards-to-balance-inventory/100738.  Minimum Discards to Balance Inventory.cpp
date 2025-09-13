class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int discard_count=0, n=arrivals.size();
        vector<bool>discarded(n+1,0);
        map<int,int>mp;
        for(int i=1; i<=n; i++){
            int outside_the_window = max(1, i-w+1) - 1; // i.e the prev
            // cout<< "for i="<<i <<", Outside the window = "<<outside_the_window<<endl;
            if (outside_the_window>=1 && mp.find(arrivals[outside_the_window-1]) != mp.end() && !discarded[outside_the_window]){
                // cout<<"Removing the id="<<outside_the_window<<endl;
                mp[arrivals[outside_the_window-1]]--;
                if (mp[arrivals[outside_the_window-1]] == 0) mp.erase(arrivals[outside_the_window-1]);
            }
            // int size = mp.find(arrivals[i-1])!=mp.end() ? mp.find(arrivals[i-1])->second: 0;
            if(mp[arrivals[i-1]]+1 > m){
                // cout<<"Now discarding the index i="<<i<<endl;
                discarded[i]=true;
                discard_count++;
            }else{
                mp[arrivals[i-1]]++;
            }
        }
        return discard_count;
    }
};