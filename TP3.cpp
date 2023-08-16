#include <iostream>
#include <iostream>
#include <math.h>      
#include <numeric>
#include <vector>
#include <unistd.h>

using namespace std;

// Declare you variables, structures, forks, etc.
int nb_philo = 6;


//Function declaration
void Think(int id){
  	cout<<"I am the Philosopher number "<<id<<"and I am thinking." << endl;
  	sleep(5);
};

void PickupForks(int id){
    	cout<<"I am the Philosopher number "<<id<<" and I am PickingupForks."<< endl;   
};

void Eat(int id){
    	cout<<"I am the Philosopher number "<<id<<" and I am Eating."<< endl;
    	sleep(2);
};

void PutForks(int id){
   	cout<<"I am the Philosopher number "<<id<<" and I am Putting the forks."<< endl;
};


//CREATE THE THREAD philosopher
void* philoprocess(void* threadarg)
{
   	int id = *(int*)threadarg;
    	cout<<"I am the Philosopher number "<<id<<": "<< endl;
    	Think(id);
    	PickupForks(id);
    	Eat(id);
    	PutForks(id);

   
    	pthread_exit(NULL);
}

///// MAIN /////
int main() {
    
    	cout<<"Info: "<<endl;
    	cout<<"Philosophers and forks are numbered, in counter-clockwise direction. The fork to the right of a philosopher 'i' and the left 'i-1' (with the exeption of the first philosopher)."<<endl<<endl;
    
       
    	while(true) {
        
   		//Create threads
    		pthread_t tphilo[nb_philo];
    		for(int i = 0; i<nb_philo; i++){
        
			int rc;
        		rc = pthread_create(&tphilo[i], NULL, philoprocess, &i); 
        
        		if (rc){
            			cout << "Error:unable to create thread for philosopher " << i << endl;
        		}
    		};
        
   	 	//Check if all the threads are finished before ending the execution
    		for(int i =0; i<nb_philo;i++){
            		pthread_join(tphilo[i],NULL);
    		}
    
    	};
    
    return 0;
}

