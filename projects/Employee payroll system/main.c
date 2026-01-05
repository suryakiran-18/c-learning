#include<stdio.h>
#include"operation.h"
#include"auth.h"

int main(){
      // To display menu..
      int is_login = 0;
      int id = 0;
      int choice;
      do{
          printf("____Welcome to our company____\n");
          printf("Select one option below.\n");
          printf("1.Adding details of new employee.\n");
          printf("2.Calculate your salary.\n");
          printf("3.Generate pay slip.\n");
          printf("4.To exit.\n");
          scanf("%d",&choice);

          // Directing to related operation..
        
          if(choice == 1){
               add_employee();
          }
          else{
            if(is_login == 0){
                   id = login();
                   is_login++;
            }
            if(id == 0){
                printf("You have entered wrong details.\n");
                continue;
            } 
            else {
                switch(choice){
                    
                    case 2 : calculate_salary(id);
                             break;        
                    case 3 : generate_payslip(id);
                             break;
                    case 4 : printf("Thank you..\n");
                             break;
                    default : printf("Invalid choice.Try again.\n");
                              break;
                } 
            }
          }  
      }while(choice != 4);
  return 0;
}
