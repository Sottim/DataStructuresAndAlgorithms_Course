#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <stdbool.h>

#define Table_Size 10

// Linked list node for storing key and the value associated with that key in the hash table
struct Node {
  char* key;
  int value;
  struct Node* next;
};

typedef struct Node *nodeAddress;

// hash table data structure which has the node table to contain the table size.
// Table size is predefined above 
struct HashTable {
  struct Node* table[Table_Size];
};

typedef struct HashTable *hashTableAddress;

// Function to create a new node using the singly linked list data structure.
nodeAddress create_node(char *key, int value) {
  nodeAddress new_Node = malloc(sizeof(struct Node));
  new_Node->key = key;
  new_Node->value = value;
  new_Node->next = NULL;
  return new_Node;
}

//Function to test the primality
bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
//Generates the random number 
int generateRandomNumber(int minimum, int maximum) {
    return minimum + rand() % (maximum - minimum + 1);
}

int generatePrime(int min, int max) {
    int n;
    //Check if the randomly generated number is prime or not, if not again generate till it is prime.
    while (!is_prime(n)){
        n = generateRandomNumber(min, max);
    }
    return n;
}

// Using dot product hash function, we now calculate the hash value from this dotProduct() function.
int dotProduct(char *key) {
  int hash = 0, prime = 53;
  int temp = prime;
  // Key is a string which is input by the user. So keyLength finds the length of that each string that is 
  // passed as a argument in the function.
  int len = strlen(key); // stores the length of the key i.e length of the string
  for (int i = 0; i < len; i++) {
    hash += (int)key[i] * prime; // Using the randomly generated prime number hash for the particular character is calculated.
    prime = prime * temp;
  }
  // calculate the hash value of the key which is a string.
  return hash % Table_Size; 
}

// Inserting a key and the value of that key into the hash table
void insert(hashTableAddress hashTable, char *key, int value) {
  // call the dotProduct fucntion which returns the hashed value of the string.
  int hash = dotProduct(key);
  
  // We create the node first and then insert the hashed value of the code in the table.
  nodeAddress newNode = create_node(key, value);
  
  // after we get the hash value of the key, we insert the value using linked list in the table 
  newNode->next = hashTable->table[hash];
  hashTable->table[hash] = newNode;
}

// This  function searches a key in the hash table and if it finds returns the value otherwise returns -100 
int search(hashTableAddress hashTable, char* key) {
  int hash = dotProduct(key);
  //looking for the entered key's avaibality in the hash table.
  nodeAddress current = hashTable->table[hash];
  while (current != NULL) { 

    if (strcmp(current->key, key) == 0) {
      return current->value;
    }
    //if the string to be looked for doesnot match with the key or sting in the table move to next sting
    current = current->next;
  }
  // if not found till end return the garbage value of -100
  return -100;
}



int main() {
  // Create the hash table to store the values.
  hashTableAddress hashTable = malloc(sizeof(struct HashTable));
  
  int prime = generatePrime(100, 1000);
  // Insert some key-value pairs into the hash table
  // Here enter keys as country and value as the no. of times they have won FIFA World Cup. 
  insert(hashTable, "Brazil", 5);
  insert(hashTable, "Germany", 4);
  insert(hashTable, "Argentina", 3);
  insert(hashTable, "France", 2);
  insert(hashTable, "England", 1);

  // Search for a key in the hash table
  int value = search(hashTable, "Argentina");
  printf("Value for key 'Argentina': %d\n", value);

  return 0;
}