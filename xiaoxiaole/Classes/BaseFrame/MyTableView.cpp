
#include "MyTableView.h"
MyTableView * MyTableView::create(TableViewDataSource *source, Size size)
{
	MyTableView *table = new MyTableView;

	//��ʼ��
	table->initWithViewSize(size, NULL);
	table->autorelease();
	table->setDataSource(source);
	table->_updateCellPositions();
	table->_updateContentSize();


	return table;
}

void MyTableView::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	if (!this->isVisible())
	{
		return;
	}

	if (_touchedCell)
	{
		//�ж�pTouch�Ƿ�����m_pTouchedCell���������ľ���,��������˾���ŵ���
		Vector<Node *> vec = (Vector<Node *>) _touchedCell->getChildren();

		Sprite *sprite = (Sprite *)vec.at(0);
		Rect rcSprite = sprite->boundingBox();
		Point ptInWorld = pTouch->getLocation();
		Point ptInCell = _touchedCell->convertToNodeSpace(ptInWorld);


		if (rcSprite.containsPoint(ptInCell) && _tableViewDelegate != NULL)
		{
			_tableViewDelegate->tableCellUnhighlight(this, _touchedCell);
			_tableViewDelegate->tableCellTouched(this, _touchedCell);
		}
		this->_touchedCell = NULL;
	}
	ScrollView::onTouchEnded(pTouch, pEvent);
}

#if 0
bool MyTableView::onTouchBegan(Touch *pTouch, Event *pEvent)
{
	/*if (!this->isVisible())
	{
	return false;
	}
	if (_touchedCell)
	{
	m_TouchDown = pTouch;
	return true;
	}*/

	return true;
}

void MyTableView::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	ScrollView::onTouchMoved(pTouch, pEvent);
}
#endif

