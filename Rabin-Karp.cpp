/*-------------------------Rabin-Karp String Matching Algorithm-------------------------*/

#include<bits/stdc++.h>
#define MX 100000
using namespace std;
double hash_value[MX];
int k=0;
void Generate_hash_for_Pattern(string pt,string tx);
double Generate_hash_for_text(string tx);
main(int argc,char *argv[])
{
    string pattern,text;
    double txt_code;
    vector<int>shift;
    int cnt=0;

    cout << "Pattern : " ;
    cin >> pattern;
    cout << "Text : " ;
    cin >> text ;


    Generate_hash_for_Pattern(pattern,text);   /*Generate Hash Function for Full Pattern. */
    double tx_code=Generate_hash_for_text(text);  /*Generate Hash for Pattern. */

    for(int i=0; i<k; i++)
        if(hash_value[i]==tx_code)        /*Evaluating Match or MisMatch*/
            shift.push_back(cnt);
        else
            cnt++;
    if(shift.size()==0)
        cout << "The Pattern is not found in this Text." << endl;
    else
    {
        cout << "The Text is found in " ;
        for(int i=0; i<shift.size(); i++)
            cout << shift[i]+1 << " ";
        cout << "shift in this Pattern." << endl;

    }

}

void Generate_hash_for_Pattern(string pt,string tx)
{
    int ptLen=pt.length(),txLen=tx.length(),p=tx.length()-1;
    double sum=0;
    for(int i=0; i<ptLen-txLen+1; i++)
    {
        for(int j=i; j<i+txLen; j++)
        {
            if(pt[j]>='A' && pt[j]<='Z')
                sum+=(int)pt[j]%64*pow(10,p--);
            else if(pt[j]>='a' && pt[j]<='z')
                sum+=(int)pt[j]%96*pow(10,p--);
            else if(pt[j]>='0' && pt[j]<='9')
                sum+=(int)pt[j]%47*pow(10,p--);
        }
        hash_value[k++]=sum;
        sum=0;
        p=tx.length()-1;
    }

}
double Generate_hash_for_text(string tx)
{
    int txLen=tx.length(),p=tx.length()-1;
    double sum=0;
    for(int i=0; i<txLen; i++)
    {
        if(tx[i]>='A' && tx[i]<='Z')
            sum+=(int)tx[i]%64*pow(10,p--);
        else if(tx[i]>='a' && tx[i]<='z')
            sum+=(int)tx[i]%96*pow(10,p--);
        else if(tx[i]>='0' && tx[i]<='9')
            sum+=(int)tx[i]%47*pow(10,p--);
    }
    return sum;
}
