#include <stdio.h>
#include <unistd.h>

#include <wiringx.h>

#define A_PIN 12
#define B_PIN 24
#define C_PIN 8
#define D_PIN 16
#define E_PIN 18
#define F_PIN 10
#define G_PIN 22

int initialize();
void draw_number(int n);
void draw(int a, int b, int c, int d, int e, int f, int g);

int main() {
    if (initialize()) {
        printf("initialization error\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        draw_number(i);
        sleep(1);
    }
}

void draw_number(int n) {
    switch(n) {
        case 0:
            draw(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);
            break;
        case 1:
            draw(LOW, HIGH, HIGH, LOW, LOW, LOW, LOW);
            break;
        case 2:
            draw(HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH);
            break;
        case 3:
            draw(HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH);
            break;
        case 4:
            draw(LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH);
            break;
        case 5:
            draw(HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH);
            break;
        case 6:
            draw(HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH);
            break;
        case 7:
            draw(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);
            break;
        case 8:
            draw(HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH);
            break;
        case 9:
            draw(HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH);
            break;
        default:
            break;
    }
}

void draw(int a, int b, int c, int d, int e, int f, int g) {
    digitalWrite(A_PIN, a);
    digitalWrite(B_PIN, b);
    digitalWrite(C_PIN, c);
    digitalWrite(D_PIN, d);
    digitalWrite(E_PIN, e);
    digitalWrite(F_PIN, f);
    digitalWrite(G_PIN, g);
}

int initialize() {
    if(wiringXSetup("milkv_duos", NULL) == -1) {
        wiringXGC();
        return 1;
    }

    if(wiringXValidGPIO(A_PIN) != 0) {
        printf("Invalid GPIO %d\n", A_PIN);
        return 1;
    }
    pinMode(A_PIN, PINMODE_OUTPUT);

    if(wiringXValidGPIO(B_PIN) != 0) {
        printf("Invalid GPIO %d\n", B_PIN);
        return 1;
    }
    pinMode(B_PIN, PINMODE_OUTPUT);

    if(wiringXValidGPIO(C_PIN) != 0) {
        printf("Invalid GPIO %d\n", C_PIN);
        return 1;
    }
    pinMode(C_PIN, PINMODE_OUTPUT);

    if(wiringXValidGPIO(D_PIN) != 0) {
        printf("Invalid GPIO %d\n", D_PIN);
        return 1;
    }
    pinMode(D_PIN, PINMODE_OUTPUT);

    if(wiringXValidGPIO(E_PIN) != 0) {
        printf("Invalid GPIO %d\n", E_PIN);
        return 1;
    }
    pinMode(E_PIN, PINMODE_OUTPUT);

    if(wiringXValidGPIO(F_PIN) != 0) {
        printf("Invalid GPIO %d\n", F_PIN);
        return 1;
    }
    pinMode(F_PIN, PINMODE_OUTPUT);

    if(wiringXValidGPIO(G_PIN) != 0) {
        printf("Invalid GPIO %d\n", G_PIN);
        return 1;
    }
    pinMode(G_PIN, PINMODE_OUTPUT);

    return 0;
}
