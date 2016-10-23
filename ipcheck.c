/*
	Program to validate IPv4 address strings
	In the case that the IP address is not valid 
	1.111.111.111
	0xFF FF FF FF
	  255 255 255 255
*/
#include <stdio.h>
#include <stdlib.h>

//Args arg[1] = ipaddress string
int main(int argc, char *argv[]) {
	
	validateIP(argv[1]);

	return 0;
}

int validateIP(char *ipaddress){
	if( strlen(ipaddress) < 4 && strlen(ipaddress) > 18){
		printf("%s is not a valid IP address and cannot be parsed out. \n", ipaddress);
	}

	int currentIndex = 0;
	int validIp = 0;
	int currentOctLen = 0;
	do{
		if(ipaddress[currentIndex] > '/' && ipaddress[currentIndex] < ':'){
			if(currentOctLen > 2){
				printf("%s needs to be formated \n", ipaddress);
				validIp = 1;
			}else{
				currentOctLen++;
				currentIndex++;
			}
		}else if(ipaddress[currentIndex] == '.' ){
			currentIndex = currentIndex + 2;
			currentOctLen = 0;
		}else{
			printf("%d currentOctLen %d currentIndex %lu size of ipaddress\n", currentOctLen, currentIndex, strlen(ipaddress));
			printf("%s is not a valid IP address and cannot be parsed out. \n", ipaddress);
		}

		if(strlen(ipaddress) == currentIndex){ 
			validIp = 1;	
			printf("%s is a valid IP \n", ipaddress);
		}
	}while(!validIp);

}

