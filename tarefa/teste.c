#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"

//pinos utilizados para a comunicação I2C
#define I2C_PORT i2c1 
#define PINO_SCL 14 //clock
#define PINO_SDA 15 //dados
#define LED_R_PIN 13
#define LED_G_PIN 11
#define LED_B_PIN 12

#define BTN_A_PIN 5

int A_state = 0;    //Botao A está pressionado?

ssd1306_t disp;

void inicializa(){

    stdio_init_all(); //inicializa a funcionalidade de entrada/saida
    i2c_init(I2C_PORT, 400*1000);// I2C Inicialização do barramento i2c. Usando 400Khz(taxa padrão)
    gpio_set_function(PINO_SCL, GPIO_FUNC_I2C); //Configura o pino (SCL) para o modo I2C
    gpio_set_function(PINO_SDA, GPIO_FUNC_I2C); //Configura o pino (SDA) para o modo I2C
    gpio_pull_up(PINO_SCL); //para manter os pinos em nível lógico alto
    gpio_pull_up(PINO_SDA); //para manter os pinos em nível lógico alto
    //disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, 0x3C, I2C_PORT); // Inicializa o display OLED SSD1306 com a resolução de 128x64 pixels e o endereço I2C 0x3C (endereço padrão do display)
    // INICIANDO LEDS
    gpio_init(LED_R_PIN);
    gpio_set_dir(LED_R_PIN, GPIO_OUT);
    gpio_init(LED_G_PIN);
    gpio_set_dir(LED_G_PIN, GPIO_OUT);
    gpio_init(LED_B_PIN);
    gpio_set_dir(LED_B_PIN, GPIO_OUT);

    // INICIANDO BOTÄO
    gpio_init(BTN_A_PIN);
    gpio_set_dir(BTN_A_PIN, GPIO_IN);
    gpio_pull_up(BTN_A_PIN);

}

void mostrar_texto(int col, int lin, int tam, char *msg,  bool q){
    if(q){
    ssd1306_clear(&disp);//Limpa a tela  do display   
    } 
    ssd1306_draw_string(&disp, col, lin,tam, msg);//desenha o texto
    ssd1306_show(&disp);//Atualiza a tela para mostrar o texto
    
    
}

void SinalAberto(){
    gpio_put(LED_R_PIN, 0);
    gpio_put(LED_G_PIN, 1);
    gpio_put(LED_B_PIN, 0);   
}

void SinalAtencao(){
    gpio_put(LED_R_PIN, 1);
    gpio_put(LED_G_PIN, 1);
    gpio_put(LED_B_PIN, 0);

    char *text = "";
}

void SinalFechado(){
    gpio_put(LED_R_PIN, 1);
    gpio_put(LED_G_PIN, 0);
    gpio_put(LED_B_PIN, 0);
}

//verifica se o botão foi pressionado
int WaitWithRead(int timeMS){
    for(int i = 0; i < timeMS; i = i+100){
        A_state = !gpio_get(BTN_A_PIN);
        if(A_state == 1){
            return 1;
        }
        sleep_ms(100);
    }
    return 0;
}

int main() {
    inicializa(); // Inicializa os dispositivos
    char *text = "";
    while(true) {
        SinalFechado(); // Inicia o semáforo fechado (vermelho aceso)
        text = "SINAL FECHADO";
        mostrar_texto(5, 20, 1, text, true);
        

        text = "AGUARDE";
        mostrar_texto(5, 40, 1, text, false);
        sleep_ms(1000);
        


       A_state = WaitWithRead(8000);   //espera com leitura do botäo
     
       if(A_state) { //Se apertar no botão
        SinalAtencao();
        text = "SINAL DE ATENCAO";
        mostrar_texto(5, 20, 1, text, true);
      

        text = "PREPARE-SE";
        mostrar_texto(5, 40, 1, text, false);
        sleep_ms(5000);

        SinalAberto();
        text = "SINAL ABERTO";
        mostrar_texto(5, 10, 1, text, true);

        text = "ATRAVESSAR";
        mostrar_texto(5, 30, 1, text, false);
        

        text = "COM CUIDADO";
        mostrar_texto(5, 40, 1, text, false);
        sleep_ms(8000);

        }
    } 
    return 0;
}
