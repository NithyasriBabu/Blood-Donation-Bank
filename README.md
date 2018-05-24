# Setup to run BloodBank Project

Installtion Procedure for Database of Blood Bank
------------------------------------------------
1. Setup the Database:
	a. Create all the databases using the BloodBank.sql file. 
	b. Details of all the tables are below:
		1. USERDB - Details about the user and information needed for the blood donation (Primary Key: Phone Number)
		2. TAGGED - Each donor tags someone who they wish to be their donor
		3. HOSPITALS - List of hospitals with its location
		4. BLOODCAMP - Details about the blood donation camps held at registered hospitals 
		5. BLOODBANK - Availability of each blood type at registerd hospitals
	c. Insert data into HOSPITALS, BLOODBANK and BLOODCAMP tables

Changes to code: 
----------------
In the file Main/Cpp/Main.cpp, line 23, 
 DB::initializeDBConnection((string)"hcu08orauser1d@unixdb",(string)"tcshyd");

Change this username and password to give access to your oracle database.
	a) Change the "hcu08orauser1d@unixdb" to your oracle username and
	b) Change the "tcshyd" to your oracle password.

Compile and Run the Code:
-------------------------

Use below commands to compile all programs and generate DIS.o executable.
	make -f DISmakefile1

Command to run the executable: DIS or ./DIS or ./DIS.o
