
Vorteile der verketteten Liste: Sehr flexibler Speicher, wächst und schrumpft, ohne große Re‑Allokationen; Einfügen und Löschen mitten in der Liste ist effizient, wenn man den Vorgänger kennt (nur Zeiger umhängen).​

Nachteile der verketteten Liste: Kein wahlfreier Zugriff, jedes Element braucht einen zusätzlichen Zeiger → mehr Speicher; schlechtere Cache‑Lokalität und dadurch langsamer beim sequentiellen Durchlaufen als ein Array.​

Vorteile des Mini‑Vectors: Sehr schnelles Lesen über Index, da die Elemente im Speicher zusammenhängend liegen; gute Cache‑Nutzung; einfachere Implementierung, und push_back ist im Mittel effizient dank Verdopplung der Kapazität.​

Nachteile des Mini‑Vectors: Selten, aber teuer: Beim Vergrößern müssen alle Elemente kopiert werden; Einfügen/Löschen in der Mitte ist langsam, weil viele Elemente verschoben werden müssen; Kapazität kann temporär mehr Speicher reservieren als tatsächlich benötigt.​

Wann welche Struktur? Liste, wenn viele Einfügungen/Löschungen an beliebigen Positionen und die Reihenfolge wichtig ist, aber seltener zufällig per Index zugegriffen wird. Mini‑Vector, wenn du häufig zufällig per Index liest oder iterierst und nur selten in der Mitte einfügst/löschst, z.B. bei typischen Containern in Algorithmen.​

Sortieren – Mini‑Vector: Klassische Sortieralgorithmen wie Quicksort oder Mergesort arbeiten sehr effizient, weil sie per Index auf das Array zugreifen können und die Daten im Cache liegen; Vergleiche und Swaps sind O(1) und die Gesamtkomplexität liegt typischerweise bei O(nlog⁡n).​

Sortieren – Liste: Zugriff auf das i‑te Element ist O(n), daher sind array‑basierte Sortierverfahren ungeeignet; oft verwendet man Listen‑Mergesort, der mit Zeiger‑Umhängen arbeitet und trotzdem 
O(nlogn) erreicht, aber mit höherem Konstantfaktor und mehr Zeigeroperationen.​

Binären Baum strukturieren: Üblich ist ein struct mit Wert sowie zwei Zeigern, z.B. struct Node { int data; Node* left; Node* right; };, eventuell ergänzt um einen Zeiger auf den Elternknoten oder Meta‑Information wie Höhe/Farbe bei Balancierbäumen.​