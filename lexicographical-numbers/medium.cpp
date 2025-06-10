class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> output;

        function<void(int)> DFS = [&](int temp) {
            if (temp > n)
                return;
            
            output.push_back(temp);
            DFS(temp*10);
            if (temp % 10 != 9)
                DFS(temp + 1);
        };

        DFS(1);

        return output;
    }
};
