# Steps to run BloodBank Project
## Setup the Database:
* Create all the databases using the BloodBank.sql file. 
* Details of all the tables are below:
	* USERDB - Details about the user and information needed for the blood donation (Primary Key: Phone Number)
	* TAGGED - Each donor tags someone who they wish to be their donor
	* HOSPITALS - List of hospitals with its location
	* BLOODCAMP - Details about the blood donation camps held at registered hospitals 
	* BLOODBANK - Availability of each blood type at registerd hospitals
* Insert data into HOSPITALS, BLOODBANK and BLOODCAMP tables

## Changes to code: 
In the file Main/Cpp/Main.cpp, line 23, <br/>
> DB::initializeDBConnection((string)"hcu08orauser1d@unixdb",(string)"tcshyd"); <br/>

Change this username and password to give access to your oracle database. <br/>
* Change the "hcu08orauser1d@unixdb" to your oracle username <br/>
* Change the "tcshyd" to your oracle password. <br/>

## Compile and Run the Code:
* Commands to compile: make -f DISmakefile1 (Makefile provided with code)
* Executable generated: DIS.o 
* Command to run the executable: DIS or ./DIS or ./DIS.o
