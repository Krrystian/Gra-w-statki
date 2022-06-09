# Gra-w-statki
Prosta, niedopracowana gra w statki, robiona w wolnym czasie

Projekt robiony w c++, służący do nauki i sprawdzenia swoich umiejetnosci.

06.06.22:

DO ZMIANY: 
  1. Wywolanie operatora do kazdego statku jest bez sensu. Mozna usunąć i użyć funkcji wielostatek zamiast ich.
  2. Zmniejszenie ilosci zmiennych przekazywanych do funkcji.
  3. Makefile.

BŁĘDY DO NAPRAWY:
  1. Komputer moze sam siebie zniszczyc, w najgorszym wypadku gra nie dobiegnie do końca.
  2. Jeżeli najpierw podamy WIERSZ a potem KOLUMNE, program oszaleje.
  3. Czasami się nie ładuje gra.

09.06.22

DO ZMIANY: 
  1. --Wywolanie operatora do kazdego statku jest bez sensu. Mozna usunąć i użyć funkcji wielostatek zamiast ich.
  2. Zmniejszenie ilosci zmiennych przekazywanych do funkcji. PROBLEM: Sporo rzeczy do zmiany i brak czasu obecnie na ich zmianę.
  4. --Makefile.

BŁĘDY DO NAPRAWY:
  1. --Komputer moze sam siebie zniszczyc, w najgorszym wypadku gra nie dobiegnie do końca.
  2. Jeżeli najpierw podamy WIERSZ a potem KOLUMNE, program oszaleje.
  3. --Czasami się nie ładuje gra. ROZWIĄZANIE: Ograniczyć ilość możliwych prób na ulokowanie statków i przerwać program w wypadku nie znalezienie ich.
