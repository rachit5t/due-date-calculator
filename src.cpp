#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
using namespace std;


struct DATE{
        int year;
        int month;
        int day;
        char title[50];
    };

    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int total_day;
    int seconds;

int total_day_calculator(int year, int month, int day);
int current_day_calculator();
void read_file();
void write_file();

int main(){
    start:
    system("cls");
    read_file();
    write_file();
    goto start;
}

void read_file(){
    char two[20];
    char three[20];
    char four[20];
    DATE info_taker;
    FILE*my_file;
    my_file = fopen("Assignment_details.txt","r");
    cout<<"\t(The submission day is not counted but today is counted. If it\n\tsays 1 days remaining then it means tommorrow is submission and today is\n\tthe last day and 0 means today is the submission day)\n\n";
    cout<<"\t"<<"Title"<<"\t\t\t\t"<<"Urgent_level"<<"\t\t"<<"Remaining_days \n";
	while(fscanf(my_file, "%s %s %s %s", info_taker.title, two, three, four) == 4){
        info_taker.year = atoi(two);
        info_taker.month = atoi(three);
        info_taker.day = atoi(four);
        int difference;
        difference = total_day_calculator(info_taker.year, info_taker.month, info_taker.day) - current_day_calculator();
        if (difference > 14){
            cout<<"\t"<<info_taker.title<<"\t\t\t"<<"Green"<<"\t\t\t"<<difference<<"\n";
        } else if(difference > 7){
            cout<<"\t"<<info_taker.title<<"\t\t\t"<<"Yellow"<<"\t\t\t"<<difference<<"\n";
        } else if(difference > 3){
            cout<<"\t"<<info_taker.title<<"\t\t\t"<<"Red"<<"\t\t\t"<<difference<<"\n";
        }else {
            cout<<"\t"<<info_taker.title<<"\t\t\t"<<"Denger"<<"\t\t\t"<<difference<<"\n";
        }
        
    }
    fclose(my_file);
}


void write_file(){
    char add_confirm; 
    char confirm = 'y';
    DATE info_taker;
    cout<<" DO you want to add another Assignment? : ";
    scanf("%s",&add_confirm);
    if (add_confirm == confirm){
    cout<<" Type the Title : ";
    scanf("%s",&info_taker.title);
    cout<<" Type the year : ";
    scanf("%d",&info_taker.year);
    cout<<" Type the month : ";
    scanf("%d",&info_taker.month);
    cout<<" Type the day : ";
    scanf("%d",&info_taker.day);
    FILE*my_file;
    my_file = fopen("Assignment_details.txt","a");
	fprintf(my_file,"%s %d %d %d\n", info_taker.title, info_taker.year, info_taker.month, info_taker.day);
	fclose(my_file);
}
}

int total_day_calculator(int year, int month, int day){
    if (year % 4 == 0){
        days[1] = 29;
    }

total_day = day;
month = month - 2;
while (month > -1){
    total_day += days[month]; 
    month--;  
}



while (year > 1970){
    if (year % 4 == 0){
        days[1] = 29;
    } else {
        days[1] = 28;
    }
    month = 13;
     month = month - 2;
    while (month > -1){
    total_day += days[month];
    month--;
}
year--; 
}
return total_day;
}



int current_day_calculator(){
    time_t current_time;
    seconds = 0;
    current_time = time(NULL);
    seconds  = (current_time/86400) + 1;
    return seconds;
}