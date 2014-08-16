#include "qh_string.h"

#include <string.h>

//////////////////////////////////


//////////////////////////////////

namespace qh
{
	// TODO ½«ÔÚÕâÀïÐ´ÊµÏÖ´úÂë

	string::string()
		: data_(NULL), len_(0)
	{

	}

	string::string( const char* s )
	{
		if(!s)
		{
			data_=NULL;
		} 
		else 
		{  
			data_=new char[strlen(s)+1];
			len_=strlen(s);
			strcpy(data_,s);  
		}  
	}

	string::string( const char* s, size_t len )  
	{
	
		if(!s||len<0||len>strlen(s))
		{
			fprintf(stderr, "size is illegal \n" );   //长度为负数！
			data_=NULL;
			len_=0;
		} 

		else 
		{  
			data_=new char[len+1];
			len_=strlen(s);
			strcpy(data_,s);  
		}  
	}

	string::string( const string& rhs )
	{
		if(!rhs.data_)
		{
			this->data_=NULL;
		} 
		else   
		{  
			data_=new char[strlen(rhs.data_)+1];
			len_=rhs.len_;
			strcpy(data_,rhs.data_); 
		}
	}

    string string::operator+(const string &other)const  
	{  
		string newString;  
		if(!other.data_)  
			newString = *this;  
		else if(!data_)  
			newString = other;  
		else  
		{  
			newString.data_ = new char[strlen(data_)+strlen(other.data_)+1];  
			strcpy(newString.data_,data_);  
			strcat(newString.data_,other.data_);  
		}  
		return newString;  
	}  

	string& string::operator=( const string& rhs )
	{
		if (this!=&rhs)  
		{  
			delete[] data_;  
			if(!rhs.data_)
			{
				data_=NULL;
			}
			else  
			{  
				data_ = new char[strlen(rhs.data_)+1];
				len_=rhs.len_;
				strcpy(data_,rhs.data_);  
			}  
		} 
		return *this;
	}

	bool string::operator==(const string &s)      
	{  
		if ( strlen(s.data_) != strlen(data_) )  
			return false;  
		return strcmp(data_,s.data_)?false:true;  
	} 

	string::~string()
	{
		delete[] data_;
		len_=0;
	}

	size_t string::size() const
	{
		return len_;
	}

	const char* string::data() const
	{		
		if(data_)
		{
			return data_;
		}

		else
		{
			return NULL;
		}
	}

	const char* string::c_str() const
	{

		return NULL;
	}

	char& string::operator[]( size_t index )
	{
		if (index>=0&&index<=len_)  
			return data_[index];
		else 
		{
			 fprintf(stderr, "Index is out of range\n" );   //数组下标越界判断
		}
			return data_[len_] ;

	}

	/////////////////////////////////输入输出流重载
	std::ostream& operator<<(std::ostream& os,string& str)  
	{  
		os << str.data_;  
		return os;  
	}  

	std::istream &operator>>( std::istream &input, string &s )  
	{  
		char temp[ 255 ]; //用于存储输入流  
		input>>std::setw(255)>>temp;  
		s = temp; //使用赋值运算符  
		return input; //使用return可以支持连续使用>>运算符  
	}  
}
