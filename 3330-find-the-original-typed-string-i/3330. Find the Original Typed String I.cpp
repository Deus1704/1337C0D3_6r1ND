class Solution {
public:
    int possibleStringCount(string word) {
        int ans=0, n = word.size(), pos=0;
        while (pos<n){
            int start=pos;
            while (pos>0 && word[pos]==word[pos-1]) pos++;
            // cout<<"start="<<start<<", and pos="<<pos<<endl;
            if (start!=pos){
                ans+=pos-start;
            }
            pos++;
        }
        return ans+1;
    }
};