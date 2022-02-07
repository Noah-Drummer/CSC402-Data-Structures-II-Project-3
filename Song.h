
#ifndef Song.h
#define Song.h

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <locale>


using namespace std;

class Song{
	public:
		
		struct byYear : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getYear() < y.getYear());}
		};
		
		struct byBPM : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getBPM() < y.getBPM());}
		};
	
		struct byEnergy : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getEnergy() < y.getEnergy());}
		};
		
		struct byPop : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getPop() < y.getPop());}
		};
		
		struct byDance : public binary_function<Song, Song, bool>{
			bool operator()
			 (Song x, Song y) {return (x.getDance() < y.getDance());}
		};
		
		Song();
		string getTitle();
		string getArtist();
		string getGenre();
		int getYear();
		int getBPM();
		int getEnergy();
		int getPop();
		int getDance();
		bool operator==(int);
		bool operator==(string);
		bool operator==(Song);
		string title;
		string artist;
		string genre;
		int year;
		
	private:
		int bpm;
		int energy;
		int popularity;
		int danceability;
	
	friend ostream &operator<<(ostream&, const Song &s);
	friend istream &operator>>(istream&, Song &s);
};

#endif