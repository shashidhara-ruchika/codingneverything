/* Define   */

DROP DATABASE IF EXISTS BOOKSHOP;
CREATE DATABASE BOOKSHOP;

USE BOOKSHOP;

DROP TABLE IF EXISTS CUSTOMER;
CREATE TABLE CUSTOMER
(
	IDCUSTOMER INT NOT NULL,
	NAME VARCHAR(60),
	ADDRESS VARCHAR(60),
	PHONE VARCHAR(60),
	EMAIL VARCHAR(60),

	PRIMARY KEY (IDCUSTOMER)
);


DROP TABLE IF EXISTS PUBLISHER;
CREATE TABLE PUBLISHER
(
	IDPUBLISHER INT NOT NULL,
	NAME VARCHAR(60),
	ADDRESS VARCHAR(60),
	PHONE VARCHAR(60),
	URL VARCHAR(60),

	PRIMARY KEY (IDPUBLISHER)
);


DROP TABLE IF EXISTS AUTHOR;
CREATE TABLE AUTHOR
(
	IDAUTHOR INT NOT NULL,
	NAME VARCHAR(60),
	ADDRESS VARCHAR(60),

	PRIMARY KEY (IDAUTHOR)
);


DROP TABLE IF EXISTS WAREHOUSE;
CREATE TABLE WAREHOUSE
(
	IDWAREHOUSE INT NOT NULL,
	ADDRESS VARCHAR(60),
	PHONE VARCHAR(60),

	PRIMARY KEY (IDWAREHOUSE)
);


DROP TABLE IF EXISTS BOOKS;
CREATE TABLE BOOKS
(
	ISBN BIGINT NOT NULL,
	TITLE VARCHAR(60),
	BOOKS_YEAR INT,
	PRICE DECIMAL(5),
	PUBLISHER_IDPUBLISHER INT NOT NULL,
	AUTHOR_IDAUTHOR INT NOT NULL,

	PRIMARY KEY (ISBN),

	CONSTRAINT BOOKS_PUBLISHER_IDPUBLISHER
	FOREIGN KEY (PUBLISHER_IDPUBLISHER)
	REFERENCES PUBLISHER (IDPUBLISHER)
	ON UPDATE CASCADE,

	CONSTRAINT BOOKS_AUTHOR_IDAUTHOR
	FOREIGN KEY (AUTHOR_IDAUTHOR)
	REFERENCES AUTHOR (IDAUTHOR)
	ON UPDATE CASCADE
);
CREATE INDEX IDX_PUBLISHER_IDPUBLISHER ON BOOKS (PUBLISHER_IDPUBLISHER);
CREATE INDEX IDX_AUTHOR_IDAUTHOR ON BOOKS (AUTHOR_IDAUTHOR);


DROP TABLE IF EXISTS STORED_IN;
CREATE TABLE STORED_IN
(
	BOOKS_ISBN BIGINT NOT NULL,
	WAREHOUSE_IDWAREHOUSE INT NOT NULL,
	BOOK_COUNT INT,

	PRIMARY KEY (BOOKS_ISBN, WAREHOUSE_IDWAREHOUSE),

	CONSTRAINT STORED_IN_BOOKS_ISBN
	FOREIGN KEY (BOOKS_ISBN)
	REFERENCES BOOKS (ISBN)
	ON UPDATE CASCADE,

	CONSTRAINT STORED_IN_WAREHOUSE_IDWAREHOUSE
	FOREIGN KEY (WAREHOUSE_IDWAREHOUSE)
	REFERENCES WAREHOUSE (IDWAREHOUSE)
	ON UPDATE CASCADE
);
CREATE INDEX IDX_BOOKS_ISBN ON STORED_IN (BOOKS_ISBN);
CREATE INDEX IDX_WAREHOUSE_IDWAREHOUSE ON STORED_IN (WAREHOUSE_IDWAREHOUSE);


DROP TABLE IF EXISTS SHOPPING_BASKET;
CREATE TABLE SHOPPING_BASKET
(
	IDSHOPPINGBASKET INT NOT NULL,
	CUSTOMER_IDCUSTOMER INT NOT NULL,

	PRIMARY KEY (IDSHOPPINGBASKET)
);


DROP TABLE IF EXISTS SHOPPING_BASKET_CONTAINS;
CREATE TABLE SHOPPING_BASKET_CONTAINS
(
	SHOPPING_BASKET_IDSHOPPINGBASKET INT NOT NULL,
	BOOKS_ISBN BIGINT NOT NULL,
	BOOK_COUNT INT,

	PRIMARY KEY (SHOPPING_BASKET_IDSHOPPINGBASKET, BOOKS_ISBN),

	CONSTRAINT SHOPPING_BASKET_CONTAINS_SHOPPING_BASKET_IDSHOPPINGBASKET
	FOREIGN KEY (SHOPPING_BASKET_IDSHOPPINGBASKET)
	REFERENCES SHOPPING_BASKET (IDSHOPPINGBASKET)
	ON UPDATE CASCADE,

	CONSTRAINT SHOPPING_BASKET_CONTAINS_BOOKS_ISBN
	FOREIGN KEY (BOOKS_ISBN)
	REFERENCES BOOKS (ISBN)
	ON UPDATE CASCADE
);
CREATE INDEX IDX_SHOPPING_BASKET_IDSHOPPINGBASKET ON SHOPPING_BASKET_CONTAINS (SHOPPING_BASKET_IDSHOPPINGBASKET);
CREATE INDEX IDX_BOOK_ISBN ON SHOPPING_BASKET_CONTAINS (BOOKS_ISBN);

/* Populate */

use	bookshop;

/* a) insert into Publisher */
insert	into	Publisher	
values(01,	'Penguin	Random	House',	'Luchana	23	Madrid	
Spain',535819,'http://www.penguinrandomhouse.com/');
insert	into	Publisher	
values(02,	'Hachette	Livre','50	Victoria	Embankment',227000,	'https://www.hachette.com');
insert	into	Publisher	
values(03,	'HarperCollins','The	News	Building London	Bridge	
Street',2427737,'https://www.harpercollins.com/');

/* b) insert into Author */
insert	into	Author	values	(01,'Cat	Sebastian','9296	Henry	St.	Auburndale	FL	33823');
insert	into	Author	values	(02,'Lorraine	Heath','974	Broad	Dr.	Marcus	Hook	PA	19061');
insert	into	Author	values	(03,'Jill	Shalvis','187	Cherry	Rd.	Reston	VA	20191');
insert	into	Author	values	(04,'Kevin	Kwan','13	Locust	St.	Round	Lake	IL	60073');
insert	into	Author	values	(05,'Elisabeth	Noreback','26	Rock	Creek	Dr.	Tuscaloosa	AL	35405');
insert	into	Author	values	(06,'Pamela	Brown',	'409	Santa	Clara	Ave.	Cedar	Rapids	IA	52402');

/* c) insert into Books - Haper Collins Publisher */
insert	into	Books	values	('9706279318','A Gentleman Never Keeps Score',2018,384.00,03,01);
insert	into	Books	values	('9728304828','Texas Glory',2015,94.50,03,02);
insert	into	Books	values	('9702833373','Rainy day friends',2017,45.00,03,03);	

/* d) insert into Books - Penguin Random House Publisher */
insert	into	Books	values	('9703859383','Crazy Rich Asians',2018,234.50,01,04);
insert	into	Books	values	('9793937483','Tell	me you are mine',2015,23.60,01,05);
insert	into	Books	values	('9729473047','The spy and the traitor',2010,200.00,01,	05);

/* e) insert into Books - Hachette Livre Publisher */
insert	into	Books	values	('9703746264','Paradise	Sky	by Joe Lansdale',2016,145.00,02,06);
insert	into	Books	values	('9739482733','Meet	Camaro from	The	Night Charter',2010,165.99,02,06);

/* f) insert into Customer */
insert	into	Customer	values	(01, 'Karol	Wilson', 
	'75	Poplar	Court	Eugene	OR	97402', 115099561, 'emkw@mail.com');
insert	into	Customer	values	(02, 'Richard	Orson',	
	'33	Richardson	Dr.	Chandler	AZ	85224', 45528305,	'rior@mail.com');
insert	into	Customer	values	(03, 'Loraine	Williams', 
	'8	Market	St.	Portsmouth	VA	23703', 2211600, 'lowi@mail.com');
insert	into	Customer	values	(04, 'Scott	Luka',	
	'412	Pawnee	Lane	Kenosha,	WI	53140', 649373, 'sclu@mail.com');

/* g) insert into Warehouse */
insert	into	Warehouse	values	(01, '530	Roosevelt	Lane	Hopewell	Junction	NY	12533', 5393544);
insert	into	Warehouse	values	(02, '9592	Applegate	Road	Bedford	OH	44146', 9759583);
insert	into	Warehouse	values	(03, '21	Arch	Ave.	Grand	Haven	MI	49417', 9958484);
select * from warehouse;

/* h) insert into Shopping_Basket and Shopping_Basket_Contains */
insert	into	shopping_basket	values	(01, 01);
insert	into	shopping_basket	values	(02, 02);
insert	into	shopping_basket	values	(03, 03);
insert	into	shopping_basket	values	(04, 04);

insert	into	shopping_basket_contains	values(01,'9706279318',1);
insert	into	shopping_basket_contains	values(01,'9703746264',1);
insert	into	shopping_basket_contains	values(01,'9729473047',1);
insert	into	shopping_basket_contains	values(02,'9739482733',1);
insert	into	shopping_basket_contains	values(02,'9728304828',1);
insert	into	shopping_basket_contains	values(02,'9702833373',2);
insert	into	shopping_basket_contains	values(02,'9703859383',1);
insert	into	shopping_basket_contains	values(03,'9793937483',1);
insert	into	shopping_basket_contains	values(03,'9703859383',1);
insert	into	shopping_basket_contains	values(03,'9702833373',1);
insert	into	shopping_basket_contains	values(04,'9739482733',1);
insert	into	shopping_basket_contains	values(04,'9702833373',1);
insert	into	shopping_basket_contains	values(04,'9729473047',1);
insert	into	shopping_basket_contains	values(04,'9793937483',1);

/* i) insert into Stored_In */
insert	into	stored_in	values('9728304828',01,15);
insert	into	stored_in	values('9739482733',01,29);
insert	into	stored_in	values('9729473047',01,151);
insert	into	stored_in	values('9703859383',02,20);
insert	into	stored_in	values('9793937483',02,383);
insert	into	stored_in	values('9706279318',02,293);
insert	into	stored_in	values('9702833373',03,393);
insert	into	stored_in	values('9729473047',03,38);
insert	into	stored_in	values('9706279318',03,48);
insert	into	stored_in	values('9739482733',03,29);

/* Queries  */

USE BOOKSHOP;

/*	1)	Which book is being	sold more right	now?	*/
-----
SELECT TOP 1 B.ISBN, B.TITLE, SUM(SBC.BOOK_COUNT) AS SUM_BOOK_COUNT
FROM SHOPPING_BASKET_CONTAINS SBC, BOOKS B
WHERE B.ISBN = SBC.BOOKS_ISBN 
GROUP BY B.ISBN, B.TITLE
ORDER BY SUM_BOOK_COUNT DESC;
-----
SELECT TOP 1 B.ISBN, B.TITLE, SUM(SBC.BOOK_COUNT) AS SUM_BOOK_COUNT
FROM SHOPPING_BASKET_CONTAINS SBC 
	 INNER JOIN BOOKS B ON B.ISBN = SBC.BOOKS_ISBN 
GROUP BY B.ISBN, B.TITLE
ORDER BY SUM_BOOK_COUNT DESC;
-----


/*	2)	Which customer is buying more books?		*/
-----
SELECT TOP 1 C.NAME, COUNT(SBC.BOOK_COUNT) AS TOTAL_BOOK_COUNT 
FROM CUSTOMER C, SHOPPING_BASKET SB, SHOPPING_BASKET_CONTAINS SBC
WHERE 
	C.IDCUSTOMER = SB.CUSTOMER_IDCUSTOMER AND
	SB.IDSHOPPINGBASKET = SBC.SHOPPING_BASKET_IDSHOPPINGBASKET
GROUP BY C.NAME
ORDER BY TOTAL_BOOK_COUNT DESC;
-----
SELECT TOP 1 C.NAME, COUNT(SBC.BOOK_COUNT) AS TOTAL_BOOK_COUNT 
FROM CUSTOMER C
	 INNER JOIN SHOPPING_BASKET SB 
		ON C.IDCUSTOMER = SB.CUSTOMER_IDCUSTOMER
	 INNER JOIN SHOPPING_BASKET_CONTAINS SBC 
		ON SB.IDSHOPPINGBASKET = SBC.SHOPPING_BASKET_IDSHOPPINGBASKET	
GROUP BY C.NAME
ORDER BY TOTAL_BOOK_COUNT DESC;
-----


/*	3)	Which warehouse	has	Texas Glory	in stock?	*/
-----
SELECT W.IDWAREHOUSE AS WAREHOUSE_CODE, W.PHONE, W.ADDRESS
FROM WAREHOUSE W, STORED_IN S, BOOKS B
WHERE
	B.TITLE = 'Texas Glory' AND
	B.ISBN = S.BOOKS_ISBN AND
	W.IDWAREHOUSE = S.WAREHOUSE_IDWAREHOUSE;
-----
SELECT W.IDWAREHOUSE AS WAREHOUSE_CODE, W.PHONE, W.ADDRESS
FROM WAREHOUSE W
	 INNER JOIN STORED_IN S ON W.IDWAREHOUSE = S.WAREHOUSE_IDWAREHOUSE
	 INNER JOIN BOOKS B ON B.ISBN = S.BOOKS_ISBN
WHERE B.TITLE = 'Texas Glory'	
-----


/*	4)	Which author has more books	on sell?		*/
-----
SELECT TOP 1 A.NAME, COUNT(B.TITLE) AS TOTAL_BOOK_COUNT
FROM AUTHOR A, BOOKS B
WHERE A.IDAUTHOR = B.AUTHOR_IDAUTHOR
GROUP BY A.NAME
ORDER BY TOTAL_BOOK_COUNT DESC;
-----
SELECT TOP 1 A.NAME, COUNT(B.TITLE) AS TOTAL_BOOK_COUNT
FROM AUTHOR A INNER JOIN BOOKS B ON A.IDAUTHOR = B.AUTHOR_IDAUTHOR
GROUP BY A.NAME
ORDER BY TOTAL_BOOK_COUNT DESC;
-----


/*	5)	Which publisher	offers	less books?			*/
-----
SELECT TOP 1 P.NAME, COUNT(B.TITLE) AS TOTAL_BOOK_COUNT
FROM PUBLISHER P, BOOKS B
WHERE P.IDPUBLISHER = B.PUBLISHER_IDPUBLISHER
GROUP BY P.NAME
ORDER BY TOTAL_BOOK_COUNT ASC;
-----
SELECT TOP 1 P.NAME, COUNT(B.TITLE) AS TOTAL_BOOK_COUNT
FROM PUBLISHER P INNER JOIN BOOKS B ON P.IDPUBLISHER = B.PUBLISHER_IDPUBLISHER
GROUP BY P.NAME
ORDER BY TOTAL_BOOK_COUNT ASC;
-----

