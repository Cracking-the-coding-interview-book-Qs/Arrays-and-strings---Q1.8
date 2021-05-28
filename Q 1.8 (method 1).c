//method 1>>

//Logic
//Traverse the array and mark the number of total zeros present in the matrix along with their location
//code dekho sidha .Idhar likhke samzana mushkil hai.
//use two auxiliary arrays to store the location. It will take O(R+C) space.

#include<stdio.h>

int main()
{
	int a[100][100],i,R,C,j,counter=0;
	
	printf("\nHow many rows do you want? => ");
	scanf("%d",&R);
	printf("\nHow many columns do you want? => ");
	scanf("%d",&C);
	
	//creating two auxiliary arrays and initialising them all to 1
	int row[R];
	
    for(i=0;i<R;i++)
	{
		row[i]=1;
	}

	int col[C];
	
	for(i=0;i<C;i++)
	{
		col[i]=1;
	}

	printf("\t\nPlz start filling your elements one by one. (ROW-WISE SORTED)");

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
			if(a[i][j]==0)
			{
				row[i]=0;  //marking location of row 
				col[j]=0;  //marking  location of column
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
		for(i=0;i<R;i++)
		{
			for(j=0;j<C;j++)
			{
				//if any one of the parameter is zero, then make that element 0
				if(row[i]==0 || col[j]==0)
				{
					a[i][j]=0;
				}
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
