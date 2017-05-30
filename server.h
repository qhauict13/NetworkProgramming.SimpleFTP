#ifndef SERVER_H
#define SERVER_H

#include "siftp.h"

	/* constants */
	
		#define SERVER_SOCKET_BACKLOG 5
        #define SERVER_USERNAME "root"
		#define SERVER_PASSWORD	"ict58"
		#define DATABASE_SERVER "localhost"
		#define DATABASE_USER "root"
		#define DATABASE_PASSWORD NULL
		#define ARRAY_MAX 100
	
	/* services */
	
		/**
		 * Establishes a network service on the specified port.
		 */
		Boolean service_create(int *ap_socket, const int a_port);		
#endif
