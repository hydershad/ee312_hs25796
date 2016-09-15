#include<stdio.h>

int main(void){
int conversion = 0;
int exit = 0;

while (exit == 0) {
	printf("Conversion menu:\n");
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
	scanf_s("%d", &conversion);
	getchar();

	if (conversion == 1) {
		unsigned int aus_hour = 0;
		unsigned int ire_hour = 0;
		unsigned int ire_min = 0;
		printf("Enter Austin time to be converted, expressed in hours and minutes: ");
		scanf_s("%d", &aus_hour);
		scanf_s("%d", &ire_min);
		ire_hour = (aus_hour + 6) % 24;
		if (aus_hour >= 18) {
			printf("The time in Ireland equivalent to %d ", aus_hour);
			printf("%d", ire_min);
			printf(" in Austin is %d ", ire_hour);
			printf("%d", ire_min);
			printf(" of the next day.\n");
		}
		if (aus_hour < 18) {
			printf("The time in Ireland equivalent to %d ", aus_hour);
			printf("%d", ire_min);
			printf(" in Austin is %d ", ire_hour);
			printf("%d", ire_min);
			printf(" of the same day.\n");
		}

		conversion = 0;
	}
	if (conversion == 2) {
		unsigned int ire_hour = 0;
		unsigned int aus_hour = 0;
		unsigned int aus_min = 0;
		printf("Enter Irish time to be converted, expressed in hours and minutes: ");
		scanf_s("%d", &ire_hour);
		scanf_s("%d", &aus_min);
		aus_hour = ((ire_hour + 24) - 6) % 24;
		if (ire_hour >= 6) {
			printf("The time in Austin equivalent to %d ", ire_hour);
			printf("%d", aus_min);
			printf(" in Ireland is %d ", aus_hour);
			printf("%d", aus_min);
			printf(" of the same day.\n");
		}
		if (ire_hour < 6) {
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
		scanf_s("%lf", &dollars);
		scanf_s("%lf", &cents);
		euros = (dollars*(0.89)) + ((cents/100)*(0.89));
		printf("EUR value is: %lf\n", euros);

		conversion = 0;
	}
	if (conversion == 4) {
		int dollars = 0;
		int cents = 0;
		int remainder = 0;
		float euros = 0;
		printf("Enter EUR value: ");
		scanf_s("%f", &euros);
		euros = euros*1.13;
		dollars = euros / 1;
		 cents = (euros-dollars)*1000;
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
		celsius = (5*(farenheit - 32))/9;
		remainder = ((5*(farenheit - 32))/9);
		remainder = remainder - celsius;
		if (remainder>=a) {
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
		farenheit = ((9 *celsius)/ 5)+32;
		remainder = ((9*celsius)/ 5)+32;
		remainder = remainder - farenheit;
		if (remainder >= a) {
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
		a = (kg) / 0.45359237;
		b = a * 16;
		oz = b;
		remainder = b - oz;
		if (remainder >= 0.5) {
			oz = oz + 1;
		}
		lbs = oz / 16;
		oz = oz % 16;
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
		kg = (lbs + a)*0.45359237;
		printf("Weight in kg is: %lf ", kg);
		printf("kg.\n");

		conversion = 0;
	}
	if (conversion == 9) {
		double km = 0;
		double mi = 0;

		printf("Enter distance in km: ");
		scanf_s("%lf", &km);
		mi = (km * 0.6213712);
		printf("Distance in miles is: %lf ", mi);
		printf("mi.\n");

		conversion = 0;
	}
	if (conversion == 10) {
		double km = 0;
		double mi = 0;

		printf("Enter distance in miles: ");
		scanf_s("%lf", &mi);
		km = (mi / 0.6213712);
		printf("Distance in km is: %lf ", km);
		printf("km.\n");
	}
	if (conversion == 11) {
		printf("Goodbye.\n");
		exit = 1;
	}
}
getchar();
return 0;
}
