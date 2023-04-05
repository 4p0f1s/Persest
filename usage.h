void gen(){
    printf("Usage:\n");
    printf(" persest [command]\n\n");
    printf("Available Commands:\n");
    printf(" user\t\tUsercreation/deletion mode\n");
    printf(" persistence\tPersistence creation mode\n");
    printf(" rdp\t\tRDP enable/disable mode\n");
    printf(" clean\t\tClean logs mode\n");
    printf(" -h help\tHelp for persest\n");
}

void us(){
  printf("Usage:\n");
  printf(" persest user [flags]\n\n");
  printf("Available Flags:\n");
  printf("-u name:\tEnter the name of the user\n");
  printf("-p password:\tEnter the password of the user\n");
  printf("-g group:\tEnter the group whre add the user\n");
  printf("-A admin:\tAdd the user to admin group (Require flag '-g' with the group name)\n");
  printf("-D Domain:\tPerforms the user add on the domain\n");
  printf("-e Active:\tCause the account to be active or not (Options: yes/no. By default YES)\n");
  printf("-a add:\t\tAdd the user\n");
  printf("-d del:\t\tDelete the user\n");
  printf("-h help:\tHelp for persest user flag\n");
}

void pers(){
  printf("Usage:\n");
  printf(" persest persistence [flags]\n\n");
  printf("Available Flags:\n");
  printf("-a add:\t\tAdd the service\n");
  printf("-d del:\t\tDelete the service\n");
  printf("-f file:\tOur payload file\n");
  printf("-h help:\tHelp for persest persistence flag\n");
}

void rd(){
  printf("Usage:\n");
  printf(" persest rdp [flags]\n\n");
  printf("Available Flags:\n");
  printf("-e enable:\tEnable RDP service\n");
  printf("-d disable:\tDisable RDP service\n");
  printf("-h help:\tHelp for persest rdp flag\n");
}

void cl(){
  printf("Usage:\n");
  printf(" persest clean [flags]\n\n");
  printf("Available Flags:\n");
  printf("-a All:\t\tClean all logs\n");

}
