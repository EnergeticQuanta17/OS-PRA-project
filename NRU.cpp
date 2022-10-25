#include<bits/stdc++.h>
using namespace std;
#include<vector>
class NRU
{
    public:
        vector<int> nn;
        vector<int> nm;
        vector<int> rn;
        vector<int> rm;
        
        vector<int> f;
        int cap;
        NRU(int capacity)
        {
            cap=capacity;
        }
        void insert(int page_no)
        {
            nn.push_back(page_no);
            f.push_back(page_no);
            cap--;
        }
        void Delete()
        {
            cap++;
            if(nn.size()!=0)
            {
                cout<<"Removing from (Not Referenced, Not Modified):- Page number:";
                int x=nn.back();
                cout<<x<<endl;
                nn.pop_back();
                return;
            }
            if(nm.size()!=0)
            {
                cout<<"Removing from (Not Referenced, Modified):- Page number:";
                int x=nm.back();
                nm.pop_back();
                return;
            }
            if(rn.size()!=0)
            {
                cout<<"Removing from (Referenced, Not Modified):- Page number:";
                int x=rn.back();
                rn.pop_back();
                return;
            }
            if(rm.size()!=0)
            {
                cout<<"Removing from (Referenced, Modified):- Page number:";
                int x=rm.back();
                rm.pop_back();
                return;
            }
        }
        void put(int page_no)
        {
            for(int i=0;i<f.size();i++)
                if(f[i]==page_no)
                    return;
            
            if(cap==0)
                Delete();
            insert(page_no);
        }
        void remove(int page_no)
        {
            vector<int>::iterator itr4321;
            for(auto itr4321=nn.begin();itr4321!=nn.end();itr4321++){
                if(*itr4321==page_no)
                {
                    nn.erase(itr4321);
                    return;
                }
            }

            vector<int>::iterator itr432;
            for(auto itr432=nm.begin();itr432!=nm.end();itr432++){
                if(*itr432==page_no)
                {
                    nm.erase(itr432);
                    return;
                }
            }

            vector<int>::iterator itr43;
            for(auto itr43=rn.begin();itr43!=rn.end();itr43++){
                if(*itr43==page_no)
                {
                    rn.erase(itr43);
                    return;
                }
            }

            vector<int>::iterator itr4;
            for(auto itr4=rm.begin();itr4!=rm.end();itr4++){
                if(*itr4==page_no)
                {
                    rm.erase(itr4);
                    return;
                }
            }
        }
        void request_modify_reference(int page_no, int mod, int ref)
        {
            remove(page_no);
            if(mod==0 && ref==0)
                nn.push_back(page_no);
            else if(mod==1 && ref==0)
                nm.push_back(page_no);
            else if(mod==0 && ref==1)
                rn.push_back(page_no);
            else if(mod==1 && ref==1)
                rm.push_back(page_no);
        }

        void display()
        {
            for(int i=0;i<nn.size();i++)
                cout<<nn[i]<<" ";
            for(int i=0;i<nm.size();i++)
                cout<<nm[i]<<" ";
            for(int i=0;i<rn.size();i++)
                cout<<rn[i]<<" ";
            for(int i=0;i<rm.size();i++)
                cout<<rm[i]<<" ";
            cout<<endl;
        }
};

int main()
{
    int capacity, n;
    cout<<"Enter the maximum number of frames possible: ";
    cin>>capacity;
    NRU obj(capacity);

    cout<<"Enter the number of pages involved: ";
    cin>>n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    int pn,mod,ref;
    for(int i=0;i<n;i++)
    {
        obj.put(v[i]);
        char c='Y';
        cout<<"Pages in main memory after "<<(i+1)<<" pages have been processed: ";
        obj.display();
        do{
            cout<<"Enter page_no which was referenced/modified:(format: page_no mod=0/1 ref=0/1): after "<<(i+1)<<" pages have been analysed:";
            cin>>pn>>mod>>ref;
            obj.request_modify_reference(pn,mod,ref);
            cout<<"Do you want to register another change?(Y/N): ";
            cin>>c;
        }while(c=='Y');
    }
    return 0;
}
    