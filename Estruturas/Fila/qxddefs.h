/************************************************************************
 **
 **  @file   qxddefs.h
 **  @date   2018-8-13
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


#ifndef QXDDEFS_H
#define QXDDEFS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>

//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//. OBSERVAÇÕES
//.
//. - Não altere este arquivo.
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

/**
 * Diz respeito a referências inválidas ou inexistentes. Pode ser usado para
 * representar erro ou falha quando esperamos uma referência.
 */
#define QX_LAMBDA_REF NULL
/**
 * Diz respeito a um índice inválido ou inexistente. Pode ser usado para
 * representar erro ou falha quando esperamos um índice.
 */
#define QX_LAMBDA_INDEX SIZE_MAX
/**
 * Diz respeito a elementos inválidos ou inexistentes. Pode ser usado para
 * representar erro ou falha quando esperamos um elemento.
 */
#define QX_LAMBDA_ELEMENT INT_MIN

/**
 * @brief Usado sempre que o parâmetro ou retorno disser respeito a um índice
 *        de um vetor ou lista.
 */
typedef size_t qxIndex;

#endif // QXDDEFS_H
