class Solution {
public:
    int bestClosingTime(string c) {
        int max=0, curr=0, best=0;
        for(int i=0; i<c.length(); ++i){
            curr += (c[i]=='Y')?1:-1;
            if (curr>max){
                max=curr;
                best=i+1;
            }
        }
        return best;
    }
};