
#ifndef __MY_DATASOURCE_H_
#define __MY_DATASOURCE_H_

#include "../Common/Utils.h"

class MyDataSource : public TableViewDataSource
{
public:
std::vector <TableViewCell *> m_cells;

//重载TableViewDataSource类的虚函数
virtual Size cellSizeForTable(TableView *table);
virtual TableViewCell *tableCellAtIndex(TableView *table, ssize_t idx);
virtual ssize_t numberOfCellsInTableView(TableView *table);

public:
MyDataSource();
~MyDataSource();



};



#endif