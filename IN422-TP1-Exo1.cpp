/////////////////////////////////
//	 Course IN422 
//	 Real Time Information Systems
//	 TP1-EXERCISE1
/////////////////////////////////

#include <iostream>
#include <time.h>
using namespace std;

int main(){

	time_t debut;	// Number of seconds between January 1, 1970 0:00 and the entry request
	time_t fin;		// Number of seconds between January 1, 1970 0:00 and the entry
	int temps;		// Number of seconds apart
	char texte[150]; // String containing the text between
	struct tm * temps_local; // Local time
	clock_t temps_systeme; // Number of Clock ticks
	//////////////////////////////////////////////
	cout << "--- TP 1 EXO 1 ---" << endl;
	cout <<	"Enter a string of characters:" << endl; // Request to enter a string
	///////////////////////////////////////////////////////////////////////////////////
	time(&debut); // Record the number of seconds since January 1, 70 in start
	cin >> texte; // Enter the text
	time(&fin);   // Record the number of seconds since January 1, 70 in end
	temps=(int) (fin-debut); // Difference in number of seconds + cast (conversions) to Integer
	cout <<"You put "<<temps<<" second (s)!"<<endl; // Display the entry time
	/////////////////////////////////////////////////////////////////////////////////
	// acquisition and processing of local time
	temps_local=localtime(&fin); // Convert to local time and displays on the next lines
	cout << "Today's date is: " << temps_local->tm_mday << "/" << temps_local->tm_mon+1 << "/" << temps_local->tm_year+1900 << endl;
	cout << "The local time is: " << temps_local->tm_hour << ":" << temps_local->tm_min << ":" << temps_local->tm_sec << endl;
	// Acquisition and visualization of "system time"
	temps_systeme = clock(); // Function allowing to know how long the process has lasted
	cout << "The program lasted " << temps_systeme << " seconds! " << endl; // Display
	// Wait for end
	cout << "Enter a key to exit ..." << endl;
	cin>>texte;
}
