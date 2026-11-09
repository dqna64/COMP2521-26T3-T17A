/*
Analyse time complexity
O(S) = ???
*/

#include <stdbool.h>

typedef int Key;
typedef int Val;
typedef struct HashTable
{
    Key k;
    Val v;
} HashTable;

HashTable HashTableNew(void);
void HashTableFree(HashTable ht);
void HashTableInsert(HashTable ht, int key, int value);
bool HashTableContains(HashTable ht, int key);
int HashTableGet(HashTable ht, int key);
void HashTableDelete(HashTable ht, int key);
int HashTableSize(HashTable ht);

bool threeSum(int arr[], int size, int sum)
{
    HashTable ht = HashTableNew();

    for (int i = 0; i < size; i++)
    {
        if (HashTableContains(ht, sum - arr[i]))
        {
            HashTableFree(ht);
            return true;
        }

        for (int j = 0; j < i; j++)
        {
            HashTableInsert(ht, arr[i] + arr[j], 0);
        }
    }

    HashTableFree(ht);
    return false;
}
