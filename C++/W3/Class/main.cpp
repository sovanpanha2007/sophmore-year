#include <iostream>
#include "utils/Hero.hpp" // this is custom include header file
using namespace std;

//hello
int main(){
    // In the mystical realm of Eldoria, two formidable warriors are about to clash.
    // Richard, the valiant knight, with his trusty sword, and Rascal, the cunning archer.
    Hero richard("Richard", 50, 50, 25, "Sword");
    Hero rascal("Rascal", 40, 15, 10, "Bow and Arrow");

    // The air crackles with anticipation. Let's see their stats before the epic duel.
    cout << "Before battle:\n";
    richard.info();
    rascal.info();

    // The battle begins!
    cout << "\nBattle:\n";
    // Richard, with a mighty swing of his sword, lands the first blow.
    richard.strike(rascal);
    // Rascal, quick and agile, retaliates with a swift arrow.
    rascal.strike(richard);
    // Richard, fueled by determination, strikes again, his sword finding its mark.
    richard.strike(rascal);
    // He presses his advantage, delivering another powerful strike.
    richard.strike(rascal);

    // The dust settles. Let's see the state of our cunning archer.
    cout << "\nAfter attack:\n";
    rascal.info();

    // The tale of this battle will be told for ages to come.
    return 0;
}