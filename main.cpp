#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
#include "setLinked.h"

std::ofstream file("time.dat");

void mierzenie_wstawiania(setLinked& zbiorA, int iteration){
    auto start = std::chrono::high_resolution_clock::now();
    zbiorA.insert(iteration);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    file << iteration << " " << duration << " ";
}

void mierzenie_usuwania(setLinked& zbiorA, int iteration){
    auto start = std::chrono::high_resolution_clock::now();
    zbiorA.usuwanie(iteration);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    file << duration << " ";
}


void mierzenie_sumy(setLinked zbiorA, setLinked zbiorB) {
    auto start = std::chrono::high_resolution_clock::now();
    setLinked suma = zbiorA + zbiorB;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end- start).count();
    file << duration << " ";
}

void mierzenie_wspolnej(setLinked zbiorA, setLinked zbiorB) {
    auto start = std::chrono::high_resolution_clock::now();
    setLinked wspolna = zbiorA & zbiorB;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    file << duration << " ";
}

void mierzenie_roznicy(setLinked zbiorA, setLinked zbiorB) {
    auto start = std::chrono::high_resolution_clock::now();
    setLinked roznica = zbiorA - zbiorB;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    file << duration << "\n";
}

int main() {
    if (!file) {
        std::cerr << "Nie udało się otworzyć pliku do zapisu!" << std::endl;
        return 1;
    }
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int iteration = 1; iteration <= 1000; ++iteration) {
        setLinked set_A, set_B;
        std::uniform_int_distribution<> distr(0, iteration);

        for(int i = 0; i < iteration; i++){
            set_A.insert(distr(gen));
            set_B.insert(distr(gen));
        }

        mierzenie_wstawiania(set_A, iteration);
        mierzenie_usuwania(set_A, iteration);
        mierzenie_sumy(set_A, set_B);
        mierzenie_wspolnej(set_A, set_B);
        mierzenie_roznicy(set_A, set_B);
    }

    file.close();
    std::cout << "Dane zapisane do time.dat" << std::endl;
    return 0;
}