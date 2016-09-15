/*
Code written by HYDER SHAD, UT EID: hs25796
FALL 2016 EE 312 Software Design
Professor: BARBER
TA: NOLAN CORCORAN
9/1/2016
Assignment #2 - Conversions
*/

#include<stdio.h>
int main(void){
int conversion = 0;		//user input variable for conversion to execute
int exit = 0;			//serves as booleaan to exit conversion program

while (exit == 0) {								
	printf("\n");			//newline helps separate previous answers from new conversion requests
	printf("Conversion menu:\n");				//output full conversion menu to select from
	printf("1. Convert a given Austin time to Irish time\n");
	printf("2. Convert a given Irish time to Austin time\n");
	printf("3. Convert a given USD value to EUR\n");
	printf("4. Convert a given EUR value to USD value\n");
	printf("5. Convert a given Fahrenheit temperature to Celsius\n");
	printf("6. Convert a given Celsius temperature to Fahrenheit\n");
	printf("7. Convert a given weight in kg to pounds, ounces\n");
	printf("8. Convert a given weight in pounds, ounces to kg\n");
	printf("9. Convert a given distance in km to miles\n");
	printf("10. Convert a given distance in miles to km\n");
	printf("11. Stop doing conversions and quit the program\n");
	printf("Enter a number from the menu (1-11) to select a specific conversion to perform or quit.\n");
	scanf_s("%d", &conversion); //gets user input to determine conversion to execute
	getchar();
	printf("\n");  //helps with readability

	if (conversion == 1) {			
		unsigned int aus_hour = 0;
		unsigned int ire_hour = 0;
		unsigned int ire_min = 0;
		printf("Enter Austin time to be converted, expressed in hours and minutes: ");
		scanf_s("%d", &aus_hour);
		scanf_s("%d", &ire_min);
		ire_hour = (aus_hour + 6) % 24; // adds 6 to austin hour and determines whether it overflows into the next day
		if (aus_hour >= 18) {
			printf("The time in Ireland equivalent to %d ", aus_hour); //next day in ireland
			printf("%d", ire_min);
			printf(" in Austin is %d ", ire_hour);
			printf("%d", ire_min);
			printf(" of the next day.\n");  
		}
		if (aus_hour < 18) {
			printf("The time in Ireland equivalent to %d ", aus_hour); //same day in ireland
			printf("%d", ire_min);
			printf(" in Austin is %d ", ire_hour);
			printf("%d", ire_min);
			printf(" of the same day.\n");
		}

		conversion = 0; //reset conversion variable
	}
	if (conversion == 2) {
		unsigned int ire_hour = 0;
		unsigned int aus_hour = 0;
		unsigned int aus_min = 0;
		printf("Enter Irish time to be converted, expressed in hours and minutes: ");
		scanf_s("%d", &ire_hour);
		scanf_s("%d", &aus_min);
		aus_hour = ((ire_hour + 24) - 6) % 24; //subtracts 6 from ireland hour and determines if underflows into previous day
		if (ire_hour >= 6) {                                            //same day in autin
			printf("The time in Austin equivalent to %d ", ire_hour);
			printf("%d", aus_min);
			printf(" in Ireland is %d ", aus_hour);
			printf("%d", aus_min);
			printf(" of the same day.\n");
		}
		if (ire_hour < 6) {   //previous dy in austin
			printf("The time in Austin equivalent to %d ", ire_hour);
			printf("%d", aus_min);
			printf(" in Ireland is %d ", aus_hour);
			printf("%d", aus_min);
			printf(" of the previous day.\n");
		}

		conversion = 0;
	}
	if (conversion == 3) {
		double dollars = 0;
		double cents = 0;
		double euros = 0;
		printf("Enter USD value: ");
		scanf_s("%lf", &dollars);  //interprets first value (before 'space') as dollar value
		scanf_s("%lf", &cents); //interprets second value (after 'space') as cent value
		euros = (dollars*(0.89)) + ((cents/100)*(0.89));  //shifts cents two decimal places over into correct position and multipis bothdollars and cents by correct factor tto get euro value
		printf("EUR value is: %lf\n", euros); //prints out uro value a floating point type

		conversion = 0;
	}
	if (conversion == 4) {
		int dollars = 0;
		int cents = 0;
		int remainder = 0;
		float euros = 0;
		printf("Enter EUR value: ");
		scanf_s("%f", &euros);		//gets euro value in floating point type
		euros = euros*1.13;			//mutplies euro value by correct factor to get USD value
		dollars = euros / 1;				//stores integer portion of USD value in dollar variable
		 cents = (euros-dollars)*1000;		//starts operation to round USD decimal value to nearest cent
		 remainder = cents % 10;
		 cents = cents / 10;
		 if (remainder >= 5) {
			 cents = cents + 1;
		 }
		 printf("USD value is: %d ", dollars);
		printf("%d\n", cents);
		
		conversion = 0;
	}
	if (conversion == 5) {
		double farenheit = 0;
		int celsius = 0;
		double remainder = 0;
		double a = 0.5;
		printf("Enter temperature in Farenheit: ");
		scanf_s("%lf", &farenheit);
		celsius = (5*(farenheit - 32))/9;		//integer portion of the conversion kept only in celsius variable
		remainder = ((5*(farenheit - 32))/9);	
		remainder = remainder - celsius;		//determines whether decimal portion of double is greater than or equal to 0.5 for rounding to nearest centigrade
		if (remainder>=a) {						//round up function
			celsius = celsius + 1;
		}

		printf("Temperature in Celsius is: %d\n", celsius);
		conversion = 0;
	}
	if (conversion == 6) {
		int farenheit = 0;
		double celsius = 0;
		double remainder = 0;
		double a = 0.5;
		printf("Enter temperature in Celsius: ");
		scanf_s("%lf", &celsius);
		farenheit = ((9 *celsius)/ 5)+32;		//integer portion of doule converion kept
		remainder = ((9*celsius)/ 5)+32;		
		remainder = remainder - farenheit;		//determines whether decimal portion of double is greater than or equal to 0.5 for rounding to nearest degree farenheit
		if (remainder >= a) {					//round up functtion
			farenheit = farenheit + 1;
		}

		printf("Temperature in Farenheit is: %d\n", farenheit);
		conversion = 0;
	}
	if (conversion == 7) {
		double kg = 0;
		double a = 0;
		double b = 0;
		double remainder = 0;
		int oz = 0;
		int lbs = 0;
		printf("Enter weight in kg: ");		
		scanf_s("%lf", &kg);
		a = (kg) / 0.45359237;		//converts from from kg to lbs
		b = a * 16;					//converts lbs to oz
		oz = b;
		remainder = b - oz;			//rounds to nearest oz
		if (remainder >= 0.5) {
			oz = oz + 1;
		}
		lbs = oz / 16;				//gets value in pounds from oz
		oz = oz % 16;				//gets remainder in ounces
		printf("Weight in pounds and ounces is: %d lb and ", lbs);
		printf("%d oz.\n", oz);

		conversion = 0 ;
	}
	if (conversion == 8) {
		double lbs = 0;
		double oz = 0;
		double a = 0;
		double kg = 0;
		
		printf("Enter weight in pounds and ounces: ");
		scanf_s("%lf", &lbs);
		scanf_s("%lf", &oz);
		a = oz / 16;
		kg = (lbs + a)*0.45359237;				//converts oz to lbs
		printf("Weight in kg is: %lf ", kg);	//converts lbs to kgs
		printf("kg.\n");

		conversion = 0;
	}
	if (conversion == 9) {
		double km = 0;
		double mi = 0;

		printf("Enter distance in km: ");	
		scanf_s("%lf", &km);
		mi = (km * 0.6213712);					//converts km to mi
		printf("Distance in miles is: %lf ", mi);
		printf("mi.\n");

		conversion = 0;
	}
	if (conversion == 10) {
		double km = 0;
		double mi = 0;

		printf("Enter distance in miles: ");
		scanf_s("%lf", &mi);
		km = (mi / 0.6213712);					//converts mi to km
		printf("Distance in km is: %lf ", km);
		printf("km.\n");
	}
	if (conversion == 11) {			//if option 11 selected, change exit status to 1 to exit the conversion program loop
		printf("Goodbye.\n");
		exit = 1;
	}
}
getchar();
return 0;
}
