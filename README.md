# SUPER CERVEJA
### _O super trunfo das cervejas brasileiras_
Esse projeto tem como objetivo utilizar o cunteúdo aprendido na matéria de programação III(EMB5631). Para isso, foi construído um jogo super trunfo sobre algumas das cervejas brasileiras.

## 1. REGRAS DO JOGO
O jogo é multijogdador, para tanto, algumas regras foram levemente modificadas. Assim, para iniciar o jogo é nescessário informar a quantidade de jogadores.

Em seguida, deve-se informar os devidos nomes dos jogadores, se será um bot ou um jogador e, caso seja um bot, também é nescessário informar qual a dificuldade do bot.

O jogo começa com o próximo jogador que receberia cartas. Por exemplo:
|jogador A|jogador B|jogador C|
|:-------:|:-------:|:-------:|
|10 cartas|10 cartas|9  cartas|

Assim, o jogador C começará. Em seguida, o jogador escolherá um dos atributos das cartas e aquele que tiver o maior valor levará as cartas. Ou seja, caso o jogador B ganhe teremos:
|jogador A|jogador B|jogador C|
|:-------:|:-------:|:-------:|
|9  cartas|12 cartas|8  cartas|

Por fim, ganha quem levar todas as cartas dos oponentes.

## 2. Estrutura de código
O código está estruturado em entre classes *cards*, *decks*, *jogador* e *jogo*. Para tanto estão divididos:
|Cards|Decks|Jogador|Jogo |
|:---:|:---:|:-----:|:---:|
|Armazena as propriedades de cada carta| Constroi o deck que distribuirá as caras|Armazena as propriedades de cada jogador|armazena e aplica as regras do jogo|

Para isso o método *Cards* precisa poder:
## 3. Funcionamento das estruturas
Para fins informartivos, a dificuldade do bot é construída dividindo três curvas normalizadas em torno de 33, 66 e 99 em uma escala 0-100. Ou seja, o bot fácil na média terá como valor de dificuldade 16,5%, médio de 49,5% e difícil 82,5%.

<center>
<img src="./images/dificuldade.png" height=300>
</center>

Assim, existe um comportamento variado entre os intervalos de dificuldade. O método de comportamento do bot é ditado pelo melhor valor da rodada, assim quando for a vez do bot jogar um valor entre 0 e 100 é uniformente sorteado e, então, se o valor for maior que a dificuldade do bot terá seu termo alterado.

Exemplo: em certa altura do jogo o Bot_A com 82 de dificuldade escolheria o valor (2) por ser a melhor opção, porém, se na roleta for sorteado um valor maior que 82 terá sua escolha alterada.

```txt
RODADA 47
Jogador Bot_A está avaliando 2

Bot_A DECK(15)
(3A)-----------------------------+
|Nome: Magnifica São Luís        |
+--------------------------------+
|(0)Tato: 45                     |
|(1)Aroma: 50                    |
->|(2)Sabor: 65                    |
|(3)Balanço: 60                  |
|(4)Aparência: 10                |
+--------------------------------+

Bot_B DECK(14)
(5B)-----------------------------+
|Nome: Colorado                  |
+--------------------------------+
|(0)Tato: 50                     |
|(1)Aroma: 30                    |
->|(2)Sabor: 35                    |
|(3)Balanço: 25                  |
|(4)Aparência: 20                |
+--------------------------------+
```

