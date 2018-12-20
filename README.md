# Project_2
Finding Exoplanets

Some background from the National Academy of Engineering website: “In the popular mind, scientists and engineers have distinct job descriptions. Scientists explore, experiment, and discover; engineers create, design, and build. But in truth, the distinction is blurry, and engineers participate in the scientific process of discovery in many ways. Grand experiments and missions of exploration always need engineering expertise to design the tools, instruments, and systems that make it possible to acquire new knowledge about the physical and biological worlds. In the century ahead, engineers will continue to be partners with scientists in the great quest for understanding many unanswered questions of nature.” This project is focused on exploring real data on exoplanets (and some a little closer to home). An exoplanet is a planet outside our solar system, orbiting around another star in our galaxy. Most of the exoplanets that we know of today have been discovered in the past two decades using NASA’s Kepler space telescope. In general, we are looking for exoplanets that are Earth size and within a habitable zone around a sun-like star, as that may be our best hope of finding life elsewhere in the universe.



Here is a small subset of the data that has been collected on exoplanets (in addition to two planets closer to home):

Planet Name	Planet Radius	Planet Orbital Period	Planet Equilibrium Temperature	Star Radius	Planet Distance to Star/Star Radius

Earth	0.091135	365.25	279.0	1.0	215.1

Mars	0.0475	687.0	226.0	1.0	327.8

HAT-P-16	1.289	2.77596	1626.0	1.24	7.7

K2-29	1.19	3.2588321	1171.0	0.86	10.51

KELT-4-A	0.699	2.9895932	1823.0	1.6	5.792

Kepler-452	0.145	384.843	265.0	1.11	167.9

KOI-94	0.585	54.32031	584.0	1.52	43.1

Kepler-62	0.144	122.3874	270.0	0.64	144

Kepler-46	0.808	33.60134	543.0	0.79	45.1

WASP-82	0.999	3.0678523	825.0	0.59	12.63
The units associated with the columns of data are given here:

Planet Name	Planet Radius	Planet Orbital Period	Planet Equilibrium Temperature	Star Radius	Planet Distance to Star/Star Radius
[in Jupiter radii units]	[days]	[K]	[in Solar radii]	
Note: the rightmost column is the ratio of the planet distance to its star TO its star's radius.

Note: the planet size (radius) is given as a proportion to Jupiter's radius (that's just a convenient unit on the exoplanetary scale). For example, the Earth has a radius that is 0.091135 times that of Jupiter (i.e. Earth has a radius about 9% of Jupiter's radius). Also, the orbital period is given in days, the planet temperature is given in Kelvin, and the star radius is given as a proportion to our Sun's radius (thus, Earth and Mars have star radii of 1.0).

We will again be using task levels to build the code functionality. It is highly recommended that you ensure proper functionality of all lower-level tasks before moving on to a higher-level. Also, a template code is provided. Your code must contain all aspects of the template. That is, you will need to add a lot of code, but you should not remove or modify any part of the template when adding your code. It is vital for passing some of the test cases that the function definitions (names, parameters, parameter types, return type, etc.) are exactly as they appear on the template. The template also has many commented TODO statements, which should give an outline for the coding components that are required and an overall structure to your code.


Coding Tasks - Level 0
[50 points, all test cases visible]

Properly format all output printed to the screen (see sample output below). Even if you are not able to produce the correct numbers for the later tasks, at this stage you should focus on proper formatting of the printf() statements.

Coding Tasks - Level 1
[25 points, all test cases visible]

Create and fill arrays with the data for the 10 planets from each of the columns in the table (there should be 6 total arrays of size 10 at this point, but you will make more later)
Write a function (the shell for calcDistToStar is provided in the template) to calculate the distance from the planet to its star using the data in your arrays. Note: the units for the distance must be Astronomical Units, AU (or the typical distance from the Sun to the Earth, where 1 AU = 215 solar radii). See the comments in the template for the required input parameters and return type.
Make an additional array to hold planet-distance-to-star values for each planet. Fill this array by calling calcDistToStar inside a loop. Then, print out distances for all of the planets in a list (see sample output below). All floating-point values should be printed with 3 decimal places in this lab.
Make an additional array to hold planet radius values in miles. Fill this array by doing a calculation for each planet (i.e. use a loop) using the data provided. Then, print out the radii in miles for all of the planets in a list (see sample output below). All floating-point values should be printed with 3 decimal places in this lab. This would be a great candidate for an additional user-defined function, which you are required to make at least one. Note: the radius of Jupiter is 43,441 miles as is provided as a global variable in the template.
Create a histogram where the planets are binned (i.e. grouped) based on their size (see sample output below).
write a function countNumPlanets to count the number of planets in the data whose radius falls into a specific range (see the commented template for more details).
call countNumPlanets to obtain a count for each of the following cases (Note: the radii of Earth, Neptune, and Jupiter are 3959, 15299, and 43441 miles, respectively, as are provided as global variables in the template):
      <Earth - the planet's radius is less than Earth's radius. 
      SuperEarth - the planet's radius is between Earth's radius and twice Earth's radius. 
      <Neptune - the planet's radius is between twice Earth's radius and Neptune's radius. 
      <Jupiter - the planet's radius is between Neptune's radius and Jupiter's radius. 
      >Jupiter - the planet's radius is greater than Jupiter's radius. 
.
write a function printStars to print a line of asterisks (see the commented template for more details).
use the counts returned by countNumPlanets and the functionality of printStars to create the histogram (see sample output below).
Find the planets in the data set that are deemed potentially habitable. This should be done using the user-defined function findHabitable, which must return a boolean (see the commented template for more details). For our purposes, potentially habitable is defined as all of the following (loosely interpreted from this source to include Mars as habitable):
planet's radius is between 0.2 and 5.0 times Earth's radius
planet's orbital period is between 91 and 801 days
planet's equilibrium temperature is between 183 and 294 K
planet's distance to its star is between 0.4 and 2.35 AU
Print out a list of potentially habitable planets (see sample output below).

Coding Tasks - Level 2
[10 points, test cases not visible]

These tasks require general, proper functionality of the user-defined functions (specifically the binning function), such that larger data sets of planets can be investigated. If Level 1 Tasks are programmed correctly with functions written generally, the Level 2 Tasks should automatically pass. If that is not the case, your functions are not working properly or generally.

Coding Tasks - Level 3
[15 points + 5 points Extra Credit, test cases not visible]

Some of these tasks require general, proper functionality of the user-defined functions (specifically the function that tests for planet habitability), such that larger data sets of planets can be investigated. If Level 1 Tasks are programmed correctly with functions written generally, these Level 3 Tasks should automatically pass. If that is not the case, your functions are not working properly or generally.
Sort the planet radii in increasing order and print the list to the screen (see sample output below). All floating-point values should be printed with 3 decimal places in this lab. This must be done generally using the user-defined function provided in the template. Make sure the sorting is done as the last part of your code, so that it does not corrupt the above analysis of the data.
EXTRA CREDIT: print the names of the planets in order of increasing size (see sample output below). Again, this should be done generally using a user-defined function (not provided in the template this time). Also again, make sure the sorting is done as the last part of your code, so that it does not corrupt the above analysis of the data.

Here is a complete sample output from the code, where only the first five planets on the list of been included in the investigation (note: no exoplanets have been found here, only the two in our solar system):

Planets: Earth Mars HAT-P-16 K2-29 KELT-4-A 

Planet distances to their stars (in AU): 
1.000, 1.525, 0.044, 0.042, 0.043

Planet radii (in miles): 
3958.996, 2063.448, 55995.449, 51694.790, 30365.259

Planets by size:
    <Earth: **
SuperEarth: 
  <Neptune: 
  <Jupiter: *
  >Jupiter: **

Potentially Habitable Planets: 
Earth
Mars

Planet radii in increasing order: 
2063.448, 3958.996, 30365.259, 51694.790, 55995.449

Planets sorted by size: Mars Earth KELT-4-A K2-29 HAT-P-16 

Grading
[200 points total]

100 points: auto graded test cases (105 points possible with Extra Credit)
50 points: closer inspection of program functionality.
these points will be awarded for significant progress at developing code that ended up non-functional (i.e. not passing the test cases). Your code must compile, run, and pass lower-level tasks, but any unsuccessful efforts at achieving higher-level tasks will be rewarded here.
hardcoding output to match test case output for Levels 1, 2, or 3 is not allowed and will result in -50 points for this grade component.
50 points: formatting and style, 10 points for each of the following (see piazza post @10 for more details):
meaningful identifier names (variables and functions): you must define and call at least one additional function beyond what is provided in the template
comments: short description stating the purpose of each block of code in main() and each function (reword the provided comments in your own words)
variable declaration & initialization: valid types, proper initializing, no additional global variables beyond those provided in the template, etc.
code layout: nested levels with proper indentation
program header: must include overall goal of program, author, class, and date
