class Solution {
public:
    int secondHighest(string s) {
        int n=s.length();
        int largest=-1;
        int seclargest=-1;

        for(char c:s){ // looping through all characters
            if(isdigit(c)){ // checking if it's char or int
                int d=c-'0'; //converting char to int
                if(d>largest){
                    seclargest=largest;
                    largest=d;
                }else if(d<largest && d>seclargest){
                    seclargest=d;
                }
            }
        }
        return seclargest;
    }
};