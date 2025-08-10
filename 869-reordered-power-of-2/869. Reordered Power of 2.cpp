class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string>temp;
        for (int i=0; i<34; i++){
            string power_of_two = to_string(1LL<<i); sort(power_of_two.begin(), power_of_two.end());
            temp.insert(power_of_two);
        }
        // for (auto &i:temp) cout<<i<<","; cout<<endl;
        string ip = to_string(n); sort(ip.begin(), ip.end());
        return temp.count(ip);
    }
};