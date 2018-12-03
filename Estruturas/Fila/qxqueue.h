/************************************************************************
 **
 **  @file   qxdqueue.h
 **  @date   2018-11-19
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


#ifndef ED_QXALG_QXQUEUE_H
#define ED_QXALG_QXQUEUE_H

#include "qxddefs.h"
#include <stdio.h>

//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//. OBSERVAÇÕES
//.
//. - Não altere este arquivo.
//. - Nos arquivos de implementação você pode definir outras funções para que
//.   sejam usadas como auxiliares das neste arquivo.
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

struct __qxd_queue;

/**
 * Representa uma <em>Fila Encadeada</em>, ou apenas \em Fila.
 */
typedef struct __qxd_queue *QxQueue;
/**
 * @name Gestão de vida
 */
///@{

/**
 * Cria uma nova fila.
 *
 * @return Nova fila.
 */
QxQueue qx_queue_new();

/**
 * Descarta uma fila. O uso da fila informada após ser descartada não é válido.
 *
 * @param queue Fila que será descartada.
 */
void qx_queue_delete(QxQueue queue);
///@}

/**
 * @name Consulta de estado
 */
///@{
/**
 * Determina o tamanho de uma fila.
 *
 * @param queue Fila a consultar.
 * @return Número de elementos na fila.
 */
size_t qx_queue_size(QxQueue queue);

/**
 * Determina se uma fila está ou não vazia.
 *
 * @param queue Fila a consultar.
 * @return \c true se \p queue informada não possui elementos; \c false
 *         caso contrário.
 */
bool qx_queue_empty(QxQueue queue);
///@}

/**
 * @name Consulta de elementos
 */
///@{
/**
 * Determina se uma fila possui um elemento com valor igual a um valor informado.
 *
 * @param queue Fila a consultar.
 * @param element Valor a procurar.
 * @return \c true se algum dos elementos de \p queue possui valor
 *         \p element; \c false caso contrário.
 */
bool qx_queue_contains(QxQueue queue, int element);

/**
 * Determina numa fila quantos elementos existem à frente de um valor informado.
 *
 * Ou seja, quantos elementos temos que desenfileirar de forma a obtermos um
 * elemento com valor igual ao informado na frente da fila.
 *
 * @param queue Fila a consultar.
 * @param element Valor a procurar.
 * @return Quantidade de elementos à frente do procurado; ou #QX_INFINITY_SIZE
 *         caso \p valor não exista em \p queue.
 */
size_t qx_queue_find(QxQueue queue, int element);

/**
 * Determina o valor do elemento na \em frente (início) de uma fila.
 *
 * Ou seja, determina qual seria o próximo elemento a ser removido por uma
 * chamada a \ref qx_queue_dequeue.
 *
 * @param queue Fila a consultar.
 * @return  Valor do elemento no início de \p queue, caso exista;
 *          #QX_LAMBDA_ELEMENT caso \p queue esteja vazia.
 */
int qx_queue_font(QxQueue queue);

/**
 * Determina o valor do elemento no \em fundo (fim) de uma fila.
 *
 * Ou seja, determina qual foi o último elemento enfileirado por uma chamada
 * a \ref qx_queue_enqueue.
 *
 * @param queue Fila a consultar.
 * @return  Valor do elemento no fim de \p queue, caso exista;
 *          #QX_LAMBDA_ELEMENT caso \p queue esteja vazia.
 */
int qx_queue_back(QxQueue queue);
///@}

/**
 * @name Modificação
 */
///@{
/**
 * Enfileira (\em insere) um elemento informado na fila informada.
 *
 * @param queue Fila a modificar.
 * @param elem Valor a enfileirar.
 */
void qx_queue_enqueue(QxQueue queue, int elem);

/**
 * Desenfileira (\em remove) o elemento no topo da fila informada.
 * Caso a fila esteja vazia, não faz nada.
 *
 * @param queue Fila a modificar.
 */
void qx_queue_dequeue(QxQueue queue);

/**
 * Remove \em todos os elementos de uma fila, tornando-a vazia.
 *
 * @param queue Fila a modificar.
 */
void qx_queue_clear(QxQueue queue);
///@}

/**
 * @name Extras
 */
///@{
/**
 * Gera a impressão de todos os elementos de uma fila no arquivo indicado.
 * O arquivo informado pode inclusive ser uma das saídas padrão
 * (\c stdout ou \c stderr).
 *
 * @param queue Fila a consultar.
 * @param fp Arquivo onde imprimir.
 * @see <a href="https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm" target="_blank"
 * rel="noreferrer noopener">fprintf</a>
 */
void qx_queue_print_to(QxQueue queue, FILE *fp);
///@}

#endif //ED_QXALG_QXQUEUE_H
