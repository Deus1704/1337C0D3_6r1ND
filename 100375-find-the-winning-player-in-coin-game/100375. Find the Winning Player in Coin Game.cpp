class Solution {
public:
    string losingPlayer(int x, int y) {
        int m75 = x;
        int m10 = y/4;
        int minMoves = min(m75,m10);
        if (minMoves%2) return "Alice";
        else return "Bob";
    }
};