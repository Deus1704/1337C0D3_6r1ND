// class Solution {
// public:
//     int secondsToRemoveOccurrences(string s) {
//         int timer=0, n=s.size(); bool cont = true;
//         string reversed_s = s, sorted_s=s; 
//         reverse(reversed_s.begin(), reversed_s.end());
//         sort(sorted_s.begin(), sorted_s.end());
//         if (reversed_s == sorted_s) return 0;
//         while (cont){
//             for (int i=0; i<n-1; i++){
//                 if (s[i]=='0' && s[i+1]=='1'){
//                     s[i]= '1'; s[i+1] = '0'; i++;
//                 }
//             }
//             for (int i=0; i<n-1; i++) {
//                 if (s[i]=='0' && s[i+1]=='1') { cont = true; break;}
//                 else cont = false;
//             }
//             timer++;
//         }
//         return timer;
//     }
// };

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int timer=0, n=s.size(), zero_count = 0;
        for (int i=0; i<n; i++){
            if (s[i]=='0') zero_count++;
            else if (zero_count>0){
                timer = max(timer+1, zero_count);
            }
        }
        return timer;
    }
};