# setLinked - Implementacja zbioru przy użyciu sortowanej listy jednokierunkowej

## Opis

To repozytorium zawiera implementacje typów zbioru `setLinked` w C++, a także analizę czasów operacji na tych zbiorach. Programy mierzą czas operacji takich jak wstawianie, usuwanie, suma, różnica i część wspólna dwóch zbiorów, a następnie zapisują te dane do pliku. Dodatkowo, w repozytorium znajduje się skrypt w Pythonie, który generuje wykresy z tych danych, umożliwiając analizę złożoności obliczeniowej.


## Funkcjonalności

### 1. Dodawanie elementu (`insert`)
- Wstawia nowy element do zbioru w odpowiedniej pozycji, zachowując porządek rosnący.
- Duplikaty nie są dozwolone – elementy o tej samej wartości są ignorowane.

### 2. Usuwanie elementu (`remove`)
- Usuwa określony element z listy. Jeśli element nie istnieje w zbiorze, operacja nie zmienia zbioru.

### 3. Sprawdzanie zawartości (`contains`)
- Sprawdza, czy dany element znajduje się w zbiorze.

### 4. Operacje na zbiorach:
   - **Suma (`+`)**: Tworzy nowy zbiór będący sumą dwóch zbiorów.
   - **Różnica (`-`)**: Tworzy nowy zbiór będący różnicą dwóch zbiorów (elementy w pierwszym zbiorze, ale nie w drugim).
   - **Część wspólna (`&`)**: Tworzy nowy zbiór będący częścią wspólną dwóch zbiorów.

## Przykład użycia

```cpp
#include "setLinked.h"
#include <iostream>

int main() {
    setLinked zbiorA, zbiorB;

    // Dodawanie elementów do zbioru A
    zbiorA.insert(1);
    zbiorA.insert(3);
    zbiorA.insert(5);

    // Dodawanie elementów do zbioru B
    zbiorB.insert(3);
    zbiorB.insert(4);
    zbiorB.insert(5);

    // Wypisanie zbiorów
    std::cout << "Zbiór A: ";
    zbiorA.print();
    
    std::cout << "Zbiór B: ";
    zbiorB.print();

    // Operacja suma
    setLinked suma = zbiorA + zbiorB;
    std::cout << "Suma A + B: ";
    suma.print();

    // Operacja różnica
    setLinked roznica = zbiorA - zbiorB;
    std::cout << "Różnica A - B: ";
    roznica.print();

    // Operacja część wspólna
    setLinked czescWspolna = zbiorA & zbiorB;
    std::cout << "Część wspólna A & B: ";
    czescWspolna.print();

    return 0;
}
