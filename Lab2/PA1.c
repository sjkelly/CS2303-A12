/* PA1.c -- Stephen Kelly CS2303-A03

*/

#include <stdio.h>

char isLeapYear(int y){
	if((y % 4) == 0 && ((y % 100) != 0 || (y % 400) == 0)){
		return 1;
	}
	else{
		return 0;
	} 
}

char getStartDay(int year){
	int yearDiff,startDay = 0, i;
	//calculate starting day of the year using Sunday, Jan. 1st 2012 as reference
	if(year<2012){
		yearDiff = 2012 - year;
		for(i=1; i<=yearDiff; i++){
			if(isLeapYear(2012-i))startDay+=366;
			else startDay+=365;
		}
		startDay%=7;
		startDay = (startDay==0)?1:8-startDay; //This is a correction since if calculates the day backwards from reference
	}
	else if(year==2012){
		startDay = 1;
	}
	else if(year>2012){
		yearDiff = year - 2012;
		startDay = 366;
		for(i=1; i<yearDiff; i++){
			if(isLeapYear(2012+i))startDay+=366;
			else startDay+=365;
		}
		startDay%=7;
		startDay++; //the days start at 1 so increment 
	}
	return startDay;
}

char printMonthName(int year, int month){
	int dayCount;
	switch (month){
	case 0:
		printf("January %d\n", year);
		dayCount = 31;
		break;
	case 1:
		printf("February %d\n", year);
		if(isLeapYear(year)) dayCount = 29;
		else dayCount = 28;
		break;
	case 2:
		printf("March %d\n", year);
		dayCount = 31;
		break;
	case 3:
		printf("April  %d\n", year);
		dayCount = 30;	
		break;
	case 4:
		printf("May %d\n", year);
		dayCount = 31;	
		break;
	case 5:
		printf("June %d\n", year);
		dayCount = 30;	
		break;
	case 6:
		printf("July %d\n", year);
		dayCount = 31;	
		break;
	case 7:
		printf("August %d\n", year);
		dayCount = 31;	
		break;
	case 8:
		printf("September %d\n", year);
		dayCount = 30;	
		break;
	case 9:
		printf("October %d\n", year);
		dayCount = 31;	
		break;
	case 10:
		printf("November %d\n", year);
		dayCount = 30;	
		break;
	case 11:
		printf("December %d\n", year);
		dayCount = 31;	
		break;
	}
	printf("Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
	return dayCount;
}

char printMonth(int year, int month, int startDay){
	int dayCount, i;
	
	dayCount = printMonthName(year, month);
	
	for(i = 1; i < startDay; i++) printf("     "); //space to staring point
	for(i = 1; i <= dayCount; i++){
		printf("%3d  ", i);
		if(startDay == 7){ //rollover to a new line
			printf("\n");
			startDay = 0;
		}
		startDay++;
	}
	
	//Evenly space all months
	if(startDay != 1)printf("\n\n");
	else printf("\n");

	return startDay;
}

void printCalendar(int year, char startDay){
	int i;
	for(i=0; i<12; i++){
		startDay = printMonth(year, i, startDay);  
	}
}

int main(void){
	//declare variables
	int year;
	int startDay =  0; //1 = Sun ... 7 = Sat

	//get user input	
	do{	
		printf("Please enter year for this calendar:-");
		scanf("%d", &year);
		if(year<0)printf("ERROR: Negative years not allowed\n");
	}while(year<0);
	printf("\t***\tCalendar for %d\t***\t\n",year);

	//Get starting day
	startDay = getStartDay(year);
	
	//Generate calendar
	printCalendar(year,startDay);

	return 0; //Execution successful!
}	//int main(void)
