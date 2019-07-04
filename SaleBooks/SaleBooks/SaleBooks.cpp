// SaleBooks.cpp: 定义控制台应用程序的入口点。
//

#pragma comment(lib,"libmysql.lib")
#include "stdafx.h"
#include"mysql.h"
#include<iostream>

using namespace std;

int main()
{
	const char* user_name = "root";
	const char* user_pw = "liqiuyue123";
	const char* db_name = "university";

	MYSQL obj_sql;
	mysql_init(&obj_sql);

	if (mysql_real_connect(&obj_sql, NULL, user_name, user_pw, db_name, 0, NULL, 0)) {
		cout << "The connection is successful!" << endl;
	}
	else {
		int error_code = 0;
		error_code = mysql_errno(&obj_sql);
		cout << "Error code: " << error_code << endl;

		const char* error_msg = mysql_error(&obj_sql);
		cout << error_msg << endl;
	}

	mysql_close(&obj_sql);

	system("pause");
	return 0;
}

