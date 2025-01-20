Este programa implementa o controle de pinos GPIO através de um teclado matricial. Seu funcionamento envolve o acionamento de LEDs e de um buzzer.

Sua construção foi realizada a partir da divisão de sua implementação em pequenas partes, estas sendo denominadas tarefas. As tarefas foram distribuídas entre os componentes do grupo de residentes do Embarcatech (Grupo 4 - Subgrupo 3):

- O integrante Lucas Emmanuel ficou responsável por gerenciar o repositório, criar a estrutura principal do código e implementar a inicialização dos pinos e a função de acionar o Led verde;
- O integrante Nerinho Amorim ficou responsável pela função de ler o teclado matricial e auxiliar na gerencia do repositório;
- A integrante Rebeca Helen ficou responsável pela função de acionar o Led azul;
- O integrante Guilherme Pereira ficou responsável pela função de acionar o Led vermelho;
- O integrante Gabriel Vincente ficou responsável pela função de acionar o buzzer, compilação e depuração do código;
- O integrante Gustavo Lima ficou responsável pela compilação do código, simulação no Wokwi e gravar o vídeo explicativo;
- A integrante Mariana Campanati ficou responsável por testar o código e escrever o README.md.

A utilização do programa pode ser vista neste vídeo exemplo:
[https://drive.google.com/file/d/1CSYEIRvbFC_8rhQk2buym1WFwCuRb7I9/view?usp=sharing]

Para utiliza-lo, basta realizar seu download, compilar e rodar o arquivo principal "Controle_GPIO_Teclado_Matricial_Subgrupo3". É possível de interagir com ele através do teclado matricial presente na simulação no Wokwi, presente no arquivo "diagram.json".

O usuário pode acender os LEDs verde, azul e vermelho através das teclas 1, 2 e 3, respectivamente. As teclas A, B, C e D aciona duas ou mais teclas simultaneamente. A tecla * aciona o buzzer.
