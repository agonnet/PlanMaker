// DlgTemplate.cpp: implementation of the CDlgTemplate class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "planmaker.h"
#include "DlgTemplate.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
DLGTEMPLATE* pTemplate;

CDlgTemplate::CDlgTemplate()
{
}

CDlgTemplate::~CDlgTemplate()
{
	free(pTemplate);
}

DLGTEMPLATE* CDlgTemplate::MakeTemplate(LPCSTR caption, DWORD style, int x, int y, int w, int h,
        LPCSTR font, WORD fontSize)
{

	usedBufferLength = sizeof(DLGTEMPLATE);
	totalBufferLength = usedBufferLength;

	pTemplate = (DLGTEMPLATE*)malloc(totalBufferLength);

	pTemplate->style = style;

	if (font != NULL)
	{
		pTemplate->style |= DS_SETFONT;
	}

	pTemplate->x     = x;
	pTemplate->y     = y;
	pTemplate->cx    = w;
	pTemplate->cy    = h;
	pTemplate->cdit  = 0;

	pTemplate->dwExtendedStyle = 0;

// The dialog box doesn't have a menu or a special class

	AppendData(_T("\0"), 2);
	AppendData(_T("\0"), 2);

// Add the dialog's caption to the template

	AppendString(caption);

	if (font != NULL)
	{
		AppendData(&fontSize, sizeof(WORD));
		AppendString(font);
	}
	return pTemplate;
}

DLGTEMPLATE* CDlgTemplate::AddComponent(LPCSTR type, LPCSTR caption, DWORD style, DWORD exStyle,
        int x, int y, int w, int h, WORD id)
{

	DLGITEMTEMPLATE item;
	item.style = style;
	item.x     = x;
	item.y     = y;
	item.cx    = w;
	item.cy    = h;
	item.id    = id;

	item.dwExtendedStyle = exStyle;

	AppendData(&item, sizeof(DLGITEMTEMPLATE));

	AppendString(type);
	AppendString(caption);

	WORD creationDataLength = 0;
	AppendData(&creationDataLength, sizeof(WORD));

// Increment the component count

	pTemplate->cdit++;
	return pTemplate;
}

DLGTEMPLATE* CDlgTemplate::AddButton(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id)
{

	AddStandardComponent(0x0080, caption, style, exStyle, x, y, w, h, id);

	WORD creationDataLength = 0;
	AppendData(&creationDataLength, sizeof(WORD));
	return pTemplate;
}

DLGTEMPLATE* CDlgTemplate::AddEditBox(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id)
{

	AddStandardComponent(0x0081, caption, style, exStyle, x, y, w, h, id);

	WORD creationDataLength = 0;
	AppendData(&creationDataLength, sizeof(WORD));
	return pTemplate;
}

DLGTEMPLATE* CDlgTemplate::AddStatic(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id)
{

	AddStandardComponent(0x0082, caption, style, exStyle, x, y, w, h, id);

	WORD creationDataLength = 0;
	AppendData(&creationDataLength, sizeof(WORD));
	return pTemplate;
}

DLGTEMPLATE* CDlgTemplate::AddListBox(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id)
{

	AddStandardComponent(0x0083, caption, style, exStyle, x, y, w, h, id);

	WORD creationDataLength = 0;
	AppendData(&creationDataLength, sizeof(WORD));
	return pTemplate;
}

DLGTEMPLATE* CDlgTemplate::AddScrollBar(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id)
{

	AddStandardComponent(0x0084, caption, style, exStyle, x, y, w, h, id);

	WORD creationDataLength = 0;
	AppendData(&creationDataLength, sizeof(WORD));
	return pTemplate;
}

DLGTEMPLATE* CDlgTemplate::AddComboBox(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id)
{

	AddStandardComponent(0x0085, caption, style, exStyle, x, y, w, h, id);

	WORD creationDataLength = 0;
	AppendData(&creationDataLength, sizeof(WORD));
	return pTemplate;
}

void CDlgTemplate::AddStandardComponent(WORD type, LPCSTR caption, DWORD style,
        DWORD exStyle, int x, int y, int w, int h, WORD id)
{

	DLGITEMTEMPLATE item;

// DWORD align the beginning of the component data

	AlignData(sizeof(DWORD));

	item.style = style;
	item.x     = x;
	item.y     = y;
	item.cx    = w;
	item.cy    = h;
	item.id    = id;

	item.dwExtendedStyle = exStyle;

	AppendData(&item, sizeof(DLGITEMTEMPLATE));

	WORD preType = 0xFFFF;

	AppendData(&preType, sizeof(WORD));
	AppendData(&type, sizeof(WORD));

	AppendString(caption);

// Increment the component count

	pTemplate->cdit++;
}

void CDlgTemplate::AlignData(int size)
{

	int paddingSize = usedBufferLength % size;

	if (paddingSize != 0)
	{
		EnsureSpace(paddingSize);
		usedBufferLength += paddingSize;
	}
}

void CDlgTemplate::AppendString(LPCSTR string)
{

	int length = MultiByteToWideChar(CP_ACP, 0, string, -1, NULL, 0);

	WCHAR* wideString = (WCHAR*)malloc(sizeof(WCHAR) * length);
	MultiByteToWideChar(CP_ACP, 0, string, -1, wideString, length);

	AppendData(wideString, length * sizeof(WCHAR));
	free(wideString);
}

void CDlgTemplate::AppendData(void* data, int dataLength)
{

	EnsureSpace(dataLength);

	memcpy((char*)pTemplate + usedBufferLength, data, dataLength);
	usedBufferLength += dataLength;
}

void CDlgTemplate::EnsureSpace(int length)
{

	if (length + usedBufferLength > totalBufferLength)
	{

		totalBufferLength += length * 2;

		void* newBuffer = malloc(totalBufferLength);
		memcpy(newBuffer, pTemplate, usedBufferLength);

		free(pTemplate);
		pTemplate = (DLGTEMPLATE*)newBuffer;
	}
}

