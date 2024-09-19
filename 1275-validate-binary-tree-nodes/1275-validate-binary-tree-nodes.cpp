class Solution {
public:

    // dekh muje binary tree valid ceck krne ke lie 3 property check karni hai
    //phle har child ka ek hi parent hoga
    //dusra root sirf ek hoga aur uska parent wo khud hoga
    //teesra poore tree mei ek hi component hoga at the end

    //toh pehle mai saare nodes ko alg alg componets maanunga
    //fir agr valid hai mtlb ki uska parent phle se wo khud hi parent hai starting mei toh sbke parent wo khud hi honge na
    //toh check karunga union krskta parent aur uske left child ya rootchild ke beech mei
    //agr union valid hoga toh components -- karta jaunga
    //aur at the end sirf ek component hona chaiye

    int components;
    vector<int> parent;

    int find(int x)
    {
        if(parent[x]==x)
        return x;

        return parent[x]=find(parent[x]);
    }

    bool Union(int p,int c)//p=parent,c=child
    {
        if(find(c)!=c)//agr iska parent koi aur hai uske alawa starting me hi mtlb do parent hogye fir toh false
        return false;

        //aur ek aur check jab root ko ham child na banade kisi aur node ka
        // ya parent ko child banade usike child ka

        if(find(p)==c)//mtlb cycle hoga fir aise mei
        return false;

        parent[c]=p;
        components--;

        return true;
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

        //iskop dsu se bana skta hu mai

        components=n;

        parent.resize(n);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }

        //ab mia har vald children pe jaaunga aur union krke check karunga ki valid hai ki nahi

        for(int i=0;i<n;i++)
        {
            int node=i;

            int lc=leftChild[i];
            int rc=rightChild[i];

            //ab compare karunga agr -1 nahi hai 
            if(lc!=-1 && Union(node,lc)==false)
                return false;
                //agr union false deta hai mtlb invalid hai union hona mtlb invalid hoga binary tree

            if(rc!=-1 && Union(node,rc)==false)
                return false;
            

        }

        //end mei check karunga ki componets ek hi bacha hai ki nahi

        return (components==1);
        
    }
};