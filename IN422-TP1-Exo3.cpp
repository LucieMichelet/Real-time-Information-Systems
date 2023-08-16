/////////////////////////////////
//	 Course IN422 
//	 Real Time Information Systems
//	 TP1-EXERCISE3
/////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS  3

void *PrintSentence(void *threadid){ 

	cout<<"The transmitted string is: "<<value<<endl;
	pthread_exit(NULL);
}

int main (){  

	pthread_t TH1;
	int rc;
	char TT[150]="BONJOUR";		// String of characters
	
	rc = pthread_create(&TH1, NULL, PrintSentence, &TT);
	
	if (rc){
	
		cout << "Error:unable to create thread," << rc << endl;
        exit(-1);
	}

    cout<<"\nEnd of program \enter a letter to close\n";
    pthread_exit(NULL);
   	cin>>TT;
}
