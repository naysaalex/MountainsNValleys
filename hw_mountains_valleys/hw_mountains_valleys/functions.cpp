#include <iostream>
#include "functions.h"

using std::cout; using std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if(a>=10 && a<=b)
	{
		if(b<10000)
		{
			return true;
		}
	}
	return false;
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	
	{
		//bigger number
		int place_holder=number;
		int count=0;
		int divide=1;
		bool first=true;
		do
		{
			count++;
			place_holder/=10;
		} while (place_holder!=0);

		place_holder = number;

		for(int i=1; i<count; i++)
		{
			divide*=10;
		}
		char var=' ';
		int check=place_holder/divide;
		int hold=0,one=0,two=0,three=0, between=1;
		bool firstRuns=true,lastSet = false, mid = false;
		if(place_holder<0)
		{
			place_holder*=-1;
		}
		do
		{
			if(!firstRuns)
			{
				//cout<<"last set"<<endl;
				lastSet=true;
				two = hold;
				place_holder/=10;
				one = place_holder%10;
				place_holder/=10;
				//cout<<" two: "<<two<<" one: "<<one<<endl;

			
			}
			else
			{
				two = place_holder%10;
				place_holder/=10;
				divide/=10;
				one = place_holder%10;
				//cout<<"two: "<<two<<"one: "<<one<<endl;

			}

		if(!mid && !lastSet)
		{
			//first=false;
			//cout<<"not mid"<<endl;
			if(var==' ')
			{
				if(count%2==0)
				{
					//even
					if(one>two)
					{
						var='V';
						mid=true;
					}
					else if(one<two)
					{
						var='M';
						mid=true;
					}
					else
					{
						return 'N';
					}
				}
				else if(count%2!=0)
				{
					//odd
					if(one>two)
					{
						var='M';
						mid=true;
					}
					else if(one<two)
					{
						var='V';
						mid=true;
					}
					else
					{
						return 'N';
					}
				}
			}
			if(var=='V')
			{
				if(count%2==0 && one>two)
				{
					//even
					var='V';
					mid=true;
				}
				else if(count%2!=0 && one<two)
				{
					var='V';
					mid=true;
				}
				else{
					//cout<<"N-"<<endl;
					return 'N';
				}
			}
			else if(var=='M')
			{
				if(count%2==0 && one<two)
				{
					var='M';
					mid=true;
				}
				else if(count%2!=0 && one>two)
				{
					var='M';
					mid=true;
				}
				else
				{
					//cout<<"N"<<endl;
					return 'N';
				}
			}
		}
		else if(mid){
			//cout<<"mid"<<endl;
				if(one<two )
				{
					//cout<<"1<2"<<endl;
				if(count%2==0 && var == 'V')
				{
					//cout<<"even - V"<<endl;
					var ='V';
				}
				else if(count%2!=0 && var =='M')
				{
					//cout<<"odd - M"<<endl;
					var='M';
				}
				
				else{
					//cout<<"N"<<endl;
					return 'N';
				}
				}
			else if(one>two )
			{
				//cout<<"1>2"<<endl;
				if(count%2==0 && var =='M')
				{
					//cout<<"even - M"<<endl;
					var='M';
				}
				else if(count %2!=0 && var=='V')
				{
					//cout<<"odd - V"<<endl;
					var = 'V';
				}
				else{
					//cout<<"N"<<endl;
					return 'N';
				}
			}
		}
		else if(lastSet)
		{
			//cout<<"last check"<<endl;
			if(one<two)
			{
					//cout<<"1<2"<<endl;
				if(count%2==0 && var == 'M')
				{
					//cout<<"even - M"<<endl;
					var ='M';
				}
				else if(var =='M')
				{
					//cout<<"odd - M"<<endl;
					var='M';
				}
				
				else{
					//cout<<"N"<<endl;
					return 'N';
				}
			}
			else if(one>two )
			{
				//cout<<"1>2"<<endl;
				if(count%2==0 && var =='V')
				{
					//cout<<"even - V"<<endl;
					var='V';
				}
				else if(var=='V')
				{
					//cout<<"odd - V"<<endl;
					var = 'V';
				}
				else{
					//cout<<"N"<<endl;
					return 'N';
				}
			}
		}
			
			if((one==two)){
			//	cout<<"N"<<endl;
				return 'N';
			}
			
			if(mid && between%2==0)
			{
				mid=false;
			}
			between++;
			hold = one;
			check = place_holder%divide;
			if(divide==10)
			{
				firstRuns=false;
			}
		//	cout<<"ph: "<<place_holder<<" check: "<<check<<" divide: "<<divide<<endl;
		}while(divide !=1 && (place_holder!=0 || check%divide!=0 ));
		//cout<<"final var: "<<var<<endl;
		return var;
	}
	return 'N';
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	int mountains=0,valleys=0;

	for(int i=a; i <= b; i++)
	{
		char range = classify_mv_range_type(i);
		if(range == 'M')
		{
			mountains++;
		}
		else if(range == 'V')
		{
			valleys++;
		}
	}

	cout<<"There are "<<mountains<<" mountain ranges and "<<valleys<<" valley ranges between "<<a<<" and "<<b<<"."<<endl;
}