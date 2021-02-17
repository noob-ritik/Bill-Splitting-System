#include <iostream>
#include<set>
#include<map>
using namespace std;
int main() {
    int no_of_people;
    cin>>no_of_people;
    string x,y;
    int amount;
    map<string,int> net;
    while(no_of_people--)
    {
        cin>>x>>y;
        cin>>amount;
        if(net.count(x)==0)
        net[x]=0;
        if(net.count(y)==0)
        net[y]=0;
        net[x]-=amount;
        net[y]+=amount;   
    }
    multiset<pair<int,string>> m;
    for(auto p:net)
    {
        string person=p.first;
        int amount=p.second;
        if(net[person]!=0)
        {
            m.insert(make_pair(amount,person));
        }
    }
    int c=0;
    while(!m.empty())
    {
        auto low=m.begin();
        auto high=prev(m.end());
        int debit=low->first;
        string debit_person=low->second;
        int credit=high->first;
        string credit_person=high->second;
        m.erase(low);
        m.erase(high);
        int settlement_amount=min(-debit,credit);
        debit+=settlement_amount;
        credit-=settlement_amount;
        cout<<debit_person<<" will pay "<<settlement_amount<<" to "<<credit_person<<endl;
        if(debit!=0)
        {
            m.insert(make_pair(debit,debit_person));
        }
        if(credit!=0)
        {
            m.insert(make_pair(credit,credit_person));
        }
        c++;
    }
    printf("Total No of Transactions needed are : %d",c);
    return 0;
}
