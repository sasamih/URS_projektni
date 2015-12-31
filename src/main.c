/*
	***************************************************************
		Saša Mihajlica 1140/12

	Opis zadatka:
		Zadatak je da se implementira stek kao modul koji je moguce koristiti
		za provjeru regularnosti unijete matematicke formule. Smatra se da je
		matematicka formula regularna ako svaka otvorena zagrada ima odgovarajucu
		zatvorenu zagradu.

	Opis rjesenja:
		Stek je implementiran kao ulancana lista struktura. Strukutura sadrzi
		podatak nekog tipa koji je moguce mijenjati pri kompajliranju i pokazivaca
		na narednu strukuru istog tipa. Za stek su implementirane funkcije za 
		postavljanje elementa na vrh steka i skidanje sa vrha steka (push i pop).
		Jos su implementirane funkcije za citanje sa vrha steka (top), za provjeru
		da li je stek prazan i za ciscenje steka (dump stek). U funkciji main 
		korisnik unosi formulu kao znakovni niz. Niz se smjesta u bafer. Bafer je
		staticki znakovni niz od 255 karaktera. Pretpostavlja se da korisnik nece
		unositi vece nizove od predvidjen. Zatim se prolazi kroz unijeti niz dok
		se ne dodje do terminirajuceg znaka('\0'). Ako se u nizu pronadje otvarajuca
		zagrada ('('), indeks pozicije se postavlja na stek. Kada se naidje na 
		zatvarajucu zagradu (')') skida se prvi element sa steka i formira se par 
		indeksa otvarajuce i zatvarajuce zagrade. Na vrhu steka se uvijek nalazi indeks
		one otvarajuce zagrade koju treba prvu zatvoriti. Ukoliko se desi da je stek 
		prazan, a u nizu se nalazi zatvarajuca zagrada ispisuje se poruka da je izraz
		neregularan. Isto se desava ako se stigne do terminirajuceg znaka u nizu, a 
		stek nije prazan. Dakle, izraz je regularan ako je analiziran citav niz i 
		stek ostane prazan na kraju izvrsavanja programa.

	Napomena:
		Za prevodjenje i pokretanje programa je potrebno iz komandne linije
		pokrenuti makefile naredbom make, a zatim pokrenuti izvrsnu datoteku main.
*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_SIZE 255

int main(int argc, char* argv[])
{
	stack_element* stack = NULL;

	printf("Unesite matematicku formulu: ");
	char formula[MAX_SIZE];
	fgets(formula, MAX_SIZE, stdin);
	printf("Unijeli ste: %s\n",formula);

	uint8_t i = 0;
	for (i = 0; formula[i] != '\0'; i++)
	{
		if ('(' == formula[i])
		{
			push(i, &stack);
		}

		if (')' == formula[i])
		{
			uint8_t open_index;
			if (pop(&open_index, &stack) == 0)
			{
				printf("Par zagrada na indeksima %d i %d\n", open_index, i);
			}
			else
			{
				printf("Unijeta formula nije regularan matematicki izraz!\n");
				return 1;
			}
		}
	}

	if (is_empty(stack))
	{
		printf("Unijeta formula nije regularan matematicki izraz!\n");
		dump_stack(&stack);
		return 1;
	}

	return 0;
}