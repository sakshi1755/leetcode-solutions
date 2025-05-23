# Trie Data Structure Implementation

This project implements a **Trie (Prefix Tree)** to support the following operations:

- `insert(word)` – Inserts a string `"word"` into the Trie.
- `search(word)` – Returns `true` if the exact string `"word"` is present in the Trie, otherwise `false`.
- `startsWith(prefix)` – Returns `true` if there is any word in the Trie that starts with the given prefix `"word"`, otherwise `false`.

---

## Query Format

Three types of queries are used to perform operations on the Trie:

- **Type 1**: Insert a word into the Trie.  
  Format: `1 word`

- **Type 2**: Search for an exact word in the Trie.  
  Format: `2 word`

- **Type 3**: Check if any word in the Trie starts with a given prefix.  
  Format: `3 word`

---

## Input / Output Format

- The first line contains an integer `Q`, the number of queries.
- The next `Q` lines each contain a query in the format described above.

---

## Constraints

- `1 <= Q <= 5 * 10^4`
- `1 <= W <= 10` (where `W` is the length of a word)
- All input strings consist of lowercase English letters `a-z` only.

---

## Sample Input 1

