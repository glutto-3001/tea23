// graveyard.cpp
#include <fmt/format.h>
#include "graveyard.h"

// globale Variable (alternativ: kann auch statisch sein)
int gundead = 13;

void awaken() {
    int undead = 666; // lokal
    fmt::println("👁️  Die lokale Variable ruft: {}", undead);
}

void persistent() {
    static int undead = 42; // statisch
    undead++;
    fmt::println("💀 Der statische Geist zählt weiter: {}", undead);
}
