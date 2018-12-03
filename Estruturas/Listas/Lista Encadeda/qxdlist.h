/************************************************************************
 **
 **  @file   qxdlist.h
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

#ifndef ED_QXALG_QXDLIST_H
#define ED_QXALG_QXDLIST_H

#include "qxddefs.h"
#include <stdio.h>

//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//. OBSERVAÇÕES
//.
//. - Não altere este arquivo.
//. - Nos arquivos de implementação você pode definir outras funções para que
//.   sejam usadas como auxiliares das neste arquivo.
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

struct __qxd_list;

/**
 * Representa uma <em>Lista Encadeada</em>, ou apenas \em Lista.
 */
typedef struct __qxd_list *QxList;

/**
 * @name Gestão de vida
 */
///@{

/**
 * Cria uma nova lista.
 *
 * @return Nova lista.
 */
QxList qx_list_new();

/**
 * Descarta uma lista. O uso da lista informada após ser descartada não é válido.
 *
 * @param list Lista que será descartada.
 */
void qx_list_delete(QxList list);
///@}

/**
 * @name Consulta de estado
 */
///@{
/**
 * Determina o tamanho de uma lista.
 *
 * @param list Lista a consultar.
 * @return Número de elementos na lista.
 */
size_t qx_list_size(QxList list);

/**
 * Determina se uma lista está ou não vazia.
 *
 * @param list Lista a consultar.
 * @return \c true se \p list informada não possui elementos; \c false
 *         caso contrário.
 */
bool qx_list_empty(QxList list);
///@}

/**
 * @name Consulta de elementos
 */
///@{
/**
 * Determina se uma lista possui um elemento com valor igual a um valor informado.
 *
 * @param list Lista a consultar.
 * @param element Valor a procurar.
 * @return \c true se algum dos elementos de \p list possui valor
 *         \p element; \c false caso contrário.
 */
bool qx_list_contains(QxList list, int element);

/**
 * Determina o índice em uma lista da primeira ocorrência de um elemento com
 * um valor informado.
 *
 * @param list Lista a consultar.
 * @param element Valor a procurar.
 * @param fromIndex Índice a partir do qual considerar a busca, ou seja, a
 *        busca inicia neste índice.
 * @return Índice do primeiro elemento em \p list com valor \p element,
 *         considerado a partir de \p fromIndex; #QX_LAMBDA_INDEX caso
 *         nenhum elemento encontrado.
 */
qxIndex qx_list_find(QxList list, int element, qxIndex fromIndex);

/**
 * Determina o índice em uma lista da última ocorrência de um elemento com um
 * valor informado.
 *
 * @param list Lista a consultar.
 * @param element Valor a procurar.
 * @param upToIndex Índice até o qual considerar a busca, ou seja, a busca vai
 *        no máximo até este índice.
 * @return Índice do último elemento em \p list com valor \p element,
 *         considerado no máximo até \p upToIndex; #QX_LAMBDA_INDEX caso nenhum
 *         elemento encontrado.
 */
qxIndex qx_list_find_last(QxList list, int element, qxIndex upToIndex);

/**
 * Determina o valor do elemento de uma lista em um determinado índice.
 *
 * @param list Lista a consultar.
 * @param index Índice a considerar.
 * @return Valor do elemento no índice \p index, caso exista; #QX_LAMBDA_ELEMENT
 *         caso \p index esteja fora dos limites de \p list.
 */
int qx_list_at(QxList list, qxIndex index);

/**
 * Determina o valor do primeiro elemento de uma lista.
 *
 * @param list Lista a consultar.
 * @return  Valor do primeiro elemento de \p list, caso exista;
 *          #QX_LAMBDA_ELEMENT caso \p list esteja vazia.
 */
int qx_list_font(QxList list);

/**
 * Determina o valor do último elemento de uma lista.
 *
 * @param list Lista a consultar.
 * @return  Valor do último elemento de \p list, caso exista;
 *          #QX_LAMBDA_ELEMENT caso \p list esteja vazia.
 */
int qx_list_back(QxList list);
///@}

/**
 * @name Modificação
 */
///@{
/**
 * Insere um novo elemento em um dado índice em uma lista, sem perder os
 * elementos anteriores.
 *
 * @param list Lista a modificar.
 * @param element Valor a inserir.
 * @param index Índice que o novo elemento deve ocupar.
 * @return \c true se a inserção foi realizada; \c false caso \p index seja
 *         inválido para \p list ou caso não haja mais memória.
 */
bool qx_list_insert_at(QxList list, int element, qxIndex index);

/**
 * Insere um novo elemento no início de uma lista, sem perder os elementos
 * anteriores.
 *
 * @param list Lista a modificar.
 * @param element Valor a inserir.
 */
void qx_list_push_front(QxList list, int element);

/**
 * Insere um novo elemento no fim de uma lista, sem perder os elementos
 * anteriores.
 *
 * @param list Lista a modificar.
 * @param element Valor a inserir.
 */
void qx_list_push_back(QxList list, int element);

/**
 * Remove de uma lista o \em primeiro elemento com um dado valor.
 *
 * @param list Lista a modificar.
 * @param element Valor a procurar.
 * @return Índice que o elemento removido \em ocupava na lista; #QX_LAMBDA_INDEX
 *         caso não exista em \p list elemento com valor \p element.
 */
qxIndex qx_list_remove_element_first(QxList list, int element);

/**
 * Remove de uma lista o \em último elemento com um dado valor.
 *
 * @param list Lista a modificar.
 * @param element Valor a procurar.
 * @return Índice que o elemento removido \em ocupava na lista; #QX_LAMBDA_INDEX
 *         caso não exista em \p list elemento com valor \p element.
 */
qxIndex qx_list_remove_element_last(QxList list, int element);

/**
 * Remove de uma lista \em todos os elementos com um dado valor.
 *
 * @param list Lista a modificar.
 * @param element Valor a procurar.
 * @return Quantidade de elementos removidos
 */
unsigned int qx_list_remove_element_all(QxList list, int element);

/**
 * Remove um elemento de uma lista num índice dado.
 *
 * @param list Lista a modificar.
 * @param index Índice do elemento a ser removido.
 * @return \c true caso a remoção tenha ocorrido; \c false caso \p index seja
 *         inválido para \p list.
 */
bool qx_list_remove_at(QxList list, qxIndex index);

/**
 * Remove o primeiro elemento de uma lista.
 *
 * @param list Lista a modificar.
 */
void qx_list_pop_front(QxList list);

/**
 * Remove o último elemento de uma lista.
 *
 * @param list Lista a modificar.
 */
void qx_list_pop_back(QxList list);

/**
 * Remove \em todos os elementos de uma lista, tornando-a vazia.
 *
 * @param list Lista a modificar.
 */
void qx_list_clear(QxList list);
///@}

/**
 * @name Extras
 */
///@{
/**
 * Gera a impressão de todos os elementos de uma lista, ordenados pelo índice,
 * no arquivo indicado. O arquivo informado pode inclusive ser uma das saídas
 * padrão (\c stdout ou \c stderr).
 *
 * @param list Lista a consultar.
 * @param fp Arquivo onde imprimir.
 */
void qx_list_print_to(QxList list, FILE *fp);
///@}

#endif //ED_QXALG_QXDLIST_H
