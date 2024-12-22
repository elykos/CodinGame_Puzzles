#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char str[4000];
	
	gets(str);
	
	char output[1000];
	char r_str[200];

	output[0] = '\0';
	
	int k;
	for(k=0;k<200;k++)
	{
		r_str[k] = '\0';
	}
	
	//gets(str);
	
	strcat(str,"n");

	int season = 1;

	int current_char = 0;

	int counter = 0;

	char *ptr;
	
	ptr = str;
	
	//printf("sizeof pointer : %d \n",sizeof(char));

	while (*(ptr) != 'n')
	{
		
		if (season == 1)
		{
			if (*(ptr + 1) == '0')
			{
				
				//printf("*(ptr+1) == 0 ---");
				current_char = 0;
				
				ptr++; 
				ptr++;
				//printf("neos ptr = %d \n",ptr);
			}

			else if (*(ptr + 1) == ' ')
			{
				
				//printf("*(ptr+1) == ' ' ---");
				current_char = 1;
				
				ptr++;
				//printf("neos ptr = %d \n",ptr);
			}

			season = 0;
		}

		if (season == 0)
		{
			ptr++;

			if (*ptr == '0')
			{
				//printf("*ptr == '0' ---");
				counter++;
			}
			
			ptr++;

			while ((*ptr != 'n') && (*ptr != ' '))
			{
				//printf("*ptr == %c\n",*ptr);
				if (*ptr == '0')
				{
					counter++;
				}
				
				//printf("\ncounter = %d\n",counter);
				
				ptr++;
			}

			int j;
			for (j = 0;j < counter;j++)
			{
				if(current_char == 1)
				{
					strcat(output, "1");
				}
				
				else if(current_char == 0)
				{
					strcat(output, "0");
				}
				
			}

			counter = 0;
			
			if(*ptr != 'n')
			{
				ptr++;
			}
			
			season = 1;
			
		}
	}

	strcat(output,"n");

	//printf("\n%s\n", output);
	
	
	ptr = output;
	
	while(*ptr != 'n')
	{
		//printf("Mphke while me *ptr = %c \n",*ptr);
		int j;
		
		char bit_num = 0;
		
		for(j=7;j>0;j--)
		{
			//printf("j = %d and *ptr = %c \n",j,*ptr);
			
			if(*ptr=='1')
			{
				bit_num |= (1<<j-1);
			}
			ptr++;
		}
		
		//printf("%x",bit_num);
		//printf("strlen(r_str) : %d ",strlen(r_str));
		r_str[strlen(r_str)] = bit_num;
		//ptr++;
	}
	
	printf("%s",r_str);
	printf("\n");
	
	system("pause");

	return(0);
}
