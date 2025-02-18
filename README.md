# Linked List Implementation in C++

This document explains a simple implementation of a singly linked list data structure. The program provides various operations to manipulate the linked list.

## Table of Contents

- [Basic Structure](#basic-structure)
- [Operations](#operations)
- [Visual Representations](#visual-representations)

## Basic Structure

### Node Structure

```cpp
typedef struct node {
    int data;    // Stores the actual value
    node* link;  // Points to the next node
} node;
```

### Visual Representation of a Node

```
+----------+------+
|  data    | link |
+----------+------+
```

## Operations

### 1. Create (create())

Creates a new linked list by repeatedly adding nodes.

```
Before: NULL
After:  [1]→[2]→[3]→NULL
```

### 2. Insert at Beginning (insertAtBeg())

Adds a new node at the start of the list.

```
Before: [2]→[3]→NULL
After:  [1]→[2]→[3]→NULL
```

### 3. Insert at End (insertAtEnd())

Adds a new node at the end of the list.

```
Before: [1]→[2]→NULL
After:  [1]→[2]→[3]→NULL
```

### 4. Insert at Position (insertAtPos())

Inserts a node at a specific position.

```
Position 2:
Before: [1]→[3]→NULL
After:  [1]→[2]→[3]→NULL
```

### 5. Delete at Position (deleteAtPosition())

Removes a node from a specific position.

```
Delete at position 2:
Before: [1]→[2]→[3]→NULL
After:  [1]→[3]→NULL
```

## Implementation Details

### Key Pointers Used

- `root`: Always points to the first node
- `p`: Used for traversal
- `q`: Used for new node creation

### Memory Management

- Uses dynamic memory allocation with `new` operator
- Each node is allocated separately on the heap

## Common Pitfalls to Avoid

1. Not handling empty list cases
2. Not updating root when deleting first node
3. Not properly maintaining links when inserting/deleting

## Time Complexities

| Operation           | Time Complexity |
| ------------------- | --------------- |
| Insert at Beginning | O(1)            |
| Insert at End       | O(n)            |
| Insert at Position  | O(n)            |
| Delete at Position  | O(n)            |
| Display             | O(n)            |

## Usage Example

```cpp
QList myList;
myList.create();        // Create initial list
myList.insertAtBeg(5);  // Insert 5 at beginning
myList.display();       // Show the list
```

## Visual Flow of Operations

### Insert at Beginning

```
Step 1: Create new node
[New]

Step 2: Point new node to current root
[New]→[Old Root]→[...]→NULL

Step 3: Update root to new node
Root = [New]→[Old Root]→[...]→NULL
```

### Delete at Position

```
Step 1: Traverse to position-1
[1]→[2]→[3]→[4]→NULL
     ↑
     p

Step 2: Update links
[1]→[2]→[4]→NULL
     ↑  ⤴
     p
```

This implementation provides a foundation for understanding linked list operations and can be extended for more complex applications.
