#include<bits/stdc++.h>
using namespace std;

class node{
    public: 
        int val;
        node *next,*prev;
        node(int v){
            val=v;
        }
};

class Optimal
{
    public:
        int cap;
        Optimal(int capacity)
        {
            cap=capacity;
        }
        bool search(int key, vector<int>& fr)
        {
            for (int i = 0; i < fr.size(); i++)
                if (fr[i] == key)
                    return true;
            return false;
        }
        
        int predict(vector<int>& pg, vector<int>& fr, int index)
        {
            int pn=pg.size();
            int res = -1, farthest = index;
            for (int i = 0; i < fr.size(); i++) {
                int j;
                for (j = index; j < pn; j++) {
                    if (fr[i] == pg[j]) {
                        if (j > farthest) {
                            farthest = j;
                            res = i;
                        }
                        break;
                    }
                }
                if (j == pn)
                    return i;
            }
            return (res == -1) ? 0 : res;
        }
 
        void optimalPage(vector<int>& pg)
        {
            int pn=pg.size();
            vector<int> fr;
            int hit = 0;
            for (int i = 0; i < pn; i++) {
                if (search(pg[i], fr)) {
                    hit++;
                    continue;
                }
                if (fr.size() < cap)
                    fr.push_back(pg[i]);
                else {
                    int j = predict(pg, fr, i + 1);
                    fr[j] = pg[i];
                }
                cout<<"Page numbers in main memory after "<<(i+1)<<" page request: ";
                for(int j=0;j<fr.size();j++)
                    cout<<fr[j]<<" ";
                cout<<"\n";
            }
            cout << "No. of hits = " << hit << endl;
            cout << "No. of misses = " << pn - hit << endl;
        }

};

int main()
{
    int capacity, n;
    cout<<"Enter the maximum number of frames possible: ";
    cin>>capacity;
    Optimal obj(capacity);

    cout<<"Enter the number of pages involved: ";
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    obj.optimalPage(v);
}