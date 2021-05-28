//method 2>>

//Logic
//Traverse the array and mark the number of total zeros present in the matrix along with their location
//code dekho sidha .Idhar likhke samzana mushkil hai.
//use first row and first column as auxiliary arrays to store the location. It will take save auxiliary space.
//use two markers for marking the first row and first corner.
//then traverse for remaining matrix that is for (M-1*N-1)

#include<stdio.h>

int main()
{
	int a[100][100],i,R,C,j,counter=0;
	
	printf("\nHow many rows do you want? => ");
	scanf("%d",&R);
	printf("\nHow many columns do you want? => ");
	scanf("%d",&C);
	
	//creating two markers and initialising them all to false. Atleast ek bhi 0 raha to we can make whole row/col zero.
	//I could use bool here but C doesn't have boolean data type. So I am using integer type to mark.
	int row_mark=1;
	int col_mark=1;
	
	printf("\t\nPlz start filling your elements one by one. ");

	//feeding matrix
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf("\na%d%d => ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	
	//travrsing the matrix and then getting number of zeros and marking their locations by zeros
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			//first row check ki pehle
			if(i==0 && a[i][j]==0)
			{
				row_mark=0;
				counter++;
			}
			//first column check kiya abhi
			if(j==0 && a[i][j]==0)
			{
				col_mark=0;
				counter++;
			}
			//for remaining matrix
			if(a[i][j]==0)
			{
				a[0][j]=0;  //first row is used to mark the column numbers
				a[i][0]=0;   //first col is used to mark the row numbers
				counter++;
			}
		}
	}
	if(counter==0)  //corner case
	{
		printf("\nNo 0s present in the given matrix");
	}
	else
	{
		//now modifying the matrix and making rows and columns 0 if any 0 is encountered
		
		
		for(i=1;i<R;i++)
		{
			for(j=1;j<C;j++)
			{
				//For remaining matrix, if any one of the parameter is zero, then make that element 0
				if(a[0][j]==0 || a[i][0]==0)
				{
					a[i][j]=0;
				}
			}
		}
		
		//if there is zero in first row,make first row equal to 0
		if(row_mark==0)
		{
			for(i=0;i<C;i++)
			{
				a[0][i]=0;
			}	
		}
		
		//ye baad me isiliye kyuki pehle first row and col ki values ka use hone do and baad me modify hone do.
		//if there is zero in first col,make first col equal to 0
		if(col_mark==0)
		{
			for(i=0;i<R;i++)
			{
				a[i][0]=0;
			}	
		}
		
		
	}
	
	printf("\nThe modified matrix is => \n");
	printf("\n");
	
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			printf(" %d ",a[i][j]);
		}
		printf("\n");
	}
return 0;
}
