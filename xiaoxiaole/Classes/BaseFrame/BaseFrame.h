#ifndef __BASEFRAME_H_
#define __BASEFRAME_H_

#include "..\Common\Utils.h"
class MyDataSource;
class MyTableView;
class SceneBase : public Layer,public TableViewDelegate
{
public:
	virtual bool init();

	CREATE_FUNC(SceneBase);
	CREATE_SCENE(SceneBase);

	void addScrollViewFrame();

public:
	//添加MyDataSource和MyTableView成员变量
	MyDataSource *m_dataSource;
	MyTableView  *m_table;

	//重载TableViewDelegate虚函数
	virtual void tableCellTouched(TableView* table, TableViewCell *cell);

	//重载ScrollView的虚函数
	virtual void scrollViewDidScroll(ScrollView *view);

	virtual void scrollViewDidZoom(ScrollView *view);
};

#endif