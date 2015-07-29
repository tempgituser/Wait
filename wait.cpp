#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#ifdef _WINDOWS
#define __SLEEP__FUNC(x) _sleep(x)
#define __PLATFORM_SLEEP_RATE__ 1
#endif
#ifdef __linux__
#include <unistd.h>
#define __SLEEP__FUNC(x) usleep(x)
#define __PLATFORM_SLEEP_RATE__ 1000
#endif

bool checkInput(char* msChar){

	int msCharLen = strlen(msChar);
	for (int i = 0; i < msCharLen; i++){
		if (msChar[i] < '0' || msChar[i] > '9'){
			printf("wait:时间输入不合法。\n");
			return false;
		}
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (argc <= 1){
		//wcout << "wait!" << endl;
		return 0;
	}
	else if (argc > 2){
		printf("wait:参数过多\n");
		exit(1);
	}
	else{
		//char ** argn = allocate_argn(argc, argv);
		for (int i = 1; i < argc; i++){
			char* msChar = (char*)argv[i];
			while (!checkInput(msChar)){
				msChar = (char*)malloc(256 * sizeof(char));
				memset(msChar, '\0', sizeof(char));
				printf("输入时间:");
				scanf("%s", msChar);
			}

			int ms = atoi(msChar);
			//_sleep(ms);
			__SLEEP__FUNC(ms*__PLATFORM_SLEEP_RATE__);
			//wcout << ms << endl;
		}
	}
	return 0;
}


