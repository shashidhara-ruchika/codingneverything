/*
------------------------------------
TABLE: CITY                             
------------------------------------
FIELD           TYPE            
-----------------------------------
ID              NUMBER          
NAME            VARCHAR2(17)    
COUNTRYCODE     VARCHAR2(3)     
DISTRICT        VARCHAR2(20)    
POPULATION      NUMBER          
------------------------------------


------------------------------------
TABLE: COUNTRY
------------------------------------
FIELD           TYPE            
-----------------------------------
CODE            VARCHAR2(3)
NAME            VARCHAR2(44)
CONTINENT       VARCHAR2(13)
REGION          VARCHAR2(25)
SURFACEAREA     NUMBER
INDEPYEAR       VARCHAR2(5)
POPULATION      NUMBER
LIFEEXPECTANCY  VARCHAR2(4)
GNP             NUMBER
GNPOLD          VARCHAR2(9)
LOCALNAME       VARCHAR2(44)
GOVERNMENTFORM  VARCHAR2(44)
HEADOFSTATE     VARCHAR2(4)
CODE2           VARCHAR2(2)
-----------------------------------
*/

/*
https://www.hackerrank.com/challenges/select-all-sql/problem

Query all columns (attributes) for every row in the CITY table.
*/

SELECT * 
FROM CITY;

/*
https://www.hackerrank.com/challenges/select-by-id/problem

Query all columns for a city in CITY with the ID 1661.
*/

SELECT *
FROM CITY
WHERE ID = 1661;

/*
https://www.hackerrank.com/challenges/japanese-cities-attributes/problem

Query all attributes of every Japanese city in the CITY table.
The COUNTRYCODE for Japan is JPN.
*/

SELECT *
FROM CITY
WHERE CITY.COUNTRYCODE = 'JPN';

/*
https://www.hackerrank.com/challenges/japanese-cities-name/problem

Query the names of all the Japanese cities in the CITY table.
The COUNTRYCODE for Japan is JPN.
*/

SELECT CITY.NAME
FROM CITY
WHERE CITY.COUNTRYCODE = 'JPN';

/*
https://www.hackerrank.com/challenges/revising-the-select-query/problem

Query all columns for all American cities in the CITY table with populations larger than 100000.
The CountryCode for America is USA.
*/

SELECT *
FROM CITY
WHERE
    CITY.COUNTRYCODE = 'USA' AND
    CITY.POPULATION > 100000;

/*
https://www.hackerrank.com/challenges/revising-the-select-query-2/problem

Query the NAME field for all American cities in the CITY table with populations larger than 120000.
The CountryCode for America is USA.
*/

SELECT CITY.NAME
FROM CITY
WHERE
    CITY.COUNTRYCODE = 'USA' AND
    CITY.POPULATION > 120000;

/*
https://www.hackerrank.com/challenges/average-population/problem

Query the average population for all cities in CITY, rounded down to the nearest integer.
*/

SELECT ROUND(AVG(CITY.POPULATION))
FROM CITY;

/*
https://www.hackerrank.com/challenges/japan-population/problem

Query the sum of the populations for all Japanese cities in CITY.
The COUNTRYCODE for Japan is JPN.
*/

SELECT SUM(CITY.POPULATION)
FROM CITY
WHERE CITY.COUNTRYCODE = 'JPN';

/*
https://www.hackerrank.com/challenges/population-density-difference/problem

Query the difference between the maximum and minimum populations in CITY.
*/

SELECT MAX(CITY.POPULATION) - MIN(CITY.POPULATION)
FROM CITY;

/*
https://www.hackerrank.com/challenges/revising-aggregations-the-count-function/problem

Query a count of the number of cities in CITY having a Population larger than 10000.
*/

SELECT COUNT(CITY.POPULATION)
FROM CITY
WHERE CITY.POPULATION > 100000;

/*
https://www.hackerrank.com/challenges/revising-aggregations-sum/problem

Query the total population of all cities in CITY where District is California.
*/

SELECT SUM(CITY.POPULATION)
FROM CITY
WHERE CITY.DISTRICT = 'California';

/*
https://www.hackerrank.com/challenges/revising-aggregations-the-average-function/problem

Query the average population of all cities in CITY where District is California.
*/

SELECT AVG(CITY.POPULATION)
FROM CITY
WHERE CITY.DISTRICT = 'California';

/*
https://www.hackerrank.com/challenges/african-cities/problem

Given the CITY and COUNTRY tables, 
query the names of all cities where the CONTINENT is 'Africa'.
Note: CITY.CountryCode and COUNTRY.Code are matching key columns.
*/

SELECT CITY.NAME
FROM CITY
WHERE CITY.COUNTRYCODE IN
(
    SELECT COUNTRY.CODE
    FROM COUNTRY
    WHERE COUNTRY.CONTINENT = 'Africa'
);

/*
https://www.hackerrank.com/challenges/asian-population/problem

Given the CITY and COUNTRY tables,
query the sum of the populations of all cities where the CONTINENT is 'Asia'.
Note: CITY.CountryCode and COUNTRY.Code are matching key columns.
*/

SELECT SUM(CITY.POPULATION)
FROM CITY
WHERE CITY.COUNTRYCODE IN 
(
    SELECT DISTINCT COUNTRY.CODE
    FROM COUNTRY
    WHERE COUNTRY.CONTINENT = 'Asia'
);

/*
https://www.hackerrank.com/challenges/average-population-of-each-continent/problem

Given the CITY and COUNTRY tables, query the names of all the continents (COUNTRY.Continent) 
and their respective average city populations (CITY.Population) rounded down to the nearest integer.
Note: CITY.CountryCode and COUNTRY.Code are matching key columns.
*/

SELECT COUNTRY.CONTINENT, FLOOR(AVG(CITY.POPULATION))
FROM CITY INNER JOIN COUNTRY
ON CITY.COUNTRYCODE = COUNTRY.CODE
GROUP BY COUNTRY.CONTINENT;

