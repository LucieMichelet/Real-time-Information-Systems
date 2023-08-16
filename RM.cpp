//////////////////////////////////////////////////////////////////////////
/////////////// TP n°2 : Implémentation des algorithmes - RM /////////////
/////////////////////////// Lucie MICHELET ///////////////////////////////

#include<iostream>
#include<math.h>
#include <algorithm>
#include <vector>
 
using namespace std;

// Initialization of the task 

class task{
	public :
		int Ro=0;
		int C =0;
		int D =1;
		int P =1;
		float Prio;
		int id;
		int rC;
		int rP;
		void set_param(int r,int c,int d,int p,int i);
};

void task::set_param(int r,int c,int d,int p,int i){
	Ro = r;
	C = c;
	D = d;
	P = p;
	Prio = (float)1/P;
	id = i+1;
	rC = c;
	rP = Ro+P;
};


// Printing the task

void print_task(int n, vector<task> vtask){
	cout<<"------------------------ Printing the tasks --------------------------\n"<<endl;
	for(int i=0;i<n;i++){
		cout<<"Task "<<vtask[i].id;
		cout<<"\tRo"<<"\tC"<<"\tD"<<"\tP"<<"\tPriority"<<endl;
		cout<<"\t"<<vtask[i].Ro<<"\t"<<vtask[i].C<<"\t"<<vtask[i].D<<"\t"<<vtask[i].P<<"\t"<<vtask[i].Prio<<"\n\n";
	}
}

// Creatig the task 

vector<task> create_task(int n,vector<task> vtask){
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"-----------------------Creation of the tasks -------------------------\n"<<endl;
	for (int i=0; i<n;i++){
		int r,c,d,p;
		cout<<"Creation on the Task n°"<<i+1<<" : "<<endl;
		cout<<"\nEnter the date of the first wake up, R = ";
		cin>>r;
		cout<<"Enter the execution time, C = ";
		cin>>c;
		cout<<"Enter current task deadline, D = ";
		cin>>d;
		cout<<"Enter the period, P = ";
		cin>>p;
		cout<<endl;
		task T;
		T.set_param(r,c,d,p,i);
		vtask.push_back(T);
	}
	return vtask;
}

// Calculation of acceptibility test

float RMused(int n,vector<task> vtask){
	float P;
	for(int i=0;i<n;i++){
		P += (float) (vtask[i].C)/(vtask[i].P);}
	return P;
}

float RMmax(int n){
	return n*(pow(2,(float)1/n)-1);
}


// Period calculation

int period(int n,vector<task> vtask){
	int p;
	for(int i=1;i<n;i++){
		p = (vtask[i-1].P*vtask[i].P)/__gcd(vtask[i-1].P,vtask[i].P);
	}
	return p;
}

// Acceptibility test

bool acceptibility_test(int n,vector<task> vtask){
	bool result;
	float used = RMused(n,vtask);
	float max = RMmax(n);
	cout<<"\n----------------------------------------------------------------------\n"<<endl;
	cout<<"\nPercentage of CPU used by the RM : "<<used<<endl;
	cout<<"Percentage of CPU to not exced : "<<max<<"\n\n";
	if (used<=max){
		cout<<"Let's determine the timeline with the Rate Monotonic Algorithm !\n"<<endl;
		result = true;	
		}
	if (used>max){
		cout<<"It is not possible to applicate the Rate Monotonic Algorithm.\n"<<endl;
		result = false;
		}
	return result;
}

// To sort the vector according to the priority
bool compare(const task& a, const task& b) {
    return a.Prio > b.Prio;
}



void RM_algorithm(int n, vector<task> vtask){
	bool result = acceptibility_test(n,vtask);
	if(result == true){
		int t = 0;
		int nbt =0;
		cout<<"--------------------------- The timeline -----------------------------"<<endl;
		int Period = period(n,vtask);
		cout<<"\nThe timeline is cyclic after "<<Period<<" seconds.\n"<<endl;
		
		while(t<Period){
		int resC=0;
		cout<<"Time : "<<t<<"s"<<endl;
			for(int i = 0; i<n;i++){
				if(t%vtask[i].rP==0){
					vtask[i].rC = vtask[i].C;}
				resC += vtask[i].rC;
			}
			
			if(resC == 0){
				cout<<"\t\tNo task is running."<<endl;
			}
			if(resC !=0){
				if(vtask[nbt%n].Ro<=t){
					cout<<"\t\tTask "<<vtask[nbt%n].id<<" is running."<<endl;
					vtask[nbt%n].rC --;
					if(vtask[nbt%n].rC == 0){nbt++;}
				}		
			
				if(vtask[nbt%n].Ro > t){
					cout<<"\t\tTask "<<vtask[nbt%n+1].id<<" is running."<<endl;
					vtask[nbt%n+1].rC --;	
					if(vtask[nbt%n+1].rC == 0){nbt++;}		
				}
			}
		t++;
		}
		cout<<"\n------------------------- End of the program -------------------------\n"<<endl;
		
	
	}
	if(result == false){cout<<"\nTry again with other tasks ..."<<endl;}

} 


// Main code 

int main(){

	int n;
	cout<<"Please enter the number of task that need to be scheduled : ";
	cin>>n;
	cout<<endl;
	vector<task> vtask;
	vtask = create_task(n,vtask);
	std::sort(vtask.begin(), vtask.end(), compare);
	print_task(n,vtask);
	RM_algorithm(n,vtask);

}
