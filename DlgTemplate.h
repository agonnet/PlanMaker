// DlgTemplate.h: interface for the CDlgTemplate class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLGTEMPLATE_H__E6ED6240_1318_11D9_93D6_F851ED1C3803__INCLUDED_)
#define AFX_DLGTEMPLATE_H__E6ED6240_1318_11D9_93D6_F851ED1C3803__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CDlgTemplate  
{
public:

    int totalBufferLength;
    int usedBufferLength;
	
	CDlgTemplate();
	virtual ~CDlgTemplate();
    DLGTEMPLATE* MakeTemplate(LPCSTR caption, DWORD style, int x, int y, int w, int h,
        LPCSTR font, WORD fontSize);
    DLGTEMPLATE* AddComponent(LPCSTR type, LPCSTR caption, DWORD style, DWORD exStyle,
        int x, int y, int w, int h, WORD id);
    DLGTEMPLATE* AddButton(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id);
    DLGTEMPLATE* AddEditBox(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id);
    DLGTEMPLATE* AddStatic(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id);
    DLGTEMPLATE* AddListBox(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id);
    DLGTEMPLATE* AddScrollBar(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id);
    DLGTEMPLATE* AddComboBox(LPCSTR caption, DWORD style, DWORD exStyle, int x, int y,
        int w, int h, WORD id);

protected:

    void AddStandardComponent(WORD type, LPCSTR caption, DWORD style,
        DWORD exStyle, int x, int y, int w, int h, WORD id);
    void AlignData(int size);
    void AppendString(LPCSTR string);
    void AppendData(void* data, int dataLength);
    void EnsureSpace(int length);
};

#endif // !defined(AFX_DLGTEMPLATE_H__E6ED6240_1318_11D9_93D6_F851ED1C3803__INCLUDED_)
