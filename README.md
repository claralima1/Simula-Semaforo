# 🚦 Semáforo com Display OLED e LEDs RGB  

Projeto de um **semáforo interativo** com controle via botão, **display OLED SSD1306** e **LEDs RGB**, utilizando o microcontrolador **Raspberry Pi Pico**.  
O sistema exibe as fases de **Sinal Fechado**, **Sinal de Atenção** e **Sinal Aberto** no display, alterando as cores dos LEDs de acordo com cada estado.

---

## 🧩 Componentes Utilizados  

- 🥧 **Raspberry Pi Pico**  
- 🖥️ **Display OLED SSD1306** (128x64 pixels)  
- 🌈 **LEDs RGB** (vermelho, verde e azul)  
- 🔘 **Botão de acionamento**

---

## ⚙️ Funcionalidade  

O semáforo possui **três estados principais**:

1. 🔴 **Sinal Fechado**: Tráfego parado.  
2. 🟡 **Sinal de Atenção**: Preparação para abrir.  
3. 🟢 **Sinal Aberto**: Tráfego liberado.

➡️ A troca de estados ocorre após o **pressionamento do botão**, sendo exibida tanto no **display OLED** quanto nos **LEDs RGB**.

---

## 🗂️ Pinagem  

| Componente          | Função          | GPIO |
|---------------------|-----------------|------|
| 🕒 **SCL (Clock I2C)** | Comunicação    | 14   |
| 📝 **SDA (Data I2C)**  | Comunicação    | 15   |
| 🔴 **LED Vermelho**    | Sinal fechado  | 13   |
| 🟢 **LED Verde**       | Sinal aberto   | 11   |
| 🔵 **LED Azul**        | Extra/atenção  | 12   |
| 🔘 **Botão A**         | Acionamento    | 5    |

---

## ▶️ Como Funciona  

1. **Início**: Estado **🔴 Sinal Fechado** com LED vermelho aceso e mensagem no display.  
2. **Após 8s**: Botão pressionado → Estado **🟡 Sinal de Atenção** com LEDs vermelho + verde acesos.  
3. **Após 5s**: Transição para **🟢 Sinal Aberto**, exibindo “Atravessar com Cuidado”.  
4. 🔁 O ciclo se repete enquanto o sistema estiver ligado.

---

## 🛠️ Instalação  

1. **Configuração do ambiente**  
   - Instale o compilador C para o Raspberry Pi Pico.  
   - Adicione as bibliotecas necessárias.

2. **Conexões**  
   - Conecte o Raspberry Pi Pico ao **display OLED**, **LEDs RGB** e **botão**, conforme a pinagem.

3. **Compilação e Upload**  
   - Compile o código e faça o upload para o Raspberry Pi Pico.

---

## 💻 Código  

O código principal está no arquivo **`teste.c`**, utilizando:  
- 📚 Biblioteca **`ssd1306`** para controle do display.  
- 🔧 Biblioteca **`pico/stdlib`** para GPIO e funções de I/O.

---

## 📦 Dependências  

- `ssd1306` – Controle do display OLED.  
- `pico/stdlib` – Entrada/saída e GPIO.
