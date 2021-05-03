/*
 ============================================================================
 Name        : 3.c
 Author      : Vika
 Version     :
 Copyright   : VSU
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

// Автор: Скляренко Виктория
// 1 курс, 4 группа ИВТ (лучщая на физфаке!)
// 2021 год
// программа - калькулятор
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	float a, b, d;
// a - первое число, b - второе число, d - переменная, которая используется в  операции возведения в степень
	char c, n;
// c - операция, n - ответ на вопрос: Do you want to continue?
	float s;
// s тоже используется в операции возведения в степень (d - для положительной степени, s - для отрицательной)
	int i;
// эта штука нужна для нахождения факториала и возведения в степень
	long int f;
// f - факториал
	f = 1;
	do {
		printf(" Input a number: ");
		scanf("%f", &a);
		printf(" Select an operation (+,-,*,/,^,!): ");
		scanf(" %c", &c);
// тут нас просят ввести первое число и операцию
// если операция "!", то все прекрасно, мы получаем ответ и все; если же это какая-то другая операция, тогда нас требуют ввести второе число
		if (c == '!') {
			printf("%f", a);
			if (a < 0) {
				printf(" Error");
// нельзя определить факториал отрицательного числа
			} else {
				if (a == 0) {
					printf(" 1");
// факториал 0 равен 1; невероятно, но факт
				} else {
					for (i = 1; i <= a; i++) {
						f *= i;
					}
					printf(" Result: %ld", f);
				}
			}
// далее следуют операции, для которых нужно второе число
		} else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
			printf(" Input a second number: ");
			scanf("%f", &b);
			switch (c) {
// сложение
			case '+':
				printf(" Result: %f: ", a + b);
				break;
// вычитание
			case '-':
				printf("Result: %f: ", a - b);
				break;
// умножение
			case '*':
				printf(" Result: %f: ", a * b);
				break;
// деление
			case '/':
				if (a == 0) {
					printf("0");
				} else if (b == 0) {
					printf(" Error");
// ошибка, так как делить на 0 нельзя
				} else {
					printf(" Result: %f: ", a / b);
				}
				break;
// возведение в степень
			case '^':
				d = 1;
// это для положительной степени
				if (b < 0) {
					for (int i = 0; i > b; i--) {
						d *= a;
					}
					s = 1 / d;
				} else if (b == 0) {
					s = 1;
				} else {
// для отрицательной
					for (int i = 1; i <= b; i++) {
						d *= a;
					}
					s = d;
				}
				printf(" Result: %f", s);
				break;
			default:
				printf(" Error");
			}
// если ввести какой-то другой символ - будет ошибка
		} else {
			printf(" Error");
		}
// тут у нас спрашивают: "хотим ли мы продолжить?"
// если переменная равна y, о калькулятор перезапускается, если переменная равна n, то на этом все завершается
		printf(" Do you want to continue? (y/n)");
		scanf(" %c", &n);
	} while (n == 'y');
}

