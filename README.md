<div align="center">

# 🧩 Hashing Collision in C

### A clean and beginner-friendly C program for exploring hash functions and collision handling techniques.

<br>

![C](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Data Structure](https://img.shields.io/badge/Data%20Structure-Hash%20Table-orange?style=for-the-badge)
![Concept](https://img.shields.io/badge/Concept-Hashing%20%26%20Collision-success?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge)

</div>

---

## 📌 Project Overview

This project is a **C-based hash table program** designed to demonstrate how different hashing methods work and how collisions can be handled inside a fixed-size hash table.

The program allows users to choose a hashing technique, select a collision-handling method, insert string keys, and display the final hash table structure. It is a great learning project for understanding how data can be mapped into table indexes and what happens when multiple keys produce the same index.

---

## ✨ Key Features

- Supports multiple hashing methods
- Handles collisions using different strategies
- Stores string-based keys
- Prevents duplicate key insertion in chaining-based lookups
- Displays the full hash table after insertion
- Uses dynamic memory allocation for chained nodes
- Cleans up allocated memory before the program exits

---

## 🧠 Core Concepts

This project covers several important data structure and C programming concepts:

- Hash tables
- Hash functions
- Collision handling
- Linear probing
- Separate chaining
- Rehashing / double hashing
- Linked lists
- Pointers
- Dynamic memory allocation with `malloc()`
- Memory cleanup with `free()`
- Function pointers in C

---

## 🗂️ Hash Table Structure

The program uses a fixed table size of `10`.

```c
#define TABLE_SIZE 10
```

Each hash table index stores a main key and an optional linked list chain for collision handling.

```c
typedef struct Node {
    char key[100];
    struct Node* next;
} Node;

typedef struct HashTable {
    char key[100];
    Node* chain;
} HashTable;
```

---

## 🔢 Supported Hashing Methods

The program provides five hashing techniques that can be selected through the menu.

| No. | Hashing Method | Description |
|---|---|---|
| 1 | Division Method | Converts the key into an integer value, then uses modulo division with the table size. |
| 2 | Mid-Square Method | Squares the converted key value and extracts digits from the middle of the result. |
| 3 | Folding Method | Splits the key into smaller parts, combines them, and maps the result into the table. |
| 4 | Digit Extraction Method | Extracts selected digits from the converted key value to generate an index. |
| 5 | Rotating Hash | Applies bit shifting to rotate the converted key value before mapping it to an index. |

---

## ⚔️ Collision Handling Methods

A collision happens when two or more keys are mapped to the same hash table index. This project includes three collision-handling approaches.

| No. | Collision Method | How It Works |
|---|---|---|
| 1 | Linear Probing | Searches for the next available empty slot in the table. |
| 2 | Chaining | Stores collided keys in a linked list at the same index. |
| 3 | Rehashing | Uses a secondary hash function to calculate a new step size when a collision occurs. |

---

## ⚙️ Main Functions

| Function | Purpose |
|---|---|
| `initializationHT()` | Initializes every hash table index with an empty key and no chain. |
| `StoI()` | Converts a string key into an integer by summing its character values. |
| `DivHash()` | Generates an index using the division method. |
| `MidSquareHash()` | Generates an index using the mid-square method. |
| `FoldingHash()` | Generates an index using the folding method. |
| `DigitExtractionHash()` | Generates an index using digit extraction. |
| `RotatingHash()` | Generates an index using bit rotation. |
| `LinearProbingInsert()` | Inserts a key using linear probing for collision handling. |
| `ChainingInsert()` | Inserts a key using linked-list chaining. |
| `RehashingInsert()` | Inserts a key using a secondary hash function. |
| `displayHT()` | Prints the current hash table contents. |
| `freeMemory()` | Frees all dynamically allocated chain nodes. |

---

## 🖥️ Example Program Flow

When the program runs, the user can choose a hashing method first:

```text
Pilihlah Opsi Metode Hashing:
1. Division
2. Mid-Square
3. Folding
4. Digit Extraction
5. Rotating Hash
6. Keluar
```

After that, the user chooses a collision-handling method:

```text
Pilihlah Opsi Metode Penanganan Collision:
1. Linear Probing
2. Chaining
3. Rehashing
```

Then, the user can insert keys one by one:

```text
Input key (string) atau ketik 'exit' untuk keluar: apple
Input key (string) atau ketik 'exit' untuk keluar: mango
Input key (string) atau ketik 'exit' untuk keluar: exit
```

The program will display the hash table after the insertion session ends.

---

## 📊 Sample Output Format

```text
Hash Table
Index 0:
Index 1: apple
Index 2:
Index 3: mango
Index 4:
Index 5:
Index 6:
Index 7:
Index 8:
Index 9:
```

If chaining is selected and a collision happens, the output may look like this:

```text
Index 4: apple -> mango banana
```

---

## 🚀 How to Run

### 1. Clone the repository

```bash
git clone https://github.com/aphroditemoon/hashing-collision.git
cd hashing-collision
```

### 2. Compile the program

If your source file is named `File.c`, run:

```bash
gcc File.c -o hashing_collision
```

If you rename the file to something cleaner, such as `hashing_collision.c`, run:

```bash
gcc hashing_collision.c -o hashing_collision
```

### 3. Run the program

For Windows:

```bash
hashing_collision
```

For macOS or Linux:

```bash
./hashing_collision
```

---

## 📂 Recommended Repository Structure

```text
hashing-collision/
│
├── File.c
└── README.md
```

For a cleaner project structure, you can rename `File.c` to:

```text
hashing_collision.c
```

Recommended structure:

```text
hashing-collision/
│
├── hashing_collision.c
└── README.md
```

---

## 🎯 Project Goals

The goal of this project is to help students understand how hashing works in a practical way. Instead of only learning the theory, this program shows how keys are inserted into a table, how indexes are generated, and how collisions can be resolved using different techniques.

This project is especially useful for learning:

- Why collisions happen in hash tables
- How different hash functions produce different indexes
- How linear probing searches for empty slots
- How chaining uses linked lists to store collided keys
- How rehashing uses a secondary hash function to reduce clustering

---

## 📝 Notes for Future Improvements

Here are a few ideas that could make this project even better:

- Add a search feature for existing keys
- Add a delete feature for removing keys
- Allow users to reset the hash table without restarting the program
- Improve duplicate checking for linear probing and rehashing
- Add clearer input validation for menu choices
- Support larger table sizes
- Display the selected hash function and collision method in the final output

---

## 👨‍💻 Author

**Erlangga Putra Mahardika**  
Repository: `hashing-collision`

---

<div align="center">

### ⭐ Thanks for checking out this project!

If this project helped you learn hashing and collision handling, consider giving the repository a star.

</div>
