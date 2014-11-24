// Programm um aus verschiedenen Dreiecksberechnungen auszuwählen
// und diese dann mit 2 Eingaben zu füttern und das Ergebnis anzuzeigen
//

#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

// Prototyp für Funktion erstellen & Übergabevariablen deklarieren
bool dateneingabeUndPrufung(char, char);
double flaechenBerechnung(double, double);

double seiteBerechnen = 0;
double winkelBerechnen = 0;

int main()
{
	// Abfrage welche Berechnung durchgeführt werden soll
	// 2 Seiten oder 1 Seite + 1 Winkel
	int abfrage1 = 0;
	// WIESO KEIN UTF-8????????
	locale::global(locale("German_germany"));
	cout << "Rechtwinkeliges Dreieck berechnen" << "\n\n-1- für die Berechnung aus Seite und Seite\n-2- für die Berechnung aus Seite und Winkel\n" << endl;
	cin >> abfrage1;

	// Welche Berechnung wurde gewählt
	switch (abfrage1)
	{
		// Wenn 1 (2 Seiten) gewählt wurde
	case 1:
	{
		// Welche Seiten werden definiert?
		char ersteSeite = 0;
		char zweiteSeite = 0;
		cout << "\n          A\n         /|\n        / |\n      c/  |b\n      /   |\n     /    |\n    /_____|\n   B   a   C=90\n" // Dreieck "Zeichnen"
			<< "\nBitte die beiden Seiten angeben die definiert werden:" << endl;
		cin >> ersteSeite;
		cout << "und" << endl;
		cin >> zweiteSeite;

		// Entscheidung treffen für Berechnung
		switch (ersteSeite + zweiteSeite)
		{
		// case a+b = 195
		case 195:
		{
			double seiteA = 0;
			double seiteB = 0;
			cout << "\nSeite a: ";
			cin >> seiteA;
			cout << "Seite b: ";
			cin >> seiteB;

			// Ausgabe Seite c
			double ausgabeSeiteC{ sqrt(seiteA * seiteA + seiteB * seiteB) };
			cout << "\nSeite c: " << ausgabeSeiteC << endl;

			// Ausgabe Winkel Alpha
			double ausgabeWinkelAlpha{ asin(seiteA / ausgabeSeiteC) * 180.0 / PI };
			cout << "Winkel Alpha: " << ausgabeWinkelAlpha << endl;

			// Ausgabe Winkel Beta
			double ausgabeWinkelBeta{ asin(seiteB / ausgabeSeiteC) * 180.0 / PI };
			cout << "Winkel Beta: " << ausgabeWinkelBeta << "\n" << endl;

			// Ausgabe der Fläche
			cout << "Fläche: " << flaechenBerechnung(seiteA, seiteB) << "\n" << endl;

		}
			break;

		// case a+c = 196
		case 196:
		{
			double seiteA = 0;
			double seiteC = 0;
			cout << "\nSeite a: ";
			cin >> seiteA;
			cout << "Seite c: ";
			cin >> seiteC;

			// Ausgabe Seite b
			double ausgabeSeiteB{ sqrt(seiteC * seiteC - seiteA * seiteA) };
			cout << "\nSeite b: " << ausgabeSeiteB << endl;

			// Ausgabe Winkel Alpha
			double ausgabeWinkelAlpha{ asin(seiteA / seiteC) * 180.0 / PI };
			cout << "Winkel Alpha: " << ausgabeWinkelAlpha << endl;

			// Ausgabe Winkel Beta
			double ausgabeWinkelBeta{ asin(ausgabeSeiteB / seiteC) * 180.0 / PI };
			cout << "Winkel Beta: " << ausgabeWinkelBeta << "\n" << endl;

			// Ausgabe der Fläche
			cout << "Fläche: " << flaechenBerechnung(seiteA, ausgabeSeiteB) << "\n" << endl;

		}
			break;

		// case b+c = 197
		case 197:
		{
			double seiteB = 0;
			double seiteC = 0;
			cout << "\nSeite b: ";
			cin >> seiteB;
			cout << "Seite c: ";
			cin >> seiteC;

			// Ausgabe Seite b
			double ausgabeSeiteA{ sqrt(seiteC * seiteC - seiteB * seiteB) };
			cout << "\nSeite a: " << ausgabeSeiteA << endl;

			// Ausgabe Winkel Alpha
			double ausgabeWinkelAlpha{ asin(ausgabeSeiteA / seiteC) * 180.0 / PI };
			cout << "Winkel Alpha: " << ausgabeWinkelAlpha << endl;

			// Ausgabe Winkel Beta
			double ausgabeWinkelBeta{ asin(seiteB / seiteC) * 180.0 / PI };
			cout << "Winkel Beta: " << ausgabeWinkelBeta << "\n" << endl;

			// Ausgabe der Fläche
			cout << "Fläche: " << flaechenBerechnung(ausgabeSeiteA, seiteB) << "\n" << endl;

		}
			break;

		default:
		{
			cout << "\nEingabe nicht erkannt, bitte neu starten\a\n" << endl;
		}
		}
		
	}
		break;

	case 2:
	{
		// Was wird definiert?
		char ersteSeite = 0;
		char winkel = 0;
		cout << "\n          A\n         /|\n        / |\n      c/  |b\n      /   |\n     /    |\n    /_____|\n   B   a   C=90\n" // Dreieck "Zeichnen"
				<< "\nBitte die Seite angeben die definiert wird:" << endl;
		cin >> ersteSeite;
		cout << "\nBitte den Winkel angeben der definiert wird:" << endl;
		cin >> winkel;

		// Eingaben in int switchen
		int iErsteSeite{ ersteSeite };
		int iWinkel{ winkel };

		// Winkel-Entscheidung umrechnen um mit a+B und b+A nicht die gleichen Werte zu bekommen
		iWinkel *= 3;
		
		// Entscheidung treffen was berechnet wird
		switch (iErsteSeite + iWinkel)
		{
		// case a+Alpha = 292
		case 292:
		{
			// Eingabe Funktion starten, prüfen ob false
			if (dateneingabeUndPrufung(ersteSeite, winkel) == false)
			{
				break;
			}
			else
			{
				// Ausgabe Seite b
				double ausgabeSeiteB{ seiteBerechnen / tan(winkelBerechnen * PI / 180) };
				cout << "\nSeite b: " << ausgabeSeiteB << endl;

				// Ausgabe Seite c
				double ausgabeSeiteC{ sqrt(seiteBerechnen * seiteBerechnen + ausgabeSeiteB * ausgabeSeiteB) };
				cout << "Seite c: " << ausgabeSeiteC << endl;

				// Ausgabe Winkel Beta
				double ausgabeWinkelBeta{ 90 - winkelBerechnen };
				cout << "Winkel Beta: " << ausgabeWinkelBeta << "\n" << endl;

				// Ausgabe der Fläche
				cout << "Fläche: " << flaechenBerechnung(seiteBerechnen, ausgabeSeiteB) << "\n" << endl;

			}
		}
			break;

		// case b+Alpha = 293
		case 293:
		{
			// Eingabe Funktion starten, prüfen ob false
			if (dateneingabeUndPrufung(ersteSeite, winkel) == false)
			{
				break;
			}
			else
			{
				// Ausgabe Seite a
				double ausgabeSeiteA{ seiteBerechnen * tan(winkelBerechnen * PI / 180) };
				cout << "\nSeite a: " << ausgabeSeiteA << endl;

				// Ausgabe Seite c
				double ausgabeSeiteC{ sqrt(seiteBerechnen * seiteBerechnen + ausgabeSeiteA * ausgabeSeiteA) };
				cout << "Seite c: " << ausgabeSeiteC << endl;

				// Ausgabe Winkel Beta
				double ausgabeWinkelBeta{ 90 - winkelBerechnen };
				cout << "Winkel Beta: " << ausgabeWinkelBeta << "\n" << endl;

				// Ausgabe der Fläche
				cout << "Fläche: " << flaechenBerechnung(seiteBerechnen, ausgabeSeiteA) << "\n" << endl;

			}
		}
			break;

		// case c+Alpha = 294
		case 294:
		{
			// Eingabe Funktion starten, prüfen ob false
			if (dateneingabeUndPrufung(ersteSeite, winkel) == false)
			{
				break;
			}
			else
			{
				// Ausgabe Seite a
				double ausgabeSeiteA{ seiteBerechnen * cos(winkelBerechnen * PI / 180.0) };
				cout << "\nSeite a: " << ausgabeSeiteA << endl;

				// Ausgabe Seite b
				double ausgabeSeiteB{ seiteBerechnen * sin(winkelBerechnen * PI / 180.0) };
				cout << "Seite b: " << ausgabeSeiteB << endl;

				// Ausgabe Winkel Beta
				double ausgabeWinkelBeta{ 90 - winkelBerechnen };
				cout << "Winkel Beta: " << ausgabeWinkelBeta << "\n" << endl;

				// Ausgabe der Fläche
				cout << "Fläche: " << flaechenBerechnung(ausgabeSeiteA, ausgabeSeiteB) << "\n" << endl;

			}
		}
			break;

		// case a+Beta = 295
		case 295:
		{
			// Eingabe Funktion starten, prüfen ob false
			if (dateneingabeUndPrufung(ersteSeite, winkel) == false)
			{
				break;
			}
			else
			{
				// Ausgabe Seite b
				double ausgabeSeiteB{ seiteBerechnen * tan(winkelBerechnen * PI / 180) };
				cout << "\nSeite b: " << ausgabeSeiteB << endl;

				// Ausgabe Seite c
				double ausgabeSeiteC{ sqrt(seiteBerechnen * seiteBerechnen + ausgabeSeiteB * ausgabeSeiteB) };
				cout << "Seite c: " << ausgabeSeiteC << endl;

				// Ausgabe Winkel Alpha
				double ausgabeWinkelAlpha{ 90 - winkelBerechnen };
				cout << "Winkel Alpha: " << ausgabeWinkelAlpha << "\n" << endl;

				// Ausgabe der Fläche
				cout << "Fläche: " << flaechenBerechnung(seiteBerechnen, ausgabeSeiteB) << "\n" << endl;

			}
		}
			break;

		// case b+Beta = 296
		case 296:
		{
			// Eingabe Funktion starten, prüfen ob false
			if (dateneingabeUndPrufung(ersteSeite, winkel) == false)
			{
				break;
			}
			else
			{
				// Ausgabe Seite a
				double ausgabeSeiteA{ seiteBerechnen / tan(winkelBerechnen * PI / 180) };
				cout << "\nSeite a: " << ausgabeSeiteA << endl;

				// Ausgabe Seite c
				double ausgabeSeiteC{ sqrt(seiteBerechnen * seiteBerechnen + ausgabeSeiteA * ausgabeSeiteA) };
				cout << "Seite c: " << ausgabeSeiteC << endl;

				// Ausgabe Winkel Alpha
				double ausgabeWinkelAlpha{ 90 - winkelBerechnen };
				cout << "Winkel Alpha: " << ausgabeWinkelAlpha << "\n" << endl;

				// Ausgabe der Fläche
				cout << "Fläche: " << flaechenBerechnung(seiteBerechnen, ausgabeSeiteA) << "\n" << endl;

			}
		}
			break;

		// case c+Beta = 297
		case 297:
		{
			// Eingabe Funktion starten, prüfen ob false
			if (dateneingabeUndPrufung(ersteSeite, winkel) == false)
			{
				break;
			}
			else
			{
				// Ausgabe Seite a
				double ausgabeSeiteA{ seiteBerechnen * sin(winkelBerechnen * PI / 180.0) };
				cout << "\nSeite a: " << ausgabeSeiteA << endl;

				// Ausgabe Seite b
				double ausgabeSeiteB{ seiteBerechnen * cos(winkelBerechnen * PI / 180.0) };
				cout << "Seite b: " << ausgabeSeiteB << endl;

				// Ausgabe Winkel Beta
				double ausgabeWinkelAlpha{ 90 - winkelBerechnen };
				cout << "Winkel Alpha: " << ausgabeWinkelAlpha << "\n" << endl;

				// Ausgabe der Fläche
				cout << "Fläche: " << flaechenBerechnung(ausgabeSeiteA, ausgabeSeiteB) << "\n" << endl;

			}
		}
			break;
			
		default:
		{
			cout << "\nEingabe nicht erkannt, bitte neu starten\a\n(Winkel in Großbuchstaben angeben!)\n" << endl;
		}
		}

	}
		break;

	default:
	{
		cout << "\nEingabe nicht erkannt, bitte neu starten\a\n" << endl;
	}
	}
		system("PAUSE");
		return 0;
}


bool dateneingabeUndPrufung(char ersteSeite, char winkel)
{
	cout << "\nSeite " << ersteSeite << ": ";
	cin >> seiteBerechnen;
	cout << "Winkel " << winkel << ": ";
	cin >> winkelBerechnen;

	if (winkelBerechnen >= 90.0 || winkelBerechnen <= 0.0)
	{
		cout << "\nBerechnung nicht möglich! (Winkel falsch)\n\a" << endl;
		return false;
	}
		return true;
}

double flaechenBerechnung(double seiteA, double seiteB)
{
	return seiteA * seiteB / 2;
}