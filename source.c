//
// Created by Kataee on 07/03/2021.
//

#include "header.h"
int sumOfNumbers(int num, int sum) {
    if (num==0) {
        return sum;
    } else {
        num--;
        int readNum;
        printf("Irj be egy szamot. ");
        scanf("%i", &readNum);

        return (readNum + sumOfNumbers(num, sum));


    }
}

//fgv -ben megadott szám fordítottja, 123 - > 321
int reverseNumber(int num1, int num2) {
    if (num1 == 0) {
        return num2;
    } else {
        num2 = 10 * num2;
        num2 += num1 % 10;
        num1 = num1/10;
        return reverseNumber(num1, num2);
    }
}

//egy számot generál, addig olvas be amíg nem 0
int someNumberGenerator(int created) {
    int number;
    printf("Irj be egy szamot: ");
    scanf("%i", &number);
    if (number == 0) {
        return created;
    } else {
        created = created * 10;
        created = created + number;
        return someNumberGenerator(created);
    }
}

//legkisebb számot téríti vissza, annyit olvas be amekkora a /number/
int minMain(int number, int min) {
    if (number <= 0) {
        return 0;
    } else {
        int readNum;
        printf("Irj be egy szamot: ");
        scanf("%i", &readNum);
        number--;
        min = readNum;

        return minimum(number, min);

    }
}
//^^^
int minimum(int number, int min) {
    if (number == 0) {
        return min;
    } else {
        int readNum;
        printf("Irj be egy szamot: ");
        scanf("%i", &readNum);
        number--;
        if (readNum < min) {
            min = readNum;
        }
        return minimum(number, min);
    }
}

//legnagyobb számot téríti vissza, annyit olvas be amekkora a /number/
int maxMain(int number, int max) {
    if (number <= 0) {
        return 0;
    } else {
        int readNum;
        printf("Irj be egy szamot: ");
        scanf("%i", &readNum);
        number--;
        max = readNum;
        return maximum(number, max);

    }
}
//^^^
int maximum(int number, int max) {
    if (number == 0) {
        return max;
    } else {
        int readNum;
        printf("Irj be egy szamot: ");
        scanf("%i", &readNum);
        number--;
        if (readNum > max) {
            max = readNum;
        }
        return maximum(number, max);
    }
}

//létrehozunk egy tömböt amibe elemeket rakunk be, majd ellenőrizzük, hogy szimmetrikus-e
bool simmetricArrayMain() {
    printf("Ird be milyen hosszu legyen a tomb. ");
    int length;
    scanf("%i", &length);
    int* array;
    array = (int*)malloc(length*sizeof(int));
    if (array == 0) {
        printf("Error allocating array pointer");
        return 0;
    }
    printf("Ird be a tomb elemeit\n");
    for (int i=0; i<length; ++i) {
        scanf("%i", &array[i]);
    }
    printf("A tomb: ");
    for (int i=0; i<length; ++i) {
        printf("%i", array[i]);
    }
    printf("\n");
    return simmetricArray(&array[0], length, length, -1, 1);
}

int simmetricArray(int* array, int lengthUnMod, int length, int start, bool simmetric) {
    //printf("%i %i %i\n", array[start+1], array[length-1], (array[start+1] == array[length-1]));

    simmetric = array[start+1] == array[length-1];
    if (simmetric == 0) {
        return simmetric;
    } else if (start == lengthUnMod/2 || start == (lengthUnMod/2)-1) {
        return simmetric;
    } else {
        return simmetricArray(&array[0], lengthUnMod, length - 1, start + 1, simmetric);
    }
}