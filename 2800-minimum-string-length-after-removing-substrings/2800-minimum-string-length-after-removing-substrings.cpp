class Solution {
public:
    int minLength(string s) {

        // ab interviewer o(1) space complexity ya mtlb inplace solution maangskta
        //which is also o(n) in time complexity

        //toh ham kya do pointer lenge i aur j
        //jaise hi i pe A/C and j pe B/D aayega mai i-- aur j++ karunga
        //aur agr aisa nahi hai toh s[i] pe s[j] daaldunga
        // aur i negative bhi soskta puraane operations se toh usko phle hi handle krlenge 
        

        int i=0; 
        int j=1;

        int n=s.size();

        while(j<n)
        {
            //ab starting mei negative check krna padega 
            //kyuki purane operation se syd i -1 hogaya ho
            if(i<0)
            {
                i++;
                s[i]=s[j];
            }
            else if((s[i] == 'A' && s[j] == 'B') ||
              (s[i] == 'C' && s[j] == 'D'))
              {
                i--;
              }
            
            else
            {
                i++;
                s[i]=s[j];
            }
              j++;
        }

        return i+1;
    }
};