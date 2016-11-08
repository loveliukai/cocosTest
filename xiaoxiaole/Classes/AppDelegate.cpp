#include "AppDelegate.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"
#include "BaseFrame/BaseFrame.h"

#include "AudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) { 
        glview = GLViewImpl::create("test");
        director->setOpenGLView(glview);
    }

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	std::vector<Size> sizeVec;
	sizeVec.push_back(Size(1280, 720));
	sizeVec.push_back(Size(960, 640));
	sizeVec.push_back(Size(960, 540));
	sizeVec.push_back(Size(728, 480));
	sizeVec.push_back(Size(800, 480));
	sizeVec.push_back(Size(854, 480));
	glview->setFrameSize(320, 800);
#endif


	Size frameSize = glview->getFrameSize();

	//这填写的就是一般你作为背景图片的那种图片的大小，适配的原理就是放到和缩小，而以什么为参照，当然就是

	//以最大的那张图片为参照，什么图片最大，当然是背景图片了，以后美工做图的时候用的就是以下的这个尺寸

	Size winSize1 = Size(640, 853);
	//将宽和高做一个比，通过这个比，来具体的调整逻辑分辨率的大小
	float widthRate = frameSize.width / winSize1.width;
	float heightRate = frameSize.height / winSize1.height;
	//如果是if中的语句，说明逻辑的高度有点大了，就把逻辑的高缩小到和宽度一样的比率
	if (widthRate > heightRate)
	{
		//里边传入的前俩个参数就是逻辑分辨率的大小，也就是通过getWinSize()得到的大小
		glview->setDesignResolutionSize(winSize1.width,
			winSize1.height*heightRate / widthRate, kResolutionNoBorder);
	}

	else

	{
		glview->setDesignResolutionSize(winSize1.width*widthRate / heightRate,
			winSize1.height, kResolutionNoBorder);
	}

    //director->getOpenGLView()->setDesignResolutionSize(600, 800, ResolutionPolicy::EXACT_FIT);

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

    // create a scene. it's an autorelease object

	auto scene = SceneBase::sceneCreate();
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
