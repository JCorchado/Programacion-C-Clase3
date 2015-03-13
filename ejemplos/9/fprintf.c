#include <stdio.h>
#include <stdlib.h>

void genera_mensaje(FILE *file)
{
	int linea = 0;
	int resError;
	while (linea < 6) {
		resError=fprintf(file, "Linea %d: Mensaje de prueba\n", linea);
		if(resError < 0)
			return NULL;
		linea++;
	}
	rewind(file);
}

int main (void)
{
	FILE *file = fopen("datos.dat", "a+");
	char *code;
	size_t n = 0;
	int c,resErr;

	if (file == NULL)
		return -1;

	genera_mensaje(file);

	code = malloc(101);
	while(fgets(code, 100, file)) {
		printf("%s", code);
	}

	free(code);
	resErr=fclose(file);
	if(resErr!=0)
		return NULL;
	return 0;
}
