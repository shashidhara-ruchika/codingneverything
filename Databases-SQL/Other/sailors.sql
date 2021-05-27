/* Define   */
DROP DATABASE IF EXISTS sailorsdb;
CREATE DATABASE sailorsdb;

USE sailorsdb; 

drop table if exists Sailors;
create table Sailors (
 sid integer primary key,
 name varchar(32) not null,
 rating integer,
 age integer
);

drop table if exists Boats;
create table Boats (
 bid integer primary key,
 name varchar(32) not null,
 color varchar(16)
);

drop table if exists Reserves;
create table Reserves (
 sid integer,
 bid integer,
 day date,
 primary key (sid, bid, day),
 foreign key (sid) references Sailors(sid),
 foreign key (bid) references Boats(bid)
);

/* Populate */

USE sailorsdb;

insert into Sailors (sid, name, rating, age) values (22, 'Dustin', 7, 45);
insert into Sailors (sid, name, rating, age) values (29, 'Brutus', 1, 33);
insert into Sailors (sid, name, rating, age) values (31, 'Lubber', 8, 55.5);
insert into Sailors (sid, name, rating, age) values (32, 'Andy', 8, 25.5);
insert into Sailors (sid, name, rating, age) values (58, 'Rusty', 10, 35);
insert into Sailors (sid, name, rating, age) values (64, 'Horatio', 7, 35);
insert into Sailors (sid, name, rating, age) values (71, 'Zorba', 10, 16);
insert into Sailors (sid, name, rating, age) values (85, 'Art', 3, 25.5);
insert into Sailors (sid, name, rating, age) values (95, 'Bob', 3, 63.5);

insert into Boats (bid, name, color) values (101, 'Interlake', 'blue');
insert into Boats (bid, name, color) values (102, 'Interlake', 'red');
insert into Boats (bid, name, color) values (103, 'Clipper', 'green');
insert into Boats (bid, name, color) values (104, 'Marine', 'red');

insert into Reserves (sid, bid, day) values (22, 101, '2017-10-10');
insert into Reserves (sid, bid, day) values (22, 102, '2017-10-10');
insert into Reserves (sid, bid, day) values (22, 103, '2017-07-10');
insert into Reserves (sid, bid, day) values (22, 102, '2017-09-11');
insert into Reserves (sid, bid, day) values (22, 104, '2017-11-07');
insert into Reserves (sid, bid, day) values (31, 102, '2017-11-07');
insert into Reserves (sid, bid, day) values (31, 103, '2017-08-07');
insert into Reserves (sid, bid, day) values (64, 101, '2017-09-19');
insert into Reserves (sid, bid, day) values (64, 102, '2017-09-29');

/* Queries  */

/* Perfom Queries on sailorsdb */
USE sailorsdb;


/* Show all data in each table */
SELECT * FROM Boats;
SELECT * FROM Reserves;
SELECT * FROM Sailors;


/* Obtain the Salior's Names & Boat ID who have reserved atleast one boat */
SELECT S.name, R.bid
FROM Sailors S, Reserves R
WHERE S.sid = R.sid;


/* Obtain the Salior's Names who have atleast one boat */
SELECT DISTINCT S.name
FROM Sailors S, Reserves R
WHERE S.sid = R.sid;


/*Obtain the Sailor's names who have reserved boat #103 */

/* Join */
SELECT S.name
FROM Sailors S, Reserves R
WHERE S.sid = R.sid AND R.bid = 103;

/* Nested Query */
SELECT S.name 
FROM Sailors S
WHERE S.sid IN (
	SELECT R.sid
	FROM Reserves R
	WHERE R.bid = 103
);


/* Obtain the names & ages of the Sailors who have reserved a red boat,
list them in the order of age */

/* Join */
SELECT DISTINCT S.name, S.age
FROM Sailors S, Reserves R, Boats B
WHERE B.color = 'red' AND B.bid = R.bid AND R.sid = S.sid
ORDER BY S.age;

/* Nested Query */
SELECT S.name, S.age
FROM Sailors S
WHERE S.sid IN (
	SELECT R.sid
	FROM Reserves R
	WHERE R.bid IN (
		SELECT B.bid
		FROM Boats B
		WHERE B.color = 'red'
	)
)
ORDER BY S.age;


/* Obtain the ratings of Sailors whose name begins 
and ends with B & contains at least 3 characters */
SELECT S.name, S.rating
FROM Sailors S
WHERE S.name LIKE 'B_%B';


/* Obtain the sid's of sailors who've reserved a red or a green boat */

/* Join */
SELECT DISTINCT R.sid
FROM Reserves R, Boats B
WHERE (B.color = 'red' OR B.color = 'green') AND R.bid = B.bid;

/* Nested Query */
SELECT DISTINCT R.sid
FROM Reserves R
WHERE R.bid IN (
	SELECT B.bid
	FROM Boats B
	WHERE B.color = 'red' OR B.color = 'green'
);

/* Union */
SELECT DISTINCT R.sid
FROM Reserves R, Boats B
WHERE B.color = 'red' AND R.bid = B.bid
UNION 
SELECT DISTINCT R.sid
FROM Reserves R, Boats B
WHERE B.color = 'green' AND R.bid = B.bid;


/* Obtain sailor details whose rating is greater than 
that of a sailor called Horatio */
SELECT *
FROM Sailors S
WHERE S.rating > ANY (
	SELECT S2.rating
	FROM Sailors S2
	WHERE S2.name = 'Horatio'
);


/* Obtain saliors who have resrved all boats */

/* Not Exists */
SELECT S.name
FROM Sailors S
WHERE NOT EXISTS (
	SELECT B.bid
	FROM Boats B
	WHERE NOT EXISTS ( 
		SELECT R.bid
		FROM Reserves R
		WHERE R.bid = B.bid AND R.sid = S.sid
	)
);

/* Not In, Not exists */
SELECT S.name
FROM Sailors S
WHERE NOT EXISTS (
	SELECT B.bid
	FROM Boats B
	WHERE B.bid NOT IN ( 
		SELECT R.bid
		FROM Reserves R
		WHERE R.sid = S.sid
	)
);


/*Obtain the count of the number of sailors */
SELECT COUNT(*) AS sailors_count
FROM Sailors;


/* Obtain the average age of sailors who have rating 10 */
SELECT AVG(S.age) AS avg_age
FROM Sailors S
WHERE S.rating = 10;


/* Obtain the name of the sailors with max rating */
SELECT DISTINCT S.name
FROM Sailors S
WHERE S.rating = (
	SELECT MAX(S2.rating)
	FROM Sailors S2
);


/* Obtain the count of different ratings */ 
SELECT COUNT(DISTINCT S.rating) as rating
FROM Sailors S;


/* Obtain the average age of sailors for each rating level */
SELECT S.rating, AVG(S.age) as avg_age
FROM Sailors S
GROUP BY S.rating;


/* Obtain the average age of sailors for each rating level
that has at least two sailors */
SELECT S.rating, AVG(S.age) as avg_age
FROM Sailors S
GROUP BY S.rating
HAVING COUNT(*) > 1;


/* Obtain all sailors who are atleast 40 years old for each rating */
SELECT S.rating, AVG(S.age) as avg_age
FROM Sailors S
WHERE S.age >= 40
GROUP BY S.rating;


/* Obatin all sailors for each(grouped by) rating 
who are atleast 40 years old */
SELECT S.rating, AVG(S.age) as avg_age
FROM Sailors S
GROUP BY S.rating
HAVING AVG(S.age) >= 40;


/* Sample of Aggregated Functions with NULLS */
DELETE FROM Sailors WHERE sid = 99;

INSERT INTO Sailors
VALUES (99, 'Dan', NULL, 40.0)

SELECT * FROM Sailors;

/* Obtain the count of the number of sailors */
SELECT COUNT(*) AS sailors_count
FROM Sailors;

/* Obtain the count of different ratings */ 
SELECT COUNT(DISTINCT S.rating) as rating
FROM Sailors S;

/* Obtain the count of the age of all sailors */
SELECT COUNT(S.age) AS sailors_count
FROM Sailors S;


/* Outer Joins */

/* Obtain all sailors who that have reserved boats and those who have not */

/* Left Outer Join */
SELECT S.sid, S.name, R.bid
FROM Sailors S LEFT OUTER JOIN Reserves R
ON R.sid = S.sid
ORDER BY S.sid;


/* Obtain all sailors only who have reserved boats */

/* Right Outer Join */
SELECT S.sid, S.name, R.bid
FROM Sailors S RIGHT OUTER JOIN Reserves R
ON R.sid = S.sid
ORDER BY S.sid;


/* Obtain all rows from the left table and all rows from the right table */

/* Full Outer Join Using Union */
SELECT S.sid, S.name, R.bid
FROM Sailors S LEFT OUTER JOIN Reserves R
ON R.sid = S.sid
UNION
SELECT S.sid, S.name, R.bid
FROM Sailors S RIGHT OUTER JOIN Reserves R
ON R.sid = S.sid
ORDER BY S.sid;


/* Obtain report of sailors younger than 19 years old from the sailors table */

/* Trigger - MySQL */
DROP TABLE IF EXISTS ReportYoungSailors;
CREATE TABLE ReportYoungSailors (
	sid INTEGER NOT NULL PRIMARY KEY,
	name VARCHAR(32) NOT NULL,
	age INTEGER,
	rating INTEGER	
);

DROP TRIGGER IF EXISTS YoungSailorsUpdate;
CREATE TRIGGER YoungSailorsUpdate
AFTER INSERT ON Sailors
FOR EACH ROW
INSERT INTO ReportYoungSailors (sid, name, age, rating);

SELECT *
FROM Sailors
WHERE age <= 18;

INSERT INTO Sailors 
VALUES (27, 'Alfred', 17, 9);

SELECT *
FROM ReportYoungSailors;