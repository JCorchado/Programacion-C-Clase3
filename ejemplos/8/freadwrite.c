#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp;
	char c[] = "ejemplo fwrite/fread";
	char buffer[20];
	int Escritos,Leidos;
	fp = fopen("datos.dat", "w+");
	if (fp == NULL)
		return -1;

	Escritos = fwrite(c, strlen(c) + 1, 1, fp)
	if(Escritos != strlen(c))
		return -1;
	rewind(fp);

	Leidos = fread(buffer, strlen(c) + 1, 1, fp);
	if(Leidos != Escritos)
		return -1;

	printf("%s\n", buffer);

	fclose(fp);
	return 0;
}
