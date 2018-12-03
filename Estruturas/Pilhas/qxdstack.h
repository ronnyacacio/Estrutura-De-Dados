/************************************************************************
 **
 **  @file   qxdstack.h
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


#ifndef ED_QXALG_QXDSTACK_H
#define ED_QXALG_QXDSTACK_H

#include "qxddefs.h"
#include <stdio.h>

//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//. OBSERVAÇÕES
//.
//. - Não altere este arquivo.
//. - Nos arquivos de implementação você pode definir outras funções para que
//.   sejam usadas como auxiliares das neste arquivo.
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

struct __qxd_stack;

/**
 * Representa uma <em>Pilha</em>. O tipo de pilha (estática ou dinâmica) é
 * definido pela implementação.
 */
typedef struct __qxd_stack *QxStack;


/**
 * @name Gestão de vida
 */
///@{
/**
 * Cria uma nova pilha.
 *
 * @param  initCapacity Capacidade inicial da pilha. Pode ser ignorado pela
 *                     implementação caso não seja necessário.
 * @remark \p initCapacity não deve ser 0 para implementações sequenciais.
 * @return Nova pilha.
 */
QxStack qx_stack_new(size_t initCapacity);

/**
 * Descarta uma pilha. O uso da pilha informada após ser descartada não é válido.
 *
 * @param stack Pilha que será descartada.
 */
void qx_stack_delete(QxStack stack);
///@}

/**
 * @name Consulta de estado
 */
///@{
/**
 * Determina o tamanho de uma pilha, ou seja, o número de elementos colecionados.
 *
 * @param stack Pilha a consultar.
 * @return Número de elementos na pilha.
 */
size_t qx_stack_size(QxStack stack);

/**
 * Determina a capacidade máxima atual da pilha.
 *
 * A diferença entre a capacidade e o tamanho determina o número de elementos
 * que ainda podemos inserir sem causar uma realocação de memória na pilha.
 *
 * Para implementações que não limitam a capacidade da pilha de forma rígida,
 * deve sempre retornar #QX_INFINITY_SIZE.
 *
 * @param stack Pilha a consultar.
 * @return Número de espaços existentes para elementos na pilha; ou #QX_INFINITY_SIZE.
 */
size_t qx_stack_capacity(QxStack stack);

/**
 * Determina se uma pilha está ou não vazia.
 *
 * @param stack Pilha a consultar.
 * @return \c true se \p stack informada não possui elementos; \c false
 *         caso contrário.
 */
bool qx_stack_empty(QxStack stack);

/**
 * Determina se o vetor está com sua capacidade completamente ocupada por
 * elementos.
 *
 * Ou seja, caso a resposta seja \c true, não há espaço livre para novos
 * elementos, de forma que uma nova inserção causaria uma realocação de
 * memória no vetor.
 *
 * Para implementações que não limitam a capacidade da pilha de forma rígida,
 * deve sempre retornar \c false.
 *
 * @param stack Pilha a consultar.
 * @return \c true caso \p stack informada não possui espaço livre; \c false
 *         caso contrário.
 */
bool qx_stack_full(QxStack stack);
///@}

/**
 * @name Consulta de elementos
 */
///@{
/**
 * Determina o elemento atualmente no topo da pilha informada.
 *
 * Ou seja, o elemento que seria removido por uma chamada a \ref qx_stack_pop.
 *
 * @param stack Pilha a consultar.
 * @return valor de elemento; ou #QX_LAMBDA_ELEMENT caso \c stack esteja vazia.
 */
int qx_stack_top(QxStack stack);

/**
 * Determina se uma pilha possui um elemento com valor igual a um valor informado.
 *
 * @param stack Pilha a consultar.
 * @param element Valor a procurar.
 * @return \c true se algum dos elementos de \p stack possui valor
 *         \p element; \c false caso contrário.
 */
bool qx_stack_contains(QxStack stack, int element);

/**
 * Determina numa pilha quantos elementos existem acima de um valor informado.
 *
 * Ou seja, quantos elementos temos que desempilhar de forma a obtermos um
 * elemento com valor igual ao informado no topo da pilha.
 *
 * @param stack Pilha a consultar.
 * @param element Valor a procurar.
 * @return Quantidade de elementos acima do procurado; ou #QX_INFINITY_SIZE
 *         caso \p valor não exista em \p stack.
 */
size_t qx_stack_find(QxStack stack, int element);
///@}

/**
 * @name Modificação
 */
///@{
/**
 * Empilha um elemento informado na pilha informada.
 *
 * @param stack Pilha a modificar.
 * @param elem Valor a empilhar.
 */
void qx_stack_push(QxStack stack, int elem);

/**
 * Desempilha o elemento no topo da pilha informada. Caso a pilha esteja vazia,
 * não faz nada.
 *
 * @param stack Pilha a modificar.
 */
void qx_stack_pop(QxStack stack);

/**
 * Remove \em todos os elementos de uma pilha, tornando-a vazia.
 *
 * @param stack Pilha a modificar.
 */
void qx_stack_clear(QxStack stack);
///@}

/**
 * @name Extras
 */
///@{
/**
 * Gera a impressão de todos os elementos de uma pilha no arquivo indicado.
 * O arquivo informado pode inclusive ser uma das saídas padrão
 * (\c stdout ou \c stderr).
 *
 * @param stack Pilha a consultar.
 * @param fp Arquivo onde imprimir.
 * @see <a href="https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm" target="_blank"
 * rel="noreferrer noopener">fprintf</a>
 */
void qx_stack_print_to(QxStack stack, FILE *fp);
///@}

#endif //ED_QXALG_QXDSTACK_H
