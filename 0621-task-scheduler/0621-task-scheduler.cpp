class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int p = tasks.size();

        if(n==0){
            return p;
        }
        int counter[26] = {0};
        for (char &ch : tasks){
            counter[ch - 'A']++;
        }
        sort(begin(counter), end(counter));
        int chunks = counter[25] - 1;
        int idleS = chunks * n;
        for(int i = 24; i>=0; i--){
            idleS -= min(chunks, counter[i]);
        }
        // turnary operation 
        return idleS < 0 ? p : p + idleS;
    }
};