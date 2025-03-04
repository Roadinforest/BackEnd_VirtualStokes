#include "backEndWithDataBase.h"
#include <string>


// The implement of backEndWithDataBase Class

//Constructor , the basic information is host+user+password+database
backEndWithDataBase::backEndWithDataBase(const char* _host, const  char* _user, const  char* _password, const  char* _database,
	unsigned int _port, const char* _unix_socket , unsigned long _client_flag)
	:host(_host), user(_user), password(_password), database(_database), port(_port), unix_socket(_unix_socket)
	, client_flag(_client_flag)
{
	mysql_init(&mysql);

	// Connect to MySQL database using mysql_real_connect
	if (mysql_real_connect(&mysql, host, user, password, database, port, unix_socket, client_flag)) {
		std::cout << "Connected to MySQL database successfully!" << std::endl;
		std::cout << "Database Name:" << database << std::endl;

	}
	else {
		std::cerr << "Connection error: " << mysql_error(&mysql) << std::endl;
	}

}

MYSQL_RES* backEndWithDataBase::query(const char* query)
{
	// Assuming 'mysql' is already initialized and connected properly

	int ret = mysql_query(&mysql, query);

	if (ret != 0) {
		std::cout << "Query execution failed: " << mysql_error(&mysql) << std::endl;
		return nullptr;
	}
	else {
		// Query executed successfully, handle results
		MYSQL_RES* result = mysql_store_result(&mysql);

		if (result == nullptr) {
			std::cout << "Failed to get the result set" << std::endl;
		}
		else {
			// Process the result set if needed
			int num_fields = mysql_num_fields(result);
			MYSQL_ROW row;
			while ((row = mysql_fetch_row(result))) {
				for (int i = 0; i < num_fields; i++) {
					std::cout << row[i] << " ";
				}
				std::cout << std::endl;
			}
		}
		return result;
	}
}


const char* field_type_to_string(enum_field_types type) {
    switch (type) {
    case MYSQL_TYPE_DECIMAL:      return "DECIMAL";
    case MYSQL_TYPE_TINY:         return "TINYINT";
    case MYSQL_TYPE_SHORT:        return "SMALLINT";
    case MYSQL_TYPE_LONG:         return "INT";
    case MYSQL_TYPE_FLOAT:        return "FLOAT";
    case MYSQL_TYPE_DOUBLE:       return "DOUBLE";
    case MYSQL_TYPE_NULL:         return "NULL";
    case MYSQL_TYPE_TIMESTAMP:    return "TIMESTAMP";
    case MYSQL_TYPE_LONGLONG:     return "BIGINT";
    case MYSQL_TYPE_INT24:        return "MEDIUMINT";
    case MYSQL_TYPE_DATE:         return "DATE";
    case MYSQL_TYPE_TIME:         return "TIME";
    case MYSQL_TYPE_DATETIME:     return "DATETIME";
    case MYSQL_TYPE_YEAR:         return "YEAR";
    case MYSQL_TYPE_NEWDATE:      return "NEWDATE";
    case MYSQL_TYPE_VARCHAR:      return "VARCHAR";
    case MYSQL_TYPE_BIT:          return "BIT";
    case MYSQL_TYPE_JSON:         return "JSON";
    case MYSQL_TYPE_NEWDECIMAL:   return "NEWDECIMAL";
    case MYSQL_TYPE_ENUM:         return "ENUM";
    case MYSQL_TYPE_SET:          return "SET";
    case MYSQL_TYPE_TINY_BLOB:    return "TINYBLOB";
    case MYSQL_TYPE_MEDIUM_BLOB:  return "MEDIUMBLOB";
    case MYSQL_TYPE_LONG_BLOB:    return "LONGBLOB";
    case MYSQL_TYPE_BLOB:         return "BLOB";
    case MYSQL_TYPE_VAR_STRING:   return "VAR_STRING";
    case MYSQL_TYPE_STRING:       return "STRING";
    case MYSQL_TYPE_GEOMETRY:     return "GEOMETRY";
    default:                      return "UNKNOWN";
    }
}

void backEndWithDataBase::tableDesc(const char* tableName) {
    // Using std::string to concatenate
    std::string result = "SELECT * FROM " + std::string(tableName) + " LIMIT 1";
    const char* _query = result.c_str();

    MYSQL_RES* queryResult = query(_query);
    if (queryResult == NULL) {
        std::cerr << "Query failed: " << mysql_error(&mysql) << std::endl;
        return;
    }

    unsigned int num_fields;
    unsigned int i;
    MYSQL_FIELD* fields;

    num_fields = mysql_num_fields(queryResult);
    fields = mysql_fetch_fields(queryResult);
    for (i = 0; i < num_fields; i++)
    {
        printf("Field %u is %s\n", i, fields[i].name);
        std::cout << "Field name: " << fields[i].name << std::endl;
        std::cout << "Field type: " << field_type_to_string(fields[i].type) << std::endl;
        std::cout << "Field allows NULL: " << ((fields[i].flags & NOT_NULL_FLAG) ? "No" : "Yes") << std::endl;
    }

    mysql_free_result(queryResult);
}


//Cloase the Mysql
void backEndWithDataBase::close()
{
	mysql_close(&mysql); // Close MySQL connection
}

