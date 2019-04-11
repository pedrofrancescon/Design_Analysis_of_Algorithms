//
//  gennumbers.c
//
//  Created by Pedro Francescon Cittolin 
//  Copyright © 2019 Pedro Francescon Cittolin. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]){

	if(argc != 2)
	{
		fprintf(stderr, "Uso: %s size\n", argv[0]);
		return 1;
	}
	
	int maxval = atoi(argv[1]);
	maxval++;
	srand(time(NULL));

	for (int i = 1; i < maxval; i++)
	{
		//printf("%d\n", i);
		printf("%d\n", (int)(rand()%maxval));
	}

	return 0;
}
