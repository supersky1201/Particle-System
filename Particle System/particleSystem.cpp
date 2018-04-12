#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include "ParticleSystem.h"
#include <vector>

using namespace sf;
using namespace std;

 ParticleSystem::ParticleSystem(Vector2f pos, Texture* tex, float speed, float a, float b,int i, float start_x, float final_x)
{
	 total = 5;
	 systemPos = pos;
	 systemTex = tex;
	 systemSpeed = speed;
	 systemA = a;
	 systemB = b;
	 type = i;
	 startX = start_x;
	 finalX = final_x;
	 parNum = 0;
}



 void ParticleSystem::renderSys(RenderWindow* window)
 {
	 int n = 0;
	 for (int i = 0;i < particleAry.size();i++)
	 {
		 particleAry[i]->renderPar(window);
		 n = n + 1;
	 }
	 parNum = n;
 }

 int ParticleSystem::getParNum()
 {
	 return parNum;
 }

 void ParticleSystem::updatePar(float dt)
 {

	 for (int i = 0;i < particleAry.size();i++)
	 {
		 particleAry[i]->update(dt);
	 }
	 if (particleAry.size() < total)
	 {
		 ParticleClass* particle = new ParticleClass(systemPos, systemTex, systemSpeed,systemA, systemB,type,startX,finalX);
		 particleAry.push_back(particle);
	 }
	 numControl(dt);
 }

 void ParticleSystem::numControl(float dt)
 {
	
	 for (int i = particleAry.size() - 1; i >= 0;i--)
	 {
		 if (particleAry[i]->isDead() == true)
		 {
			 delete particleAry[i];
			 particleAry.erase(particleAry.begin() + i);
		 }
	 }
 }

 void ParticleSystem::addTotal()
 {
	 total = total + 1000;
 }

 void ParticleSystem::subTotal()
 {
	 if (total > 10)
	 {
		 total = total - 500;
	 }
 }


