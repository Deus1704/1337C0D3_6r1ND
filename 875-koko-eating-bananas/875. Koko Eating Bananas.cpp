class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int k=1;
        int maxy=INT_MIN;
        for (auto &i:piles){
            maxy = max(maxy,i);
        }
        if (piles.size() == h) return maxy;
        int l=1,r=maxy;
        while (l<=r){
            int mid = (l+r)/2;
            long long hrs=0;
            for (auto &i:piles){
                hrs+= i>=mid? ((i/mid)+1*(i%mid!=0)):1;
            }
            cout<<"The hours for mid ="<<mid<<" is ="<<hrs<<endl;
            if (hrs>h){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return l;
    }
};
