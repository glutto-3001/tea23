#include <iostream>
#include <fmt/format.h>

enum Zustand {
    Garagentor_zu,
    Fahre_hoch,
    Stop_auf_dem_Weg_nach_oben,
    Garagentor_offen,
    Fahre_runter,
    Stop_auf_dem_Weg_nach_unten,
    Zustandsanzahl  // Hilfswert, für die Tabellenlänge
};

enum Ereignis {
    Taste,
    Endschalter_oben,
    Endschalter_unten,
    Ereignisanzahl
};

// Look-Up-Tabelle: nächste Zustände
Zustand overgangsTabelle[Zustandsanzahl][Ereignisanzahl] = {
    // Garagentor_zu   // Fahre_hoch   // Stop_auf_dem_Weg_nach_oben   // Garagentor_offen   // Fahre_runter   // Stop_auf_dem_Weg_nach_unten
    // Taste,          Endschalter_oben,         Endschalter_unten
    {Fahre_hoch, Garagentor_zu, Garagentor_zu},                        // Garagentor_zu
    {Stop_auf_dem_Weg_nach_oben, Garagentor_offen, Fahre_hoch},        // Fahre_hoch
    {Fahre_runter, Stop_auf_dem_Weg_nach_oben, Stop_auf_dem_Weg_nach_oben}, // Stop_auf_dem_Weg_nach_oben
    {Fahre_runter, Garagentor_offen, Garagentor_offen},                // Garagentor_offen
    {Stop_auf_dem_Weg_nach_unten, Fahre_runter, Garagentor_zu},        // Fahre_runter
    {Fahre_hoch, Stop_auf_dem_Weg_nach_unten, Stop_auf_dem_Weg_nach_unten} // Stop_auf_dem_Weg_nach_unten
};

Zustand zustand = Garagentor_zu;

void printZustand() {
    switch (zustand) {
        case Garagentor_zu: fmt::println("Garagentor zu"); break;
        case Fahre_hoch: fmt::println("Fahre hoch"); break;
        case Stop_auf_dem_Weg_nach_oben: fmt::println("Stop auf dem Weg nach Oben"); break;
        case Garagentor_offen: fmt::println("Garagentor offen"); break;
        case Fahre_runter: fmt::println("Fahre runter"); break;
        case Stop_auf_dem_Weg_nach_unten: fmt::println("Stop auf dem Weg nach unten"); break;
    }
}

// Einfache Ereignisverarbeitung via Tabelle
void eingabe(Ereignis ev) {
    zustand = overgangsTabelle[zustand][ev];
}

int main() {
    Ereignis ablauf[] = {
        Taste, Taste, Taste,
        Taste, Taste,
        Endschalter_oben,
        Taste, Endschalter_unten
    };

    int n = sizeof(ablauf) / sizeof(ablauf[0]);
    printZustand();
    for (int i = 0; i < n; ++i) {
        eingabe(ablauf[i]);
        printZustand();
    }
    return 0;
}