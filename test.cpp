#include <stdio.h>
#include <mysql.h>
#include <iostream>



int main(void)
{
	MYSQL mysql;//数据库句柄
	MYSQL_RES* res; //查询结果集
	MYSQL_ROW row;  //记录结构体

    const char* host = "localhost"; // MySQL server host
    const char* user = "root"; // MySQL username
    const char* password = "Lin.34683"; // MySQL password
    const char* database = "test"; // MySQL database name
    unsigned int port = 3306; // MySQL port (default is 3306)
    const char* unix_socket = nullptr; // Unix socket (can be nullptr for TCP/IP)
    unsigned long client_flag = 0; // Connection flags (usually 0)

	//初始化
	mysql_init(&mysql);


        // Connect to MySQL database using mysql_real_connect
        if (mysql_real_connect(&mysql, host, user, password, database, port, unix_socket, client_flag)) {
            std::cout << "Connected to MySQL database successfully!" << std::endl;

            // Perform SQL queries, data retrieval, etc.

            mysql_close(&mysql); // Close MySQL connection
        }
        else {
            std::cerr << "Connection error: " << mysql_error(&mysql) << std::endl;
            return 1; // Exit with error if connection fails
        }

        int ret = mysql_query(&mysql, "select * from test;");
        std::cout << ret << std::endl;

        return 0;
    


}