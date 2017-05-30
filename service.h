#ifndef SERVICE_H
#define SERVICE_H

#include "siftp.h"

	/* constants */
	
		/** max length of a service command's name */
		#define SERVICE_COMMAND_SIZE	4
		
		/** argument separators in a command string */
		#define SERVICE_COMMAND_ARGUMENT_DELIMITERS	" \t"
		
		#define SERVICE_PERMS_READ_TEST	"r"
		#define SERVICE_PERMS_WRITE_TEST	"a"
		
	/* services */
	
		/**
		 * Establishes a SimpleFTP session.
		 */
		Boolean session_create(const int a_socket);
		
		/**
		 * Destroys an established SimpleFTP session.
		 */
		Boolean session_destroy(const int a_socket);
		
		/**
		 * Performs interaction/dialouge.
		 */
		void service_loop(const int a_socket);
	
		/**
		 * Performs a simple two-way query & response dialouge.
		 */
		Boolean service_query(const int a_socket, const Message *ap_query, Message *ap_response);
		
		/**
		 * Returns a string containing the absolute path of the extension relative to the base path.
		 */
		Boolean service_getAbsolutePath(const String a_basePath, const String a_extension, String a_result);
		
		/**
		 * Sends a command status acknowlegdement for a command.
		 */
		Boolean service_sendStatus(const int a_socket, const Boolean a_wasSuccess);

		/**
		 * Returns an array of words parsed from the command string. Assumes words are separated by <tt>SERVICE_COMMAND_ARGUMENT_DELIMITERS</tt> characters.
		 */
		String* service_parseArgs(const String a_cmdStr, int *ap_argc);
		
		/**
		 * Frees memory associated with the array created exclusively by <tt>parseArgs()</tt>.
		 */
		void service_freeArgs(String *ap_argv, const int a_argc);
		
		/**
		 * Returns the value of the command staus acknowlegdement.
		 */
		Boolean service_recvStatus(const int a_socket);

		/**
		 * Performs a remote command and returns its status.
		 */
		Boolean remote_exec(const int a_socket, Message *ap_query);
		
		/**
		 * Handles a command occuring in interaction/dialouge.
		 */
		Boolean service_handleCmd(const int a_socket, const String *ap_argv, const int a_argc);
		
		/**
		 * Changes the path of the current working dir.
		 */
		Boolean service_handleCmd_chdir(String a_currPath, const String a_newPath);
		
		/**
		 * Returns true if the path is accessible under the given permissions.
		 */
		Boolean service_permTest(const String a_path, const String a_mode);
		
		/**
		 * Returns true if the path has all of the given attributes. <tt>errno</tt> is also set upon failure.
		 */
		Boolean service_statTest(const String a_path, const int a_testMode, const int a_resultMode);
		
		/**
		 * Returns contents of a file or NULL upon error.
		 */
		String service_readFile(const String a_path, int *ap_length);
		
		/**
		 * Returns names of all files in the given directory. Each directory entry name is separated by a newline. The trailing newline is replaced by a null terminator.
		 */
		String service_readDir(const String a_path, int *ap_length);
		
		/**
		 * Writes data whilst overwriting any existing file at the given path.
		 */
		Boolean service_writeFile(const String a_path, const String a_data, const int a_length);
		
#endif

