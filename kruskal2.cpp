#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> edl,mst;
vector<int> p;
void print(){
    for (auto i:mst){
        int sc=get<0>(i);
        int de=get<1>(i);
        int wt=get<2>(i);

        cout<<sc<<" "<<de<<" "<<wt<<endl;
    }
}

bool sortBywt(tuple<int,int,int> a,tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}

int findOp(int u){
    if(p[u]== -1 )
        return u;
    else
        findOp(p[u]);
}

void unionOp(int arsc,int arde){
    p[arde]= arsc;
}

int main()
{
    int v,e,sc,de,wt;
    cout<<"Enter Vertex and Edge number: ";
    cin>>v>>e;
    for(int i =1;i<=e;i++){
            cout<<"edge "<<i<<": ";
        cin>>sc>>de>>wt;
        edl.push_back(make_tuple(sc,de,wt));
    }

    sort(edl.begin(),edl.end(),sortBywt);
    p.resize(v,-1);
    for(auto i:edl){
        int sc=get<0>(i);
        int de=get<1>(i);
        int wt=get<2>(i);
        int arsc = findOp(sc);
        int arde = findOp(de);

        if(arsc==arde)
            continue;
        else{
            unionOp(arsc,arde);
            mst.push_back(i);
            if(mst.size()==(v-1)) break;
        }
    }
    print();

    return 0;
}