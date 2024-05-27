#include <iostream>

float GetPiFloat() { return 3.14; }
double GetPiDouble() { return 3.14; }
int main(void){

// Converting a float to an int will fail
int A{GetPiFloat()};

// Converting a double to an int will fail
int B{GetPiDouble()};

// Converting a double to a float will fail
float C{GetPiDouble()};

// But converting a float to a double is fine
// Any float can be converted to a double
// without data loss
double D{GetPiFloat()};
}


//////////////////////////

// ! OPTIONAL ARGUMENTS :

void TakeDamage( int Damage, bool isMagical = false)
{
  // Magical damage is doubled
  Health -= isMagical ? Damage * 2 : Damage;
}

// ! EXPLICITELY OPTIONAL ARGUMENTS :

int Add(int x = 1, int y = 2, int z = 3){
return x + y + z;
}

int main(){
  // Will return 6
Add({}, {}, {}); 
}

// ! CONTINUE STATEMENT :

#include <iostream>
using namespace std;

int main(){
  int Number{0};
  while (Number < 10) {
    ++Number;
    if (Number == 5) continue; // Kind of skip the code underneath and loop once again
    cout << Number << ", ";
  }
}

// ! CLASSES AND CONSTRUCTORS :

#include <iostream>
using namespace std;

class Monster {
public:
	Monster(string Name, int Health = 150){ // constructors can also have optional parameters
    mName = Name;
    mHealth = Health;
    cout << mName << " Ready for Battle!"
      << "\nHealth: " << mHealth;
  }

private:
  string mName;
  int mHealth;
};

int main(){
  Monster Bonker{"Bonker"};
  cout << '\n';
  Monster Basher{"Basher", 250};
}

