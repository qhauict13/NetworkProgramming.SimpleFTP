#ifndef DATABASE_H
#define DATABASE_H

#include "server.h"
#include <mysql/mysql.h>

	/* services */
	
		/**
		 * Establishes a connection to database
		 */
		MYSQL* connect_database();

#endif