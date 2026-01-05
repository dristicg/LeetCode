class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum=0;//
        int minAbs= INT_MAX;// smallest absoulet valur
        int negativeCount=0;// no. of -ve integer...

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int val = matrix[i][j];

                if(val < 0) negativeCount++;
                
                totalSum += abs(val); // abs is inbuild function it works as abd(-1)=1 
                minAbs = min(minAbs, abs(val));
            }
        }
        
        if (negativeCount % 2 == 0)
            return totalSum;
        else
            return totalSum - 2 * minAbs;
    }
};