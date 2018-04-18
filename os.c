#include<stdio.h>

int main()
{
	int page_fault_rate, memory_access_time,a;
	int page_fault_not_modified, page_fault_modified, choice, modified_per;
	int max_accept_page_fault = 200000000;
	
	printf("Enter page fault if an empty page is available\t or\n The replaced page is not modified in millisecond:\n");
	scanf("%d",&page_fault_not_modified);
	
	printf("Enter page fault if The replaced page is modified in millisecond:");
	scanf("%d",&page_fault_not_modified);
	
	printf("Enter memory access time\n");
	scanf("%d",&memory_access_time);
	
	printf("press \t1 \tif the page is modified\npress \t2 \tif the page is modified");
	switch(choice)
	{
		case 1:
			printf("The page is modified: \n Enter the modified percentage of the time\n");
			scanf("%d",&modified_per);
			
			a= ((1-page_fault_rate)*memory_access_time) + ((modified_per/100)*page_fault_rate*max_accept_page_fault) +((1-(modified_per/100))*page_fault_rate*8000000)-200;	
		printf("value of page fault rate :",page_fault_rate);
		page_fault_rate= 100/1640010;
		printf("value of page fault rate is %d",page_fault_rate);
		case 2:
			printf("The page is not modified: \n retry again \n");
				
	}
	
	
}
