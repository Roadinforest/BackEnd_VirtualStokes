#pragma once

#include <stdio.h>
#include <mysql.h>
#include <iostream>


class backEndWithDataBase
{
private:
	MYSQL mysql;

	const char* host = "10.128.11.30"; // MySQL server host
	const char* user = "visitor"; // MySQL username
	const char* password = "VirtualStokes"; // MySQL password
	const char* database = "test"; // MySQL database name
	unsigned int port = 3306; // MySQL port (default is 3306)
	const char* unix_socket = nullptr; // Unix socket (can be nullptr for TCP/IP)
	unsigned long client_flag = 0; // Connection flags (usually 0)


public:

	//Constructor , the basic information is host+user+password+database
	backEndWithDataBase(const char* _host, const  char* _user, const  char* _password, const  char* _database,
		unsigned int _port = 3306, const char* _unix_socket = nullptr, unsigned long _client_flag = 0);

	//Query some line to the database
	MYSQL_RES* query(const char* query);

	//Get the information of the field 
	void tableDesc(const char* tableName);

	//Cloase the Mysql
	void close();
};
