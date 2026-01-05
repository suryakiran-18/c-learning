#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include"operation.h"
#include"auth.h"

// login function..
int  login(){
     struct employee E;
     char name[100];
     int id;
     int flag = 0;

     printf("Enter your name : ");
     scanf(" %[^\n]",name);
     printf("Enter your Employee id : ");
     scanf("%d",&id);

     FILE *fp;
     fp = fopen("Employee_records.dat","rb");
    
     if(fp == NULL){
        printf("Something went wrong.Try again.\n");
        return 0;
     }

     while(fread(&E,sizeof(E),1,fp)){
            if(strcmp(name,E.name) == 0 && id == E.id){
                printf("You logged in successfully.\n");
                flag++;
                break;
            }
     }

     fclose(fp);

     if( flag == 0){
          return 0;
     }

     return E.id;
}