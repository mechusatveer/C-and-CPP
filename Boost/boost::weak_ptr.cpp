A pointer that does not own or automatically destroy the object it references
(whose lifetime is assumed to be managed by a shared_ptr). We could think it as 
a shared_ptr observer.

A weak_ptr points to the resource managed by a shared_ptr without assuming any
responsibility for it. The reference count for a shared_ptr doesn't increase when 
a weak_ptr references it. That means that the resource of a shared_ptr can be deleted 
while there are still weak_ptr pointing to it. When the last shared_ptr is destroyed, 
the resource is deleted and any remaining weak_ptr are set to NULL. One use for weak_ptr,
as shown in the example below, is to avoid memory leaks caused by circular references.

A weak_ptr can't directly access the resource it points to, we must create a shared_ptr 
from the weak_ptr to access the resource. There are two ways to do this.

We can pass the weak_ptr to the shared_ptr constructor. That creates a shared_ptr to the
resource being pointed to by the weak_ptr and properly increases the reference count.
If the resource has already been deleted, the shared_ptr constructor will 
throw a boost::bad_weak_ptr exception.

We can also call the weak_ptr member function lock(), which returns a shared_ptr to the 
weak_ptr's resource. If the weak_ptr points to a deleted resource, lock will return an empty
shared_ptr. The lock() should be used when an empty shared_ptr isn't considered an error. 
We can access the resource once you have a shared_ptr to it. This approach is shown in
the example below.

weak_ptr should be used in any situation where we need to observe the resource but don't 
want to assume any management responsibilities for it. The example shows the use of weak_ptrs
in circularly referential data, a situation in which two objects refer to each other
internally.

song.h
======
#ifndef SONG_H
#define SONG_H

#include <string>
using std::string;

#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp" 

class Singer; // forward declaration

class Song
{
public:
	Song(const string &SongTitle) ;
        ~Song();
	void printSingerName();
        string title; 
        boost::weak_ptr<Singer> weakSingerPtr;   
        boost::shared_ptr<Singer> sharedSingerPtr; 
};
#endif

Singer.h
========
#ifndef SINGER_H
#define SINGER_H
#include <string>
using std::string;

#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp" 

class Song;

class Singer
{
public:
	Singer::Singer(const string &SingerName);
	~Singer();
	void printSongTitle() ;
        string name; 
	boost::weak_ptr<Song> weakSongPtr;   
	boost::shared_ptr<Song> sharedSongPtr; 
};
#endif
       
       
Singer.cpp
==========
#include <string>
using namespace std;

#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp" 

#include "Song.h"
#include "Singer.h"

Singer::Singer(const string &SingerName) : name(SingerName) 
{
	cout << "Singer constructor: " << name << endl;
}

Singer::~Singer() 
{
	cout << "Singer destructor: " << name << endl; 
}

void Singer::printSongTitle() 
{
	// if weaksongPtr.lock() returns a non-empty shared_ptr
	if (boost::shared_ptr<Song> songPtr = weakSongPtr.lock()) { 
		cout << "Reference count for song " << songPtr->title            
		<< " is " << songPtr.use_count() << "." << endl;              
		cout << "Singer " << name << " wrote the song " << songPtr->title << "\n\n";
	} 
	else // weaksongPtr points to NULL
	        cout << "This Singer has no song." << endl;
}


song.cpp
========
#include <string>
using namespace std;

#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp" 

#include "Song.h"
#include "Singer.h"

Song::Song(const string &SongTitle) : title(SongTitle) 
{
	cout << "Song constructor: " << title << endl;
}
Song::~Song() 
{
	cout << "Song destructor: " << title << endl;
}
void Song::printSingerName() 
{
	// if weakSingerPtr.lock() returns a non-empty shared_ptr
	if (boost::shared_ptr<Singer> singerPtr = weakSingerPtr.lock()  ) {
		// show the reference count increase and print the Singer's name
		cout << "Reference count for Singer " << singerPtr->name 
		     << " is " << singerPtr.use_count() << "." << endl;    
		cout << "The Song " << title << " was written by "       
		     << singerPtr->name << "\n" << endl;   
		} 
 	else // weakSingerPtr points to NULL
 		cout << "This Song has no Singer." << endl;
}

main.cpp
========
#include <iostream>
#include <string>

#include "boost/shared_ptr.hpp"
#include "boost/weak_ptr.hpp"

#include "Singer.h"
#include "Song.h"

using namespace std;

int main()
{
	cout << "Creating a Song and an Singer ..." << endl;
	boost::shared_ptr<Song> SongPtr( new Song( "The Boys" ) );
	boost::shared_ptr<Singer> SingerPtr(new Singer( "Girls Generation" ) ); 

	cout << "\nReferencing the Song and Singer to each other..." << endl;
	SongPtr->weakSingerPtr = SingerPtr;
	SingerPtr->weakSongPtr = SongPtr;  

 	cout << "\nSetting the shared_ptr data members to create the memory leak..." << endl;
        
	SongPtr->sharedSingerPtr = SingerPtr;
	SingerPtr->sharedSongPtr = SongPtr; 
	
	cout << "Reference count for SongPtr and SingerPtr should be one, but ... " << endl;
	cout << "Reference count for Song " << SongPtr->title << " is "
	     << SongPtr.use_count() << endl;
	cout << "Reference count for Singer " << SingerPtr->name << " is "
	     << SingerPtr.use_count() << "\n" << endl;

	cout << "\nAccess the Singer's name and the Song's title through "
        << "weak_ptrs." << endl;
	SongPtr->printSingerName(); 
	SingerPtr->printSongTitle();
 
	cout << "Reference count for each shared_ptr shoulb be back to one:" << endl;
	cout << "Reference count for Song " << SongPtr->title << " is "
	     << SongPtr.use_count() << endl;
        cout << "Reference count for Singer " << SingerPtr->name << " is "
             << SingerPtr.use_count() << "\n" << endl;
 
 	// the shared_ptrs go out of scope, the Song and Singer are destroyed
	cout << "The shared_ptrs are going out of scope." << endl;
 
	return 0;
}

There is memory leak destructor for song and singer not get called
if we comment these lines
//SongPtr->sharedSingerPtr = SingerPtr;
//SingerPtr->sharedSongPtr = SongPtr; 

proper destructor get called.
