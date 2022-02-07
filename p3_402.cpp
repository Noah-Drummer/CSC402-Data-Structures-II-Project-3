//Author:         Noah Cregger
//Creation Date:  4/20/20
//Due Date:       4/29/20
//Course:         CSC402-401
//Professor Name: Dr. Spiegel
//Assignment:     Assignment 3
//Filename:       p3_402.cpp
//Purpose:        Read in a data file containing information on the most popular songs on spotify from
//                2010 to 2019, and then allow the user to view the data multiple ways, as well as
//                sort the data multiple ways.

/**
 * @file p3_402.cpp
 * @author Noah Cregger
 * @brief Read in a data file containing information on the most popular songs on spotify from 2010
 to 2019, and then allow the user to view the data multiple ways, as well as sort the data multiple ways. 
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>


using namespace std;

 /**
  * @brief A class for holding song information containing functors for sorting data, and operator
  overloads for comparing data
  *       
*/ 
class Song{
	public:
		
		 /**
		  * @brief A struct for a functor that sorts by year 
		  */ 
		struct byYear : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getYear() < y.getYear());}
		};
		
		/**
		  * @brief A struct for a functor that sorts by BPM 
		  */ 
		struct byBPM : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getBPM() < y.getBPM());}
		};
	
		/**
		  * @brief A struct for a functor that sorts by energy 
		  */ 
		struct byEnergy : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getEnergy() < y.getEnergy());}
		};
		
		/**
		  * @brief A struct for a functor that sorts by popularity 
		  */ 
		struct byPop : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getPop() < y.getPop());}
		};
		
		/**
		  * @brief A struct for a functor that sorts by danceability 
		  */ 
		struct byDance : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getDance() < y.getDance());}
		};
		
		/**
		* @brief constructor to fill all song data as empty
		*/
		Song();

		/**
		* @brief Get the song title
		*/		
		string getTitle();
		
		/**
		* @brief Get the artist of the song
		*/		
		string getArtist();

		/**
		* @brief Get the genre of the song
		*/		
		string getGenre();
		
		/**
		* @brief Get the year of the song
		*/		
		int getYear();
		
		/**
		* @brief Get the BPM of the song
		*/		
		int getBPM();

		/**
		* @brief Get the energy of the song
		*/		
		int getEnergy();

		/**
		* @brief Get the popularity of the song
		*/		
		int getPop();
		
		/**
		* @brief Get the danceability of the song
		*/		
		int getDance();
		
		/**
		* @brief Comparator operator overload for string (title)
		* @param songSearch the title of the song to look for
		*/		
		bool operator==(string);
		
		string title;
		string artist;
		string genre;
		int year;
		
	private:
		int bpm;
		int energy;
		int popularity;
		int danceability;
	
	/**
	* @brief Output operator overload to output all of the data in the current Song class
	* @param Destination reference to the output stream
	* @param s reference to the current Song class
	*/			
	friend ostream &operator<<(ostream&, const Song &s);
	
	/**
	* @brief Input operator overload to input all of the data into the current Song class
	* @param Source reference to the input stream
	* @param s reference to the current Song class
	*/			
	friend istream &operator>>(istream&, Song &s);
};

/**
* @brief constructor to fill all song data as empty
*/
Song::Song(){
	title = artist = genre = "";
	year = bpm = energy = popularity = danceability = 0;
}

/**
* @brief Get the song title
* @return title the song title
*/		
string Song::getTitle(){
	return(title);
}

/**
* @brief Get the artist of the song
* @return artist the song artist
*/		
string Song::getArtist(){
	return(artist);
}

/**
* @brief Get the genre of the song
* @return genre the song genre
*/		
string Song::getGenre(){
	return(genre);
}

/**
* @brief Get the year of the song
* @return year the song year
*/		
int Song::getYear(){
	return(year);
}

/**
* @brief Get the BPM of the song
* @return bpm the song bpm
*/		
int Song::getBPM(){
	return(bpm);
}

/**
* @brief Get the energy of the song
* @return energy the song energy
*/
int Song::getEnergy(){
	return(energy);
}

/**
* @brief Get the popularity of the song
* @return popularity the song popularity
*/
int Song::getPop(){
	return(popularity);
}

/**
* @brief Get the danceability of the song
* @brief danceability the song danceability
*/
int Song::getDance(){
	return(danceability);
}

/**
* @brief Comparator operator overload for string (title)
* @param songSearch the title of the song to look for
* @return true or false based on if the title is equivalent to the title being looked for
*/		
bool Song::operator==(string songSearch){
	return(title == songSearch);
}

/**
* @brief Input operator overload to input all of the data into the current Song class
* @param Source reference to the input stream
* @param s reference to the current Song class
* @return Source reference to the input stream
*/	
istream &operator>>(istream& Source, Song &s){
	//variable x is for converting string to int
	int x = 0;
	//variables here are for holding the string values of the number data for the song
	string yr;
	string beats;
	string nrg;
	string dncblt;
	string poplrty;
	//Go the the input stream and read in variables, stopping at the comma
	getline(Source, s.title, ',');
	getline(Source, s.artist, ',');
	getline(Source, s.genre, ',');
	getline(Source, yr, ',');
	getline(Source, beats, ',');
	getline(Source, nrg, ',');
	getline(Source, dncblt, ',');
	getline(Source, poplrty);
	//convert year to an int and store it in x, then store that in current class
	stringstream changey(yr);
	changey >> x;
	s.year = x;
	//convert bpm to an int and store it in x, then store that in current class
	stringstream changeb(beats);
	changeb >> x;
	s.bpm = x;
	//convert energy to an int and store it in x, then store that in current class
	stringstream changen(nrg);
	changen >> x;
	s.energy = x;
	//convert danceability to an int and store it in x, then store that in current class
	stringstream changed(dncblt);
	changed >> x;
	s.danceability = x;
	//convert popularity to an int and store it in x, then store that in current class
	stringstream changep(poplrty);
	changep >> x;
	s.popularity = x;
	return Source;
}

/**
* @brief Output operator overload to output all of the data in the current Song class
* @param Destination reference to the output stream
* @param s reference to the current Song class
* @param Destination reference to the output stream 
*/			
ostream &operator<<(ostream &Destination, const Song &s)
{
	//Print out all of the current song information
	Destination<<"Title: "<<s.title<<endl;
	Destination<<"Artist: "<<s.artist<<endl;
	Destination<<"Genre: "<<s.genre<<endl;
	Destination<<"Year: "<<s.year<<endl;
	Destination<<"BPM: "<<s.bpm<<endl;
	Destination<<"Energy: "<<s.energy<<endl;
	Destination<<"Danceability: "<<s.danceability<<endl;
	Destination<<"Popularity: "<<s.popularity<<endl;
	return Destination;
}

/**
* @brief Fill a vector of class Song by reading in per line from a dataset and 
push back the current song onto the vector once it hits the end of line and continue until
the end of file
* @param SongV reference to a vector of type Song 
*/	
void getInfo(vector<Song> &SongV){
	ifstream inFile;
	Song currSong; //create a empty song class for the current class 
	inFile.open("CSc402SongDataUpper.txt");
	//Read data into the current class, and then push it back, continue till end of file
	while(inFile >> currSong){
		SongV.push_back(currSong);
	}
	inFile.close();
}

/**
* @brief Print out all of the songs and their information
* @param SongV Vector holding song information
*/
void printSongs(vector<Song> SongV){
	
	vector<Song>::iterator it;   //uses iterator to print vector
	//print out the data for all Songs in the vector
	for(it=SongV.begin(); it != SongV.end(); it++){
		cout<<*it<<endl;
	}
}

/**
* @brief Search through the vector of Songs for songs from a specific year
* @param SongV Vector holding song information
*/
void yearSearch(vector<Song> SongV){
	int yrIn; //variable to hold year to search for (from user)
	int cnt = 0; //counter to see if anything is found
	cout << "Enter the year you want to search for: ";
	cin >> yrIn;
	while(cin.fail()){
		cout << "Not a valid year. Enter a year to search for: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> yrIn;
	}
	cout << endl;
	vector<Song>::iterator it;
	//Search through all Songs in vector
	for (it = SongV.begin(); it != SongV.end(); it++){
		//if year in current song is equal to year from input, print out information and increment counter
		if((*it).year == yrIn){
			cout<<*it<<endl;
			cnt++;
		}
	}
	//if the year was not found in any songs, print out year not found
	if (cnt == 0){
		cout << "Year not found." << endl << endl;
	}
}

/**
* @brief Search through the vector of Songs for songs from a specific artist
* @param SongV Vector holding song information
*/
void artistSearch(vector<Song> SongV){
	string artIn; //variable to hold user input (artist)
	int cnt = 0; //counter to see if anything is found
	cout << "Enter the name of an artist to search for: ";
	//read in the user input including spaces
	getline(cin, artIn);
	getline(cin, artIn);
	cout << endl;
	//convert lowercase letters of user input into uppercase
	for(int i = 0; i<artIn.length(); i++){
		if(artIn[i] >= 97 && artIn[i] <= 122){
			artIn[i]-=32;
		}
	}
	vector<Song>::iterator it;
	//search through all songs in vector
	for (it = SongV.begin(); it != SongV.end(); it++){
		//if artist in current song is equal to user input, print out song information and increment count
		if((*it).artist == artIn){
			cout<<*it<<endl;
			cnt++;
		}
	}
	//if count is 0, artist wasn't found
	if (cnt == 0){
		cout << "Artist not found." << endl << endl;
	}
}

/**
* @brief Search through the vector of Songs for a specific song
* @param SongV Vector holding song information
*/
void songSearch(vector<Song> SongV){
	
	string songIn; //variable for user input (song)
	cout << "Enter the name of a song to search for: ";
	//read in user input including spaces
	getline(cin, songIn);
	getline(cin, songIn);
	cout << endl;
	//convert lowercase letters of user input into uppercase
	for(int i = 0; i<songIn.length(); i++){
		if(songIn[i] >= 97 && songIn[i] <= 122){
			songIn[i]-=32;
		}
	}
	vector<Song>::iterator it;
	//use find function for vector and look for the user input
	it = find(SongV.begin(), SongV.end(), songIn);
	//if the user input was not found, print that out and return
	if (it == SongV.end()){
		cout << "Song not found" << endl << endl;
		return;
	}
	//if song was found, print out song info
	cout<<*it<<endl;
}

/**
* @brief Search through the vector of Songs for songs of a specific genre
* @param SongV Vector holding song information
*/
void genreSearch(vector<Song> SongV){ 
	string genIn; //variable for holding user input (genre)
	int cnt = 0; //counter variable
	cout << "Enter the name of a genre to search for: ";
	//read in user input including spaces
	getline(cin, genIn);
	getline(cin, genIn);
	cout << endl;
	//convert all lowercase letters from user input into uppercase
	for(int i = 0; i<genIn.length(); i++){
		if(genIn[i] >= 97 && genIn[i] <= 122){
			genIn[i]-=32;
		}
	}
	vector<Song>::iterator it;
	//search through all songs in vector
	for (it = SongV.begin(); it != SongV.end(); it++){
		//if genre from user input matches a song's genre, print its information and increment count
		if((*it).genre == genIn){
			cout<<*it<<endl;
			cnt++;
		}
	}
	//if count is 0, no genre was found
	if (cnt == 0){
		cout << "Genre not found." << endl << endl;
	}
}

/**
* @brief Search through the vector of Songs for songs containing a given word
* @param SongV Vector holding song information
*/
void wordSearch(vector<Song> &SongV){
	string wordIn; //variable for user input of a word
	int cnt = 0; //counter
	cout << "Enter a word to search for in song titles: ";
	cin >> wordIn;
	cout << endl;
	//convert all lowercase letters from user input into uppercase
	for(int i = 0; i<wordIn.length(); i++){
		if(wordIn[i] >= 97 && wordIn[i] <= 122){
			wordIn[i]-=32;
		}
	}
	vector<Song>::iterator it;
	//search through all the songs in the vector
	for (it = SongV.begin(); it != SongV.end(); it++){
		//using the find function, if the title contains the word print out song info and increment counter
		if((*it).title.find(wordIn) != string::npos){
			cout<<*it<<endl;
			cnt++;
		}
	}
	//if counter is 0, word wasn't found
	if (cnt == 0){
		cout << "Word not found." << endl << endl;
	}
}

/**
* @brief Menu for user to choose which sort to run
* @param SongV Reference to vector holding song information
* @param SortType Reference to the way the data is currently sorted
*/
void songSort(vector<Song> &SongV, char &SortType){
	char opt; //user input for sort option
	//print out options until user inputs a valid option
	do{
		cout << "Choose an option to sort by:" <<endl;
		cout << "Y)ear sort" << endl;
		cout << "E)nergy sort" <<endl;
		cout << "P)opularity sort" <<endl;
		cout << "B)PM sort" << endl;
		cout << "D)anceability sort" <<endl;
		cout << "G)o back" <<endl;
		cout << "Enter your choice: ";
		cin >> opt;
		//if the user input is same as the way the data is currently formatted, print that out and return
		if(opt == SortType){
			cout << endl << "It is already sorted as such." << endl << endl;
			return;
		}
		cout << endl;
		//switch for user input
		switch(opt){
			//Year sort using byYear functor and update SortType to Y
			case 'Y':
				sort(SongV.begin(), SongV.end(), Song::byYear());
				SortType = 'Y';
				return;
			//Energy sort using byEnergy functor and update SortType to E
			case 'E':
				sort(SongV.begin(), SongV.end(), Song::byEnergy());
				SortType = 'E';
				return;
			//Popularity sort using byPop functor and update SortType to P
			case 'P':
				sort(SongV.begin(), SongV.end(), Song::byPop());
				SortType = 'P';
				return;
			//BPM sort using byBPM functor and update SortType to B
			case 'B':
				sort(SongV.begin(), SongV.end(), Song::byBPM());
				SortType = 'B';
				return;
			//Danceability sort using byDance functor and update SortType to D
			case 'D':
				sort(SongV.begin(), SongV.end(), Song::byDance());
				SortType = 'D';
				return;
		}
	}while(opt != 'G'); //if option is G, go back
	return;
}	

/**
* @brief Menu for how to view the data based on user input
* @param SongV Reference to the vector holding song information
*/
void menuFunc(vector<Song> &SongV){
	char opt; //user input
	char SortType = 'Y'; //default sort type is by year
	//Loop through getting user input until user inputs Q for quit
	do{
		cout << "Choose an option:" <<endl; 
		cout << "P)rint all" << endl;
		cout << "Y)ear search" << endl;
		cout << "A)rtist search" << endl;
		cout << "T)itle search" << endl;
		cout << "G)enre search" << endl;
		cout << "W)ord search" << endl;
		cout << "S)ort" << endl;
		cout << "Q)uit" << endl;
		cout << "Enter your choice: ";
		cin >> opt;
		//Switch statement for view options
		switch(opt){
			//Print out all songs
			case 'P':
				cout << "All song info:" << endl;
				printSongs(SongV);
				break;
			//Print out all songs in a certain year
			case 'Y':
				yearSearch(SongV);
				break;
			//Print out all songs by a certain artist
			case 'A':
				artistSearch(SongV);
				break;
			//Print out info of song with a given title
			case 'T':
				songSearch(SongV);
				break;
			//Print out info of all songs with a certain genre
			case 'G':
				genreSearch(SongV);
				break;
			//Print out info of all songs with a certain word in their title
			case 'W':
				wordSearch(SongV);
				break;
			//Sort the data 
			case 'S':
				cout << endl;
				songSort(SongV, SortType);
				break;
		}
	}while(opt != 'Q');
}

/**
* @brief Driver program
* @return 0 for ending program
*/
int main(){
	
	//Create a vector to hold Song class
	vector<Song> SongV;
	//Fill the vector with getInfo
	getInfo(SongV);
	//Print menu to screen and get user input 
	menuFunc(SongV);
	
	return 0;
}


