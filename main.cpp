#include <mixed.h>
#include <parser.h>

using namespace std;

int main()
{
    reserved.push_back("input");
    reserved.push_back("var");
    reserved.push_back("val");
    reserved.push_back("print");

    string s;
    //now we think everything wrote correct and there're ; after each string
    getline(cin, s);
    s = s.substr(0, s.size()-1);
    while(s != "0"){
        parse(s);
        getline(cin, s);
        s = s.substr(0, s.size()-1);
    }

    for(multimap<string, Mixed>::iterator i = mixes.begin(); i!= mixes.end(); ++i){
        cout << i->first<< " = ";
        if(i->second.type == Inty)
                cout << i->second.inty;
        if(i->second.type == Floaty)
                cout << i->second.floaty;
        if(i->second.type == Stringy)
                cout << i->second.stringy;
        cout << endl;
    }
    return 0;
}
