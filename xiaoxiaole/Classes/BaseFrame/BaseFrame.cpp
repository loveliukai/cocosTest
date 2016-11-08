
#include "BaseFrame.h"
#include "MyDataSource.h"
#include "MyTableView.h"
bool SceneBase::init()
{
	if (!Layer::init())
		return false;
	Sprite *background = Sprite::create("../materials/logo@2x.png");
	background->setPosition(WinSize.width / 2, WinSize.height / 2);
	addChild(background);

	addScrollViewFrame();

	return true;
}


void SceneBase::addScrollViewFrame()
{
	m_dataSource = new MyDataSource();
	MyTableView *view = MyTableView::create(m_dataSource, WinSize);

	this->addChild(view);
	//水平滚动
	view->setDirection(ScrollView::Direction::HORIZONTAL);

	//加载资源
	view->reloadData();
	//将自己设为代理
	view->setDelegate(this);
}

void SceneBase::tableCellTouched(TableView* table, TableViewCell *cell)
{
	//得到点击的为哪一个菜单选项
	int index = cell->getIdx();
}

void SceneBase::scrollViewDidScroll(ScrollView *view)
{

}

void SceneBase::scrollViewDidZoom(ScrollView *view)
{

}



