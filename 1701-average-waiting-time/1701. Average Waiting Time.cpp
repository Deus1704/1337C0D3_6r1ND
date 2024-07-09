class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long numOfCustomers = customers.size();
        long long waitingTime = 0;
        long long currentTime = 0;
        long long finishingTime = 0;
        currentTime = customers[0][0];
        for (auto cust : customers){
            if (cust[0]>currentTime){
                currentTime = cust[0];
            }
            finishingTime = currentTime + cust[1];
            waitingTime += finishingTime - cust[0];
            currentTime = finishingTime;
        }        
        return (long double)waitingTime/numOfCustomers;
    }
};
