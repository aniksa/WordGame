#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {}

AppDelegate::~AppDelegate() {}

void AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}

static int register_all_packages()
{
    return 0;
}

bool AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) 
	{
        glview = GLViewImpl::create("WordGame");
		glview->setFrameSize(350, 600);
        director->setOpenGLView(glview);
    }
    director->setDisplayStats(false);
    director->setAnimationInterval(1.0 / 60);
    register_all_packages();

    auto scene = HelloWorld::createScene();
    director->runWithScene(scene);

    return true;
}

void AppDelegate::applicationDidEnterBackground() 
{
    Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() 
{
    Director::getInstance()->startAnimation();
}