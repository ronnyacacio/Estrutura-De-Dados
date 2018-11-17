#ifndef QXDVECTOR_H
#define QXDVECTOR_H

#include "qxddefs.h"
#include <stdio.h>

//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//. OBSERVAÇÕES
//.
//. - Não altere este arquivo.
//. - Nos arquivos de implementação você pode definir outras funções para que
//.   sejam usadas como auxiliares das neste arquivo.
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

struct __qxd_vector;

typedef struct __qxd_vector *QxVector;


QxVector qx_vector_new(size_t capacity);

void qx_vector_delete(QxVector vector);

size_t qx_vector_size(QxVector vector);

size_t qx_vector_capacity(QxVector vector);

bool qx_vector_empty(QxVector vector);

bool qx_vector_full(QxVector vector);

bool qx_vector_contains(QxVector vector, int element);

qxIndex qx_vector_find(QxVector vector, int element, qxIndex fromIndex);

qxIndex qx_vector_find_last(QxVector vector, int element, qxIndex upToIndex);

int qx_vector_at(QxVector vector, qxIndex index);

int qx_vector_font(QxVector vector);

int qx_vector_back(QxVector vector);

bool qx_vector_insert_at(QxVector vector, int element, qxIndex index);

void qx_vector_push_front(QxVector vector, int element);

void qx_vector_push_back(QxVector vector, int element);

qxIndex qx_vector_remove_element_first(QxVector vector, int element);

qxIndex qx_vector_remove_element_last(QxVector vector, int element);

unsigned int qx_vector_remove_element_all(QxVector vector, int element);

bool qx_vector_remove_at(QxVector vector, qxIndex index);

void qx_vector_pop_front(QxVector vector);

void qx_vector_pop_back(QxVector vector);

void qx_vector_print_to(QxVector vector, FILE *fp);

#endif //ED_QXALG_QXDVECTOR_H
