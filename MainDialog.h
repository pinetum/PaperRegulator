#ifndef MAINDIALOG_H
#define MAINDIALOG_H
#include "wxcrafter.h"
#include <wx/timer.h>
class MainDialog : public MainDialogBaseClass
{
public:
    MainDialog(wxWindow* parent);
    virtual ~MainDialog();
	wxString transData;
    wxString last_transData;
	wxTimer* m_timer;
	bool m_b_scanning;
protected:
    virtual void OnTextUpdate(wxCommandEvent& event);
    virtual void OnContentInserted(wxRichTextEvent& event);
    virtual void OnBtnGOClick(wxCommandEvent& event);
	virtual void OnBtnScanClick(wxCommandEvent& event);
    void OnTimer(wxTimerEvent& event);
	void getClip();
};
#endif // MAINDIALOG_H
