#include <cstring>
#include <iostream>
using namespace std;

class Sales {
  public:
    Sales(char *name, char *id, int age);

    friend void operator<<(ostream &os, Sales &s);
    friend Sales &operator>>(istream &is, Sales &s);

  private:
    char name_[10];
    char id_[10];
    int age_;
};

Sales::Sales(char *name, char *id, int age) {
    strcpy(name_, name);
    strcpy(id_, id);
    age_ = age;
}

void operator<<(ostream &os, Sales &s) {
    os << s.name_ << '\t';
    os << s.id_ << '\t';
    os << s.age_ << '\n';
}

Sales &operator>>(istream &is, Sales &s) {
    is >> s.name_ >> s.id_ >> s.age_;
    return s;
}

int main() {
    Sales s1("杜康", "2141981", 40);
    cout << s1;
    cout << endl;
    cin >> s1;
    cout << s1;
    return 0;
}