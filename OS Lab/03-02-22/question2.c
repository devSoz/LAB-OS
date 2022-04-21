#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *file;
	char line[100];
	file = fopen(argv[1], "r");
	while(fscanf(file, "%[^\n]\n", line) != EOF)
		printf("%s\n", line);
	fclose(file);
	
	return 0;
}
		
		
