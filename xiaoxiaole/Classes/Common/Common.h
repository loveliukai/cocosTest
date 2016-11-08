#ifndef __COMMON_H_
#define __COMMON_H_

#include "Earse.h"
#define CREATE_SCENE(__Type) \
	static Scene *sceneCreate()\
	{ \
	Scene *scene = Scene::create(); \
	__Type *layer = __Type::create(); \
	scene->addChild(layer); \
	return scene; \
	}\

#define WinSize Director::getInstance()->getWinSize()
	

#endif