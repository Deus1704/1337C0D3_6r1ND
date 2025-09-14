class Solution {
public:
    int nthUglyNumber(int n) {
        if (n<=6) return n; 
        vector<int>pre_compute(n+1,0);
        int ptr1=0, ptr2=0, ptr3=0; pre_compute[0]=1;
        for(int ptr = 1; ptr<=n; ptr++){
            int ug1 = pre_compute[ptr1]*2;
            int ug2 = pre_compute[ptr2]*3;
            int ug3 = pre_compute[ptr3]*5;
            pre_compute[ptr] = min({ug1, ug2, ug3});
            if (pre_compute[ptr] == ug1) ptr1++;
            if (pre_compute[ptr] == ug2) ptr2++;
            if (pre_compute[ptr] == ug3) ptr3++;
        }
        return pre_compute[n-1];
    }
};