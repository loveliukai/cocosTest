
#ifndef __MYTABLEVIEW_H_
#define __MYTABLEVIEW_H_

#include "../Common/Utils.h"
class MyTableView : public TableView
{
public:
	//
	Point m_PointStart;
	static MyTableView *table ;
	static MyTableView *create(TableViewDataSource *source, Size size);
	virtual bool onTouchBegan(Touch *pTouch, Event *pEvent);
	virtual void onTouchMoved(Touch *pTouch, Event *pEvent);
	virtual void onTouchEnded(Touch *pTouch, Event *pEvent);
};

#endif