#include "tabObject.h"
#include "stdafx.h"
HRESULT tabUI::QueryInterface(REFIID riid, void** ppvObject){
	*ppvObject = 0;
	if(IsEqualIID(riid, IID_IUnknown))
		*ppvObject = static_cast<IWebUIDelegate*>(this);
	else if(IsEqualIID(riid, IID_IWebUIDelegate))
		*ppvObject = static_cast<IWebUIDelegate*>(this);
	else
		return E_NOINTERFACE;
	AddRef();
	return S_OK;
}

ULONG tabUI::AddRef()
{
    return ++m_refCount;
}

ULONG tabUI::Release(void)
{
    ULONG newRef = --m_refCount;
    if (!newRef)
        delete this;

    return newRef;
}

HRESULT tabUI::runJavaScriptAlertPanelWithMessage(IWebView* sender, BSTR message)
{
    ::MessageBox(0, message, _T("WebKit Alert!"), MB_OK);
    return S_OK;
}
