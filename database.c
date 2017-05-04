#include "database.h"
#include <mysql/mysql.h>
#include <stdio.h>
void finish_with_error(MYSQL *conn)
{
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

void connect_database() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;
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
    if (mysql_query(conn, "SELECT * FROM users")) {
        finish_with_error(conn);
    }
    
    res = mysql_use_result(conn);
    while ((row = mysql_fetch_row(res)) != NULL) {
        // printf("%s\n", check_string);
        printf("%s\n", row[1]);
    }
    /* close connection */
    mysql_free_result(res);
    mysql_close(conn);
}

int main() 
{
	connect_database();
}