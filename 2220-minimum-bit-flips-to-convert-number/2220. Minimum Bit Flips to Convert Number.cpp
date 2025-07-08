class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count_of_flips=0;
        while(start || goal){
            if ( (!(start&1) && (goal&1)) || ((start&1) && !(goal&1)) ) count_of_flips++;
            start>>=1;goal>>=1;
        }
        return count_of_flips;
    }
};