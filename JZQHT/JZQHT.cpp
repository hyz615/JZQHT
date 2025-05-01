// JZQHT.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "crow_all.h"
#include "mysql.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
string username_requist;
string password_requist;
string sqlip;
int sqlport;
string sqluser;
string sqlpassword;
string sqldatabase;
MYSQL mysql;
bool ConnectDatabase()
{
	mysql_init(&mysql);   
	if (!(mysql_real_connect(&mysql, sqlip.c_str(), sqluser.c_str(), sqlpassword.c_str(), sqldatabase.c_str(), sqlport, NULL, 3306)))
	{
		cout << "Error connecting to database:" << mysql_error(&mysql) << endl;
		return false;
	}
	else
	{
		cout << "success to connect" << endl;
		cout << "Connected..." << endl;
		return true;
	}
}
void insert(string atr1, string atr2, string val1,string val2) {
	string sql = "INSERT INTO userss ("+atr1+", "+atr2+") VALUES ('" + val1 + "', '" + val2 + "')";
	if (mysql_query(&mysql, sql.c_str()) != 0)
	{
		cout << "Error inserting data: " << mysql_error(&mysql) << endl;
	}
	else
	{
		cout << "Data inserted successfully." << endl;
	}
}
void FreeConnect()
{
	mysql_close(&mysql);
	cout << "Released" << endl;
}
int main()
{
	
    crow::SimpleApp app;
	cout << "please enter the information of sql, ip, port, username, password and database" << endl;
	cin >> sqlip;
	cin >> sqlport;
	cin >> sqluser;
	cin >> sqlpassword;
	cin >> sqldatabase;
	ConnectDatabase();
    CROW_ROUTE(app, "/")([]() {
        return "running";
        });

    app.port(18080).multithreaded().run();
}
