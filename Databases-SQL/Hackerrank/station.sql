/*
----------------------------
TABLE: STATION
----------------------------
FIELD       TYPE
----------------------------
ID          NUMBER
CITY        VARCHAR2(21)
STATE       VARCHAR2(2)
LAT_N       NUMBER
LAT_W       NUMBER
----------------------------
*/

/*
https://www.hackerrank.com/challenges/weather-observation-station-1/problem

Query a list of CITY and STATE from the STATION table.
*/

SELECT STATION.CITY, STATION.STATE
FROM STATION;

/*
https://www.hackerrank.com/challenges/weather-observation-station-2/problem

Query the following two values from the STATION table:
The sum of all values in LAT_N rounded to a scale of  decimal places.
The sum of all values in LONG_W rounded to a scale of  decimal places.
*/

SELECT ROUND(SUM(S.LAT_N), 2), ROUND(SUM(S.LONG_W), 2)
FROM STATION AS S;

/*
https://www.hackerrank.com/challenges/weather-observation-station-3/problem

Query a list of CITY names from STATION for cities that have an even ID number.
Print the results in any order, but exclude duplicates from the answer.
*/

SELECT DISTINCT STATION.CITY
FROM STATION
WHERE ID % 2 = 0;

/*
https://www.hackerrank.com/challenges/weather-observation-station-4/problem

Find the difference between the total number of CITY entries in the table and 
the number of distinct CITY entries in the table.
*/

SELECT COUNT(STATION.CITY ) - COUNT(DISTINCT STATION.CITY )
FROM STATION;

/*
https://www.hackerrank.com/challenges/weather-observation-station-5/problem

Query the two cities in STATION with the shortest and longest CITY names, 
as well as their respective lengths (i.e.: number of characters in the name). 
If there is more than one smallest or largest city, 
choose the one that comes first when ordered alphabetically.
*/

SELECT S.CITY, CHAR_LENGTH(S.CITY)
FROM STATION AS S
ORDER BY CHAR_LENGTH(S.CITY) ASC, S.CITY ASC
LIMIT 1;

SELECT S.CITY, CHAR_LENGTH(S.CITY)
FROM STATION AS S
ORDER BY CHAR_LENGTH(S.CITY) DESC, S.CITY ASC
LIMIT 1;

/*
https://www.hackerrank.com/challenges/weather-observation-station-6/problem

Query the list of CITY names starting with vowels (i.e., a, e, i, o, or u) from STATION.
Your result cannot contain duplicates.
*/

SELECT DISTINCT STATION.CITY
FROM STATION
WHERE STATION.CITY RLIKE '^[aeiou]';

/*
https://www.hackerrank.com/challenges/weather-observation-station-7/problem

Query the list of CITY names ending with vowels (a, e, i, o, u) from STATION.
Your result cannot contain duplicates.
*/

SELECT DISTINCT STATION.CITY
FROM STATION
WHERE STATION.CITY RLIKE '[aeiou]$';

/*
https://www.hackerrank.com/challenges/weather-observation-station-8/problem

Query the list of CITY names from STATION which have vowels (i.e., a, e, i, o, and u) 
as both their first and last characters.
Your result cannot contain duplicates.
*/

SELECT DISTINCT STATION.CITY
FROM STATION
WHERE STATION.CITY RLIKE '^[aeiou].*[aeiou]$';

/*
https://www.hackerrank.com/challenges/weather-observation-station-9/problem 

Query the list of CITY names from STATION that do not start with vowels.
Your result cannot contain duplicates.
*/

SELECT DISTINCT STATION.CITY
FROM STATION
WHERE STATION.CITY RLIKE '^[^aeiou]';

/*
https://www.hackerrank.com/challenges/weather-observation-station-10/problem

Query the list of CITY names from STATION that do not end with vowels.
Your result cannot contain duplicates.
*/

SELECT DISTINCT STATION.CITY
FROM STATION
WHERE STATION.CITY RLIKE '[^aeiou]$';

/*
https://www.hackerrank.com/challenges/weather-observation-station-11/problem

Query the list of CITY names from STATION that either 
do not start with vowels or do not end with vowels. 
Your result cannot contain duplicates.
*/

SELECT DISTINCT STATION.CITY
FROM STATION
WHERE STATION.CITY RLIKE '^[^aeiou]|[^aeiou]$';

/*
https://www.hackerrank.com/challenges/weather-observation-station-12/problem

Query the list of CITY names from STATION that
do not start with vowels and do not end with vowels.
Your result cannot contain duplicates.
*/

SELECT DISTINCT STATION.CITY
FROM STATION
WHERE STATION.CITY RLIKE '^[^aeiou].*[^aeiou]$';

/*
https://www.hackerrank.com/challenges/weather-observation-station-13/problem

Query the sum of Northern Latitudes (LAT_N) from STATION 
having values greater than 38.7880 and less than 137.2345. 
Truncate your answer to 4 decimal places.
*/

SELECT ROUND(SUM(S.LAT_N), 4)
FROM STATION AS S
WHERE S.LAT_N > 38.7880 AND S.LAT_N < 137.2345;

/*
https://www.hackerrank.com/challenges/weather-observation-station-14/problem

Query the greatest value of the Northern Latitudes (LAT_N) from STATION 
that is less than 137.2345. Truncate your answer to  decimal places.
*/

SELECT ROUND(MAX(S.LAT_N), 4)
FROM STATION AS S
WHERE S.LAT_N < 137.2345;

/*
https://www.hackerrank.com/challenges/weather-observation-station-15/problem

Query the Western Longitude (LONG_W) for the largest Northern Latitude (LAT_N) 
in STATION that is less than 137.2345. Round your answer to 4 decimal places.
*/

SELECT ROUND(S.LONG_W, 4)
FROM STATION AS S
WHERE S.LAT_N =
(
    SELECT MAX(S.LAT_N)
    FROM STATION AS S
    WHERE S.LAT_N < 137.2345
);

/*
https://www.hackerrank.com/challenges/weather-observation-station-16/problem

Query the smallest Northern Latitude (LAT_N) from STATION 
that is greater than 38.7780. Round your answer to 4 decimal places.
*/

SELECT ROUND(MIN(S.LAT_N), 4)
FROM STATION AS S
WHERE S.LAT_N > 38.7780;

/*
https://www.hackerrank.com/challenges/weather-observation-station-17/problem

Query the Western Longitude (LONG_W)where the smallest Northern Latitude (LAT_N) 
in STATION is greater than 38.7780. Round your answer to 4 decimal places.
*/

SELECT ROUND(S.LONG_W, 4)
FROM STATION AS S
WHERE S.LAT_N = 
(
    SELECT MIN(S.LAT_N)
    FROM STATION AS S
    WHERE S.LAT_N > 38.7780
);

/*
https://www.hackerrank.com/challenges/weather-observation-station-18/problem

Consider P1(a,b) and P2(c,d) to be two points on a 2D plane.

a happens to equal the minimum value in Northern Latitude (LAT_N in STATION).
b happens to equal the minimum value in Western Longitude (LONG_W in STATION).
c happens to equal the maximum value in Northern Latitude (LAT_N in STATION).
d happens to equal the maximum value in Western Longitude (LONG_W in STATION).

Query the Manhattan Distance between points P1 and P2 
and round it to a scale of 4 decimal places.

Manhattan Distance: The distance between two points measured along axes at right angles. 
In a plane with p1 at (x1, y1) and p2 at (x2, y2), it is |x1 - x2| + |y1 - y2|.
*/

SELECT ROUND
(
    ABS(MAX(S.LAT_N) - MIN(S.LAT_N)) 
    +
    ABS(MAX(S.LONG_W) - MIN(S.LONG_W))
    , 4
)
FROM STATION AS S;

/*
https://www.hackerrank.com/challenges/weather-observation-station-19/problem

Consider P1(a,c) and P2(b,d) to be two points on a 2D plane 
where (a,b) are the respective minimum and maximum values of Northern Latitude (LAT_N) 
and (c,d) are the respective minimum and maximum values of Western Longitude (LONG_W) in STATION.

Query the Euclidean Distance between points  and  and format your answer to display  decimal digits.

Euclidian Distance: sqrt( (x1 - x2)^2 + (y1 - y2)^ 2 )
*/

SELECT ROUND
(
    SQRT 
    (
        POW(MAX(S.LAT_N) - MIN(S.LAT_N), 2) 
        +
        POW(MAX(S.LONG_W) - MIN(S.LONG_W), 2)

    )
    , 4
)
FROM STATION AS S;

/*
https://www.hackerrank.com/challenges/weather-observation-station-20/problem

A median is defined as a number separating the higher half of a data set from the lower half. 
Query the median of the Northern Latitudes (LAT_N) from STATION 
and round your answer to 4 decimal places.
*/

SELECT ROUND(S.LAT_N, 4) 
FROM STATION AS S
WHERE 
(
    SELECT COUNT(SL.LAT_N) 
    FROM STATION AS SL
    WHERE SL.LAT_N < S.LAT_N 
) 
= 
(
    SELECT COUNT(SR.LAT_N) 
    FROM STATION AS SR
    WHERE SR.LAT_N > S.LAT_N
);

set @rowindex := -1; /* 1) creates an index*/ 
/* 3) the outer query will select the average of the 2(for odd no. of values)/1(for even) values we found in the middle of the sorted array */
select round(avg(lat_n),4)
from
/* 2) the index will increment for each new value of lat_n it finds, and sort them by lat_n
*/
(select @rowindex:=@rowindex+1 as rowindex, lat_n 
from station
order by lat_n) as l 
where l.rowindex in (floor(@rowindex/2), ceil(@rowindex/2));
