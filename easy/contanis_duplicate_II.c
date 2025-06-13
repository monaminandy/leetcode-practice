#include <stdio.h>
#include <stdlib.h> // For malloc, free, abs
#include <stdbool.h> // For bool type

// --- Hash Table Structures and Functions ---

// Node for linked list in each hash table bucket (for separate chaining)
typedef struct HashNode {
    int key;         // The number from nums (e.g., nums[i])
    int value;       // The index of that number (e.g., i)
    struct HashNode* next; // Pointer to the next node in the chain
} HashNode;

// Hash Table structure
typedef struct {
    HashNode** buckets; // Array of pointers to HashNodes (the buckets)
    int size;           // Number of buckets in the hash table
} HashTable;

// Simple hash function for positive integers
// Returns an index within the hash table's size
unsigned int hash(int key, int tableSize) {
    // Since nums[i] >= 1, key is always positive.
    // If keys could be negative, use: `(unsigned int)((long long)key % tableSize + tableSize) % tableSize;`
    return (unsigned int)key % tableSize;
}

// Creates and initializes a new hash table
HashTable* createHashTable(int tableSize) {
    HashTable* ht = (HashTable*)malloc(sizeof(HashTable));
    if (ht == NULL) {
        return NULL; // Memory allocation failed
    }
    ht->size = tableSize;
    // calloc initializes memory to zero, which is important for pointers (sets them to NULL)
    ht->buckets = (HashNode**)calloc(tableSize, sizeof(HashNode*));
    if (ht->buckets == NULL) {
        free(ht); // Free the HashTable struct if buckets allocation fails
        return NULL; // Memory allocation failed
    }
    return ht;
}

// Inserts or updates a key-value pair in the hash table
// If key exists, its value (index) is updated to the new value.
void hashTablePut(HashTable* ht, int key, int value) {
    unsigned int index = hash(key, ht->size);
    HashNode* current = ht->buckets[index];
    
    // Traverse the list in the bucket to check if the key already exists
    while (current != NULL) {
        if (current->key == key) {
            current->value = value; // Key found, update its index
            return;
        }
        current = current->next;
    }
    
    // Key not found, create a new node and add it to the beginning of the chain
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    if (newNode == NULL) {
        // Handle allocation failure (in competitive programming, often assumed to succeed)
        return;
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = ht->buckets[index]; // New node points to the old head of the chain
    ht->buckets[index] = newNode;        // New node becomes the new head
}

// Retrieves the value (index) associated with a key from the hash table
// Returns -1 if the key is not found
int hashTableGet(HashTable* ht, int key) {
    unsigned int index = hash(key, ht->size);
    HashNode* current = ht->buckets[index];
    
    // Traverse the list in the bucket to find the key
    while (current != NULL) {
        if (current->key == key) {
            return current->value; // Key found, return its value (index)
        }
        current = current->next;
    }
    return -1; // Key not found
}

// Frees all memory allocated for the hash table
void freeHashTable(HashTable* ht) {
    if (ht == NULL) return; // Nothing to free
    
    for (int i = 0; i < ht->size; i++) {
        HashNode* current = ht->buckets[i];
        while (current != NULL) {
            HashNode* temp = current; // Save current node
            current = current->next;  // Move to the next node
            free(temp);               // Free the saved node
        }
    }
    free(ht->buckets); // Free the array of bucket pointers
    free(ht);          // Free the HashTable struct itself
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    
    int hashTableSize = 100003; 
    
    HashTable* ht = createHashTable(hashTableSize);
    if (ht == NULL) {
       
        return false; 
    }

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        int prev_index = hashTableGet(ht, num); 
        if (prev_index != -1) {
           
            if (abs(i - prev_index) <= k) {
                freeHashTable(ht); // Found a valid pair, so free memory and return true
                return true;
            }
        }
        
        hashTablePut(ht, num, i);
    }


    freeHashTable(ht); // Free memory before returning
    return false;
}
