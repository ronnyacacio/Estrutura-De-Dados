/************************************************************************
 **
 **  @file   qxdvector.h
 **  @date   2018-11-7
 **  @author Arthur Rodrigues Araruna <ararunaufc(at)gmail.com>
 **
 **  @brief
 **
 **  @copyright
 **  This source code is part of an educational project, associated with
 **  an undergraduate course or extension project, that is hosted at
 **  Universidade Federal do Ceará, Campus Quixadá.
 **  Copyright (C) 2018 UFC Quixadá, All Rights Reserved.
 **
 **  This project is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  This project is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with the source code of this project. If not, see
 **  <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef ED_QXALG_QXDVECTOR_H
#define ED_QXALG_QXDVECTOR_H

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
