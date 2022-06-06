# Gra-w-statki
Prosta, niedopracowana gra w statki, robiona w wolnym czasie

Projekt robiony w c++, służący do nauki i sprawdzenia swoich umiejetnosci.

DO ZMIANY: 
  1. Wywolanie operatora do kazdego statku jest bez sensu. Mozna usunąć i użyć funkcji wielostatek zamiast ich.
  2. Do kontenera ustawienia można dodać vektor plansz.
  3. (Polimorfizm, a w zasadzie jego brak) komputera wielomasztowiec sprawdza czy jest to komputer czy czlowiek, a nie musi przy uzyciu polimorfizmu.
  4. Przeciazenie operatora ++/-- na funkcji z trzymasztowcami po przekatnej (?).
  5. Zmniejszenie ilosci zmiennych przekazywanych do funkcji.

BŁĘDY DO NAPRAWY:
  1. Komputer moze sam siebie zniszczyc, w najgorszym wypadku gra nie dobiegnie do końca.
  2. Jeżeli najpierw podamy WIERSZ a potem KOLUMNE, program oszaleje.
  3. Czasami się nie ładuje gra, winą jest komputer, któremu zajmuje strasznie dlugo wczytanie pól(?)

To wszystkie jakie zauważyłem (06.06.22).

07.06.22:
  -Komputer moze sam siebie zniszczyc, wyeleminowanie niekończącej się gry
  +Komputer moze strzelic dwa razy w to samo miejsce, jezeli na tym polu stoi statek
