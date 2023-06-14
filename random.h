#ifndef GRAPHS__RANDOM_H_
#define GRAPHS__RANDOM_H_

#include <iostream>

/**
 * Генеирует случайное число от min до max(включая max)
 * @param min Минимальное значение, которое может быть сгенерировано
 * @param max Максимальное значение, которое может быть сгенерировано
 * @return случайное число от min до max(включая max)
 */
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

std::pair<int, int> twoRandomDifferentInts(int min, int max) {
    int first = randomInt(min, max);
    int second = randomInt(min, max);
    while (second == first) {
        second = randomInt(min, max);
    }
    return {first, second};
}

#endif  // GRAPHS__RANDOM_H_
