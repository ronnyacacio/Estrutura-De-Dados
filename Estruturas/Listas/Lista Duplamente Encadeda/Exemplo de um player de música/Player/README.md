# Player de Música
## Descrição
Criar um programa para "imitar" um *player* de música cujo funcionamento segue mais ou menos a dinâmica de um player de carro. 

Associado ao *player*, temos a noção de uma *playlist*, de onde o player tira informações sobre como navegar pelas "músicas".

Nenhuma música precisa tocar de verdade, pois viabilizar essa funcionalidade está fora do escopo da disciplina.

## Interface
- A interação com o usuário deverá ser feita através de um menu de opções, que deve ser exibido ao usuário sempre que uma nova ação puder ser tomada.

    -  As operações mínimas devem ser:
    
        1. Tocar
        1. Pausar
        1. Parar
        1. Avançar música
        1. Retroceder música
        1. Estado atual
        1. Inserir música
        1. Remover música
        1. Mostrar *playlist*
        1. Encerrar
        
    - Algumas opções podem apresentar um sub-menu ao usuário ou pedir novas informações.
    
        - "Inserir música" deve pedir a posição na *playlist* onde inserir a música.
        
        - "Remover música" deve perguntar qual da músicas da *playlist* deve ser removida.
        
    - As "músicas" devem ser representadas por *strings*. Permita o uso de até 10 caracteres.
        
    - Sempre que a playlist for exibida na tela, deve haver algum destaque sobre a música atual.
    
### Observações
1. **Parar** faz com que, ao retomar a reprodução, a primeira música da *playlist* passe a ser considerada a atual.

1. Estando na última música, **Avançar** vai para a primeira.

1. Estando na primeira música, **Retroceder** vai para a última.

1. **Estado atual** diz respeito a se o *player* está *Reproduzindo*, *Pausado* ou *Parado* e qual é a música atual.

1. O usuário pode inserir uma música em qualquer posição válida dentro da playlist.

1. O usuário pode remover qualquer música da playlist.

## Funcionalidades opcionais
- Você pode omitir as entradas do menu que não se aplicam ao contexto atual. (Por exemplo, quando tocando, não apresentar a opção "Tocar").

- Você pode permitir nomes maiores para as músicas.

- Você pode adicionar uma noção de tempo de duração às músicas e uma forma de avançar a reprodução da *playlist* automaticamente.