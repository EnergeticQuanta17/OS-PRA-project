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

class LFU{
    public:
       map<int,int> m;
       map<int,int> frequency_map;
        int cap;
        LFU(int capacity)
        {
            cap=capacity;
        }

        void insert(int page_no)
        {
            frequency_map[page_no]++;
            m[page_no]++;
            cap--;
        }

        void Delete(int page_no)
        {
            m[page_no]--;
            cap++;
        }

        void put(int value)
        {
            if(m[value]!=0)
            {
                frequency_map[value]++;
                return;
            }
            if(cap==0)
            {
                int minimum=INT_MAX;
                int index=0;
                for(auto i: frequency_map)
                {
                    if(minimum>i.second && m[i.first]!=0)
                    {
                        minimum=i.second;
                        index=i.first;
                    }
                }
                Delete(index);
            }
            insert(value);
        }

        void print_pages()
        {
            for(auto i: m)
            {
                if(i.second>0)
                    cout<<i.first<<" ";
            }
            cout<<"\n";
        }
};

int main()
{
    int capacity, n;
    cout<<"Enter the maximum number of frames possible: ";
    cin>>capacity;
    LFU obj(capacity);

    cout<<"Enter the number of pages involved: ";
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    for(int i=0;i<n;i++)
    {
        obj.put(v[i]);
        cout<<"After "<<i<<" pages invoked: ";
        obj.print_pages();
    }
}