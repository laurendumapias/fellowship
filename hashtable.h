#ifndef Hashtable_h
#define Hastable_h
#include <string>

class Hashtable
{
 public:
  Hashtable (int size);
  bool set(int perm, Student s);
  std::string get(int perm);
  std::string delete(int perms);
  float load();

 private:
  struct Entry {
    int perm;
    Student s;
  };
  Entry **table;
  int used;
  int tableSize;
  int hash1 (int k);
  int hash2 (int x);
  int lookupDoubleHash(int perm);
};

#endif

