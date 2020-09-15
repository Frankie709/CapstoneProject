all:
	g++ -g -std=c++11 main.cpp hero.cpp hero.hpp demon.cpp demon.hpp minion.cpp minion.hpp arrayClass.cpp arrayClass.hpp bag.cpp bag.hpp castle.cpp castle.hpp caves.cpp caves.hpp character.cpp character.hpp desert.cpp desert.hpp dungeon.cpp dungeon.hpp item.cpp item.hpp forest.cpp forest.hpp foyer.cpp foyer.hpp game.cpp game.hpp home.cpp home.hpp lab.cpp lab.hpp river.cpp river.hpp bedroom.cpp bedroom.hpp dininghall.cpp dininghall.hpp mountains.cpp mountains.hpp parser.cpp parser.hpp room.cpp room.hpp terrace.cpp terrace.hpp tower.cpp tower.hpp town1.cpp town1.hpp town2.cpp town2.hpp farm.cpp farm.hpp valley.cpp valley.hpp textFormatter.hpp textFormatter.cpp map.hpp map.cpp filesystem.cpp filesystem.hpp interaction.hpp interaction.cpp -o agaros

clean:
	rm agaros
