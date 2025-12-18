#include <fmt/chrono.h>
#include <fmt/format.h>
#include <iostream>

auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);

    // switch case geht auch mittels liste wenn man bspw. Enum Class States nutzt und dort die States definiert, kann man dies über states::gewünschter Status (case states::status) verwenden.
    // auch über Array möglich
    // mittels Input Array ist der Code überprüfbar (Constant input_size = 3;  bool input(input_size) = {Taste, EndschalterUnten, EndschalterOben};)
    
    int State = 10;
    int prevState = -1;  // ungültiger Startwert, damit Eingabe beim ersten Durchlauf erfolgt
    bool Taste = false;
    bool EndschalterUnten = false;
    bool EndschalterOben = false;

    while (true)
    {
        // Erst Ausgabe, nur wenn aktueller State neu ist
        if (State != prevState) {
            fmt::print("Aktueller State: {}\n", State);

            // Ausgabe des State-Textes passend zum State
            switch (State)
            {
            case 0:
                fmt::print("State ist: Stop auf dem Weg nach oben\n");
                break;
            case 1:
                fmt::print("State ist: Garagentor offen\n");
                break;
            case 2:
                fmt::print("State ist: Fahre runter\n");
                break;
            case 3:
                fmt::print("State ist: Stop auf dem Weg nach unten\n");
                break;
            case 4:
                fmt::print("State ist: Garagentor zu\n");
                break;
            case 10:
                fmt::print("State ist: Fahre Hoch\n");
                break;
            default:
                fmt::print("Unbekannter State, setze auf 10\n");
                State = 10;
                break;
            }

            // Eingabeaufforderung für den neuen State
            int taste_input, unten_input, oben_input;
            fmt::print("Taster drücken? (0/1): ");
            std::cin >> taste_input;
            fmt::print("Endschalter unten aktiv? (0/1): ");
            std::cin >> unten_input;
            fmt::print("Endschalter oben aktiv? (0/1): ");
            std::cin >> oben_input;

            Taste = (taste_input != 0);
            EndschalterUnten = (unten_input != 0);
            EndschalterOben = (oben_input != 0);

            prevState = State;
        }

        // Nun erst werden die Eingaben ausgewertet und der nächste State bestimmt
        int nextState = State;
        switch (State)
        {
        case 0:
            if (Taste) nextState = 2;
            break;
        case 1:
            if (Taste) nextState = 2;
            break;
        case 2:
            if (Taste) nextState = 3;
            else if (EndschalterUnten) nextState = 4;
            break;
        case 3:
            if (Taste) nextState = 10;
            break;
        case 4:
            if (Taste) nextState = 10;
            break;
        case 10:
            if (Taste) nextState = 0;
            else if (EndschalterOben) nextState = 1;
            break;
        default:
            nextState = 10;
            break;
        }

        if (nextState != State)
        {
            State = nextState;
            fmt::print("---- Zyklus beendet ----\n\n");
        }
    }
    // ALTERNATIV mit LUT: siehe main2.cpp

    return 0;
}
