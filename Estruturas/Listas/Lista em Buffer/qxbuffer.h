/************************************************************************
 **
 **  @file   qxdbuffer.h
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


#ifndef ED_QXALG_QXBUFFER_H
#define ED_QXALG_QXBUFFER_H

#include "qxddefs.h"
#include <stdio.h>

//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
//. OBSERVAÇÕES
//.
//. - Não altere este arquivo.
//. - Nos arquivos de implementação você pode definir outras funções para que
//.   sejam usadas como auxiliares das neste arquivo.
//.!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

struct __qxd_buffer;

/**
 * Representa uma <em>Buffer Sequencial Circular</em>, ou apenas \em Buffer.
 */
typedef struct __qxd_buffer *QxBuffer;


/**
 * @name Gestão de vida
 */
///@{
/**
 * Cria um novo buffer.
 *
 * @param  capacity Capacidade \em definitiva do buffer.
 * @pre    \p capacity > 0
 * @return Novo buffer.
 */
QxBuffer qx_buffer_new(size_t capacity);

/**
 * Descarta um buffer. O uso do buffer informado após ser descartado não é válido.
 *
 * @param buffer Buffer que será descartado.
 */
void qx_buffer_delete(QxBuffer buffer);
///@}

/**
 * @name Consulta de estado
 */
///@{
/**
 * Determina o tamanho de um buffer.
 *
 * @param  buffer Buffer a consultar.
 * @return Número de elementos no buffer.
 */
size_t qx_buffer_size(QxBuffer buffer);

/**
 * Determina a capacidade máxima do buffer.
 *
 * A diferença entre a capacidade e o tamanho determina o número de elementos
 * que ainda podemos inserir no buffer.
 *
 * @param  buffer Buffer a consultar.
 * @return Número de espaços existentes para elementos no buffer.
 */
size_t qx_buffer_capacity(QxBuffer buffer);

/**
 * Determina se um buffer está ou não vazio.
 *
 * @param  buffer Buffer a consultar.
 * @return \c true se \p buffer informado não possui elementos; \c false
 *         caso contrário.
 */
bool qx_buffer_empty(QxBuffer buffer);

/**
 * Determina se o buffer está com sua capacidade completamente ocupada por
 * elementos.
 *
 * Ou seja, caso a resposta seja \c true, não há espaço livre para novos
 * elementos, de forma que uma nova inserção falharia.
 *
 * @param  buffer Buffer a consultar.
 * @return \c true caso \p buffer informado não possua espaço livre; \c false
 *         caso contrário.
 */
bool qx_buffer_full(QxBuffer buffer);
///@}

/**
 * @name Consulta de elementos
 */
///@{
/**
 * Determina o valor do elemento na \em frente (início) de um buffer.
 *
 * Ou seja, determina qual seria o próximo elemento a ser removido por uma
 * chamada a \ref qx_buffer_dequeue.
 *
 * @param  buffer Buffer a consultar.
 * @return Valor do primeiro elemento de \p buffer, caso exista;
 *         #QX_LAMBDA_ELEMENT caso \p buffer esteja vazia.
 */
int qx_buffer_font(QxBuffer buffer);

/**
 * Determina o valor do elemento no \em fundo (fim) de um buffer.
 *
 * Ou seja, determina qual foi o último elemento enfileirado por uma chamada
 * a \ref qx_buffer_enqueue.
 *
 * @param  buffer Buffer a consultar.
 * @return Valor do último elemento de \p buffer, caso exista;
 *         #QX_LAMBDA_ELEMENT caso \p buffer esteja vazia.
 */
int qx_buffer_back(QxBuffer buffer);
///@}

/**
 * @name Modificação
 */
///@{
/**
 * Enfileira (\em insere) um elemento informado no buffer informado.
 *
 * @param buffer Buffer a modificar.
 * @param elem   Valor a enfileirar.
 */
void qx_buffer_enqueue(QxBuffer buffer, int elem);

/**
 * Desenfileira (\em remove) o elemento no topo do buffer informado.
 * Caso o buffer esteja vazia, não faz nada.
 *
 * @param buffer Buffer a modificar.
 */
void qx_buffer_dequeue(QxBuffer buffer);

/**
 * Move os elementos de um buffer para outro.
 *
 * Os elementos são movidos na ordem em que entraram no buffer. A movimentação
 * acaba quando:
 *     -# o buffer original esvaziar; ou
 *     -# o buffer destino encher.
 *
 * Os elementos que não foram movidos permanecem no buffer de origem.
 *
 * @param  buffer Buffer de onde os elementos sairão.
 * @param  to     Buffer para onde os elementos serão movidos.
 * @return Quantidade de elementos movidos.
 */
size_t qx_buffer_move(QxBuffer buffer, QxBuffer to);

/**
 * Remove \em todos os elementos de um buffer, tornando-o vazio.
 *
 * @param buffer Buffer a modificar.
 */
void qx_buffer_clear(QxBuffer buffer);
///@}

/**
 * @name Extras
 */
///@{
/**
 * Gera a impressão de todos os elementos de um buffer no arquivo indicado.
 * O arquivo informado pode inclusive ser uma das saídas padrão
 * (\c stdout ou \c stderr).
 *
 * @param buffer Buffer a consultar.
 * @param fp     Arquivo onde imprimir.
 * @see   <a href="https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm" target="_blank"
 * rel="noreferrer noopener">fprintf</a>
 */
void qx_buffer_print_to(QxBuffer buffer, FILE *fp);
///@}



#endif //ED_QXALG_QXBUFFER_H
