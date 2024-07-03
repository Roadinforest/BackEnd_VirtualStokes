#pragma once

#include <stdio.h>
#include <mysql.h>
#include <iostream>
#include <QString>


class BackDB
{
private:
    MYSQL mysql;//The MySql object

    const char* host = "10.128.11.30"; // MySQL server host ("Under XiaoMi13 is 192.168.237.55") Don't change it!!!
    const char* user = "visitor"; // MySQL username
    const char* password = "VirtualStokes"; // MySQL password
    const char* database = "stokes"; // MySQL database name
    unsigned int port = 3306; // MySQL port (default is 3306)
    const char* unix_socket = nullptr; // Unix socket (can be nullptr for TCP/IP)
    unsigned long client_flag = 0; // Connection flags (usually 0)

    //Constructor , the basic information is host+user+password+database
    BackDB(const char* _host, const  char* _user, const  char* _password, const  char* _database,
           unsigned int _port = 3306, const char* _unix_socket = nullptr, unsigned long _client_flag = 0);



public:

    //Usually you use this default constructor instead of using the constructor directorly
    BackDB();

    //Input the formal query lines that can be used in MySql
    //and return a MYSQL_RES object
    //Won't show the result of the query
    MYSQL_RES* query(const char* query);

    //Show the query result of the query
    //And return the result as QStirng
    QString showQuery(const char* query);

    //Get the information about the field
    void tableDesc(const char* tableName);

    //Cloase the Mysql
    void close();
};
