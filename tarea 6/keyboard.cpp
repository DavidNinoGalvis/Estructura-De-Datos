#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(){
    string fraseDanada;
    list<char> texto;
    list<char>::iterator it;
    while(getline(cin,fraseDanada)){
        texto.clear();
        it = texto.begin();
        int i = 0;
        while(i<fraseDanada.size()){
            if(fraseDanada[i]!='[' && fraseDanada[i]!=']')
                texto.insert(it,fraseDanada[i]);
            else if(fraseDanada[i]=='[')
                it = texto.begin();
            else if(fraseDanada[i]==']')
                it = texto.end();
            ++i;
        }
        for(it=texto.begin();it!=texto.end();it++)
            printf("%c",*it);
        printf("\n");
    }
    return 0;
}