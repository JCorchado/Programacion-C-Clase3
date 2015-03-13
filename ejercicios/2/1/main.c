#include "concesionario.h"
#include <getopt.h>

int main(int argc , char * argv[])
{
	struct coche *c1, *c2;
	struct concesionario *con;
	char info[4000];
	int val, option_index = 0;

	static struct option long_options[] = {
		{"matricula", required_argument, 0,'m' },
		{"ID", required_argument , 0 , 'i' },
		{"Gama", required_argument, 0 , 'g' },
		{"HELP", required_argument,0,'h' },
		{0}
	};

	val = getopt_long(argc, argv, "m:i:g:h", long_options, &option_index);
	if(val == -1)
		return val;
	
	switch (val){
	case 'm':
		printf("Opcion matricula \n");
		break;
	case 'i':
		printf("Opcion id \n");
		break;
	case 'g':
		printf("Opcion gama \n");
		break;
	case 'd':
		printf("Opcion dueño \n");
		break;
	case 'h':
		printf("Opcion helper \n");
		break;
	default:
		printf("Debe usar el parametro -m , -i , -g , -d , -h \n");
		break;
	}
	
	c1 = curso_coche_alloc();

	curso_coche_attr_set_str(c1, CURSO_COCHE_ATTR_MATRICULA, argv['m']);
	curso_coche_attr_set_str(c1, CURSO_COCHE_ATTR_MARCA, argv['g']);
	curso_coche_attr_set_u32(c1, CURSO_COCHE_ATTR_ID, argv['i']);

	c2 = curso_coche_alloc();

	curso_coche_attr_set_str(c2, CURSO_COCHE_ATTR_MATRICULA, argv['m']);
	curso_coche_attr_set_str(c2, CURSO_COCHE_ATTR_MARCA, argv['g']);
	curso_coche_attr_set_u32(c2, CURSO_COCHE_ATTR_ID, argv['i']);

	con = curso_concesionario_alloc();

	curso_concesionario_attr_set_str(con, CURSO_CONCESIONARIO_ATTR_DUENO,
					 argv['d']);

	curso_concesionario_attr_set_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE,
					   c1);

	curso_concesionario_attr_set_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE,
					   c2);

	curso_concesionario_snprintf(info, sizeof(info), con);
	printf("%s", info);

	curso_concesionario_free(con);
	return 0;
}
