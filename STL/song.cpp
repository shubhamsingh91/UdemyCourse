#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>

using namespace std;

class Song {
private:
  friend std::ostream &operator<<(std::ostream &os, const Song &s);
  std::string name;
  std::string artist;
  int rating;

public:
  Song() = default;
  Song(std::string name, std::string artist, int rating)
      : name{name}, artist{artist}, rating{rating} {}
  std::string get_name() { return name; }
  std::string get_artist() { return artist; }
  int get_rating() { return rating; }

  bool operator<(const Song &rhs) const { return this->name < rhs.name; }
  bool operator==(const Song &rhs) const { return this->name == rhs.name; }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
  os << std::setw(20) << std::left << s.name;
  os << std::setw(30) << std::left << s.artist;
  os << std::setw(2) << std::left << s.rating;
  return os;
}

void display_menu() {

  std::cout << "\nF - Play First Song" << std::endl;
  std::cout << "N - Play Next Song" << std::endl;
  std::cout << "P - Play Previous Song" << std::endl;
  std::cout << "A - Add and play a new Song at current location" << std::endl;
  std::cout << "L - List the current playlist" << std::endl;
}

void display_songs(std::list<Song> &l) {
  for (auto c : l) {
    std::cout << c << std::endl;
  }
}

void display_current(std::list<Song>::iterator it) {
  std::cout << *it << std::endl;
}

int main() {

  std::list<Song> l1;
  std::list<Song>::iterator it_c;
  // Default songs
  l1.emplace_back("God's Plan", "Drake", 5);
  l1.emplace_back("Never Be The Same", "Camila Cabello", 5);
  l1.emplace_back("Pray For Me", "The Weekend and K. Lamar", 4);
  l1.emplace_back("The Middle", "Zedd, Maren Morris", 4);
  l1.emplace_back("Wait", "Maroone 5", 5);
  l1.emplace_back("Whatever It Takes", "Imagine Dragons", 3);
  it_c = l1.begin();
  std::string song_name;
  std::string artist;
  int rating;

  char c1;

  while (c1 != 'q' && c1 != 'Q') {
    cout << "============================================" << endl;
    cout << "Enter a selection (Q to quit): ";
    cin >> c1;
    switch (c1) {
    case 'F':
    case 'f':
      it_c = l1.begin();
      cout << "\nPlaying First Song \nPlaying:" << endl;
      display_current(it_c);
      display_menu();
      break;

    case 'L':
    case 'l':
      display_songs(l1);
      std::cout << "\nCurrent Song:" << std::endl;
      display_current(it_c);
      display_menu();
      break;
    case 'N':
    case 'n':
      if (*it_c == l1.back()) {
        it_c = l1.begin();
      } else if (it_c != l1.end()) {
        it_c++;
      } else {
        cout << "Error!" << endl;
      }
      cout << "\nPlaying Next Song \nPlaying:" << endl;
      display_current(it_c);
      display_menu();
      break;
    case 'P':
    case 'p':
      if (*it_c == l1.front()) {
        it_c = l1.end();
        it_c--;
      } else if (it_c != l1.begin()) {
        it_c--;
      } else {
        cout << "Error!" << endl;
      }
      cout << "\nPlaying Next Song \nPlaying:" << endl;
      display_current(it_c);
      display_menu();
      break;
    case 'a':
    case 'A':
      cout << "Adding and playing a new song" << endl;
      cout << "Enter Song name: " << endl;
      cin >> song_name;
      cout << "Enter Artist: " << endl;
      cin >> artist;
      cout << "Enter Rating (1-5): " << endl;
      cin >> rating;
      l1.insert(it_c, Song(song_name, artist, rating));
      it_c--;
      cout << "Playing" << endl;
      display_current(it_c);
      display_menu();
      break;
    default:
      cout << "Invalid Entry!" << endl;
      display_menu();
      break;
    }
  }
  cout << "\nThank you for Listening! Bye!" << endl;
  return 0;
}