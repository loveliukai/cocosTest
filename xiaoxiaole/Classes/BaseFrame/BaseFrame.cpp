
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



