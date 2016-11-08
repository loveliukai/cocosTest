
#include "MyDataSource.h"
MyDataSource::MyDataSource()
{
	for (int i = 0; i < 3; i++)
	{
		TableViewCell *cell = new TableViewCell;
		cell->autorelease();
		m_cells.push_back(cell);
		//创建精灵显示内容
		std::string tmp = Utils::GetFormatString("%d", i + 1);
		std::string str = "cg/xxl_ftbg" + tmp + ".png";
		Sprite *sprite = Sprite::create(str);

		cell->addChild(sprite);

		//设置位置
		sprite->setPosition(Vec2(WinSize.width / 2, WinSize.height / 2));
	
	}
}

MyDataSource::~MyDataSource()
{
	m_cells.clear();
}

Size MyDataSource::cellSizeForTable(TableView *table)
{
	return WinSize;
}

ssize_t MyDataSource::numberOfCellsInTableView(TableView *table)
{
	return m_cells.size();
}

TableViewCell * MyDataSource::tableCellAtIndex(TableView *table, ssize_t idx)
{
	return (TableViewCell *)m_cells.at(idx);
}

