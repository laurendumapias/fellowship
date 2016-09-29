#include "hashtable.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>
//http://www.algolist.net/Data_structures/Hash_table/Dynamic_resizing

Hashtable::Hashtable(int size){
  tableSize = size;
  used = 0;
  this->table = new Entry*[tableSize];
  for (int i=0; i<tableSize; i++){
    Entry *newEntry = new Entry;
    Student tmp("", 0.0);
    newEntry->perm = -10;
    newEntry->s = tmp;
    table[i] = newEntry;
  }

}


int Hashtable::hash1 (int k){
  return ((k % 492113) % tableSize);
}

int Hashtable::hash2 (int x) {
  return ((x % 392113) % tableSize);
}


bool Hashtable::set(int perm, Student s){
    if (lookupDoubleHash(perm) >=  0){
      return false;
    }
    int key;
    int i =0;
    while (i>=0){
      key = (hash1(perm)+i*hash2(perm))%tableSize;
      if (table[key]->perm < 0){
        table[key]->perm = perm;
        table[key]->s = s;
        used++;
        return true;
      }
      i++;
    }
}



std::string Hashtable::get(int perm){
    int x = lookupDoubleHash(perm);
    if (x < 0){
      return "That value is NULL.";
    }
    else {
      return table[x]->s.getName();
    }
}


int Hashtable::lookupDoubleHash(int perm){
    int key;
    int i=0;
    while(i>=0){
        key = (hash1(perm) +  i*hash2(perm)) % tableSize;
        if (table[key]->perm == perm){
          return key;
        }
        if(table[key]->perm == -10){
          return -1;
        }
        i++;
      }
}

 std::string Hashtable::delete(int perm){
     int x = lookupDoubleHash(perm);
     if (x < 0){
       return "item not present in the table \n";
     }
     else{
       std::string name = table[x]->s.getName();
       Student p("", 0.0);
       table[x]->perm = -100;
       table[x]->s = p;
       return name;
     }
 }


 float load(){
     return used/tableSize;
 }

