#include "mysql_handler.h"
#include <stdio.h>
/*
gcc mysql_handler.c -o mysql_handler  `mysql_config --cflags --libs`
 */

void finish_with_error(MYSQL *con)
{
   fprintf(stderr, "%s\n", mysql_error(con));
   mysql_close(con);
   exit(1);
}

void close_mysql(MYSQL *con)
{
   fprintf(stderr, "close mysql\n");
   mysql_close(con);
   exit(1);
}

void setup_mysql(MYSQL **con)
{
   *con = mysql_init(NULL);

   if (*con == NULL)
   {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
   }

   if (mysql_real_connect(*con, "localhost", "root", "12345678",
                          NULL, 0, NULL, 0) == NULL)
   {
      fprintf(stderr, "%s\n", mysql_error(*con));
      finish_with_error(*con);
   }
}

void insert_data(MYSQL *con, char *name)
{
   static char sqlcmd[256] = {0};
   sprintf(sqlcmd, "insert fis.key_logger values(CURRENT_TIMESTAMP(6), '%s', NULL)", name);
   if (mysql_query(con, sqlcmd))
   {
      finish_with_error(con);
   }

   return;
}

// int main(){
//    MYSQL *con =NULL;
//    setup_mysql(&con);
//    insert_data(con, "a");
//    close_mysql(con);
//     return 0;
// }
