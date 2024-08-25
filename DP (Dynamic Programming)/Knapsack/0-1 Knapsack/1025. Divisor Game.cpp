

// https://leetcode.com/problems/divisor-game/discuss/1663853/C%2B%2B-two-easy-solutions-or-one-liner-mathematical-and-bruteforce-dp-with-explanation

class Solution {
public:
    bool divisorGame(int n) {
        return n%2==0 ? true : false;
    }
};