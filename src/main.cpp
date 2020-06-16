
#include <iostream>
#include "Entity.h"
#include "SimpleSprite.h"
#include "Entities/Player.h"
#include "Entities/Enemy.h"
#include <vector>
#include "SFML/Audio.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1000,1000),"SpaceRace");
    Player player;
    sf::Clock vl;
    float elapsed = vl.restart().asSeconds();
    sf::Font fnt;
    sf::Clock survivalTimer;
    window.setMouseCursorVisible(false);
    fnt.loadFromFile("data/Fonts/JetBrainsMono-Bold.ttf");
    sf::Text txt,win,trail;
    txt.setString("Your Score:");
    txt.setFillColor({255, 116, 36});
    txt.setCharacterSize(window.getSize().y*0.04f);
    txt.setFont(fnt);
    trail.setString("Trail:");
    trail.setFillColor({255, 116, 36});
    trail.setCharacterSize(window.getSize().y*0.04f);
    trail.setFont(fnt);
    trail.setPosition(0.f,window.getSize().y*0.05f);

    window.setFramerateLimit(30);
    player.mover->active = false;
    player.effect->gravity_direction={0.f,5.f};
    sf::SoundBuffer sbuffer;
    sf::Sound win_sound;
    sbuffer.loadFromFile("data/handleCoins.ogg");
    win_sound.setBuffer(sbuffer);

    std::array<Enemy,5> enemypool;
    for(auto& e:enemypool)
    {
        e.transform->setPosition(rand()%window.getSize().x,0.f);
        e.mover->speed = 200.f+rand()%70;
    }

    bool lost = false;
    int score = 0;
    bool begin=true;
    float lastime;
    while(window.isOpen())
    {
        if(begin)
        {
            window.clear();
            win.setFont(fnt);
            win.setCharacterSize(window.getSize().y*0.05f);
            win.setString("You need to dodge the Asteroids\nuse the mouse to move\n PressEnter to begin\nYou can always leave with Escape\n150+ Score is crazy good!");
            win.setFillColor(sf::Color::Red);
            window.draw(win);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                begin=false;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            survivalTimer.restart();
            window.display();
        }

        if(!lost&&!begin)
        {
            elapsed = vl.restart().asSeconds();
            window.clear();
            txt.setString("Your Score: "+ std::to_string(score)+" Time: "+std::to_string(survivalTimer.getElapsedTime().asSeconds()));
            window.draw(txt);
            window.draw(trail);
            player.transform->setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
            player.draw(window);
            player.update(elapsed);
            player.lateUpdate(elapsed);
            for(auto& enemy:enemypool)
            {
                enemy.draw(window);
                enemy.update(elapsed);
                enemy.lateUpdate(elapsed);
                if(player.hitbox->AABBCollisionTest(enemy.hitbox))
                    lost = true;

                if(enemy.transform->getY()>window.getSize().y)
                {
                    //win_sound.play();
                    enemy.transform->setPosition(rand()%window.getSize().x,0.f);
                    if(score<60)
                        enemy.mover->speed+=score+rand()%3;
                    else
                        enemy.mover->speed++;
                    score++;
                }

            }
            if(score<10)
            {
                player.afterburner->active = false;
                player.effect2->active = false;
                trail.setString("Trail: Basic");
                trail.setFillColor({217, 210, 130});
                player.effect->begin_color= {217, 210, 130};
                player.effect->end_color= {217, 183, 28};
            }
            if(score>10 && score<50)
            {

                trail.setString("Trail: Booster");
                trail.setFillColor(sf::Color::Green);
                player.effect->begin_color=sf::Color::Green;
                player.effect->end_color= {49, 135, 68};
            }
            if(score>50&&score<=75)
            {
                player.effect2->active = true;
                trail.setString("Trail: Extreme");
                trail.setFillColor({177, 20, 255});
                player.effect->begin_color= {177, 20, 255};
                player.effect->end_color= {255, 20, 91};
            }
            if(score>75&&score<100)
            {
                trail.setString("Trail: Diamond");
                trail.setFillColor({28, 204, 217});
                player.effect->begin_color= {28, 204, 217};
                player.effect->end_color= {245, 168, 0};
            }

            if(score>=100)
            {
                player.afterburner->active = true;
                trail.setString("Trail: LIGHTSPEED");
                trail.setFillColor({245, 8, 0});
                player.effect->begin_color= {245, 8, 0};
                player.effect->end_color= {245, 8, 0};
            }


            sf::Event e;
            while(window.pollEvent(e))
            {
                if(e.type == sf::Event::Closed)
                    window.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            window.display();
            lastime = survivalTimer.getElapsedTime().asSeconds();
        }
        if(lost&&!begin)
        {

            window.clear();
            win.setFont(fnt);
            win.setCharacterSize(window.getSize().y*0.05f);
            win.setString("YOUR SCORE:"+std::to_string(score)+"\n Your Time:"+std::to_string(lastime)+"\nPress Enter");
            win.setFillColor(sf::Color::Red);
            window.draw(win);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                survivalTimer.restart();
                player.transform->setY(window.getSize().y);
                score=0;
                lost = false;
                for(auto& e:enemypool)
                {
                    e.transform->setY(0.f);
                    e.transform->setX(rand()%window.getSize().x);
                    e.mover->speed=200.f+rand()%70;
                }

            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
            window.display();
        }
    }
}