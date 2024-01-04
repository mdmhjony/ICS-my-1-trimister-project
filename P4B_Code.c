
//Blood Management System Project.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
 typedef struct {
    int serial;
    char id[50];
    char area[50];
    char name[50];
    char group[50];
    char phone[50];
    char date[50];
}Person;

Person person[300];
int total_person = 0;
void append(Person new_person);
void save();
void insert();
void show();
void searchByBlood(char group[]);
void searchByArea(char area[]);
void searchById(char id[]);
void searchByAreaWithBlood();
void search();
void read();
void update();
void updateDonateDate();
void cut();



//Our main function.
int main(){
    int option;
    read();
    printf("\n\n\n");
    char str1[50]="***********Welcome************";
    char str2[50]="***Blood Management System****";
    int i=0;
    for(i=0;i<strlen(str1);i++){
        printf("%c",str1[i]);
        Sleep(50);
    }
    printf("\n");
    for(i=0;i<strlen(str2);i++){
        printf("%c",str2[i]);
        Sleep(50);
    }
    printf("\n\n\n");
    do {
        Sleep(300);
        printf("---Please press one of the option below---\n\n");
        Sleep(200);
        printf("   Insert Info press----- <1>\n");
        printf("   Show All Info press--- <2>\n");
        printf("   Search Info press----- <3>\n");
        printf("   Update Info press----- <4>\n");
        printf("   Delete Info press----- <5>\n");
        printf("   Give Blood press------ <6>\n");
        printf("   Quit press------------ <0>\n\n");
        scanf("%d", &option);
        fflush(stdin);
        switch(option){
        case 1:
            printf("\n\n\n");
            insert();
            break;
        case 2:
            printf("\n\n\n");
            show();
            break;
        case 3:
            printf("\n\n\n");
            search();
            break;
        case 4:
            printf("\n\n\n");
            update();
            break;
        case 5:
            printf("\n\n\n");
            cut();
            break;
        case 6:
            printf("\n\n\n");
            updateDonateDate();
            break;
        case 0:
            printf("\n\n\n");
            Sleep(400);
            printf("******Thank You******\n\n");
            Sleep(500);
            break;
        default:
            printf("\n");
            Sleep(200);
            printf("  ---You press wrong---\n\n\n");
       }
    }while(option!=0);



    return 0;
}


void append(Person new_person) {
    person[total_person] = new_person;
    total_person++;

    FILE *file;
    file = fopen("local.txt", "a");
     if (file == NULL) {
        printf("Error in opening file");
        // EXIT_FAILURE
        exit(1);
    }
    fprintf(file,"%d %s %s %s %s %s %s\n",new_person.serial, new_person.id, new_person.name, new_person.group, new_person.area, new_person.phone, new_person.date);//save data in database in one line.
    fclose(file);
}

void save(){
    FILE *file;
    file = fopen("local.txt", "w");
     if (file == NULL) {
        printf("Error in opening file");
        // EXIT_FAILURE
        exit(1);
    }
    for(int i = 0; i <total_person; i++)
    {
        Person new_person = person[i];
        fprintf(file,"%d %s %s %s %s %s %s\n",new_person.serial, new_person.id, new_person.name, new_person.group, new_person.area, new_person.phone, new_person.date);//save data in database in one line
    }
    if(total_person == 0)
        fprintf(file, "");
    fclose(file);
}


void insert(){
    Sleep(200);
    printf("Give How Much Donor You Store: ");
    int donor;
    scanf("%d",&donor);
    fflush(stdin);
    for(int i=1;i<=donor;i++){
    printf("\n\n----Give Donor Info-----\n\n");
    Person temp;
    temp.serial=total_person;
    printf("  Donor ID: ");
    scanf("%s",&temp.id);
    fflush(stdin);
    printf("  Donor Name: ");
    scanf("%s",&temp.name);
    fflush(stdin);
    printf("  Blood Group: ");
    scanf("%s", &temp.group);
    fflush(stdin);
    printf("  Area: ");
    scanf("%s", &temp.area);
    fflush(stdin);
    printf("  Phone No: ");
    scanf("%s", &temp.phone);
    fflush(stdin);
    strcpy(temp.date,"Not-Given");
    append(temp);
   }
    Sleep(300);
    printf("\n---Inserted Info Successfully---\n\n");
}


void show() {
    printf("            Serial         ID          Name             Group        Area        Phone        Donate-Date\n");
    printf("-----------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i <total_person; i++) {
        printf("%14d %14s %14s %14s %14s %14s %14s\n",person[i].serial,person[i].id, person[i].name, person[i].group,person[i].area, person[i].phone, person[i].date);// print one line data in console from database.
    }
    printf("\n");
}


void searchByBlood(char group[]) {
    int i,flag=0;
    for(i = 0; i <total_person; i++) {
        if(strcmp(group, person[i].group) == 0){
            flag=1;
            break;
       }
    }
     if(flag==1){
        printf("           ID            Name           Group        Area        Phone         Donate-Date\n");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        for(i = 0; i <total_person; i++) {
            if(strcmp(group, person[i].group) == 0){
             printf("%14s %14s %14s %14s %14s %14s\n",person[i].id, person[i].name, person[i].group,person[i].area, person[i].phone,person[i].date);
         }


       }

    }
     else{
         printf("\n");
         Sleep(200);
         printf("---Not found any data---\n");
    }
    printf("\n");
}



void searchById(char id[]) {
    int i,flag=0;
    for(i = 0; i <total_person; i++) {
        if(strcmp(id, person[i].id) == 0){
            flag=1;
            break;
       }
    }
     if(flag==1){
        printf("           ID            Name           Group        Area        Phone         Donate-Date\n");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        for(int i =0; i <total_person; i++) {
            if(strcmp(id, person[i].id) == 0){
             printf("%14s %14s %14s %14s %14s %14s\n",person[i].id, person[i].name, person[i].group,person[i].area, person[i].phone,person[i].date);
         }
       }

    }
     else{
         printf("\n");
         Sleep(200);
         printf("---Not found any data---\n");
    }
    printf("\n");
}


void searchByArea(char area[]) {
    int i,flag=0;
    for(i = 0; i <total_person; i++) {
        if(strcmp(area, person[i].area) == 0){
            flag=1;
            break;
       }
    }
     if(flag==1){
        printf("           ID            Name           Group        Area        Phone         Donate-Date\n");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i <total_person; i++) {
            if(strcmp(area, person[i].area) == 0){
             printf("%14s %14s %14s %14s %14s %14s\n",person[i].id, person[i].name, person[i].group,person[i].area, person[i].phone,person[i].date);
         }
       }

    }
     else{
         printf("\n");
         Sleep(200);
         printf("---Not found any data---\n");
    }
    printf("\n");
}



void searchByAreaWithBlood(char area[],char group[]) {
    int i,flag=0;
    for(i = 0; i <total_person; i++) {
        if((strcmp(area, person[i].area) == 0) && (strcmp(group, person[i].group) == 0)){
            flag=1;
            break;
       }
    }
     if(flag==1){
        printf("           ID            Name           Group        Area        Phone         Donate-Date\n");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i <total_person; i++) {
            if((strcmp(area, person[i].area) == 0) && (strcmp(group, person[i].group) == 0)){
             printf("%14s %14s %14s %14s %14s %14s\n",person[i].id, person[i].name, person[i].group,person[i].area, person[i].phone,person[i].date);
         }
       }

    }
     else{
         printf("\n");
         Sleep(200);
         printf("---Not found any data---\n");
    }
    printf("\n");
}





void search() {
    int option;
    do{
    printf("  ---Please press one of the option below---\n\n\n");
    Sleep(300);
    printf("   Search By Blood Group press-<1>\n");
    printf("   Search By Id press ---------<2>\n");
    printf("   Search By Area press------- <3>\n");
    scanf("%d", &option);
    fflush(stdin);
       switch(option){
            case 1:
                printf("Enter Blood Group: ");
                char group[3];
                scanf("%s", &group);
                fflush(stdin);
                searchByBlood(group);
                break;
            case 2:
               printf("Enter ID: ");
               char id[3];
               scanf("%s", &id);
               fflush(stdin);
               searchById(id);
               break;
            case 3:
               printf("Enter Area: ");
               char area[3];
               scanf("%s", &area);
               fflush(stdin);
              do{
               printf("      ---Please press one of the option below---\n\n");
               printf("\n  Search Area all Info Press-------------------- <1>\n");
               printf("    Search Specific Blood Group At Any Area Press- <2>\n");
               scanf("%d",&option);
               fflush(stdin);
               switch(option){
                case 1:
                   searchByArea(area);
                   break;
                case 2:
                   printf("Enter Blood Group: ");
                   char group[3];
                   scanf("%s", &group);
                   fflush(stdin);
                   searchByAreaWithBlood(area,group);
                   break;

                default:
                   Sleep(200);
                   printf(" ---You press wrong---\n\n\n");
               }
              }while(option!=1 && option!=2);
               break;

            default:
               printf("\n");
               Sleep(200);
               printf(" ---You press wrong---\n\n\n");
        }
    }while(option!=1 && option!=2 && option!=3);


}


void read(){
    Person new_person;
    int i=0;
    FILE *file;
    file = fopen("local.txt", "r");
     if (file == NULL) {
        printf("Error in opening file");
        // EXIT_FAILURE
        exit(1);
    }

    while(fscanf(file,"%d %s %s %s %s %s %s",&new_person.serial, new_person.id, new_person.name, new_person.group, new_person.area, new_person.phone, new_person.date) !=EOF) {// read one by one  line.
        person[total_person++] = new_person;
        i++;
    }
}

void update(){
    int i,flag=0;
    char a[50];
    char b[50];
    printf("Enter ID: ");
    char id[50];
    scanf("%s", &id);
    fflush(stdin);
    for(i = 0; i <total_person; i++) {
        if(strcmp(id, person[i].id) == 0){
            flag=1;
            break;
       }
    }
     if(flag==1){
        printf("\n");
        printf("           ID            Name           Group        Area        Phone         Donate-Date\n");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("%14s %14s %14s %14s %14s %14s\n\n",person[i].id, person[i].name, person[i].group,person[i].area, person[i].phone,person[i].date);
        int check;
        do{
        printf("  ---Please press one of the option below---\n\n");
        printf("   Update Only Area Press------------ <1>\n");
        printf("   Update Only Phone No. Press------- <2>\n");
        printf("   Update Both Area & Phone No Press- <3>\n");
        printf("   Don't Update Press---------------- <4>\n");
        scanf("%d",&check);
        fflush(stdin);
        switch(check){
           case 1:
            printf("Update Area : ");
            scanf("%s",&a);
            fflush(stdin);
            strcpy(person[i].area,a);
            save();
            printf("\n---Updated Area Sucessfully---\n");
            break;
          case 2:
            printf("Update Phone No : ");
            scanf("%s",&b);
            fflush(stdin);
            strcpy(person[i].phone,b);
            save();
            printf("\n---Updated Phone No Sucessfully---\n");
            break;
          case 3:
            printf("Update Area : ");
            scanf("%s",&a);
            fflush(stdin);
            strcpy(person[i].area,a);
            printf("Update Phone No : ");
            scanf("%s",&b);
            fflush(stdin);
            strcpy(person[i].phone,b);
            save();
            printf("\n---Updated Area & Phone No Sucessfully---\n");
            break;
          case 4:
            printf("\n---No Update Any Info---\n");
            break;
          default:
            printf("\n");
            printf("   ---You press wrong---\n\n\n");

          }
      }while(check !=1 && check !=2&& check !=3&& check !=4);

  }

     else{

         printf("\n");
         Sleep(200);
         printf("---Not found any data---\n");
    }
    printf("\n");
}


void updateDonateDate(){
    int i,flag=0;
    char a[50];
    printf("Enter ID: ");
    char id[50];
    scanf("%s", &id);
    fflush(stdin);
    for(i = 0; i <total_person; i++) {
        if(strcmp(id, person[i].id) == 0){
            flag=1;
            break;
       }
    }
     if(flag==1){
        printf("\n");
        printf("           ID            Name           Group        Area        Phone         Donate-Date\n");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("%14s %14s %14s %14s %14s %14s\n\n",person[i].id, person[i].name, person[i].group,person[i].area, person[i].phone,person[i].date);
        int check;
        do{
        printf("--Please press one of the option below--\n\n");

        printf("   If You Want to Give Blood press- <1>\n");
        printf("   If You Don't Give Blood press--- <2>\n");
        scanf("%d",&check);
        fflush(stdin);
        switch(check){
         case 1:
            printf("Enter Blood Donate Date (MM/DD/YYYY): ");
            scanf("%s",&a);
            fflush(stdin);
            strcpy(person[i].date,a);
            save();
            printf("\n---You Given Blood---\n");
            break;
         case 2:
            printf("\n---Not Given Blood---\n");
            break;
         default:
            printf("\n");
            printf("  ---You press wrong---\n\n\n");

        }
    }while(check !=1 && check !=2);
  }

    else{

         printf("\n");
         Sleep(200);
         printf("---Not found any data---\n");
    }
    printf("\n");
}




 void cut(){
    int i,flag=0;
    printf("Enter Which ID Do You Want to Delete: ");
    char id[50];
    scanf("%s", &id);
    fflush(stdin);
    for( i = 0; i <total_person; i++) {
        if(strcmp(id, person[i].id) == 0){
            flag=1;
            break;
       }
    }

     if(flag == 1){
        printf("           ID            Name           Group        Area        Phone         Donate-Date\n");
        printf("-------------------------------------------------------------------------------------------------------------\n");
        printf("%14s %14s %14s %14s %14s %14s\n",person[i].id, person[i].name, person[i].group,person[i].area, person[i].phone,person[i].date);
        printf("\n\n");
        int check;
        do{
        printf("   ---Please press one of the option below---\n\n");

        printf("   If You Want Delete This Info press-- <1>\n");
        printf("   If You Don't Delete This Info press- <2>\n");
        scanf("%d",&check);
        fflush(stdin);
        switch(check){
         case 1:
            for(int j=i; j<total_person; j++){

               person[i].serial = person[i+1].serial-1;
               strcpy(person[i].id,person[i+1].id);
               strcpy(person[i].name,person[i+1].name);
               strcpy(person[i].group,person[i+1].group);
               strcpy(person[i].area,person[i+1].area);
               strcpy(person[i].phone,person[i+1].phone);
               strcpy(person[i].date,person[i+1].date);
               i++;
            }
             total_person--;
             printf("\n");
             Sleep(200);
             printf("---Deleted Data successfully---\n");
             save();
             break;
        case 2:
            printf("\n---Not Deleted Data---\n");
            break;
        default:
            printf("\n");
            printf("  ---You press wrong---\n\n\n");

        }
    }while(check !=1 && check !=2);

   }



     else{

         printf("\n");
         Sleep(200);
         printf("---Not found any data---\n");
    }
    printf("\n");
 }










