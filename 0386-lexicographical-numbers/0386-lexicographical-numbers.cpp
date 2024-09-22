class Solution {
public:

    void solve(int x,int num ,vector<int> & result)
    {
        if(x > num)
        return ;

        result.push_back(x);

        //ab mai apend karunga recursively
        //kyuki 1 pe 0 appendf karenge 10 fir 100 bhi hoskta agr hamara upper bound >100 hai toh

        for(int append=0; append<=9;append++)
        {
            int newnum = x*10+append;
            solve(newnum,num,result);
        }

    }

    vector<int> lexicalOrder(int n) {
        // isko recursively solve karskte number append krke
        //dekh 1 se 9 tak hi loop chaluanga baaki mera dfs recursive type ka code handle karlega
        //muje append karna baaki fir number 10,100,11,110 aise karkte wale phle aayenge

        vector<int> result;

        int num=1;

        for(int i=1;i<=9;i++)
        {
            
            solve(i,n,result);
        }
        

        return result;
    }
};