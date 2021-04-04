/*
---------------------------
TABLE: EMPLOYEE 
---------------------------
COLUMN          TYPE
---------------------------
EMPLOYEE_ID     INTEGER
NAME            STRING
MONTHS          INTEGER
SALARY          INTEGER
---------------------------
*/

/*
https://www.hackerrank.com/challenges/name-of-employees/problem

Write a query that prints a list of employee names (i.e.: the name attribute)
from the Employee table in alphabetical order.
*/

SELECT EMPLOYEE.NAME
FROM EMPLOYEE
ORDER BY EMPLOYEE.NAME;

/*
https://www.hackerrank.com/challenges/salary-of-employees/problem

Write a query that prints a list of employee names (i.e.: the name attribute)
for employees in Employee having a salary greater than  per month
who have been employees for less than  months.
Sort your result by ascending employee_id.
*/

SELECT EMPLOYEE.Name
FROM EMPLOYEE
WHERE EMPLOYEE.Salary > 2000 AND EMPLOYEE.Months < 10
ORDER BY EMPLOYEE.Employee_id ASC;

/*
https://www.hackerrank.com/challenges/the-blunder/problem

Samantha was tasked with calculating 
the average monthly salaries for all employees in the EMPLOYEES table, 
but did not realize her keyboard's 0 key was broken 
until after completing the calculation. 
She wants your help finding the difference between her miscalculation 
(using salaries with any zeros removed), and the actual average salary.

Write a query calculating the amount of error 
(i.e.:  actual - miscalculated average monthly salaries), 
and round it up to the next integer.
*/

SELECT CEIL
(
    AVG(EMPLOYEES.SALARY) - AVG(REPLACE(EMPLOYEES.SALARY, '0', ''))    
)
FROM EMPLOYEES;

/*
https://www.hackerrank.com/challenges/earnings-of-employees/problem

We define an employee's total earnings to be their monthly salary x months worked, 
and the maximum total earnings to be the maximum total earnings for any employee in the Employee table. 

Write a query to find the maximum total earnings for all employees 
as well as the total number of employees who have maximum total earnings.

Then print these values as 2 space-separated integers.
*/

SELECT E.SALARY * E.MONTHS AS EARNINGS, COUNT(E.SALARY * E.MONTHS)
FROM EMPLOYEE AS E
GROUP BY EARNINGS
ORDER BY EARNINGS DESC
LIMIT 1;



