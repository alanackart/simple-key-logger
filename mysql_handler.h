#ifndef _MYSQL_HANDLER_H_
#define _MYSQL_HANDLER_H_
#include <my_global.h>
#include <mysql.h>
void setup_mysql(MYSQL **con); /*setup mysql connection */
void close_mysql(MYSQL *con);  /*close mysql connection */
void insert_data(MYSQL *con, char *name) ; /* insert row data */
#endif