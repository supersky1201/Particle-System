#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "particleClass.h"
#include <vector>
#include <string>
#include "particleManager.h"

using namespace sf;
using namespace std;

Vector2i pos;
RectangleShape shape;
RenderWindow window;
ParticleManager parManager;
Texture tex[3];
Text totalNum;
Font font;

float speed[3] = {100,50,200};
float a[3] = {15,35,75};
float CD = 0.25;
int loop=0;
int type = 1;
//float start, float dt, float lifetime, float final
float start_x =150;
float final_x = -140;


void render_frame()
{
	window.clear();
	parManager.renderSystem(&window);
	totalNum.setString(to_string(parManager.getTotalNum()));

	window.draw(totalNum);
	//cout << parManager.getTotalNum();
	//window.draw(shape);
	
}

void clickPar(float dt)
{
	CD = CD - dt;
	if (CD <= 0)
	{
		if (Mouse::isButtonPressed(sf::Mouse::Left))
		{
			
		
				int i = loop % 3;
				pos = Mouse::getPosition(window);
				parManager.createSys(Vector2f(pos.x, pos.y), &tex[i], speed[i], a[i], -a[i],type,start_x,final_x);
				CD = 0.25;
				loop++;

			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			parManager.sysAddTotal();
			CD = 0.25;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			parManager.sysSubTotal();
			CD = 0.25;
		}
		
	}
}


void update(float dt)
{
	clickPar(dt);
	parManager.updateSys(dt);
}

int main()
{
	for (int i = 0;i < 3;i++)
	{
		tex[i].loadFromFile(to_string(i) + ".png");
	}
	font.loadFromFile("corbel.ttf");
	totalNum.setFont(font);
	totalNum.setCharacterSize(30);
	totalNum.setFillColor(Color::White);
	totalNum.setPosition(30, 20);
	srand((unsigned)time(0));
	shape.setSize(Vector2f(800, 600));
	shape.setPosition(0, 0);
	shape.setFillColor(Color::Black);
	window.create(VideoMode(2400, 1500), "BOOM!");
	Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float dt = clock.restart().asSeconds();
		update(dt);
		render_frame();
		window.display();
	}
	return 0;
}
