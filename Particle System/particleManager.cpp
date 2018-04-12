#include "particleManager.h"
#include<cmath>

void ParticleManager::createSys(Vector2f pos,Texture* tex, float speed, float a, float b,int i,float start_x,float final_x)
{
	ParticleSystem* particleSys = new ParticleSystem (pos, tex, speed, a,b,i,start_x,final_x);
	managerAry.push_back(particleSys);
	
}

 void ParticleManager::renderSystem(RenderWindow* window)
 {
	 for (int i = 0;i < managerAry.size();i++)
	 {
		 managerAry[i]->renderSys(window);
	 }
 }

 void ParticleManager::updateSys(float dt)
 {
	 int n = 0;
	 for (int i = 0;i < managerAry.size();i++)
	 {
		 managerAry[i]->updatePar(dt);
		 n = n + managerAry[i]->getParNum();
	 }
	 totalnum = n;
 }

 void ParticleManager::sysAddTotal()
 {
	 for (int i = 0;i < managerAry.size();i++)
	 {
		 managerAry[i]->addTotal();
	 }
 }

 int ParticleManager::getTotalNum()
 {
	 return totalnum;
 }
 
 void ParticleManager::sysSubTotal()
 {
	 for (int i = 0;i < managerAry.size();i++)
	 {
		 managerAry[i]->subTotal();
	 }
 }
