/*This program will take a list of planets along with their data and 
  find habitable planets among the list of planets based on size, 
  distance to their respective star, temperature, and orbital period.
  
  This program will also sort the planets by ascending size.*/
  
//Code written by Alex Dai
//CS 107
//23 October 2018

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <float.h>
#include <math.h>

//Global variables: DO NOT REMOVE, DO NOT MODIFY, DO NOT ADD ANY MORE
double const RADIUS_JUPITER = 43441; //miles
double const RADIUS_EARTH = 3959; //miles
double const RADIUS_NEPTUNE = 15299; //miles

// calcDistToStar: calculates planet distance to its star
// [in] starRadius: radius of star in units of Solar radii
// [in] planetRatio: ratio of planet distance to star/star radius
// [out] returns double: planet distance to star in units of AU
double calcDistToStar(double starRadius, double planetRatio){
   double distToStar;
   
   distToStar = (starRadius * planetRatio) / 215; //calcualtes distance to star in AU
   
   return distToStar;
}

// countNumPlanet: bins the input data by specified interval
// [in] lowerBound: lower value of interval
// [in] upperBound: upper value of interval
// [in] data[size]: array of doubles to be binned (counted)
// [in] size: array size of data[]
// [out] returns int: count of values in data[] that fall in the specified interval
int countNumPlanets(double lowerBound, double upperBound, double data[], int size){
   int i;
   int planetCount = 0;
   
   for (i = 0; i < size; ++i) {
	   if (data[i] > lowerBound && data[i] < upperBound) {
		   ++planetCount;
	   }
   }
   
   return planetCount;
}

// print stars: prints a line of asterisks
// [in] count: number of asterisks to print
// [out] returns void: nothing returned, only asterisks printed to screen
void printStars(int count){
   int i;
   
   for (i = 0; i < count; ++i) {
	   printf("*");
   }
   printf("\n");
}

// findHabitable: apply conditions for "Habitable Exoplanet" to check if the planet is "habitable"
// [in] radius: planet radius (in miles)
// [in] orbitPer: orbital period for planet (in days)
// [in] temperature: equilibrium temperature of the planet (in K)
// [in] distance: to the star (in AU)
// [out] returns bool: true only if planet passes all the "habitable" tests, otherwise false
bool findHabitable(double radius, double orbitPer, double temperature, double distance){
   bool isHabitable = true;
   
   //checks for radius in miles
   if (radius < (0.2 * RADIUS_EARTH) || radius > (5.0 * RADIUS_EARTH)) {
	   isHabitable = false;
   }
   if (orbitPer < 91 || orbitPer > 801) {
	   isHabitable = false;
   }
   if (temperature < 183 || temperature > 294) {
	   isHabitable = false;
   }
   if (distance < 0.4 || distance > 2.35) {
	   isHabitable = false;
   }
   
   return isHabitable;
}

// printData: prints the data[] in a one-line list of numbers with 3 decimal places
// separated by a comma and space (e.g. 1.500, 2.465, 3.141, 0.003)
// [in] data[size]: array to be printed
// [in] size: array size of data[]
// [out] returns void: nothing returned, only data printed to screen
void printData(double data[], int size){
   for(int i = 0; i < size; ++i){
		printf("%.3f", data[i]);
		if (i < size - 1){
			printf(", ");
		}
	}
	printf("\n\n");
}

// sortData: sorts the elements of data[] by increasing values
// [in] data[size]: array to be sorted
// [in] size: array size of data[]
// [out] returns void: nothing returned, but data[] is modified (sorted) and returned
void sortData(double data[], int size){
   int i, j;
   double temp;
   
   for(i = 0; i < size; ++i){
	   for (j = i + 1; j < size; ++j){
		   if(data[i] > data[j]){
				temp = data[i];
				data[i] = data[j];
				data[j] = temp;
		   }
	   }
   }
}

// TODO: write and comment at least one other function that you used to achieve the tasks of the project
// calculates planet size with repect to jupiter and returns size in miles
// [in] radiusOfPlanet: the radius of the planet in jupiter radii
// [out] returns double: the radius of the planet in miles
double calcRadiusMiles(double radiusOfPlanet){
	double radiusMiles;
	
	radiusMiles = radiusOfPlanet * RADIUS_JUPITER; 
	
	return radiusMiles;
}

// sortIndex: sorts the index values of the respective planet's radii
// [in] data1[size]: array of unsorted radii
// [in] data2[size]: array of index values
// [out] returns void: data2 is modified and returned
void sortIndex(double data1[], int data2[], int size){
	//index variable
	int i, j;
	//creates and populates and array copy of data1
	double dataCopy[10];
	for(i = 0; i < size; ++i){
		dataCopy[i] = data1[i];
	}
	//array for sorted data values
	sortData(data1, size);
	//compares presorted array to the array sorted by size and reorders index
	for(i = 0; i < size; ++i){
		for(j = 0; j < size; ++j){
			if(fabs(dataCopy[j] - data1[i]) < 0.00001){
				data2[i] = j;
			}	
		}
	}
}

int main(){
	
	// index
	int i; 
	//planet names
	char planetName[][20] = { "Earth", "Mars", "HAT-P-16", "K2-29", "KELT-4-A", 
								"Kepler-452", "KOI-94", "Kepler-62", "Kepler-46", "WASP-82" };
                                
	//planet radius in jupiter radii							
    	double planetRadius[] = { 0.091135, 0.0475, 1.289, 1.19, 0.699, 0.145, 0.585, 0.144, 0.808, 0.999 };
    
	//planet orbital period in days
	double planetOrbitalPeriod[] = { 365.25, 687.0, 2.77596, 3.2588321, 2.9895932, 
									384.843, 54.32031, 122.3874, 33.60134, 3.0678523 };
                                    
	//planet equilibrium temperature in kelvin								
	double planetEqTemp[] = { 279.0, 226.0, 1626.0, 1171.0, 1823.0, 265.0, 584.0, 270.0, 543.0, 825.0 };
    
	//radius of planets' respective star as a ratio with respect to the sun
	double strRadii[] = { 1.0, 1.0, 1.24, 0.86, 1.6, 1.11, 1.52, 0.64, 0.79, 0.59 };
    
	//represents planet distance to star(solar radii) / star radius
	double distToStarRatio[] = { 215.1, 327.8, 7.7, 10.51, 5.792, 167.9, 43.1, 144, 45.1, 12.63 };
    
	//creates array as index for planet names
	int planetIndex[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
	//creates and populates array with planet distance to their respective star in AU
	double distanceToStar[10];
	for (i = 0; i < 10; ++i) {
		distanceToStar[i] = calcDistToStar(strRadii[i], distToStarRatio[i]);
	}
	//creates and populates array with planet radius in miles
	double planetRadiusInMiles[10];
	for (i = 0; i < 10; ++i) {
		planetRadiusInMiles[i] = calcRadiusMiles(planetRadius[i]);
	}
	//creates copy of planetRadiusInMiles array
	double pRadinMiles2[10];
	for(i = 0; i < 10; ++i){
		pRadinMiles2[i] = planetRadiusInMiles[i];
	}
	
	printf("Planets: ");
	for (i = 0; i < 10; ++i){
		printf("%s ", planetName[i]);
	}
	printf("\n\n");
	//prints planet distance to their respective star in AU
	printf("Planet distances to their stars (in AU):\n");
	printData(distanceToStar, 10);
	//prints planet radius in miles
    	printf("Planet radii (in miles):\n");
	printData(planetRadiusInMiles, 10);
	
	//prints histogram of planets grouped by their radius in miles
	printf("Planets by size:\n");	
	printf("%12s", "<Earth: ");
	printStars(countNumPlanets(0, RADIUS_EARTH, planetRadiusInMiles, 10));
	printf("%12s", "SuperEarth: ");
	printStars(countNumPlanets(RADIUS_EARTH, 2.0 * RADIUS_EARTH, planetRadiusInMiles, 10));
	printf("%12s", "<Neptune: ");
	printStars(countNumPlanets(2.0 * RADIUS_EARTH, RADIUS_NEPTUNE, planetRadiusInMiles, 10));
	printf("%12s", "<Jupiter: ");
	printStars(countNumPlanets(RADIUS_NEPTUNE, RADIUS_JUPITER, planetRadiusInMiles, 10));
	printf("%12s", ">Jupiter: ");
	printStars(countNumPlanets(RADIUS_JUPITER, 1000.0 * RADIUS_JUPITER, planetRadiusInMiles, 10));
	printf("\n");
	
	//prints potentially habitable planets
	printf("Potentially Habitable Planets: \n");
	for(i = 0; i < 10; ++i){
		int canHabit = findHabitable(planetRadiusInMiles[i], planetOrbitalPeriod[i], planetEqTemp[i], distanceToStar[i]);
		if (canHabit == 1){
			printf("%s\n", planetName[i]);
		}
	}
	printf("\n");
	
	//prints planet radius in ascending order
	printf("Planet radii in increasing order: \n");
	sortData(planetRadiusInMiles, 10);
	printData(planetRadiusInMiles, 10);
	
	//prints planet names in ascending order by radius size
	sortIndex(planetRadius, planetIndex, 10);
	printf("Planets sorted by size: ");
	for(i = 0; i < 10; ++i){
		printf("%s", planetName[planetIndex[i]]);
		if (i < 9){
			printf(" ");
		}
	}
    printf("\n");
    return 0;
}

