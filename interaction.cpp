#include "interaction.hpp"

Interaction::Interaction(){
    flashbackCounter = 0;
    text = new TextFormatter();
    parser = new Parser();
    fight1 = true; 
    fight2 = true; 
    fight3 = true;
    fight4 = true;
    fight5 = true;
    fight6 = true;

}

Interaction::~Interaction(){
    delete text;
    delete parser;
}

bool Interaction::fight(Character *&hero, Character *&enemy){
	bool winner = false;
    while(hero->getHealth() > 0 && enemy->getHealth() > 0){
        //hero attack
        std::cout << "Select Attack weapon: " << std::endl;
        std::cout << "1. Sword" << std::endl;
        std::cout << "2. Lumen" << std::endl;
        std::cout << ">> ";
        int attackChoice = 0;
        while(!(std::cin >> attackChoice) || attackChoice <1 || attackChoice > 2)
        {
            std::cout << "1. Sword" << std::endl;
            std::cout << "2. Lumen" << std::endl;
            std::cout << ">>";
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        std::cin.ignore(100, '\n');
        int playerAttack;
        if(attackChoice == 1)
        {
            playerAttack = hero->attack1();
        }
        else
        {
            playerAttack = hero->attack2();
        }
        //enemy defend
        enemy->defend(playerAttack);
        
        //enemy attack
        //Get Random attack
        if(enemy->getHealth() > 0)
        {
            int chance = enemy->attackChance();
            int enemyAttack;
            if(chance == 1)
            {
                enemyAttack =enemy->attack1();

            }
            else
            {	
                enemyAttack =enemy->attack2();
            }
            //hero defend
            hero->defend(enemyAttack);
        }
    }
    //establish winner
    if(enemy->getHealth() <= 0)
    {
        std::cout << std::endl;
        winner = true;
    }
    if(hero->getHealth() <= 0)
    {
        std::cout << std::endl;
        text->print("The " + enemy->getName() + "has struck you down.\n", 1);
        winner = false;
    }
    return winner;

}


//Will only be called from 4 rooms to print flashbacks
//Will only be called if its the first time visiting the room
//Will print appropriate flashback based on counter
//Trigger specific memory in a specific room? ****
void Interaction::printFlashback(Room *&curRoom, Character *&hero){
    if(curRoom->getRoomName() == "FARM" || curRoom->getRoomName() == "RIVER" ||curRoom->getRoomName() == "MOUNTAINS" ||curRoom->getRoomName() == "CAVE"){
        if(!curRoom->getVisited()){
            if(getFlashbackCounter() == 0){
                text->print("\nPain races through your head as the feeling of a memory flutters to the front of your mind.\n", 1);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("You are standing in an open green field..\n"
                "A rushing river winds through the land into the forest..\n"
                "You are covered in sweat and mud from practicing your swordsmanship,\n"
                "blade an extension of your arm moving like water through the air, with the occasional burst of flame shooting out..\n", 1);
                text->print("In the distance is a magnificent castle where the King and The Order Elders reside..\n"
                "Thunderstorms gather in the horizon..\n", 1);
                text->print("Your childhood friend Adelina, rushes to greet you..\n"
                "Her ivory bow slung across her back, the plants around her coming alive to greet her as she passes..\n", 1);
                text->print(text->changeColor(hero->getName() + ", I've been looking for you everywhere.\nThe council has made a decision! Queen Helen will lead the hunt for the Demon ", "YELLOW") + text->changeColor("Aragos", "RED") + text->changeColor(" minions terrorizing the Wastelands!..\n","YELLOW"), 1);
                text->print(text->changeColor("Queen Helen is going herself? This Demon must be powerful if the leader of The Order is leading the hunt..\n", "GREEN"), 1);
                text->print("" + text->changeColor("Aragos", "RED") + text->changeColor(" is a Greater Demon, so he can't exist in this realm without a host.\n"
                "But if we let his minions unchecked, they are sure to find him a host in no time..\n", "YELLOW"), 1);
                text->print("You gaze out towards the wastelands, wondering what facing a demon of that magnitude must be like..\nThunder crackles in the distance, the winds pick up, and rain starts pounding the castle as the storm arrives..\n", 1);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("....\n", 6);
                increaseFlashback();
            }
            else if(getFlashbackCounter() == 1){
                text->print("\nPain races through your head as the feeling of a memory flutters to the front of your mind.\n", 1);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("You are in the " + text->changeColor("dining hall", "R") + " inside the castle.\n"
                "The King, The Order Elders, and select few of The Order are sitting around the table at the center of the room..\n" 
                "Queen Helen's spot is hauntingly empty..\n"
                "Adelina, the ever loyal friend, is seated next to you..\n", 1);
                text->print(text->changeColor("Hey " + hero->getName() + ".. Is it just me, or does King Elias look sick..\n", "YELLOW"), 1);
                text->print("You look over at King Elias and notice he has a ghastly complexion..\n"
                "Pale skin, sunken eyes, and appears to fidget every now and then.\n"
                "He makes eye contact with you, and his eyes seem to flash black for a brief instance..\n", 1);
                text->print(text->changeColor("It's understandable. Queen Helen's death must still be on his mind. It's on everyone's right now, and the Demon wasn't slain either..\n", "GREEN"), 1);
                text->print(text->changeColor(hero->getName() + " hush!! The Elders are speaking..\n", "YELLOW"), 1);
                text->print(text->changeColor("My King Elias..\n"
                "The council has concluded that the Demon ", "CYAN") + text->changeColor("Aragos", "RED") + text->changeColor(" is the one responsible for the death of Queen Helen\n"
                "and is behind the drought and plague that has infested this land..\n"
                "We must send out..\n", "CYAN"), 1);
                text->print(text->changeColor("ENOUGH! I have heard too much talk about demons..\n"
                "The drought has affected the land, which has driven the people to act irrationally..\n", "RED"), 1);
                text->print(text->changeColor("Irrationally?..\n"
                "My king, there has been an increase in rapes, murders, the trees and rivers are dying..\n", "CYAN"), 1);
                text->print(text->changeColor("Am I not the KING?..\n"
                "You are my subjects and you will do as I say!!\n"
                "Now leave this matter of DEMONS alone!..\n", "RED"), 1);
                text->print("The king storms out of the council room..\n"
                "There is a noticeable chill that settles over the room.\n"
                "You clench your fist in frustration and your Lumen flares briefly..\n"
                "Adelina gives you a worried look..\n", 1);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("....\n", 6);
                increaseFlashback();
            }
            else if(getFlashbackCounter() == 2){
                text->print("\nPain races through your head as the feeling of a memory flutters to the front of your mind.\n", 1);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("You are standing under the canopy of The " + text->changeColor("Black Forest", "R") + ".\n"
                "Adelina's favorite " + text->changeColor("tree", "F") + " can be seen a short distance away.\n"
                "Order members are rushing back and forth preparing for whats to come..\n", 1);
                text->print("Adelina has a scared but determined look on her face..\n"
                "Demon sightings have increased around the realm.\n"
                "Murders have gone unanswered for months, and the drought has shown no sign of ending.\n"
                "A council elder approches..\n", 1);
                text->print(text->changeColor("The king has gone mad with grief. We must act now or we will lose the realm to darkness.\n"
                "We are sending our best warriors out to slay the demons in the surrounding areas,\n"
                "and hopefully have a chance to retake the realm..\n", "CYAN"), 1);
                text->print(text->changeColor("GONE MAD you say..\n"
                "My dear Jeremiah, you have no idea what's really going on..\n", "RED"), 1);
                text->print("As quiet as shadows, the king and his soldiers had surrounded The Order..\n"
                "Devilish grins were planted on the soldier's faces.\n"
                "Their eyes a shade of black that should not have been possible..\n"
                "Dread filled the air. The animals and insects had gone quiet..\n", 1);
                text->print(text->changeColor("I had hoped to wait a bit longer, but you have forced my hand. Take them..\n", "RED"), 1);
                text->print("As quick as snakes, the soldiers rushed forward. Outnumbered, The Order Members fell one by one.\n"
                "A soldier approaches and attempts to cleave you in half.\n"
                "You swing your sword and parry a blow, ready to burn through the soldier with your Lumen..\n"
                "But hesitate as you remember they are still citizens of the realm, who you are sworn to protect..\n", 1);
                text->print("But something isn't right..\n"
                "The soldiers looked sick, but have unnaturally fast reflexes..\n"
                "They haven't been acting like themselves for weeks..\n"
                "Something is wrong..\n", 1);
                text->print("You duck underneath an axe, crete some distance from the soldier with your Lumen, and turn as you search for Adelina..\n"
                "You finally locate her knelt by the large " + text->changeColor("tree", "F") + ", when she gets hit in the back of the head and she crumbles to the floor..\n"
                "Blood coats her hair immediately as she is carried by a soldier back into the castle..\n", 1);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("....\n", 6);
                increaseFlashback();
            }
            else if(getFlashbackCounter() == 3){
                text->print("\nPain races through your head as the feeling of a memory flutters to the front of your mind.\n", 1);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("You are sprinting through the castle halls looking for Adelina. You saw her crumble from a blow to the head and get dragged inside the castle..\n", 1);
                text->print("You think to yourself, \"Why would the king do this? Something isn't right..\"\n"
                "Unable to find Adeline you decide to try to rationalize with the king..\n", 1);
                text->print("Screams are coming from every direction..\n"
                "You see the soldiers attacking the residents and Order members in the castle..\n" 
                "The scent of blood fills your nostrils.. Maniacal laughter fills the air..\n", 1);
                text->print("You approach the top of the King's " + text->changeColor("tower", "R") + ", barrel through the door and freeze..\n", 1);
                text->print("The King is standing in the center of the room alongside his general..\n"
                "However, their faces are twisted into a demonic face, with blazing black eyes that lock right on you..\n"
                "The air goes out of your lungs at the realization..\n", 1);
                text->print(text->changeColor("ARAGOS", "RED") + text->changeColor(" has possessed the King..\n", "GREEN"), 1);
                text->print("You are caught off guard, stunned at this revelation,\n"
                "The King's general has no trouble getting to you before you move.\n"
                "He slams his fist into your stomach and across your chin, making you see stars as you fall to your knees..\n", 1);
                text->print(text->changeColor("Well, well, well.. The secret is out..\n"
                "Yes, your King was a fool to make a deal with me after his precious Helen very nearly destroyed my realm..\n", "RED"), 1);
                text->print(text->changeColor("Now I can't have you telling everyone the truth. This is the end for you..\n", "RED"), 1);
                text->print("The King/Demon raises his hand and places it on your forehead..\n"
                "It feels as if the Demon is burning away your mind and soul..\n"
                "With a cry, you are able to shake free of the soldier's grip, and summon your Lumen to form a wall of fire before you..\n", 1);
                text->print("The fire explodes between you and the Demons, but the concussive force sends you flying back,\n"
                "crashing through the window, and you fall into the river waiting below..\n", 1);
                text->print("....\n", 6);
                text->print("....\n", 6);
                text->print("....\n", 6);
                increaseFlashback();
            }
        }
    }
}

std::string Interaction::intro() {
    std::string yourName;
    std::string answer;
    bool correctName = false;
    // Story Prologue
  
    text->print("PROLOGUE\n...\n...\n", 6);
    text->print("Thunderstorms rage outside.. Rain and winds torment the windows.. There is a strong scent of sulfur in the air..\n", 1);
    text->print("The king is on his knees, tears streaming down his face.\n"
    "The King is kneeling inside a bright red pentagram.\nBlack smoke rising from the candles at the five points.\n"
    "An ominous living shadow engulfs the room in darkness, sucking in any warmth or light the fireplace would give..\n", 1);
    text->print(text->changeColor("ARAGOS!! I'm begging you! Save my wife! Save Helen!\n", "BLUE"), 1);
    text->print(text->changeColor("Your kind has hunted demons for centuries and now the KING comes crawling to me on his knees.. PATHETIC..\n", "RED"), 1);
    text->print("The candles flash for a brief second..\n", 1);
    text->print(text->changeColor("I would not have summoned you if it wasn't for a valid cause! YOUR minion poisoned her and we can't stop the spread!..\n", "BLUE"), 1);
    text->print(text->changeColor("The QUEEN infiltrated my domain and sought to KILL ME! Such actions deserve the punishment she received..\n", "RED"), 1);
    text->print(text->changeColor("Forgive her, for she is foolish!! I told her to leave such matters as yourself alone, and to put and end to \n"
    "the folly of a plan that was to destroy you. I will do anything, give you whatever you desire!\n"
    "Please.. Jus.. Just spare her life..\n", "BLUE"), 1);
    text->print(text->changeColor("Anything?.. Very well.. \n", "RED"), 1);
    text->print("Thunder crackles outside. Wind slams against the windows.. Unrelenting rain pounds against the wall..\n", 1);
    text->print(text->changeColor("You will provide me and my children free reign over Nagarny Village to do as we please. Rape.. Pillage.. Feast..\n", "RED"), 1);
    text->print("The shadow had no form.. But the hint of a smile was evident throughout the room..\n", 1);
    text->print(text->changeColor("... Very well. Just please save my wife...\n", "BLUE"), 1);
    text->print(text->changeColor("Excellent..\n"
    "To start off, I will need a cup of your blood..\n", "RED"), 1);
    text->print("The king grabs the blade from his desk and slashes it across his palm without hesitation, and pours his blood into a white gold chalice...\n", 1);
    text->print("The shadow takes the form of a man, and takes the chalice from the king.\n"
    "The DEMON starts chanting in a demonic tongue and a sense of dread settles over the king..\n", 1);
    text->print("The candles start to burn a dark black flame.\n"
    "A feeling of icy coldness settles over the king and dread starts rising to the surface..\n", 1);
    text->print("The king falls to his knees, and clutches at his chest, feeling as if his very soul is being torn from his body..\n", 1);
    text->print(text->changeColor("Whats happening? What are you doing to me!?\n", "BLUE"), 1);
    text->print("The blood in the chalice starts to boil, and a bright light starts to shine from the King's heart.\n"
    "Pain shoots through the King's body as the Demon's shadow is sucked into the King's soul.\n", 1);
    text->print("The King's screams are silenced as the shadow is sucked in completely..\n"
    "The King's eyes flash a solid black..\n", 1);
    text->print(text->changeColor("You were a fool to think I would help after your wife tried to kill me.\n"
    "Now, I will turn your kingdom, into my new realm..\n", "RED"), 1);
    text->print("The Demon/King " + text->changeColor("Aragos", "RED") + " walks away as Queen Helen lays on the bed..\n", 1);
    text->print("The winds continue to howl outside, but the rain was noticeably quiet..\n", 1);
    text->print("...\n...\n...\n", 6);
    

    //Dialogue With Linota 
    text->print("You're laying down in a warm bed. There's a fire crackling nearby. You hear a worried but relieved voice..\n", 1);
    text->print(text->changeColor("Oh you're awake! You gave me quite a scare..\n"
    "I thought you would never wake up!..\n", "YELLOW"), 1);
    text->print(text->changeColor("Wh..Where am I? What happened?..\n", "GREEN"), 1);
    text->print(text->changeColor("I found you half dead at the mouth of the Zemya River.\n", "YELLOW"), 1);
    text->print(text->changeColor("The river?..\n", "GREEN"), 1);
    text->print(text->changeColor("I don't know what kind of trouble you got into, but you're lucky to be alive in the condition I found you..\n", "YELLOW"), 1);
    text->print("Pain lances through your head as you try to recollect your memory..\n", 1);
    text->print(text->changeColor("I.. I can't remember what happened..\n", "GREEN"), 1);
    text->print(text->changeColor("I wouldn't be surprised. You have been unconscious for TWO weeks since I found you.\n"
    "I was starting to think you would never wake..\n", "YELLOW"), 1);
    text->print(text->changeColor("TWO WEEKS!!\n", "GREEN"), 1);
    text->print(text->changeColor("Yes, TWO weeks.. You have been in quite a state. High fever, chills, and constant mutterings about demons..\n"
    "What is your name?\n", "YELLOW"), 1);
    text->print(text->changeColor("I.. I don't know..\n", "GREEN"), 1);
    text->print(text->changeColor("Oh my..\nIm terribly sorry.. My name is Linota..\n", "YELLOW"), 1);
    text->print(text->changeColor("I know you don't recall what happened or who you are, but I need to be able to call you something..\n", "YELLOW"), 1);
   
    
    // Enter and validate your name
    while (!correctName){
        yourName = parser->validateInput(text->changeColor("Well, what would you like to be called?: ", "YELLOW"));
        answer = parser->validateInput(text->changeColor(yourName + "? Is that what you want to be called? (Y/N): ", "YELLOW"), "yesNo");
        answer = text->toUpperCase(answer);
        if (answer == "Y" || answer == "YES"){
            correctName = true;
        } 
    }
    
    text->print(text->changeColor("OK. I will call you " + yourName + "..\n..\n", "YELLOW"), 1);
    text->print("One.. Week.. Later..\n", 6);
    text->print("You stand up and stretch, finally regaining the strength in your limbs..\n"
    "Your energy came back faster than expected..\n"
    "You feel as if you have fire coursing through your veins..\n"
    "However, even with all the physical progress you have done, your memory has not returned.\n", 1);
    text->print(text->changeColor("I'm happy to see you're doing a lot better.\n"
    "I may not have been able to help you with your memory, but maybe somebody out in the realm can..\n"
    "Just be careful. There have been rumors of demons invading the realm and the recent drought has brought out the worst in people..\n", "YELLOW"), 1);
    text->print(text->changeColor("Uhhh.. Demons??\n", "GREEN"), 1);
    text->print(text->changeColor("Just a couple tips for your journey.\n"
    "You will be faced with multiple features, locations, and items you can interact with.\n"
    "Features will show up in ", "YELLOW") + text->changeColor("Magenta", "F") + text->changeColor(".\n"
    "Items will appear in ", "YELLOW") +text->changeColor("Cyan", "I") + text->changeColor(".\n"
    "And rooms you can travel to will be in ", "YELLOW") + text->changeColor("Blue", "R") + text->changeColor(".\n"
    "If you wish to change room, you can enter North, South, East, or West.\n"
    "You may also enter Up, Down, Left, Right.\n"
    "There are a variety of ways to interact with features.\n"
    "You must state the action plus the feature, such as \"Look Bookshelf\"\n"
    "And there are various items you can pick up or take.\n"
    "Such as \"Take Text\"\n"
    "In order to help with your journey, please take this Map and Bag.\n"
    "The bag only has room for 3 items, so please be smart with your space.\n"
    "You can enter \"inventory\" to display what you are carrying.\n"
    "You may also \"Drop\" select items to make room in your bag.\n"
    "If you ever feel weary on your journey, enter \"Save\" to save your progress.\n"
    "If you are nostalgic, enter \"Load\" to load a previous journey.\n"
    "I hope these tips help you on your journey.\n"
    "If you are ever confused on what you can do, please enter \"Help\"\n"
    "Now rest up, and tomorrow you can head out on your adventure.\n..\n", "YELLOW"), 1);
    
        
    return yourName;
}

int Interaction::getFlashbackCounter(){
    return flashbackCounter;
}

void Interaction::increaseFlashback(){
    flashbackCounter++;
}

void Interaction::setFlashbackCounter(int i){
    flashbackCounter = i;
}

bool Interaction::mountainFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[], bool& skip){
    if (curRoom->getRoomName() == "MOUNTAINS" && !curRoom->getRoomChanges(1)){
        text->print("You walk into the Orden mountains and take in the grand vista. As you start to ascend the mountain you notice a man wearing\n"
        "a royal guard outfit. You approach him, hoping he can give you answers. As you face him you see his skin is pale white and his eyes stare at\n"
        "you through cold red pupils. You notice a " + text->changeColor("ring", "I") + " on his finger. Before you can think he jumps and attacks you...\n"
        "You think back to your resurfaced memory of battle, where you attack with your " + text->changeColor("sword", "I") + " or use your " + text->changeColor("Lumen", "GREEN") + " to fend off enemies..\n This is how you can defeat this " + text->changeColor("Possessed Soldier", "RED") + ".. \n"
        "You unsheath your sword, and brace your self for the battle in front of you..\n", 1);
        if (fight(hero, minion)){
            text->print("You block the " + text->changeColor("Possessed Soldier's", "RED") + " attack, and counter with a punch to his nose, breaking it..\n"
            "The " + text->changeColor("Possessed Soldier's", "RED") + " stumbles back and you impale your sword in his chest.\n"
            "The blade slides right out, and the " + text->changeColor("Possessed Soldier's", "RED") + " crumbles to the ground deafeated.\n"
            "After the battle, you look at your " + text->changeColor("sword", "I") + " and realize that it is badly damaged.\n"
			"It cannot be used in another battle in this condition. You stand over your vanquished foe and notice the " + text->changeColor("ring", "I") + " again.\n", 1);
            if (roomArr[6]->getFeature1Interaction(0)){
                text->print("Could this be the old man's " + text->changeColor("ring", "I") + ", you wonder?...\n", 1);
            }
            else {
                text->print("Maybe this " + text->changeColor("ring", "I") + " could come in handy, you wonder?...\n", 1);
            }
            text->print("As you grab the " + text->changeColor("Possessed Soldier's", "RED") + " cursed finger to take the " + text->changeColor("ring", "I") + " off, the minion rustles to life and stabs\n"
            "your hand with a dagger.\n" + text->changeColor("Now you will enjoy the same fate as I, HAHAHAHAHAAHAHAHAH", "RED") + " he cackles. \nYou strike him down again..\n"
            "You rip the " + text->changeColor("ring", "I") + " off his finger, but the pain from your hand shoots across your body, causing you to drop the " + text->changeColor("ring", "I") + ". Your legs\n"
            "start to wobble and your vision fades until you fall to the ground.\n", 1);
            text->print("..........\n", 6);
            text->print(text->changeColor("....Hello...?\n", "YELLOW"), 6);
            text->print(text->changeColor("... You ... awake...?\n", "YELLOW"), 6);
            text->print("You look around and notice you are in a room full of tinctures and potions. You look at your hand and notice it is\n"
            "bandaged. The pain has subsided. A big man with a burly beard is standing over you.\n" + text->changeColor("'You're finally awake. \n"
            "My name's Borin, I'm an alchemist here in Nagorny Village. I was out looking for mixtures when I found you. You're lucky I got to you \n"
            "when I did, otherwise you probably wouldn't be alive. Feel free to rest as long as you like. If you ever want to talk or need anything \n"
            "cleaned or looked at, I specalize in stone alchemy and have all sorts of mixtures.\n", "YELLOW") + "You thank him profusely and gather your \n"
            "bag before heading into the village. Nagorny village is near the top of the Orden mountains. You look down the path to the mountains\n"
            "and wonder how far the alchemist had to carry you... \n", 1);
			hero->bag->remove(itemArr[1]);
			hero->bag->insert(itemArr[15]);
            roomArr[5]->bag->insert(itemArr[0]);
            roomArr[5]->setCanEnter(true);
            curRoom->setRoomChanges(1, true);
            curRoom = curRoom->getRight();
            skip = false;
            return true;
        }
        else {
            text->print("You stagger on the mountain floor as you lie there dying, never knowing your true purpose.\n", 1);
            return false;
        }
    }
    return true;
}

bool Interaction::labFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[], bool& skip){
    if (curRoom->getRoomName() == "LAB" && !curRoom->getRoomChanges(0)){
        text->print("You open the door, and cross the threshold into the other room.\n"
        "You are standing in a brightly lit room, with all kinds of bloody and rusted\n"
        "medical " + text->changeColor("equipment", "F") + " hanging on the walls.\n"
        "All around the room are stone slabs. Your stomach lurches as you see bodies, laying on slabs, that \n"
        "have been torn apart, injected with unknown substances, and had demon apendages sown on to them.\n"
        "One body looks to be further experimented on than others. You can only describe it as looking like a " + text->changeColor("mutant", "F") + ".\n"
        "And standing above him is a man with a hunched back, and blood red eyes.\n"
        "He looks as if he's about to pour some " + text->changeColor("chemicals", "I") + " on the body.\n"
        "His head snaps right to you, and rolls his eyes..\n", 1);
        text->print(text->changeColor("I told these IMBECILES to send the next one, when I told them to!!\n"
        "Don't they know my work is an art and cant be rushed..\n"
        "How can we overtake this realm if my work is sloppy?..", "RED"), 1);
        text->print("Anger bubbles to the surface..\n"
        "You unsheath your sword, and flash some Lumen in your left hand..\n", 1);
        text->print(text->changeColor("Ohhh we got a lively one..\n"
        "Very well..\n", "RED"), 1);
        text->print(""+ text->changeColor("The Scientist", "RED") + " places the vial of "+ text->changeColor("chemicals", "I") + " inside one of his pockets, unfurls his black wings, and launches himself at you..\n", 1);
        if (fight(hero, minion)){
            text->print(""+ text->changeColor("The Scientist", "RED") + " flies over you..\n"
            "You swing your sword and cut off one of his wings.. "+ text->changeColor("The Scientist", "RED") + " crashes to the floor..\n"
            "Before he can recover, you pounce on his chest, punch through his chest cavity, and ignite your Lumen, burning him from the inside..\n"
            ""+ text->changeColor("The Scientist", "RED") + " burns up and as his life force ends, his body turns to ash..\n"
            "The vial of "+ text->changeColor("chemicals", "I") + " falls out and rolls on the floor..\n", 1);
            text->print("You sheath your sword. Exhale some fire from your nostrils,\n"
            "and are content you found justice for countless victims..\n"
            "But one thing sticks with you.. What did the demon mean by overtaking this realm...\n", 1);
            //Drop Chemicals
            roomArr[15]->bag->insert(itemArr[14]);
            curRoom->setRoomChanges(0, true);
            return true;
        }
        else{
            text->print("You fall to your knees, clutching at the fatal wound on your chest..\n"
            "You fall on your side, as your vision slowly goes black, and you can't help but think,\n"
            "that Adelina and the other prisoners will meet the same fate as you...\n", 1);
            return false;
        }
    }
    return true;
}

bool Interaction::terraceFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[], bool& skip){
    if (curRoom->getRoomName() == "TERRACE" && !curRoom->getRoomChanges(0)){
        text->print("You open the door, and walk out to the " + text->changeColor("terrace", "R") + ".\n"
        "You take a couple of steps and freeze..\n"
        "In front of you is a large.. thing.. hovering over a purple and black " + text->changeColor("rift", "F") + ".\n"
        "The demon has large bat wings coming out of its back. Horns curved like a sheep. And arms that reach all the way to the ground while standing..\n"
        "The demon is chanting in a demonic language, and a small monster comes out of the " + text->changeColor("rift", "F") + ", and scurries down the wall..\n "
        "The demon turns around, and his eyes widen in surprise.\n", 1);
        text->print(text->changeColor("We KILLED you!!.\n"
        "There is no way you could have survived My Master's attack and the fall from the " + text->changeColor("throne", "R") + " room..\n"
        "I will make sure his General does not fail him!\n", "RED"), 1);
        text->print("" + text->changeColor("The General", "RED") + " lowers his shoulder and barrels toward you.\n"
        "You unsheath your sword and cover it in your Lumen, ready to fight..\n", 1);
        if (fight(hero, minion)){
            text->print("" + text->changeColor("The General", "RED") + " reaches too far, and you sidestep his punch.\n"
            "You cock back, light your hand with Lumen and place it right on " + text->changeColor("The General's", "RED") + " chest.\n"
            "Your hand burns straight through his chest, until you grab hold of his " + text->changeColor("heart", "I") + " and yank it out...\n"
            "" + text->changeColor("The General", "RED") + " takes a shuddering gasp, and turns into ash before he hits the floor.\n"
            "" + text->changeColor("Heart", "I") + " in your hand, you drop it to the floor..\n"
            "You stand triumphant, and look towards the " + text->changeColor("throne", "R") + " room, ready to do whatever it takes to end the Darkness..\n", 1);
            curRoom->setRoomChanges(0, true);
            //Drop heart into terrace
            roomArr[13]->bag->insert(itemArr[8]);
            return true;
        }
        else{
            text->print("" + text->changeColor("The General", "RED") + " parries your sword swing, causing you to go off balance..\n"
            "He pushes you, turning you around, and shoots a beam of dark energy through your back and coming out of your chest..\n"
            "You fall on your front, your vision slowly goes black, and you can't help but think,\n"
            "the realm is doomed...\n", 1);
            return false;
        }
    }
    return true;
}

bool Interaction::caveFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[]){
    if (curRoom->getRoomName() == "CAVE" && !curRoom->getVisited()){
        text->print("You approach the large troll guarding the cave. It is staring at you with giant angry eyes. \n"
        "You have gained confidence since your last battle on the mountain.\nYou unsheathe your sword. It feels sturdy to the touch.\n"
        "Despite the Blacksmith's drunkeness, he did good work. You charge at the troll and do battle...\n", 1);
        if (fight(hero, minion)){
            text->print("The " + text->changeColor("Cave Troll", "RED") + " barrels toward you as you roll between his legs,\n"
            "nimbly come to your feet, and without looking, jump as high as you can, swing your sword around, decapatating the " + text->changeColor("Cave Troll", "RED") + ".\n"
            "The " + text->changeColor("Cave Troll", "RED") + " falls with a satisfying thump..\n"
            "You sheathe your sword and walk around the giant carcass of the troll, going into the cave.\n", 1);
            return true;
        }
        else {
            text->print("You fall slain onto the cold cave floor, leaving the realm to its cursed fate.\n", 1);
            return false;
        }
    }
    return true;
}

bool Interaction::diningHallFight(Room *&curRoom, Character *&hero, Character *&minion, Room* roomArr[], Item* itemArr[]){
    if (curRoom->getRoomName() == "DINING HALL" && !curRoom->getRoomChanges(0)){
        text->print("You find yourself in a long hallway, creeping behind objects to hide your presense.\n"
		"You hear shouts and growls coming from behind you, so you pick up your pace, and walk into a " + text->changeColor("dining hall", "R") + ".\n"
        "In front of you is a giant demon. His body is covered in a leathery hide. His stomach almost the same size as the rest of him.\n"
        "He carries a giant butcher knife and is cutting up and eating his victims.\n"
        "His head snaps to face you..\n"
        "" + text->changeColor("Human meat always taste better fresh..", "RED") + ".\n"
        "" + text->changeColor("The Butcher", "RED") + " gets to his feet and stumbles towards you.\n"
        "You unsheathe your sword and prepare to face your enemy..\n", 1);
        if (fight(hero, minion)){
            text->print("You duck underneath " + text->changeColor("The Butcher's", "RED") + "cleaver, and slice his achilles tendon.\n"
            "" + text->changeColor("The Butcher", "RED") + " tumbles to his knees. You turn around and hop on his back.\n"
            "You place your palm on the back of the " + text->changeColor("The Butcher's", "RED") + " head, and burn straight down with your Lumen..\n"
            "" + text->changeColor("The Butcher", "RED") + " turns to ash as he dies.\n"
            "You sheathe your sword and take in the room before you.\n", 1);
            curRoom->setRoomChanges(0, true);
            return true;
        }
        else {
            text->print("" + text->changeColor("The Butcher", "RED") + " sweeps your leg, and you tumble backwards\n"
            "hitting your head and seeing stars. The last thing you see is " + text->changeColor("The Butcher's", "RED") + " cleaver crashing down towards your face.\n", 1);
            return false;
        }
    }
    return true;
}

bool Interaction::finalFight(Room *&curRoom, Character *&hero, Character *&demon, Room* roomArr[], Item* itemArr[], bool& victory){
    if (curRoom->getRoomName() == "THRONE"){
        text->print("You open the door at the base of the tower, and step inside.\n"
		"The door slams behind you. Ready to face the end, you make your way up the circular steps.\n"
		"You can hear the blood pounding in your head. Cold seeping into your bones with every step you take.\n"
		"The smell of sulfur increasing, the air escaping your lungs.\n"
		"Before you realize it, you are standing at the entrace of the " + text->changeColor("throne", "R") + " room.\n", 1);
        text->print("You are standing in a wide, circular room. Unlike the rest of the castle,\n"
		"this room is in pristine condition. Fine, plush rugs line the floors. The King's banners\n"
		"decorate the walls. And a royal " + text->changeColor("throne", "F") + " sits at the edge, overseeing the realm.\n"
		"The only blemish is a patched up window, with burn marks on the wall overseeing the river.\n"
		"The hint of a smile creeps onto your face.\n"
		"So still, you almost missed him, " + text->changeColor("Aragos", "RED") + ", in the kings body, stands with his back against you, facing out towards the realm.\n"
		"A cold, terrible laugh fills the room.\n", 1);
        text->print("" + text->changeColor("I never would have thought the child I blasted from this tower would have caused me so much trouble..\n"
        "I am on the verge of making this realm compatible with my own.\n"
        "Then I will be able to unleash my true form here. And I will not have you ruining my return to this realm..\n", "RED") + "", 1);
        text->print("" + text->changeColor("Aragos", "RED") + " spreads open the most beautiful Angel wings..\n"
        "His face transforms from the King into the shadow of a Demon as he charges at you..\n", 1);
        if (fight(hero, demon)){
            text->print("" + text->changeColor("Aragos", "RED") + " is starting to tire. His form starts to flicker..\n"
            "He flies at you and you roll underneath him as you swipe up and slice a wing off, which quickly turns to ash.\n"
            "" + text->changeColor("Aragos", "RED") + " howls in pain, and you don't skip a beat. You bounce straight to your feet\n"
            "and launch yourself on his back. You place your palm on his other wing and burn straight through it, causing him to crash to the floor.\n"
            "Before " + text->changeColor("Aragos", "RED") + " can recover, you bring out the " + text->changeColor("pyxis", "F") + " and activate it.\n"
            "" + text->changeColor("Aragos", "RED") + " looks back and opens his eyes in fear as he realizes what is about to happen.\n"
            "The " + text->changeColor("pyxis", "F") + " lights up and immediately starts sucking in " + text->changeColor("Aragos's", "RED") + " essence into the box.\n"
            "" + text->changeColor("Aragos's", "RED") + " howls are silenced as the " + text->changeColor("pyxis", "F") + " finishes trapping the demon.\n"
            "A crashing sound is heard from the ouside and you rush to the window in time to see the " + text->changeColor("rift", "F") + " collapse on itself.\n"
            "" + text->changeColor("Tha.. Thank you. I will now see my Helen..", "BLUE") + "\n"
            "You turn around at the sound and see the King is lying dead, but with a smile and tear on his face...\n\n", 1);
            curRoom->setRoomChanges(0, true);
			victory = true;
            //Print Epilogue
            epilogue(hero);
            return true;
        }
        else {
            text->print("You take a beam of dark energy straight to the chest, and stumble to your knees, gasping for air.\n"
            "" + text->changeColor("Aragos", "RED") + " comes up to you, and places his hand on your forhead.\n"
            "" + text->changeColor("Let me finish what I started..\n", "RED") + "He says as his palm burns away your mind and soul, leaving the realm to its cursed fate.\n", 1);
            return false;
        }
    }
    return true;
}

bool Interaction::storyElements(Room *&curRoom, Room* roomArr[], Item* itemArr[], Character *&hero, Character *&minion1, Character *&minion2, Character *&minion3,
 Character *&minion4, Character *&minion5, Character *&demon, bool& skip, bool& victory){
    printFlashback(curRoom, hero);
    fight1 = mountainFight(curRoom, hero, minion1, roomArr, itemArr, skip);
    fight2 = caveFight(curRoom, hero, minion3, roomArr, itemArr);
    fight3 = labFight(curRoom, hero, minion2, roomArr, itemArr, skip);
    fight4 = diningHallFight(curRoom, hero, minion4, roomArr, itemArr);
    fight5 = terraceFight(curRoom, hero, minion5, roomArr, itemArr, skip);
    fight6 = finalFight(curRoom, hero, demon, roomArr, itemArr, victory);
    if (!fight1 || !fight2 || !fight3 || !fight4 || !fight5 || !fight6){
        return false;
    }
    else {
        return true;
    }
}

void Interaction::epilogue(Character *&hero){
    text->print("EPILOGUE..\n..\n..\n", 6);
    text->print("Two.. Weeks.. Later..\n"
    "You sit underneath the canopy of the " + text->changeColor("Black Forest", "R") + " leaning against the large " + text->changeColor("tree", "F") + ".\n"
    "It has been hard to get a moment to yourself ever since you trapped the Demon " + text->changeColor("Aragos", "RED") + ".\n"
    "As soon as his essence was trapped, the " + text->changeColor("rift", "F") + " closed.\n"
    "However, the demons " + text->changeColor("Aragos", "RED") + " summoned did not go with it..\n"
    "Since the elders and the rest of The Order were still recovering from their time imprisoned, the task fell to you to hunt them down.\n"
    "The last demon was slain by you as it was trying to escape the " + text->changeColor("caves", "R") + ", and you decided to take a nap before\n"
    "returning to the madness of trying to put The Order and Realm back together.\n"
    "You open your eyes and see Adelina walking toward you. The sealing of " + text->changeColor("Aragos", "RED") + " also opened the magical seal on Adelina's cell.\n"
    "Her wounds are healing and she is looking a bit more lively.\n"
    "" + text->changeColor("The trees told me where you were. \nDid you think you could hide out here without me knowing..", "YELLOW") + "\n"
    "" + text->changeColor("Damn trees, I thought they were my friends now considering I talked to them.\n", "GREEN") + ".\n"
    "Adelina laughs and sits down next to you, and promptly falls asleep.\n"
    "You guess no one is ready to face the reperations that are to come... But taking a quick nap won't hurt..\n"
    "And you fall asleep peacefully for the first time since you woke up in " + text->changeColor("Linota's", "F") + " home.\n", 1);
    text->print("...\n...\n...\n", 6);
    text->print("GAME OVER\n", 6);
}

