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
	//���MyDataSource��MyTableView��Ա����
	MyDataSource *m_dataSource;
	MyTableView  *m_table;

	//����TableViewDelegate�麯��
	virtual void tableCellTouched(TableView* table, TableViewCell *cell);

	//����ScrollView���麯��
	virtual void scrollViewDidScroll(ScrollView *view);

	virtual void scrollViewDidZoom(ScrollView *view);
};

#endif