#include "concesionario.h"

int main(void)
{
	struct coche *c1, *c2;
	struct concesionario *con;
	char info[4000];
	c1 = curso_coche_alloc();

	curso_coche_attr_set_str(c1, CURSO_COCHE_ATTR_MATRICULA, "cacacaca");
	curso_coche_attr_set_str(c1, CURSO_COCHE_ATTR_MARCA, "Masserati");
	curso_coche_attr_set_u32(c1, CURSO_COCHE_ATTR_ID, 5);

	c2 = curso_coche_alloc();

	curso_coche_attr_set_str(c2, CURSO_COCHE_ATTR_MATRICULA, "cucucucu");
	curso_coche_attr_set_str(c2, CURSO_COCHE_ATTR_MARCA, "Mustang GT500");
	curso_coche_attr_set_u32(c2, CURSO_COCHE_ATTR_ID, 1);

	con = curso_concesionario_alloc();

	curso_concesionario_attr_set_str(con, CURSO_CONCESIONARIO_ATTR_DUENO,
					 "JCorchado");

	curso_concesionario_attr_set_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE,
					   c1);

	curso_concesionario_attr_set_coche(con, CURSO_CONCESIONARIO_ATTR_COCHE,
					   c2);

	curso_concesionario_snprintf(info, sizeof(info), con);
	printf("%s", info);

	curso_concesionario_free(con);
	return 0;
}
