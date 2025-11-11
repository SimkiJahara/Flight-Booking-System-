#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//All Structures

 struct DATE
 {
 int dep;
 int des;
 };
 struct seat
 {
 char type[20];
 int adultseat_price;
 int childseat_price;
 };
struct passenger
 {
 char adult_name[40];
 int passport_no;
 int adult_birth_date_day;
 int adult_birth_date_month;
 int adult_birth_date_year;
 int adult_contact;
 char adult_email[40];
 char adult_gender[5];
 char adult_address[30];
 char adult_l[2];
 int adult_u_id;
 char child_name[40];
 int child_birth_date_day;
 int child_birth_date_month;
 int child_birth_date_year;
 int child_contact;
 char child_email[40];
 char child_gender[5];
 char child_address[30];
 char child_l[2];
 int child_u_id;
 };

//functions

void welcome_message();
void bookflight(struct passenger P[100]);
void travellars(int departure_airport, int destination_airport,struct passenger P[100]);
void information(int adult, int child,struct passenger P[100]);
void payment(float TOTAL);
void check();
void cancel(struct passenger P[100]);
void show(struct passenger *p1, int child, int adult);

//Global Variables

int n1;
int n2;
int n3;




int main(){
 struct passenger P[100];
 int choice, exit=0;
 char key;
 while(exit!=1){
 welcome_message();

 //intro
 printf("\t\t\t\t\t Enter any key to continue: ");
 scanf("%c", &key);
 printf("\n\n\n\n you can select the listed options:\n\n");
 printf(" 1) Book a flight\n\n");
 printf(" 2) Cancel your flight\n\n");
 printf(" 3) Check your flight status\n\n");
 printf(" 4) Exit to the intro\n\n");
 printf(" Enter the number of your choice: ");

 scanf("%d",&choice);

 switch(choice)
 {
 case 1: bookflight(P);
 break;
 case 2: cancel(P);
 break;
 case 3: check(P);
 break;
 case 4: {
 welcome_message();
 printf("\t\t\t\t\tThank you for visiting our server.\n\n");
 }
 break;
 default: printf("\t\tPlease enter again.\n");
 break;
 }
 printf("\n\n\n\t\t\t\t\t Do you want to exit?\n\n\n\t\t\t\t\t 1.Yes\t 2.No\n\n");
 printf("\t\t\t\t Enter the number of your choice: ");
 scanf("%d",&exit);
 printf("\n\n");
 }
 return 0;
}

//Welcome Message
void welcome_message()
{
 printf("\n\n\t\t\t https://BookMyFlight.com \n\n\n");
 printf("\t\t\t*********************************************************************\n");
 printf("\t\t\t^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n");
 printf("\t\t\t_____________________________________________________________________\n");
 printf("\t\t\t | ___________________ | \n");
 printf("\t\t\t | | WELCOME | | \n");
 printf("\t\t\t | | TO | | \n");
 printf("\t\t\t | | BOOK MY FLIGHT | | \n");
 printf("\t\t\t | |_________________| | \n");
 printf("\t\t\t______________________|_____________________|________________________\n\n");
 printf("\t\t\t^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n");
 printf("\t\t\t*********************************************************************\n\n\n");
 printf("\t\t\tWe provide flights for national travels at a reasonable price.\n\n\n\n");
}

//Choose airport from here

void bookflight(struct passenger P[100])
{
 int i,choice1, choice2, count=0;

 char Airport[7][50]={
 "Hazrat Shahjalal International Airport, Dhaka",
 "Shah Amanat International Airport, Chittagong",
 "Shah Makhdum Airport, Rajshahi",
 "Barisal Airport, Barisal",
 "Jashore Airport, Jashore",
 "Saidpur Airport, Saidpur",
 "Osmani International Airport, Sylhet"
 };

 printf("\n\n\n Domestic Flights:\n\n\n");

 printf("\t\tDeparture Airport: \n\n");

 for(i=0; i<7; i++)
 {
 count++;
 printf("\t\t%d) %s\n\n", count, Airport[i]);
 }

 printf("\n\t\tEnter the number of your choice: ");
 scanf("%d", &choice1);
 printf("\n\n\n You choose- %s.\n\n", Airport[choice1-1]);

 count=0;
 printf("\n\n-----------------------------------------------------------------------------------------------------------------------\n");
 printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n\n");
 printf("\t\tDestination Airport: \n\n");

 for(i=0; i<7; i++)
 {
 if(i!=(choice1-1))
 {
 count++;
 printf("\t\t%d) %s\n\n", count, Airport[i]);
 }
 }

 printf("\n\t\tEnter the number of your choice: ");
 scanf("%d", &choice2);
 printf("\n\n\n You choose- %s.\n\n", Airport[choice2-1]);

 travellars(choice1, choice2,P);
}

//Choose Date , Time , Seats

void travellars(int departure_airport, int destination_airport,struct passenger P[100])
{
 int w=1,q=1,A1,A2,i,j,count=0,adult, child,class,choice,choice2;


 struct DATE D[42] = {
 {1,1},
 {1,2},
 {1,3},
 {1,4},
 {1,5},
 {1,6},
 {2,1},
 {2,2},
 {2,3},
 {2,4},
 {2,5},
 {2,6},
 {3,1},
 {3,2},
 {3,3},
 {3,4},
 {3,5},
 {3,6},
 {4,1},
 {4,2},
 {4,3},
 {4,4},
 {4,5},
 {4,6},
 {5,1},
 {5,2},
 {5,3},
 {5,4},
 {5,5},
 {5,6},
 {6,1},
 {6,2},
 {6,3},
 {6,4},
 {6,5},
 {6,6},
 {7,1},
 {7,2},
 {7,3},
 {7,4},
 {7,5},
 {7,6}
 };


 int date[42][14]= {
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*1D-C*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*2D-R*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*3D-B*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*4D-J*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*5D-S*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*6D-Sy*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*7C-D*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*8C-R*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*9C-B*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*10C-J*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*11C-S*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*12C-Sy*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*13R-D*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*14R-C*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*15R-B*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*16R-J*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*17R-S*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*18R-Sy*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*19B-D*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*20B-C*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*21B-R*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*22B-J*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*23B-S*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*24B-Sy*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*25J-D*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*26J-C*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*27J-R*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*28J-B*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*29J-S*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*30J-Sy*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*31S-D*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*32S-C*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*33S-R*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*34S-B*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*35S-J*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*36S-Sy*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*37Sy-D*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*38Sy-C*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*39Sy-R*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*40Sy-B*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*41Sy-J*/
 25,26,27,28,29,30,31,1,2,3,4,5,6,7, /*42Sy-S*/};

 char depart_time[5][10]={"08:00 AM","11:00 AM","03:00 PM","5:00 PM","08:00PM"};
 char arrival_time[5][10]={"08:50 AM","11:50 AM","03:50 PM","5:50 PM","08:50PM"};

 printf("\n\n----------------------------------------------------------------------------------------------------------------------\n");
 printf("\n-----------------------------------------------------------------------------------------------------------------------\n\n\n");

 printf("\t\tSelect your prefered date of travel:\n\n");

 while(w==1)
 {
 for(i=0; i<42; i++)
 {
 if(D[i].dep==departure_airport)
 {
 if(D[i].des==destination_airport)
 {
 for(j=0; j<14; j++)
 {
 A1=i;
 count++;
 if(date[i][j]>=25 && date[i][j]<=31)
 printf("\t\t%d) %d/12/2022\n",count,date[i][j]);
 if(date[i][j]>=1 && date[i][j]<=7)
 printf("\t\t%d) %d/01/2023\n",count,date[i][j]);
 }
 }
 }
 }

 count=0;

 printf("\n\t\tEnter the number of your choice: ");
 scanf("%d", &choice);

 if(date[A1][choice-1]>=25 && date[A1][choice-1]<=31)
 printf("\n\n You choose- %d/12/2022.\n\n", date[A1][choice-1]);
 if(date[A1][choice-1]>=1 && date[A1][choice-1]<=7)
 printf("\n\n You choose- %d/01/2023.\n\n", date[A1][choice-1]);

 if(date[A1][choice-1] == date[A1][0] || date[A1][choice-1] == date[A1][5] || date[A1][choice-1] == date[A1][6] || date[A1][choice-1] == date[A1][7] || date[A1][choice-1] == date[A1][1])
 {
 printf("\t\tSorry there's no flight available in this route.\n\n");
 printf("\t\tSelect another date:\n\n");
 continue;
 }

 if(date[A1][choice-1] == date[A1][4] || date[A1][choice-1] == date[A1][8] || date[A1][choice-1] == date[A1][12])
 {
 printf("\n\n--------------------------------------------------------------------------------------------------------------\n");
 printf("\n--------------------------------------------------------------------------------------------------------------------\n\n\n");
 printf("\t\tFlight available in this route.\n\n");
 while(q==1)
 {
 printf("\t\tAvailable departure time:\n\n");
 printf("\t\t1) %s\n\n\t\t2) %s\n\n",depart_time[0],depart_time[3]);
 printf("\n\t\tEnter the number of your choice: ");
 scanf("%d", &choice2);
 if(choice2==1)
 printf("\n\n\n You choose- %s:\n\n", depart_time[0]);
 if(choice2==2)
 printf("\n\n\n You choose- %s:\n\n", depart_time[3]);
 printf("\n\n---------------------------------------------------------------------------------------------------------------\n");
 printf("\n---------------------------------------------------------------------------------------------------------------------\n\n\n");
 printf("\t\tOnly 3 seats availavle.\n\n");
 printf("\t\tEnter number of travellers:\n\n");
 printf("\t\tAdult: ");
 scanf("%d", &adult);
 printf("\n\t\tChild (under the age of 12): ");
 scanf("%d", &child);

 printf("\n\n\t\ttotal travellers: %d (Adults: %d, Child: %d)\n\n", (adult+child), adult, child);

 if((adult+child)>3)
 {
 printf("\t\tSorry not enough seat available\n\n");
 printf("\t\tSelect another time:\n\n");
 continue;
 }
 else
 {
 information(adult, child,P);
 q=0;

 }
 }
 }


 if(date[A1][choice-1] == date[A1][2] || date[A1][choice-1] == date[A1][10] || date[A1][choice-1] == date[A1][13])
 {
 q=1;
 printf("\n\n---------------------------------------------------------------------------------------------------------------\n");
 printf("\n---------------------------------------------------------------------------------------------------------------------\n\n\n");
 printf("\t\tFlight available in this route.\n\n");
 while(q==1)
 {
 printf("\t\tAvailable departure time:\n\n");
 printf("\t\t1) %s\n\n\t\t2) %s\n\n\t\t3) %s\n\n",depart_time[1],depart_time[3],depart_time[4]);
 printf("\n\t\tEnter the number of your choice: ");
 scanf("%d", &choice2);
 if(choice2==1)
 printf("\n\n\n You choose- %s:\n\n", depart_time[1]);
 if(choice2==2)
 printf("\n\n\n You choose- %s:\n\n", depart_time[3]);
 if(choice2==3)
 printf("\n\n\n You choose- %s:\n\n", depart_time[4]);
 printf("\n\n---------------------------------------------------------------------------------------------------------------\n");
 printf("\n---------------------------------------------------------------------------------------------------------------------\n\n\n");
 printf("\t\t15 seats available.\n\n");
 printf("\t\tEnter number of travellers:\n\n");
 printf("\t\tAdult: ");
 scanf("%d", &adult);
 printf("\n\t\tChild (under the age of 12): ");
 scanf("%d", &child);

 printf("\n\n\t\ttotal travellers: %d (Adults: %d, Child: %d)\n\n", (adult+child), adult, child);

 if((adult+child)>15)
 {
 printf("\t\tSorry not enough seat available\n\n");
 printf("\t\tSelect another time:\n\n");
 continue;
 }
 else
 {
 information(adult, child,P);
 q=0;
 }
 }
 }

 if(date[A1][choice-1] == date[A1][3] || date[A1][choice-1] == date[A1][9] || date[A1][choice-1] == date[A1][11])
 {
 q=1;
 printf("\n\n---------------------------------------------------------------------------------------------------------------\n");
 printf("\n---------------------------------------------------------------------------------------------------------------------\n\n\n");
 printf("\t\tFlight available in this route.\n\n");
 while(q==1)
 {
 printf("\t\tAvailable departure time:\n\n");
 printf("\t\t1) %s\n\n\t\t2) %s\n\n\t\t3) %s\n\n",depart_time[0],depart_time[2],depart_time[4]);
 printf("\n\t\tEnter the number of your choice: ");
 scanf("%d", &choice2);
 if(choice2==1)
 printf("\n\n\n You choose- %s:\n\n", depart_time[0]);
 if(choice2==2)
 printf("\n\n\n You choose- %s:\n\n", depart_time[2]);
 if(choice2==3)
 printf("\n\n\n You choose- %s:\n\n", depart_time[4]);
 printf("\n\n---------------------------------------------------------------------------------------------------------------\n");
 printf("\n---------------------------------------------------------------------------------------------------------------------\n\n\n");
 printf("\t\t25 seats available.\n\n");
 printf("\t\tEnter number of travellers:\n\n");
 printf("\t\tAdult: ");
 scanf("%d", &adult);
 printf("\n\t\tChild (under the age of 12): ");
 scanf("%d", &child);

 printf("\n\n\t\ttotal travellers: %d (Adults: %d, Child: %d)\n\n", (adult+child), adult, child);

 if((adult+child)>25)
 {
 printf("\t\tSorry not enough seat available\n\n");
 printf("\t\tSelect another time:\n\n");
 continue;
 }
 else
 {
 information(adult, child,P);
 q=0;
 }
 }
 }
 w=0;
 }
}

void information(int adult, int child,struct passenger P[100])
{
 double any;
 int i,count=0,class,extra,choice;
 float total,tax,TOTAL;

 struct seat T[3]= {
 {"Economy",2500,2000},
 {"Bussiness",3000,2500},
 {"First Class",3500,3000}
 };

 printf("\n\n---------------------------------------------------------------------------------------------------------------\n");
 printf("\n---------------------------------------------------------------------------------------------------------------------\n\n\n");
 printf("\t\tSeat type:\n\n");

 for(i=0; i<3; i++)
 {
 count++;
 printf("\t\t%d) %s\n\n", count,T[i].type);
 }

 printf("\n\t\tTicket price list:\n");
 printf("\t\t-----------------------------------------------------------------------------------\n");
 printf("\t\t|| Seat Type || Adult(Per person) || Child - Under age 12 (Per person) ||\n");
 printf("\t\t-----------------------------------------------------------------------------------\n");
 printf("\t\t|| Economy || 2500 || 2000 ||\n");
 printf("\t\t|| Business || 3000 || 2500 ||\n");
 printf("\t\t|| First Class || 3500 || 3000 ||\n");
 printf("\t\t-----------------------------------------------------------------------------------\n");
 printf("\t\t5%% VAT will be included.\n\n\n");

 printf("\n\t\tEnter the number of your choice: ");
 scanf("%d", &class);
 printf("\n\n\n You choose- %s:\n\n", T[class-1].type);


 printf("\n\t\tTo carry an extra bag you have to pay extra 450 taka\n\n\t\t(Per person can carry only one extra bag weight under 4kg.)\n\n");
 printf("\n\t\tDo you want to carry extra bag?\n\n\t\t1) Yes\n\n\t\t2) No\n\n");
 printf("\n\t\tEnter the number of your choice: ");
 scanf("%d",&choice);

 if (choice==1){
 if(adult+child==1)
 {
 printf("\n\n\t\tSeat type: %s\n\n\t\tTotal:\n\n\t\tAdult- %dx%d\n\n\t\tChild- %dx%d\n\n\t\tExtra bag - 450\n\n", T[class-1].type,adult,T[class-1].adultseat_price,child,T[class-1].childseat_price);
 printf("\t\t---------------------\n\n");
 total = (adult*T[class-1].adultseat_price)+(child*T[class-1].childseat_price);
 printf("\t\t\t %.3f\n\n", total+450);
 tax = (float)total*0.05;
 printf("\t\t5%% VAT(+) - %.3f\n\n", tax);
 printf("\t\t---------------------\n\n");
 TOTAL = total+tax+450;
 printf("\t\t\t %.3f\n\n", TOTAL);
 }
 else
 {
 printf("\n\t\tHow many extra bag(s) do you want to carry?\n\t\t(You can carry upto %d bags according to the number of travellers.)\n\n\t\tEnter the number of bag(s): ", adult+child);
 scanf("%d",&extra);
 if(extra<=(adult+child))
 {
 printf("\n\t\tSeat type: %s\n\n\t\tTotal:\n\n\t\tAdult- %dx%d\n\n\t\tChild- %dx%d\n\n\t\tExtra bag - %d\n\n", T[class-1].type,adult,T[class-1].adultseat_price,child,T[class-1].childseat_price,extra*450);
 printf("\t\t---------------------\n\n");
 total = (adult*T[class-1].adultseat_price)+(child*T[class-1].childseat_price);
 printf("\t\t\t %.3f\n\n", total+(extra*450));
 tax = (float)total*0.05;
 printf("\t\t5%% VAT(+) - %.3f\n\n", tax);
 printf("\t\t---------------------\n\n");
 TOTAL = total+tax+(extra*450);
 printf("\t\t\t %.3f\n\n", TOTAL);
 }
 }
 }
 else if(choice==2)
 {
 printf("\n\t\tSeat type: %s\n\n\t\tTotal:\n\n\t\tAdult- %dx%d\n\n\t\tChild- %dx%d\n\n", T[class-1].type,adult,T[class-1].adultseat_price,child,T[class-1].childseat_price);
 printf("\t\t---------------------\n\n");
 total = (adult*T[class-1].adultseat_price)+(child*T[class-1].childseat_price);
 printf("\t\t\t %.3f\n\n", total);
 tax = (float)total*0.05;
 printf("\t\t5%% VAT(+) - %.3f\n\n", tax);
 printf("\t\t---------------------\n\n");
 TOTAL = total+tax;
 printf("\t\t\t %.3f\n\n", TOTAL);
 } 

 printf("\t\tEnter any key to continue: ");
 scanf("%lf", &any);
 printf("\n\n---------------------------------------------------------------------------------------------------------------\n");
 printf("\n---------------------------------------------------------------------------------------------------------------------\n\n\n");
 printf("\n\n\t\tEnter personal information:\n ");

 count=0;
 int unique_id=2345;
 int j,k;

 for(i=0; i<adult; i++)
 {
 count++;
 printf("\n\t\tPassenger(Adult)-%d:\n", count);
 printf("\n\t\tName: ");
 scanf("%s", P[i].adult_name);
 printf("\n\t\tNID no: ");
 scanf("%d",&P[i].passport_no);
 printf("\n\t\tBirth date: \n");
 printf("\t\tDay- ");
 scanf("%d",&P[i].adult_birth_date_day);
 printf("\t\tMonth-");
 scanf("%d",&P[i].adult_birth_date_month);
 printf("\t\tYear-");
 scanf("%d",&P[i].adult_birth_date_year);
 printf("\t\tBirthdate: %d/%d/%d\n",P[i].adult_birth_date_day,P[i].adult_birth_date_month,P[i].adult_birth_date_year);
 printf("\n\t\tGender (Male/Female/Others): ");
 scanf("%s", P[i].adult_gender);
 printf("\n\t\tContact number: ");
 scanf("%d", &P[i].adult_contact);
 printf("\n\t\tEmail Address: ");
 scanf("%s", P[i].adult_email);
 printf("\n\t\tAddress: ");
 scanf("%s", P[i].adult_address);
 fflush(stdin);
 printf("\n\n\n\t\t\t A B C D\n");
 printf("\n\t\t\t1 * * * *\n");
 printf("\n\t\t\t2 * * * *\n");
 printf("\n\t\t\t3 * * * *\n");
 printf("\n\t\t\t4 * * * *\n");
 printf("\n\t\t\t5 * * * *\n");
 printf("\n\t\t\t6 * * * *\n");
 printf("\n\t\t\t7 * * * *\n");
 printf("\n\t\t\t8 * * * *\n");
 printf("\n\t\t\t9 * * * *\n");
 printf("\n\n\t\t(Here A B C D means Lane and * means Seats)\n\n");
 printf("\n\t\tWhich seat do you want to choose?\n\t\t(for example: 3B means lane B & seat no. 3)\n\n");
 printf("\t\tEnter your choice: ");
 scanf(" %s",P[i].adult_l);
 P[i].adult_u_id=unique_id;
 printf("\n\t\tYour unique id is:%d",P[i].adult_u_id);
 unique_id++;
 }
 n1=(count+child);
 n2=count;
 n3=adult;
 for(i=0; i<child; i++)
 {
 count++;
 printf("\n\n\n\t\tPassenger(Child)-%d:\n", count);
 printf("\n\t\tName:");
 scanf("%s", P[i].child_name);
 printf("\n\t\tBirth date: \n");
 printf("\n\t\tDay- ");
 scanf("%d",&P[i].child_birth_date_day);
 printf("\n\t\tMonth-");
 scanf("%d",&P[i].child_birth_date_month);
 printf("\n\t\tYear-");
 scanf("%d",&P[i].child_birth_date_year);
 printf("\t\tBirthdate: %d/%d/%d\n",P[i].child_birth_date_day,P[i].child_birth_date_month,P[i].child_birth_date_year);
 printf("\n\t\tGender (Male/Female/Others): ");
 scanf("%s", P[i].child_gender);
 printf("\n\t\tContact number: ");
 scanf("%d", &P[i].child_contact);
 printf("\n\t\tEmail Address: ");
 scanf("%s", P[i].child_email);
 printf("\n\t\tAddress: ");
 scanf("%s", P[i].child_address);
 fflush(stdin);
 printf("\n\n\n\t\t\t A B C D\n");
 printf("\n\t\t\t1 * * * *\n");
 printf("\n\t\t\t2 * * * *\n");
 printf("\n\t\t\t3 * * * *\n");
 printf("\n\t\t\t4 * * * *\n");
 printf("\n\t\t\t5 * * * *\n");
 printf("\n\t\t\t6 * * * *\n");
 printf("\n\t\t\t7 * * * *\n");
 printf("\n\t\t\t8 * * * *\n");
 printf("\n\t\t\t9 * * * *\n");
 printf("\n\n\t\t(Here A B C D means Lane and * means Seats)\n\n");
 printf("\n\n\t\tWhich seat do you want to choose?\n\t\t(for example: 3B means lane B & seat no. 3)\n\n");
 printf("\t\tEnter your choice: ");
 scanf(" %s",P[i].child_l);
 P[i].child_u_id=unique_id;
 printf("\n\t\tYour Unique id is:%d",P[i].child_u_id);
 unique_id++;

 }
 payment(TOTAL);

 printf("\n\n---------------------------------------------------------------------------------------------------------------\n");
 printf("\n---------------------------------------------------------------------------------------------------------------------\n\n");

 show(P,child,adult);

 FILE *the_file = fopen("passenger_info.txt", "a");

 for(i=0; i<(adult); i++)
 {
 fprintf(the_file, "\n\n\t\tPassenger(Adult)-%d:\n\n\t\tName: %s\n\n\t\tNID No: %d\n\n\t\tBirthdate: %d/%d/%d\n\n\t\tContact Number: %d\n\n\t\tEmail Address: %s\n\n\t\tGender: %s\n\n\t\tAddress: %s\n\n\t\tSeat no.: %s\n\n\t\tUnique id is: %d",
 i+1,P[i].adult_name,P[i].passport_no,P[i].adult_birth_date_day,P[i].adult_birth_date_month,P[i].adult_birth_date_year,P[i].adult_contact,P[i].adult_email,P[i].adult_gender,P[i].adult_address, P[i].adult_l, P[i].adult_u_id);
 }
 for(i=0; i<child; i++)
 {
 fprintf(the_file, "\n\n\t\tPassenger(Child)-%d:\n\n\t\tName: %s\n\n\t\tBirthdate: %d/%d/%d\n\n\t\tContact Number: %d\n\n\t\tEmail Address: %s\n\n\t\tGender: %s\n\n\t\tAddress: %s\n\n\t\tSeat no.: %s\n\n\t\tUnique id is: %d",
 i+1,P[i].child_name,P[i].child_birth_date_day,P[i].child_birth_date_month,P[i].child_birth_date_year,P[i].child_contact,P[i].child_email,P[i].child_gender,P[i].child_address,P[i].child_l, P[i].child_u_id);
 }

 fprintf(the_file, "\n\n\t\tSeat type: %s\n\n\t\tTotal:\n\n\t\tAdult- %dx%d\n\n\t\tChild- %dx%d\n\n\t\tExtra bag - %dx450\n\n", T[class-1].type,adult,T[class-1].adultseat_price,child,T[class-1].childseat_price,extra);
 fprintf(the_file, "\n\n\t\t-------------------\n\n %.3f\n\n\t\t5%% tax(+)- %.3f\n\n-------------------\n\n %.3f\n\n", total,tax,TOTAL);
 printf("\n\n\t\t\t\t Sever has been updated successfully.\n");

 fclose(the_file);

}


void payment(float TOTAL)
{ int way,bank,acc_num,phone,coupon,extra,bag,expire_month,expire_year,cvc,code;
 char acc_name[40];

 printf("\n\n\n---------------------------------------------------------------------------------------------------------------\n");
 printf("\n---------------------------------------------------------------------------------------------------------------------\n\n");

 printf("\n\n\t\tTotal payable amount: %.2f", TOTAL);
 printf("\n\n\t\tATTENTION: If you cancel your flight at least 5 days prior the flight date,\n\n\t\tyou will be refunded 50 percent of the paid amount.");
 printf("\n\n\t\tIF you cancel the day before the flight date, no amount will be refunded");
 printf("\n\n\n\n\t\tAvailable Payment Method:\n\n\t\t1.Bank\n\n\t\t2.Credit Card\n");
 printf("\n\t\tEnter the number of your choice: ");
 scanf("%d",&way);

 switch(way){
 case 1:{
 printf("\n\n\t\tWe accept payment from following banks:\n");
 printf("\n\t\t1) Brac Bank\n\n\t\t2) Southeast Bank\n\n\t\t3) DBBL Bank\n\n\t\t4) Dutch-Bangla bank\n\n");
 printf("\n\t\tEnter the number of your choice: ");
 scanf(" %d", &bank);
 fflush(stdin);
 printf("\n\n\t\tEnter account holder's name: ");
 scanf("%s", acc_name);
 printf("\n\t\tEnter your account number:");
 scanf("%d",&acc_num);
 printf("\n\t\tEnter phone number to receive varification code: ");
 scanf("%d", &phone);
 printf("\n\n\t\tVarification Code has been sent to your phone number.\n\n\n\t\tPlease enter the code: ");
 scanf("%d",&code);
 printf("\n\n\n\t\tPayment process is successful. Your booking is confirmed. Booking confirmation has been sent to your email address.\n\n");
 }
 break;
 case 2:{
 printf("\n\n\t\tEnter account holder's name: ");
 scanf("%s", acc_name);
 printf("\n\t\tEnter your credit card number:");
 scanf("%d",&acc_num);
 printf("\n\t\tEnter Expiration date:");
 printf("\n\n\t\tMonth - ");
 scanf("%d",&expire_month);
 printf("\n\t\tYear - ");
 scanf("%d",&expire_year);
 printf("\n\t\tExpiration date: %d/%d",expire_month,expire_year);
 printf("\n\n\t\tEnter CVC/4DBC number: ");
 scanf("%d", &cvc);
 printf("\n\t\tEnter phone number to receive varification code: ");
 scanf("%d", &phone);
 printf("\n\n\t\tVarification Code has been sent to your phone number.\n\n\n\t\tPlease enter the code: ");
 scanf("%d",&code);
 printf("\n\n\n\t\tPayment process is successful. Your booking is confirmed. Booking confirmation has been sent to your email address.\n\n");
 }
 break;
 default: printf("\n\n\t\tEnter again.\n");
 }
}


 void show(struct passenger *p1, int child, int adult)
 {
 printf("\n\n\t\tHere is all the Passenger's main information:\n");
 for(int i=0;i<adult;i++)
 {
 printf("\n\n\t\tPassenger - %d:\n\n\t\tName: %s\n\n\t\tNID: %d\n\n\t\tGender: %s\n\n\t\tBirthdate: %d/%d/%d\n\n\t\tPhone number: %d\n\n\t\tEmail Address: %s\n\n\t\tAddress: %s\n\n\t\tUnique id : %d",
 i+1,(p1+i)->adult_name,(p1+i)->passport_no,(p1+i)->adult_gender,(p1+i)->adult_birth_date_day,(p1+i)->adult_birth_date_month,(p1+i)->adult_birth_date_year,(p1+i)->adult_contact,(p1+i)->adult_email,(p1+i)->adult_address,(p1+i)->adult_u_id);
 }
 for(int i=0; i<child; i++)
 {
 printf("\n\n\t\tPassenger - %d:\n\n\t\tName: %s\n\n\t\tGender: %s\n\n\t\tBirthdate: %d/%d/%d\n\n\t\tPhone number: %d\n\n\t\tEmail Address: %s\n\n\t\tAddress: %s\n\n\t\tUnique id : %d",
 i+1,(p1+i)->child_name,(p1+i)->child_gender,(p1+i)->child_birth_date_day,(p1+i)->child_birth_date_month,(p1+i)->child_birth_date_year,(p1+i)->child_contact,(p1+i)->child_email,(p1+i)->child_address,(p1+i)->child_u_id);
 }

 printf("\n\n\n\t\t\t\tThank you for using our server. Have a safe flight.\n\n");
 }
void check()
{
 printf("\n\n");
 char ch[100];
 FILE*the_file;
 the_file=fopen("passenger_info.txt","r") ;
 while(!feof(the_file))
 {
 fgets(ch,99,the_file);
 printf("%s",ch);
 }
 fclose(the_file);
}


void cancel(struct passenger P[100])
{ 
 int i;

 printf("\n\n\t\tAre you sure you want to cancel your flight? you will not be refunded the full paid amount.");
 printf("\n\n\t\tIf you cancel at least 5 days prior the flight date, you will be refunded 50 percent of the paid amount.");
 printf("\n\n\n\t\tIF you cancel the day before the flight date, no amount will be refunded."); 
 printf("\n\n\n\t\t\t\t\tDo you still want to cancel?\n\n\t\t\t\t\t 1.Yes\t 2.No");
 printf("\n\n\t\t\t\t Enter the number of your choice: ");
 scanf("%d",&i);

 if(i==1){
 FILE*the_file;
 the_file=fopen("passenger_info.txt","w");
 fprintf(the_file,"\n\n\t\t\t\t The information has been deleted.");
 fclose(the_file);
 check();
 printf("\n\n\t\t\t\t Server has been updated successfully.");
 printf("\n\n\t\t\t\t Thank you for using our server.");
 }
 else{
 printf("\n\n\t\t\t\t Thank you for using our server.");
 }

}
