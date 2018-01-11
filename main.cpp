// Copyright (c) 2015
// Author: Chrono Law
//#include <std.hpp>
#include <iostream>
#include <vector>

using namespace std;

#include <boost/system/error_code.hpp>
using namespace boost::system;

class my_category: public boost::system::error_category
{
public:
     virtual const char* name() const BOOST_SYSTEM_NOEXCEPT
     {
         return "myapp_category";
     }

    virtual string message(int env)const
    {
        string msg;
        switch (env){
            case 0:
                msg = "ok";
                break;
            default:
                msg = "some error";
                break;
        }
        return msg;
    }
};

int main()
{
   my_category my_category;
    boost::system::error_code ec(10,my_category);
    cout<<ec.value()<<ec.message()<<endl;


}

