//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxcrafter.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef MYWXCODE_PAPERREGULATOR_WXCRAFTER_BASE_CLASSES_H
#define MYWXCODE_PAPERREGULATOR_WXCRAFTER_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/webview.h>
#include <wx/statline.h>
#include <wx/button.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

class MainDialogBaseClass : public wxDialog
{
protected:
    wxRichTextCtrl* m_richTextCtrl22;
#if wxUSE_WEBVIEW
    wxWebView* m_webView;
#endif // wxUSE_WEBVIEW

    wxStaticLine* m_staticLine15;
    wxButton* m_buttonOK;
    wxButton* m_buttonScan;
    wxButton* m_buttonCancel;

protected:
    virtual void OnTextUpdate(wxCommandEvent& event) { event.Skip(); }
    virtual void OnContentInserted(wxRichTextEvent& event) { event.Skip(); }
    #if wxUSE_WEBVIEW
    #endif // wxUSE_WEBVIEW
    virtual void OnBtnGOClick(wxCommandEvent& event) { event.Skip(); }
    virtual void OnBtnScanClick(wxCommandEvent& event) { event.Skip(); }

public:
    wxRichTextCtrl* GetRichTextCtrl22() { return m_richTextCtrl22; }
    wxWebView* GetWebView() { return m_webView; }
    wxStaticLine* GetStaticLine15() { return m_staticLine15; }
    wxButton* GetButtonOK() { return m_buttonOK; }
    wxButton* GetButtonScan() { return m_buttonScan; }
    wxButton* GetButtonCancel() { return m_buttonCancel; }
    MainDialogBaseClass(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("My Dialog"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER);
    virtual ~MainDialogBaseClass();
};

#endif
