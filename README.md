# Semáforo com Display OLED e LEDs RGB

Este é um projeto de um semáforo com controle via botão, display OLED SSD1306 e LEDs RGB, utilizando o microcontrolador Raspberry Pi Pico. O semáforo exibe as fases de "Sinal Fechado", "Sinal de Atenção" e "Sinal Aberto" no display, e altera as cores dos LEDs RGB de acordo com a fase do semáforo.

## Componentes Utilizados

- Raspberry Pi Pico
- Display OLED SSD1306 (128x64 pixels)
- LEDs RGB (vermelho, verde e azul)
- Botão

## Funcionalidade

O semáforo possui três estados principais:

1. **Sinal Fechado** (vermelho): Indicando que o tráfego está parado.
2. **Sinal de Atenção** (vermelho e amarelo): Preparação para o semáforo abrir.
3. **Sinal Aberto** (verde): O tráfego pode passar.

A troca entre os estados ocorre após o pressionamento de um botão, e cada estado é visualizado tanto no display OLED quanto nos LEDs RGB.

## Pinagem

- **Pino SCL** (Clock I2C): GPIO 14
- **Pino SDA** (Data I2C): GPIO 15
- **LED Vermelho**: GPIO 13
- **LED Verde**: GPIO 11
- **LED Azul**: GPIO 12
- **Botão A**: GPIO 5

## Como Funciona

1. O semáforo inicia com o estado **"Sinal Fechado"**, com o LED vermelho aceso e a mensagem correspondente no display.
2. Após o pressionamento do botão por 8 segundos, o semáforo muda para o estado **"Sinal de Atenção"**, com os LEDs vermelho e verde acesos, e a mensagem "Sinal de Atenção" no display.
3. Após 5 segundos, o semáforo muda para o estado **"Sinal Aberto"**, com o LED verde aceso e as mensagens "Atravessar com Cuidado" sendo exibidas no display.
4. O ciclo se repete enquanto o sistema estiver ligado.

## Instalação

1. **Configuração do ambiente de desenvolvimento**: Instale o compilador C para o Raspberry Pi Pico e as bibliotecas necessárias.
2. **Conexões**: Conecte os pinos do Raspberry Pi Pico aos respectivos componentes (display OLED, LEDs RGB e botão).
3. **Compilação e Upload**: Compile o código e faça o upload para o Raspberry Pi Pico.

## Código

O código principal está implementado no arquivo `teste.c`. Ele utiliza a biblioteca `ssd1306` para controlar o display OLED e a biblioteca `pico/stdlib` para as funções de I/O e controle de GPIO.

## Dependências

- Biblioteca `ssd1306` para o controle do display OLED.
- Biblioteca `pico/stdlib` para funções de entrada/saída e controle de GPIO.

