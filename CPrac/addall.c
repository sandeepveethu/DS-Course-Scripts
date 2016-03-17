/*
 Using variable number of arguments for function addAll()
 to find sum of the entered integer arguments
 */

#include <stdio.h>

//va_list va_start va_arg va_end

#include <stdarg.h> //this is where magic lies!

int addAll(int,...); //function prototype for addAll() 
//NOTE: last mandatory parameter contains the number of variable arguments

int main()
{
	printf("%d ",addAll(4,2,3,4,5)); //first parameter tells the number of variable arguments
	printf("%d\n",addAll(5,3,4,2,6,1,8)); //since first parameter is 5, so the function 
	//will take only the first 5 variable arguments and ignore after that
	//so, 8 gets ignored
	//NOTE:this ignoring behaviour is similar in the printf() function because printf() also uses va_list

}

//n_args contains the value of number of variable arguments
int addAll(int n_args,...)
{
	int i,sum=0;

	va_list list_pointer; //we declare a pointer which is supposed to point to a list of variable arguments
	//but we haven't told the program which list
	//we do this in the next line

	va_start(list_pointer,n_args); //now list_pointer points to the first element of variable arguments list

	for(i=1;i<=n_args;i++)
	{
		sum += va_arg(list_pointer,int);
	}
	va_end(list_pointer); //clearning things up!
	return sum;
}
