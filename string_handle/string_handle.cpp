// Copyright (c) 2015
// Author: Chrono Law
//#include <std.hpp>
#include <iostream>
#include <vector>

using namespace std;

#include <boost/algorithm/string.hpp>
#include <boost/timer/timer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/utility/string_ref.hpp>
#include <boost/tokenizer.hpp>
using namespace boost::timer;
using namespace boost;


class demo_class{
    friend  ostream& operator<<(std::ostream& os, const demo_class& x){
        os<< "demo_class's Name";
    }
};

template <typename T>
void my_print(T& tok){
    for(auto& x: tok){
        cout<<"["<<x<<"]";
        cout<<endl;
    }

}

int main()
{
    int x = lexical_cast<int>("11");
    string str = lexical_cast<string>(456);

//    try {
//        cout<< lexical_cast<int>("0x100");
//    }catch (bad_lexical_cast& e){
//        cout<<"error: "<<e.what()<<endl;
//    }

//    cout<< lexical_cast<string>(demo_class())<<endl;

    boost::format fmt("%s:%d+%d=%d\n");
    fmt%"sum"%1%2%(1+2);
    cout<<fmt.str();
    cout<<endl;
    boost::format fmt2("%05d\n%-8.3f\n% 10s\n%05X\n");
    cout<<fmt2%62%2.236%"1223"%48;

    const char* ch = "Days of Future Past";
    string str1(ch);
    string_ref s1(ch);
    string_ref s2(str1);
    assert(s1 == s2 && s1==ch && s2 == str1);

    string_ref s3(ch,4);
    assert(s3 == str1.substr(0,4));

    string_ref s4,s5;
    s4  = ch;
    s5 = str1;

    string str3("Power Bomb");
//    assert(iends_with(str,"bomb"));
//    assert(!ends_with(str,"bomb"));
//
//    assert(starts_with(str,"Pow"));
//    assert(contains(str,"er"));
//
//    string str4 = to_lower_copy(str3);
//    assert(iequals(str3,str4));
//    string str5("power suit");
//    assert(ilexicographical_compare(str3,str5));
//    assert(all(str3.substr(0,5), is_lower()));

    string str6("Link raise the master-sword");
//    tokenizer<> tok(str6);
//    for(auto& x1:tok){
//        cout<<"["<<x1<<"]";
//    }

    char str7[]="Link ;; <master-sword> zelda";
    char_separator<char> sep;
    tokenizer<char_separator<char>, char*> tok(str7, str7+strlen(str7), sep);
    my_print(tok);

    tok.assign(str7, str7+strlen(str7),char_separator<char>(" ;-","<>"));
    my_print(tok);

    tok.assign(str7, str7+strlen(str7),char_separator<char>(" ;-<>","",keep_empty_tokens));
    my_print(tok);


}

