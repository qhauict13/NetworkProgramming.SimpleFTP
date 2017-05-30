#ifndef CLIENT_H
#define CLIENT_H

#include "siftp.h"

	/* services */
	
		/**
		 * Establishes a network connection with the specified server.
		 */
		Boolean service_create(int *ap_socket, const String a_serverName, const int a_serverPort);

#endif
