#pragma once
template <class DataType>
class Queue;
template <class DataType>
class LinkedList;
template <class DataType>
class DanhSachPhieuMuon;

template <class DataType>
class Node {
	friend Queue<DataType>;
	friend LinkedList<DataType>;
	friend class DanhSachPhieuMuon<DataType>;
public:
	DataType _data;
	Node* _pNext;
public:
	Node(DataType data);
	void display();
	void displayDetail();

};