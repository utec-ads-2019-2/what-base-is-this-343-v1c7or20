#include <iostream>
#include <cmath>

using namespace std;

int getBase(string word){
    int l1 = word.size();
    int b1=1;
    for(int i = 0; i < l1; i++) {
        if(isdigit(word[i]))
            b1 = b1 > word[i]-'0' ? b1 : word[i]-'0';
        else
            b1 = b1 > word[i]-'A'+10 ? b1 : word[i]-'A'+10;
    }
    return b1;
}

int toBase(string word, int base){
    int rpt = 0, pot=1;
    int size = word.size();
    for (int i = size-1; i >=0 ; i--) {
        if(isdigit(word[i]))
            rpt = rpt + (word[i]-'0')*pot;
        else
            rpt = rpt + (word[i]-'A'+10)*pot;
        pot = pot* base;
    }
    return rpt;
}

int main() {
   string word1,word2;
    while (cin>>word1>>word2){
        int base1 = getBase(word1)+1;
        int base2 = getBase(word2)+1;
        bool control = false;
        for (; base1 <=36; base1++) {
            for (int i = base2; i <= 36 ; i++) {
                if (toBase(word1,base1) == toBase(word2,i)){
                    cout<<word1<<" (base "<<base1<<") = "<<word2<<" (base "<<i<<")"<<endl;
                    control= true;
                }
                if (control)break;
            }
            if (control)break;
        }
        if(!control){
            cout<<word1<<" is not equal to "<<word2<<" in any base 2..36"<<endl;
        }
    }
}