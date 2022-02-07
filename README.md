# CSC402-Data-Structures-II-Project-3
Final project for my Data structures II course.

Author:         Noah Cregger
Creation Date:  4/20/20
Due Date:       4/29/20
Course:         CSC402-401
Professor Name: Dr. Spiegel
Assignment:     Assignment 3 
Filename:       Project3Readme.txt

Design Decisions:
	To hold the information of the song data, I created a class called Song that stored the song name,
	artist, genre, year, bpm, popularity, energy, and danceability. The class contains operator overloads
	for reading data in, printing it out, and finding information in the class. It also contains functors for 
	sorting data based on specific attributes, selected by the user. For proper useage of these functors, I 
	also created getVariable functions to use for each functor. After getting that set up, I had to 
	figure out how to read in the data from the file properly, so first, I created a vector of type Song
	to store each song's data from the file in. Then I created a function that reads the data in directly
	to a song in the vector. I used an operator overload so for each line, it would go through and store the 
	appropriate data into the proper variable in the Song class. After it read all of the information from one line
	into the Song class, it pushed back the Song onto the vector and prepared to read the next line into
	the next Song to go on the vector. After I had all of the data from the file properly stored into the
	Song vector, I created a menu for the user to view the data over several buttons. The user is able to view
	all of the data or they can view it by a given year, artist, song title, genre, or word that is in a title. 
	Each of these options is passed to a seperate function to handle the specified action. For printing out the
	data in a class, it uses an operator overload to print everything in the class. The user also has the option
	to sort the data being printed. If they choose this option, it takes them to a sorting menu which allows them
	to sort by year, energy, popularity, bpm, and danceability. After they choose an option, the sort function is called
	which sorts the data VIA an appropriate functor. Once the data is sorted, the user is then able to go through and 
	choose to print out the sorted information again, or sort it a different way. 
	
	I chose to use a vector because for the data I have and the operations I intended to do on it, a vector would be 
	pretty efficient. Filling the vector with Song class and then printing out all of the data was rather simple. For 
	searching, I could loop through the vector and search for all instances containing certain data, or I could use the 
	find function if it was only one class to be found. For sorting, the sort routine on the vector is pretty powerful, and
	it didn't require me to have to constantly create new data structures. I was able to use the same one and just sort it
	and print its content out however I wanted. 

Deviation:
	I implemented everything I originally planned to implement but with a few changes. Originally, when I sorted, I planned
	on printing all the data out for a given year. I realized this was a complete oversight for me, because if I did that,
	then there wouldn't be much purpose to my yearSearch() function, which does the same thing, just in two steps rather than
	one. In implementing it the way I have it currently, the user isn't forced to view the sorted function by year every time 
	they choose to sort. Rather, they can view the sorted data by year, artist, genre, song title, etc, OR they can view all
	of the sorted data all at once over all years. 
	
Problems:
	For reading in integer variabes using an istream, I first had to store the data in a string variable,
	considering the istream doesn't allow reading in data to an integer variable. Then I created integer
	variables for each piece of data, and converted the string variables into integers to store in the
	integer variables, which I then passed into the current Song class.

How to run:
	First you have to compile the program:
		g++ p3_402.cpp
		
	Then you have to run the program:
		./a.out
		
	The program will immediately read in all of the data into a vector of class Song. You will then have 
	a menu that appears on your screen that allows you to print out the data in multiple ways. You have to 
	type one of the given characters for each option, and if you don't, it will continue prompting you to enter
	an option until a valid one is given. For each option, if you don't put in a result it can find, it will tell
	you that nothing was found for your result, and prompt you again. 
	
	If you choose to sort, you will get another menu allowing you to choose what type of sort to run on the data.
	If it isn't a valid option, it will continue to prompt you until a valid option is given. You may always choose
	not to sort and hit G to go back.
	
	To quit the program, in the printing menu, you must type Q and hit enter. The program will then end.
