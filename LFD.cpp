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

class LFD{
    public:
        vector<int> f;
        int cap; 
        vector<vector<int>> v;
        LFD(int capacity)
        {
            cap=capacity;
            vector<int> temp;
        }
        LFD(int capacity, int max_p)
        {
            cap=capacity;
            vector<int> temp;
        }
        void insert(int page_no)
        {
            f.push_back(page_no);
            cap--;
        }
        void add_to_v(int val, int pos)
        {
            int flag=0;
            for(int i=0;i<v.size();i++)
            {
                if(v[i].size()==0)
                    continue;
                if(v[i][0]==val)
                {
                    v[i].push_back(pos);
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                vector<int> temp;
                temp.push_back(val);
                temp.push_back(pos);
                v.push_back(temp);
            }
        }
        void Delete(int curr_index)
        {
            int maximum=INT_MIN;
            int element=0,page_no=0;
            int index_i=0,index_j=0;
            for(int i=0;i<f.size();i++)
            {
                int local_mini=0,flag=0,index=0;
                for(int j=0;j<v.size();j++)
                {
                    if(v[j].size()==0)
                        continue;
                    if(f[i]==v[j][0])
                    {
                        int k=1;
                        while(k<v[j].size() && v[j][k]<curr_index)
                            k++;
                        if(k<v[j].size())
                        {
                            flag=1;
                            local_mini=v[j][k];
                            element=f[i];
                        }
                        break;
                    }
                }
                if(flag==0)
                {
                    page_no=f[i];
                    break;
                }
                if(maximum<local_mini)
                {
                    maximum=local_mini;
                    page_no=element;
                }
            }
            vector<int>::iterator iter=v[0].begin();
            for(auto iter=f.begin();iter!=f.end();iter++)
            {
                if(*iter==page_no)
                {
                    f.erase(iter);
                    break;
                }

            }
            cap++;
        }
        void put(int page_no, int position)
        {
            int present=-1;
            for(int i=0;i<f.size();i++)
            {
                if(f[i]==page_no)
                {
                    present=i;
                    break;
                }
            }
            if(present!=-1)
                return;
            if(cap==0)
                Delete(position);
            
            insert(page_no);
        }
        void print_pages()
        {
            for(int i=0;i<f.size();i++)
                cout<<f[i]<<" ";
            cout<<"\n";
        }

};

int main()
{
    int capacity, n;
    cout<<"Enter the maximum number of frames possible: ";
    cin>>capacity;
    LFD obj(2,50);

    cout<<"Enter the number of pages involved: ";
    cin>>n;
    
    vector<int> v(10);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    for(int i=0;i<10;i++)
        obj.add_to_v(v[i],i);
    for(int i=0;i<n;i++)
    {
        obj.put(v[i],i);
        cout<<"After "<<i<<" pages invoked: ";
        obj.print_pages();
    }
}