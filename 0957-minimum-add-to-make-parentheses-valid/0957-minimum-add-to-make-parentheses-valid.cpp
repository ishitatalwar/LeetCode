class Solution {
public:
    // using counter method 
    int minAddToMakeValid(string s) {
        int opening = 0; 
        int overbalanced_closing = 0;
        for(int i = 0;s[i]!='\0'; ++i){
            if(s[i]=='(') opening++;
            else if(opening>0) opening--;
            else overbalanced_closing++;
        }
        return opening + overbalanced_closing;
        
    }
};