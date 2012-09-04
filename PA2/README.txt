##About##
Programming assignment #1 for CS2303-A03 by Stephen Kelly.

##Program Summary##
Prints a 12 month calendar for the input year. 

##How to Run##
Compile with... 
$ gcc -Wall -o PA1 PA1.c 
run with... 
$ ./PA1
You can input any positive year, and it will calculate the day based on a simple algorithm (partially described below).

##Development Log##
Developing the output formatting on the program proved to be the simplest part the assignment. The hardest issue was developing the algorithm. I tried variants of the algorithm developed by Michael Keith and Tom Craver, as it did not use arrays. Next I attempted implementing the Gaussian algorithm. Both gave inconsistent values. 
After attempting to work out the algorithm in office hours and discussing with Rayce Stipanovich, I settled on counting back from a reference date. 2012 was convenient as it started on a Sunday. 

##Loop Invariants##
getStartDay():For Loop 1
We know our input year is less than the reference year, and the difference between the two years. We use startDay as our modified variable. On each loop we increment 'i' and subtract from reference year. We check if this new year is a leap year or not and add the corresponding amount of days to startDay. Once i is equal to the year difference we terminate the loop and startDay is left with all days between the reference year and input year.
getStartDay():For Loop 2
We know our input year is greater than the reference year, and the difference between the two years. We use startDay as our modified variable. On each loop we increment 'i' and add to reference year. We check if this new year is a leap year or not and add the corresponding amount of days to startDay. Once i is less than the year difference we terminate the loop and startDay is left with all days between the reference year and input year.
printMonth():For Loop 1
Based on the startDays we print spaces up until the specified day, so next time we print we are in the right location. We start at the first day and loop until 'i' is one less than the starting day.
printMonth:For Loop 2
We know the day count for each month. Our goal is to print all those days, starting at 1, in 7 columns. The previous loop took care of the spacing. We use startDay as a column index. Once we are at the 7th column we print a new line. At the termination of the loop, 'i' is equal to dayCount, and startDay is equal to the right of the column we last printed.   
printCalendar:For Loop 1
We call printMonth 12 times, calling with the startDay from the previous call (or calculated in the beginning). We save the return value into startDay for use in the next iteration. 'startDay' finishes equal to the starting day of the next year. 

##Algorithms Referenced/Sources##
en.wikipedia.org/wiki/Leap_year#Algorithm
