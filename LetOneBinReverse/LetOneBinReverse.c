#include <stdio.h>
#include <math.h>
int power(int a, int b){
	int tmp = a;
	if(b == 0)
		return 1;
	else if(b == 1)
		return a;
	else
		b--;
	while(b--){
		a = a * tmp;
	}
	return a;
}

int main(void){
	char num[3] = {0xf1,0xa3,0xe3};
	char tmp;
	int ptr, located, input;
	// Show org numbers
	for(int i = 0; i < sizeof(num); i++){
		printf("[%x] ",(int)num[i] - 0xffffff00);
	}
	// User input
	scanf("%d",&input);
	if(input > 8){
		ptr = (input)%8;
		located = (input)/8;
		if(ptr > 0){
			located +=1;
		}
		else if(ptr == 0){
			ptr = 8;
		}
	}
	else
	{
		ptr = input;
		located = 1;
	}
	// NOT ptr number
	tmp = (num[sizeof(num) - located] - 0xffffff00) >> (ptr-1);
	num[sizeof(num) - located] = (num[sizeof(num) - located] - 0xffffff00);
	if(tmp&0x00000001){
		num[sizeof(num) - located] -=  power(2,ptr-1);
		//printf("1 %x %x\n", num[sizeof(num) - located], power(2,ptr-1));
		printf("It was 1\n");
	}
	else{
		num[sizeof(num) - located] +=  power(2,ptr-1);
		printf("It was 0\n");
	}
	num[sizeof(num) - located] = (num[sizeof(num) - located] + 0xffffff00);
	for(int i = 0; i < sizeof(num); i++){
		if(num[i] < 0){
			printf("[%x] ",num[i] - 0xffffff00);
		}
		else{
			printf("[%x] ",num[i]);
		}
	}
	printf("\np = %d loc = %d max = %d test = %x\n",ptr,located,(int)sizeof(num), 0x1111>>0);
}
