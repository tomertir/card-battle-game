# Card Battle Game 

A turn-based card battle game written in C++, built as part of an Advanced programming course at Ben-Gurion University.

## Overview

Players choose a character class and battle against an enemy using a deck of cards. Each round, the player plays a valid set of cards from their hand to attack the enemy, while the enemy fights back. The game ends when either the player or the enemy runs out of health.

## OOP Concepts Demonstrated

- **Inheritance** — `Fighter`, `Sorcerer`, `Ranger` extend `Player`; `Troll`, `Ghost`, `Dragon` extend `Enemy`
- **Polymorphism** — virtual functions for `react_to()` and `attacked_by()`
- **Double Dispatch** — combat logic is resolved based on both the player's class and the enemy's class simultaneously
- **Operator Overloading** — `+=` and `-=` for `Deck`, `[]` for card access
- **Exception Handling** — custom `DeckEmptyException`, `bad_alloc` caught with proper cleanup

## Characters

**Players:**
-  **Fighter** — melee warrior
-  **Sorcerer** — magic caster
-  **Ranger** — ranged attacker

**Enemies:**
- **Troll**
-  **Ghost**
-  **Dragon**

Each player-enemy combination has unique combat logic, resulting in 9 different battle interactions.

## How to Build & Run

**Requirements:** G++ with C++11 or later, Make

```bash
make
./card_battle
```

## Gameplay

1. Initialize the deck by entering cards (format: `RS` where R=rank, S=suit). Enter `00` to stop.
2. Choose your player class (Fighter / Sorcerer / Ranger)
3. Choose your enemy (Troll / Ghost / Dragon)
4. Each turn, play a valid set of cards from your hand
5. The game ends when either side reaches 0 health or the deck runs out

## Project Structure

```
├── main.cpp          # Game loop, input handling, exception management
├── Card.h / .cpp     # Card representation and validation
├── Deck.h / .cpp     # Deck with operator overloading
├── Set.h / .cpp      # Card set validation logic
├── Player.h / .cpp   # Abstract base class for players
├── Fighter.h / .cpp  # Fighter subclass
├── Sorcerer.h / .cpp # Sorcerer subclass
├── Ranger.h / .cpp   # Ranger subclass
├── Enemy.h           # Abstract base class for enemies
├── Troll.h / .cpp    # Troll subclass
├── Ghost.h / .cpp    # Ghost subclass
├── Dragon.h / .cpp   # Dragon subclass
└── Makefile
```

## Technologies

- C++ (C++11)
- Object-Oriented Design (Inheritance, Polymorphism, Double Dispatch)
- STL: `vector`, `string`, `sstream`, `exception`
- Dynamic memory management

## Course

Advanced programming — Ben-Gurion University of the Negev
