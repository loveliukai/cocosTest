
#include "BaseFrame.h"
#include "MyDataSource.h"
#include "MyTableView.h"
bool SceneBase::init()
{
	if (!Layer::init())
		return false;
	Node *background = Node::create();
	m_node = background;
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

void SceneBase::adjustScrollView(float)
{
	int curPos = m_node->getPositionX();
	int minOff = 10 * WinSize.width;
	int i;
	for (i = 0; i < 5; ++i)
	{
		int adjustPos = -i*WinSize.width;
		int offset = abs(curPos - adjustPos);

		// 通过算法查找最接近的调整位置
		if (offset < minOff)
			minOff = offset;
		else
			break;
	}

	int adjustPos = -(i - 1)*WinSize.width;

	CCAction* action = CCMoveTo::create(.1f, ccp(adjustPos, m_node->getPositionY()));
	m_node->stopAllActions();
	m_node->runAction(action);
}



