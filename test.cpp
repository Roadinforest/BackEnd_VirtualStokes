#include <stdio.h>
#include <mysql.h>
#include <iostream>


MYSQL mysql;

int main(void)
{

    const char* host = "localhost"; // MySQL server host
    const char* user = "visitor"; // MySQL username
    const char* password = "VirtualStokes"; // MySQL password
    const char* database = "test"; // MySQL database name
    unsigned int port = 3306; // MySQL port (default is 3306)
    const char* unix_socket = nullptr; // Unix socket (can be nullptr for TCP/IP)
    unsigned long client_flag = 0; // Connection flags (usually 0)

	//Init
	mysql_init(&mysql);


	// Connect to MySQL database using mysql_real_connect
	if (mysql_real_connect(&mysql, host, user, password, database, port, unix_socket, client_flag)) {
		std::cout << "Connected to MySQL database successfully!" << std::endl;

		// Perform SQL queries, data retrieval, etc.

		// mysql_close(&mysql); // Close MySQL connection
	}
	else {
		std::cerr << "Connection error: " << mysql_error(&mysql) << std::endl;
		return 1; // Exit with error if connection fails
	}

	// Assuming 'mysql' is already initialized and connected properly

	int ret = mysql_query(&mysql, "SELECT * FROM pet");

	if (ret != 0) {
		std::cout << "Query execution failed: " << mysql_error(&mysql) << std::endl;
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
			mysql_free_result(result); // Free result set when done
		}
	}

	// Optionally print the return value of mysql_query
	std::cout << "Return value: " << ret << std::endl;

	return 0;

}