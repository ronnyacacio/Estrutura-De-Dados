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
