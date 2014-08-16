#ifndef QIHOO_STRING_H_
#define QIHOO_STRING_H_

#include <stdlib.h>

/////////////////////////////////
#include <iostream>
#include<iomanip>
////////////////////////////////


namespace qh
{

	typedef unsigned int size_t;   //由于前序文件QIHOO_STRING_H_不可见，这里自己定义size_t

    /**
    * A string is my own string
    * @version 2014-8-16
    */
    class string {
    public:


        friend std::ostream& operator<< (std::ostream&,string&);//重载<<运算符  
        friend std::istream& operator>> (std::istream&,string&);//重载>>运算符



        //ctor
        string();
        string(const char* s);
        string(const char* s, size_t len);
        string(const string& rhs);


		////////////////////////////////////////////////////////
        string operator+(const string &other)const;  //字符串加号operator+重载 
		////////////////////////////////////////////////////////



		////////////////////////////////////////////////////////
        string& operator=(const string& rhs);     //赋值操作符=重载
		////////////////////////////////////////////////////////



		////////////////////////////////////////////////////////
		bool operator==(const string&);              //比较操作符operator==重载
		////////////////////////////////////////////////////////

        //dtor
        ~string();

        //get
        size_t size() const;
        const char* data() const;
        const char* c_str() const;

        // set & get
        char& operator[](size_t index);

    private:
        char*  data_;
        size_t len_;
    };
}

#endif
