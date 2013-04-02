#include "stdafx.h"
#include <vector>
interface IWnd{
public:
	virtual void Create() = 0;
	virtual void ChangeSize(int x, int y) = 0;
	virtual void Destroy() = 0;
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) = 0;
private:
	HWND m_hWnd;
	int x, y, w, h;//시작 x, 시작 y, 길이, 높이
	
};

static class HandlePool{
private:
	static std::vector<IWnd> _handlelist;
	static HandlePool* _inst;
public:
	static void Create(){
		for(std::vector<IWnd>::iterator i = _handlelist.begin(); i != _handlelist.end(); i++)
			i->Create();
	}
	static void ChangeSize(int x, int y){
		for(std::vector<IWnd>::iterator i = _handlelist.begin(); i != _handlelist.end(); i++)
			i->ChangeSize(x,y);
	}
	static void Destroy(){
		for(std::vector<IWnd>::iterator i = _handlelist.begin(); i != _handlelist.end(); i++)
			i->Destroy();
	}
	static void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
		for(std::vector<IWnd>::iterator i = _handlelist.begin(); i != _handlelist.end(); i++)
			i->MsgProc(hWnd, message, wParam, lParam);
	}
	static HandlePool* Instance(){
		if(_inst == NULL)
			_inst = new HandlePool();

		return _inst;
	}

};