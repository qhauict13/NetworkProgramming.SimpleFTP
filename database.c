#include "database.h"
#include <stdio.h>
#include <string.h>

void finish_with_error(MYSQL *conn)
{
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

MYSQL* connect_database() {
    MYSQL *conn;
    // MYSQL_RES *res;
    // MYSQL_ROW row;
    char *server = DATABASE_SERVER;
    char *user = DATABASE_USER;
    char *password = DATABASE_PASSWORD; /* set me first */

    conn = mysql_init(NULL);
    /* Connect to database */
    if (!mysql_real_connect(conn, server,
                            user, password, NULL, 0, NULL, 0)) {
        finish_with_error(conn);
    }

    // // select database
    if (mysql_query(conn, "USE clion"))
    {
        finish_with_error(conn);
    }

    // if (mysql_query(conn, "SELECT * FROM users")) {
    //     finish_with_error(conn);
    // }
    
    // res = mysql_use_result(conn);
    // while ((row = mysql_fetch_row(res)) != NULL) {
    //     // printf("%s\n", check_string);
    //     printf("%s\n", row[1]);
    // }
    // /* close connection */
    // mysql_free_result(res);
    return conn;
}

void clear_flush()
{
	char c;
	while ((c = getchar()) != '\n' && c != EOF) { }
}

int main() 
{
	while(1)
	{
		MYSQL *conn = connect_database();
		int choose;
		printf("DATABASE HANDLING\n1. show users\n2. add users\n3. remove users\n4. quit\n");
		printf("Select: ");
		scanf("%d", &choose);
		switch(choose)
		{
			case 1:
				if (mysql_query(conn, "SELECT * FROM users"))
				{
					finish_with_error(conn);
				}
				MYSQL_RES *res = mysql_use_result(conn);
				MYSQL_ROW row;
				printf("\n");
				while ((row = mysql_fetch_row(res)) != NULL)
				{
					printf("%s\t\t", row[1]);
					printf("%s\n", row[2]);
				}
				printf("\n");
				mysql_free_result(res);
				break;
			case 2: 
			{
				char query[100] = "INSERT INTO users (username, password) VALUES (\"";
				char username[20];
				char password[20];
				clear_flush();
				printf("username: ");
				scanf("%[^\n]s", username);
				printf("password: ");
				clear_flush();
				scanf("%[^\n]s", password);
				clear_flush();
				strcat(query, username);
				strcat(query, "\", \"");
				strcat(query, password);
				strcat(query, "\");");
				if (mysql_query(conn, query))
				{
					finish_with_error(conn);
				}
				break;
			}
			case 3:
			{
				char query[100] = "DELETE FROM users WHERE username = \"";
				char username[20];
				clear_flush();
				printf("username: ");
				scanf("%[^\n]s", username);
				clear_flush();
				strcat(query, username);
				strcat(query, "\";");
				if (mysql_query(conn, query))
				{
					finish_with_error(conn);
				}
				break;
			}
			case 4:
				mysql_close(conn);
				return 0;
		}
		mysql_close(conn);
	}
}