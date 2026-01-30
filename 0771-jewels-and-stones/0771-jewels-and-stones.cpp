class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> result;
        for(int i=0;i<jewels.length();i++){
            result.insert(jewels[i]);
        }
        int count=0;
        for(int i=0;i<stones.length();i++){
            if(result.count(stones[i])){
                count++;
            }
        }
        return count;
    }
};