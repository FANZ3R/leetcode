
//toh trie mei mai prefix store karne ke lie 26 character ka trie structure toh bhejunga hi
//saath hi saath har node pe count bhi bhje dunga
//jo ki batayega us node pe khatam hone wale prefix ka count

struct trieNode{

    int countP=0;//is node pe klhtm hone wale prefix ka count batayega ye
    trieNode* children[26];

};




class Solution {
public:
//dekh jab bhi prefix ka scene ya question aaye toh dimaage me hamesa
//tire toh aana hi chaiye tere'
//theeke
//ab dekh muje har word ke har possible prefix ka score nikaalna hai
//toh muje prefix store karke rakhne padenge kyuki score tbhi increase hora hai jab ye kisi aur word ka prefix ho
//phle se hi toh i need to store these prefixes already

 //toh mai trie mei prefix toh store karunga hi saath hi saath mei har prefix ka count bhi store karta rahunga 
 //ki isko maine kitne baar dekha hai aise karke

    trieNode* getTrieNode()
    {
        trieNode* newNode = new trieNode();

        for(int i=0;i<26;i++)
        {
            newNode->children[i]=NULL;
        }

        newNode->countP=0;

        return newNode;
    }

    void insert(string & word,trieNode* root)
    {
        //toh mai pehle toh ek crawler banata hu jo crawl karte hue end tak jaayuega

        trieNode* crawler = root;

        for(char &ch :word)
        {
            int idx= ch-'a';
            //ab index nikaallunga kyuki maine a-z tak 0-25 indices pe aise store kiye hai character ki encodeing

            //ab check karunga pehle se hai toh ni ye character yaha pe
            if(!crawler->children[idx])
            {
                crawler->children[idx] = getTrieNode();
            }

            //aur increase uske prefix ke count ko toh anyways karunga hi
            //chahie phle se tha waha pe wo character ya nahi
            //kyuki usko firse visite kar raheie ham 

            crawler->children[idx]->countP += 1;
            
            //aur ab mai neeche traverse karunga aage toh crawler ko children pe paucha dunga
            crawler=crawler->children[idx];
        }
    }


    int score(string word, trieNode* root)
    {
        //firse ek crawler define kardeta hu crawl karne ke lie

        trieNode* crawler = root;
        int score = 0;//intitall 0 score

        //ab score calculate krne ke lie mai har character ko traverse karte hue usko find karunga trie mei
        //aur uska score jo maine phle se hi calculate kiya hua hoga us character pe end hone wale prefixes ka
        //wo apne score mei add karta rahugna

        for(char &ch: word)
        {
            int idx = ch-'a';

            score += crawler->children[idx]->countP;
            crawler=crawler->children[idx];
        }

        return score;


    }




    vector<int> sumPrefixScores(vector<string>& words) {

        //ab yaha pe aa muje sum of scores niukaalna hai har word ka
        //aur score nikaalne ke lie muje har prefix ke word ke score nikaalke sum karna hoga

        //toh phel toh prefix store kardete hai

        int n=words.size();

        trieNode* root = getTrieNode();

        for(string &word: words)
        {
            insert(word,root);
        }

        //ab mera trie bnachukaa hai toh mai apna result store karunga ab theeke

        vector<int> result(n,0);
        //isme kya result[i] = sum of scores of prefixes of word[i]

        for(int i=0;i<n;i++)
        {
            result[i] = score(words[i],root);

        }

        return result;

        
    }
};