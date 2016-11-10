
#include "MyTableView.h"
#include "BaseFrame/BaseFrame.h"
#include "MyDataSource.h"
MyTableView *MyTableView::table = nullptr;
MyTableView * MyTableView::create(TableViewDataSource *source, Size size)
{
	table = new MyTableView;
	//初始化
	table->initWithViewSize(size, NULL);
	table->autorelease();
	table->setDataSource(source);
	table->_updateCellPositions();
	table->_updateContentSize();

	
	return table;
}

void MyTableView::onTouchEnded(Touch *pTouch, Event *pEvent)
{
	//判断pTouch是否点击了m_pTouchedCell这个格子里的精灵,如果点中了精灵才调用
	Vector<Node *> vec = (Vector<Node *>) _touchedCell->getChildren();
	Sprite *sprite = (Sprite *)vec.at(0);
	Rect rcSprite = sprite->boundingBox();
	Point ptEnd = pTouch->getLocation();
	Point spInWorld = _touchedCell->convertToWorldSpace(sprite->getPosition());
	if (!this->isVisible())
	{
		return;
	}

	if (_touchedCell)
	{
		int index = _touchedCell->getIdx();
		if (index == 0)
		{
			if (ptEnd.x>m_PointStart.x)
			{
				setTouchEnabled(false);
			}
		}
		else if (index == 2)
		{
			if (ptEnd.x < m_PointStart.x)
			{
				setTouchEnabled(false);
			}
		}
					
		if (/*rcSprite.containsPoint(ptInCell) &&*/ _tableViewDelegate != NULL)
		{
			_tableViewDelegate->tableCellUnhighlight(this, _touchedCell);
			_tableViewDelegate->tableCellTouched(this, _touchedCell);
			
		}
	
		
	}
	ScrollView::onTouchEnded(pTouch, pEvent);
	if (spInWorld.x > 0 && spInWorld.x < WinSize.width)
	{
		//Point pt = _touchedCell->convertToWorldSpace(sprite->getPosition());
		Point pt = _touchedCell->getPosition();
		CCLOG("X1:%f    Y1:%f", pt.x, pt.y);
		
		_touchedCell->setPosition(Vec2(0, 0));
		sprite->runAction(MoveTo::create(.1f, Vec2(WinSize.width / 2, WinSize.height / 2)));
		 //pt = _touchedCell->convertToWorldSpace(sprite->getPosition());
		pt = _touchedCell->getPosition();
		CCLOG("X2:%f    Y2:%f", pt.x, pt.y);
	}
	this->_touchedCell = NULL;
	setTouchEnabled(true);
}

#if 1
bool MyTableView::onTouchBegan(Touch *pTouch, Event *pEvent)
{
		
		m_PointStart = pTouch->getLocation();//得到节点坐标系
		return TableView::onTouchBegan(pTouch, pEvent);
}

void MyTableView::onTouchMoved(Touch *pTouch, Event *pEvent)
{
	Point point = pTouch->getLocation();

	if (_touchedCell /*&& isTouchMoved()*/)
	{
		Vector<Node *> vec = (Vector<Node *>) _touchedCell->getChildren();
		Sprite *sprite = (Sprite *)vec.at(0);
		Point pt = _touchedCell->convertToWorldSpace(sprite->getPosition());
		Point ptStart = _touchedCell->convertToNodeSpace(m_PointStart);
		Point ptMove = _touchedCell->convertToNodeSpace(point);

		int index = _touchedCell->getIdx();
		if (index == 0)
		{
			if (point.x - m_PointStart.x > 0 && pt.x >= WinSize.width / 2)
			{
				setTouchEnabled(false);
			}
			/*else
			{
			ScrollView::onTouchMoved(pTouch, pEvent);

			CCLOG("X:%f    Y:%f\n", pt.x, pt.y);
			}*/

		}

		else if (index == 2)
		{
			if (point.x - m_PointStart.x < 0 && pt.x <= WinSize.width / 2)
			{
				setTouchEnabled(false);
			}
			/*else
			{
				ScrollView::onTouchMoved(pTouch, pEvent);

			}*/
		}
			ScrollView::onTouchMoved(pTouch, pEvent);
	
		if (_tableViewDelegate != nullptr)
		{
			_tableViewDelegate->tableCellUnhighlight(this, _touchedCell);
		}
		setTouchEnabled(true);

		//_touchedCell = nullptr;
	}


	
	
}
#endif

