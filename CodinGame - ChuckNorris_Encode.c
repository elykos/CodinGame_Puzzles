#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MESSAGE_LENGTH 101
#define BITSTREAM_LENGTH MESSAGE_LENGTH*8
#define OUTPUT_LENGTH BITSTREAM_LENGTH*8
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    char MESSAGE[MESSAGE_LENGTH];
    fgets(MESSAGE, MESSAGE_LENGTH, stdin);
    
    int i=0;
    
    char output[OUTPUT_LENGTH];
    char binary_string[BITSTREAM_LENGTH];
    
    output[0] = '\0';
    binary_string[0] = '\0';
	
	//printf("\n\nMESSAGE = %s\n\n",MESSAGE);
	//printf("\n\n Binary String = %s\n\n",binary_string);
	
    // Write an action using printf(). DON'T FORGET THE TRAILING \n
    // To debug: fprintf(stderr, "Debug messages...\n");
    while(((MESSAGE[i])!='\0') && ((MESSAGE[i])!= '\n'))
    {
    	
    	char tmp = MESSAGE[i];	 
    	
    	int j; //iterator
    	    	
    	for(j=7;j>0;j--)
	    {
	    	
	    	if((tmp&(1<<j-1))>0)
	        {	
	        	//printf("1");
	        	//printf("\n\n tmp&1 = %d and j = %d",tmp&1,j);
	        	strcat(binary_string,"1");
			}
			else if((tmp&(1<<j-1))==0)
			{
				//printf("0");
				//printf("\n\n tmp&1 = %d and j = %d",tmp&1,j);
				strcat(binary_string,"0");
			}
			else
			{
				strcat(binary_string,"u");
			}
			
			//sleep(1);
		}
		
		i++;
		
    }
    
    int j;
    
    for(j=0;j<strlen(binary_string);j++)
		{
			//printf("\n binary_string[%d] : %c \n",j,binary_string[j]);
			
			if(j==0)
			{
				if(binary_string[j]=='1')
				{
					strcat(output,"0 0");
				}
				
				else if(binary_string[j]=='0')
				{
					strcat(output,"00 0");
				}
			}
			
			else if(j>0 && j<BITSTREAM_LENGTH)
			{
				if(binary_string[j]==binary_string[j-1])
				{
					//printf("	binary_string[%d] (%c)==binary_string[%d-1] (%c) --> Writing 0\n",j,binary_string[j],j,binary_string[j-1]);
					strcat(output,"0");
				}
				
				else if(binary_string[j]!=binary_string[j-1])
				{
					if(binary_string[j]=='1')
					{
						//printf("	binary_string[%d] (%c)!= binary_string[%d-1] (%c) --> Writing _0_0\n",j,binary_string[j],j,binary_string[j-1]);
						strcat(output," 0 0");
					}
					
					else if(binary_string[j]=='0')
					{
						//printf("	binary_string[%d] (%c)!= binary_string[%d-1] (%c) --> Writing _00_0\n",j,binary_string[j],j,binary_string[j-1]);
						strcat(output," 00 0");
					}
				}
			}
		}
	
	
	//printf("\n strlen(binary_string_reversed) = %d",strlen(binary_string_reversed));
	
    //printf("\nBinary String : %s -- Binary String Length : %d ",binary_string,strlen(binary_string));
    //printf("\nOutput : %s",output);
	printf("%s",output);
	printf("\n");
	
	system("pause");

    return 0;
}
