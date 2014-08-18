#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "qh_string.h"


void test()
{
	//////////////////////////////////////////////////////////////
	qh::string string1="";      //测试空串初始化
	assert(string1=="");
	//////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////////
	qh::string string2="123\\0""456";    //转义符测试，同时测试有一个参的构造函数
	qh::string string3=string2;        //赋值符号测试
	assert(string3=="123\\0""456");
	//////////////////////////////////////////////////////////////



	///////////////////////////////////////////////////////////
	qh::string string4;
	assert(string4.size()==0);
	assert(string4.data()==NULL);  //测试无参构造函数
	///////////////////////////////////////////////////////////



	//////////////////////////////////////////////////////////////////////
	qh::string string5("$%#",-1);  //测试指定长度构造函数，并且长度非法
	assert(string5.data()==NULL&&string5.size()==0);
    //////////////////////////////////////////////////////////////////////

	qh::string string6;
	qh::string string7=string6=string2;  //测试连续赋值
	assert(string7=="123\\0""456");
	//////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////输入输出符重载测试

	std::cout<<"请输入一个字符串："<<std::endl;

	std::cin>>string4;   //请输入string4 测试输入重载是否成功
	
	std::cout<<"您输入的字符串为："<<std::endl;

	std::cout<<string4<<std::endl;   //测试输出重载是否成功

	std::cout<<"string2的值为："<<std::endl;

	std::cout<<string2<<std::endl;   //测试输出重载是否成功

	//////////////////////////////////////////////////////////////////////////////

	
	//////////////////////////////////////////////////////////////////////  运算符重载测试
	
	assert(string3[5]=='4');      //能否取得合适下标的值
	assert((string1+string2)==string2);   //空字符串与非空字符串相加是否正确
	assert((string1+string1)==string1);   //空字符串相加是否正确
	assert((string2+string2)==(string3+string3)); //字符串相加是否正确
	assert(string2[20]==string1[0]); //测试数组下标越界，是否打印越界信息提示，并且返回空值

	//////////////////////////////////////////////////////////////////////

}

int main( )
{    //TODO 在这里添加单元测试，越多越好，代码路径覆盖率越全越好
	//TODO 单元测试写法请参考INIParser那个项目，不要写一堆printf，要用assert进行断言判断。

	test();

    /////////////////////////////////////////////


	std::cout<<"All test is OK!"<<std::endl;
#ifdef WIN32
	system("pause");
#endif
	return 0;
}
