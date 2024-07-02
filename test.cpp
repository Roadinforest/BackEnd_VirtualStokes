#include "backEndWithDataBase.h"

int main(void)
{
	const char* host = "localhost"; // MySQL server host
	const char* user = "visitor"; // MySQL username
	const char* password = "VirtualStokes"; // MySQL password
	const char* database = "test"; // MySQL database name
	unsigned int port = 3306; // MySQL port (default is 3306)
	const char* unix_socket = nullptr; // Unix socket (can be nullptr for TCP/IP)
	unsigned long client_flag = 0; // Connection flags (usually 0)

	backEndWithDataBase test(host, user, password, database);
	test.query("select * from pet");
	test.tableDesc("pet");
}