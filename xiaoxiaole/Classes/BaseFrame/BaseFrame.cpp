
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
	//ˮƽ����
	view->setDirection(ScrollView::Direction::HORIZONTAL);

	//������Դ
	view->reloadData();
	//���Լ���Ϊ����
	view->setDelegate(this);
}

void SceneBase::tableCellTouched(TableView* table, TableViewCell *cell)
{
	//�õ������Ϊ��һ���˵�ѡ��
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

		// ͨ���㷨������ӽ��ĵ���λ��
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



