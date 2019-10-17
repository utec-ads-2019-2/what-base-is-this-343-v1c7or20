#include <iostream>
#include <cmath>

using namespace std;

int toDecimal(string word){
    int pot = 1;
    int rpt= 0;
    for (auto i = word.rbegin(); i != word.rend() ; i++) {
        if(isdigit(*i)){
            rpt= rpt + atoi(&(*i))*pow(36,pot);
            pot++;
        }
    }
}

int main() {
   string a,b;
    while (cin>>a>>b){
       cout<<a<<" "<<b<<endl;
   }
}