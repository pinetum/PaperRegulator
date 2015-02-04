#include "MainDialog.h"
#include <wx/log.h>
#include <wx/clipbrd.h>
#include <wx/string.h>
#include <wx/utils.h>
#include <wx/uri.h>
MainDialog::MainDialog(wxWindow* parent)
    : MainDialogBaseClass(parent)
{
	SetSize(750, 600);
	Center();
	transData ="";
	SetTitle("PaperRegulator");
}

MainDialog::~MainDialog()
{
}

void MainDialog::OnBtnGOClick(wxCommandEvent& event)
{
	if (wxTheClipboard->Open())
	{
		if (wxTheClipboard->IsSupported( wxDF_TEXT ))
		{
			wxTextDataObject data;
			wxTheClipboard->GetData( data );
			transData = data.GetText();
			transData.Replace(_("- "), _(""), true);
			transData.Replace(_("\n"), _(""), true);
			m_richTextCtrl22->Clear();
			m_richTextCtrl22->AppendText(transData);
			//transData = paperText;
		}
		wxTheClipboard->Close();
	}
	
	
}
void MainDialog::OnContentInserted(wxRichTextEvent& event)
{
	wxString str_url = "https://translate.google.com.tw/?oe=UTF-8&ie=UTF-8&hl=zh-TW&client=tw-ob#en/zh-TW/";
	str_url.Append(transData);
	wxURI url (str_url);
	str_url = url.BuildURI();
	m_webView->LoadURL(str_url);
	
	//wxLaunchDefaultBrowser(str_url);
	
	
}
void MainDialog::OnTextUpdate(wxCommandEvent& event)
{
}
