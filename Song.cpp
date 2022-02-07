
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <Song.h>

using namespace std;

Song::Song(){
	title = artist = genre = "";
	year = bpm = energy = popularity = danceability = 0;
}
string Song::getTitle(){
	return(title);
}
string Song::getArtist(){
	return(artist);
}
string Song::getGenre(){
	return(genre);
}
int Song::getYear(){
	return(year);
}
int Song::getBPM(){
	return(bpm);
}
int Song::getEnergy(){
	return(energy);
}
int Song::getPop(){
	return(popularity);
}
int Song::getDance(){
	return(danceability);
}
bool Song::operator==(string songSearch){
	return(title == songSearch);
}

bool Song::operator==(int searchYear){
	return(year == searchYear);
}

bool Song::operator==(Song searchYear){
	return(year == searchYear.year);
}

istream &operator>>(istream& Source, Song &s){
	int x = 0;
	string yr;
	string beats;
	string nrg;
	string dncblt;
	string poplrty;
	getline(Source, s.title, ',');
	getline(Source, s.artist, ',');
	getline(Source, s.genre, ',');
	getline(Source, yr, ',');
	getline(Source, beats, ',');
	getline(Source, nrg, ',');
	getline(Source, dncblt, ',');
	getline(Source, poplrty);
	stringstream changey(yr);
	changey >> x;
	s.year = x;
	stringstream changeb(beats);
	changeb >> x;
	s.bpm = x;
	stringstream changen(nrg);
	changen >> x;
	s.energy = x;
	stringstream changed(dncblt);
	changed >> x;
	s.danceability = x;
	stringstream changep(poplrty);
	changep >> x;
	s.popularity = x;
	return Source;
}

ostream &operator<<(ostream &Destination, const Song &s)
{
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