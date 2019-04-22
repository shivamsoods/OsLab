//Implementation fo SHORTEST JOB FIRST(Preemptive) Using C++
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct proccess
{
	int at,bt,ct,ta,wt,btt;
	string pro_id;

		/*
	artime = Arrival time,
	bt = Burst time,
	ct = Completion time,
	ta = Turn around time,
	wt = Waiting time
	*/

}Schedule;

bool compare(Schedule a,Schedule b)
{
	return a.at<b.at;

	/* This Schedule will always return TRUE
	if above condition comes*/
}
bool compare2(Schedule a,Schedule b)
{
	return a.bt<b.bt;

	/* This Schedule will always return TRUE
	if above condition comes*/
}

int main()
{
	Schedule pro[10];
	//An array of Processes
	int n,i,j,pcom;
	//n = number of processes, i= iteration variable

	float avgWtime=0;
	float avgTtime=0;
	
	cout<<"Enter the number of Process: ";
	cin>>n;



	for(i=0;i<n;i++)
	{
	cout<<"Enter the Process id :";	cin>>pro[i].pro_id;
		cout<<"Enter the arrival time : ";cin>>pro[i].at;
			cout<<"Enter the burst time : ";cin>>pro[i].bt;
		pro[i].btt=pro[i].bt;
		cout<<endl;
	}

	sort(pro,pro+n,compare);

	/*sort is a predefined funcion  defined in algorithm.h header file,
	it will sort the processes according to their arrival time*/

	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].at>i)
			break;
		}

		sort(pro,pro+j,compare2);

		/*sort is a predefined funcion  defined in algorithm.h header file,
	it will sort the processes according to their burst time*/

		if(j>0)
		{

			for(j=0;j<n;j++)
			{
				if(pro[j].bt!=0)
				break;
			}
			if(pro[j].at>i)

			{
				i=pro[j].at;

			}
			pro[j].ct=i+1;
			pro[j].bt--;
		}
		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(pro[j].bt==0)
			pcom++;
		}
	}

	cout<<"ID\tATime\tBTime\tCTime\tTTime\tWTime\n";

	for(i=0;i<n;i++)
	{
		pro[i].ta=pro[i].ct-pro[i].at;
		pro[i].wt=pro[i].ta-pro[i].btt;

		/*Printing the Process id, arrival time, burst time,
		completion time, turn around time, waiting time*/

		cout<<pro[i].pro_id<<"\t"<<pro[i].at<<"\t"<<pro[i].btt<<"\t"<<pro[i].ct<<"\t"<<pro[i].ta<<"\t"<<pro[i].wt;
		cout<<endl;
	}

	for(int p=0;p<n;p++){
		
		avgWtime=avgWtime+pro[p].wt;
	
	}
	
	for(int p=0;p<n;p++){
		
		avgTtime=avgTtime+pro[p].ct-pro[p].at;
	
	}
	
	cout<<"Average waiting time : "<<(avgWtime/n)<<endl;
	cout<<"Average TurnAround time : "<<(avgTtime/n);
	return 0;
}
