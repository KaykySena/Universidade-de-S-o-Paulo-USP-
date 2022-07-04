# Fonte de Tensão (3 V ~ 12 V)
Trabalho solicitado pelo professor Eduardo do Vale Simões como critério parcial de avaliação da disciplina de Eletrônica para Computação, do 1º período de 2022, do curso de Ciências de Computação do Instituto de Ciências Matemáticas e de Computação (ICMC), da Universidade de São Paulo (USP).
## Projeto
Uma fonte de tensão que recebe, em sua entrada, corrente alternada e tensão de 127V ou 220V, e converte em corrente contínua e tensão ajustável em um intervalo de 3V a 12V nos terminal de saída.
## Lista de Materiais
| Material        | Modelo |Descrição|Quantidade           | Preço  |
| ------------- |:-------------:| -----:| -----:| -----:|
|Diodo|1N4007|Silício|4|R$ 0,80|
|Transformador*|-|12 V + 12 V|1|R$ 0,00|
|Capacitor|470UFX25V|470 µF|1|R$ 1,05|
|Diodo Zener|1N4743|13 V|1|R$ 0,48|
|Resistor|1K|1 kΩ|7|R$ 0,49|
|LED|333-2SDRD/S530-A3-L|Vermelho|1|R$ 0,48|
|Potenciômetro|B10K|10 kΩ|1|R$ 7|
|Transistor|BC337-40|NPN|1|R$ 0,69|
|Placa de Prototipagem (*Protoboard*)*|-|830 Pontos|1|R$ 0,00|

*O componente elétrico foi emprestado pelo professor da disciplina.

## Circuito Elétrico
* Transformador:
    
    O transformador reduz a tensão elétrica da entrada, a tomada, no caso, sob a proporção de aproximadamente, 1 : 7,5, a razão de voltas entre o enrolamentos primário e secundário. Assim, entre os terminais de saída, a tensão é, em média, próxima à casa dos 22V.

* Ponte de Diodo

    Sendo composta por um conjunto de quatro diodos, a ponte de diodo complementa o papel do transformador, convertendo corrente alternada em contínua e, por conseguinte, os ciclos da senóide proveniente da tomada, em positivos e, assim, úteis à alimentação do circuito.

* Capacitor

    O capacitor, por sua vez, armazena carga elétrica e gera corrente quando a tensão no circuito passa a ser inferior à tensão entre as suas armaduras e, assim, ele abaixa o valor do *ripple* no circuito, em nossa fonte, de cerca de 10%.

* Diodo Zener

    Por meio do diodo zener, a tensão na saída não cai para menos de 12V

* LED

    É um elemento opcional, sendo o seu papel, apenas, de um sinalizar o funcionamento do circuito.

* Resistor

    Em síntese, os resistores promovem a diminuição do fluxo de corrente elétrica nos ramos do circuito, evitando a sobrecarga dos componentes, como é o caso do LED, por exemplo.

* Potenciômetro

    O potênciometro nos viabiliza o controle da diferença de potencial elétrico entre os terminais de saída da fonte, pois consiste em um resistor de resistência ajustável

* Transistor

    O componente exerce o controle da passagem de corrente elétrica.
### Diagrama Esquemático
### Falstad
![](Imagens/Diagrama%20Esquemático%20(Falstad).png)

https://tinyurl.com/27zkp3qr
### EAGLE
![](Imagens/Diagrama%20Esquemático%20(EAGLE).png)
## Placa de Circuito de Impresso (PCB)
![](Imagens/Placa%20de%20Circuito%20Impresso%20(PCB).png)
### Parte Superior
![](Imagens/Placa%20de%20Circuito%20Impresso%20(PCB)%20(Parte%20Superior).2.png)
### Parte Inferior
![](Imagens/Placa%20de%20Circuito%20Impresso%20(PCB)%20(Parte%20Inferior).2.png)
### Furação
![](Imagens/Placa%20de%20Circuito%20Impresso%20(PCB)%20(Furação).2.png)
## Ripple
(Imagem)
## Vídeo
(Link)
## Grupo
* Kayky Pimentel de Sena;
* Miller Matheus Lima Anacleto Rocha;
* Gabriela Amadori;
* Murilo Fonseca de Matos.