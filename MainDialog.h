#ifndef MAINDIALOG_H
#define MAINDIALOG_H
#include "wxcrafter.h"

class MainDialog : public MainDialogBaseClass
{
public:
    MainDialog(wxWindow* parent);
    virtual ~MainDialog();
	wxString transData;
protected:
    virtual void OnTextUpdate(wxCommandEvent& event);
    virtual void OnContentInserted(wxRichTextEvent& event);
    virtual void OnBtnGOClick(wxCommandEvent& event);
    
};
#endif // MAINDIALOG_H
