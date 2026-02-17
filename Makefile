Deck_game: main.o Card.o Deck.o Set.o Player.o Fighter.o Sorcerer.o Ranger.o Dragon.o Ghost.o Troll.o
	g++ main.o Card.o Deck.o Set.o Player.o Fighter.o Sorcerer.o Ranger.o Dragon.o Ghost.o Troll.o -o Deck_game

main.o: main.cpp Deck.h Card.h Player.h Fighter.h Sorcerer.h Ranger.h Enemy.h Troll.h Ghost.h Dragon.h Set.h
	g++ -c main.cpp

Card.o: Card.cpp Card.h
	g++ -c Card.cpp

Deck.o: Deck.cpp Deck.h Card.h
	g++ -c Deck.cpp

Set.o: Set.cpp Set.h Card.h
	g++ -c Set.cpp

Player.o: Player.cpp Player.h Card.h Enemy.h Set.h
	g++ -c Player.cpp

Fighter.o: Fighter.cpp Fighter.h Player.h
	g++ -c Fighter.cpp

Sorcerer.o: Sorcerer.cpp Sorcerer.h Player.h
	g++ -c Sorcerer.cpp

Ranger.o: Ranger.cpp Ranger.h Player.h
	g++ -c Ranger.cpp

Dragon.o: Dragon.cpp Dragon.h Enemy.h
	g++ -c Dragon.cpp

Ghost.o: Ghost.cpp Ghost.h Enemy.h Fighter.h Player.h Sorcerer.h Ranger.h
	g++ -c Ghost.cpp

Troll.o: Troll.cpp Troll.h Enemy.h
	g++ -c Troll.cpp

clean:
	rm -f *.o Deck_game